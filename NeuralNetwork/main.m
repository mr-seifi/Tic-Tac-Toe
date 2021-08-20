load data.mat;
X = data(:, 1:9);
y = data(:, 10);
input_layer_size = 9;
first_hidden_layer_size = 36;
second_hidden_layer_size = 36;
num_labels = 1;
m = size(X, 1);
Theta1 = randInitializeWeights(input_layer_size, first_hidden_layer_size);
Theta2 = randInitializeWeights(first_hidden_layer_size, second_hidden_layer_size);
Theta3 = randInitializeWeights(second_hidden_layer_size, num_labels);
nn_params = [Theta1(:); Theta2(:); Theta3(:)];
lambda = 1e-3;
J = nnCostFunction(nn_params, input_layer_size, first_hidden_layer_size, second_hidden_layer_size, num_labels, X, y, lambda);
options = optimset('MaxIter', 1000);
costFunction = @(p) nnCostFunction(p, input_layer_size, first_hidden_layer_size, second_hidden_layer_size, num_labels, X, y, lambda);
[nn_params1, cost] = fmincg(costFunction, nn_params, options);
Theta1 = reshape(nn_params1(1:first_hidden_layer_size * (input_layer_size + 1)), first_hidden_layer_size, (input_layer_size + 1));
Theta2 = reshape(nn_params1((1 + (first_hidden_layer_size * (input_layer_size + 1))):(((first_hidden_layer_size * (input_layer_size + 1))) + (second_hidden_layer_size * (first_hidden_layer_size + 1)))), second_hidden_layer_size, (first_hidden_layer_size + 1));
Theta3 = reshape(nn_params1((((1 + (first_hidden_layer_size * (input_layer_size + 1))) + (second_hidden_layer_size * (first_hidden_layer_size + 1)))):end), num_labels, (second_hidden_layer_size + 1));
save Theta1.mat Theta1;
save Theta2.mat Theta2;
save Theta3.mat Theta3;
predict(Theta1, Theta2, Theta3, X);
