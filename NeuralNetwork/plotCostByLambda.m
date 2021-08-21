function [J_training J_cross lambda nn_params] = plotCostByLambda(X_training, y_training, X_cross, y_cross)
input_layer_size = 9;
first_hidden_layer_size = 36;
second_hidden_layer_size = 36;
num_labels = 1;

Theta1 = randInitializeWeights(input_layer_size, first_hidden_layer_size);
Theta2 = randInitializeWeights(first_hidden_layer_size, second_hidden_layer_size);
Theta3 = randInitializeWeights(second_hidden_layer_size, num_labels);
initial_nn_params = [Theta1(:); Theta2(:); Theta3(:)];

options = optimset('MaxIter', 400);

lambda_list = 0:2e-2:2;
J_training = zeros(length(lambda_list), 1);
J_cross = zeros(length(lambda_list), 1);

for i = 1:length(lambda_list)

    costFunction = @(p) nnCostFunction(p, input_layer_size, first_hidden_layer_size, second_hidden_layer_size, num_labels, ...
                                       X_training, y_training, lambda_list(i));
    [nn_params, cost] = fmincg(costFunction, initial_nn_params, options);

    J_training(i) = nnCostFunction(nn_params, input_layer_size, first_hidden_layer_size, ...
                                second_hidden_layer_size, num_labels, X_training, y_training, ...
                                0);
    J_cross(i) = nnCostFunction(nn_params, input_layer_size, first_hidden_layer_size, ...
                                    second_hidden_layer_size, num_labels, X_cross, y_cross, ...
                                    0);
    printf(num2str(i * 100 / length(lambda_list)))
    printf('%%\n')
end

plot(lambda_list(1:length(lambda_list)), J_training, "k", lambda_list(1:length(lambda_list)), J_cross, "r");
hold on;
title('Plot Cost value by Lambda');
legend('Train', 'Cross Validation');
xlabel('Lambda');
ylabel('Error');
print -dpng 'plotByLambda2.png';
[cross_min cross_min_index] = min(J_cross);
lambda = lambda_list(cross_min_index);
costFunction = @(p) nnCostFunction(p, input_layer_size, first_hidden_layer_size, second_hidden_layer_size, num_labels, ...
                                   X_training, y_training, lambda_list(cross_min_index));
[nn_params cost] = fmincg(costFunction, initial_nn_params, options);
printf('Minimum of cross validation error is: ')
printf(num2str(cross_min))
hold off;
end
