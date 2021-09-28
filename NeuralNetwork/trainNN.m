function [Theta1, Theta2, Theta3] = trainNN(input_layer_size, first_hidden_layer_size, second_hidden_layer_size, num_labels, ...
                                            X, y, lambda)
%TRAINLINEARREG Trains linear regression given a dataset (X, y) and a
%regularization parameter lambda
%   [theta] = TRAINLINEARREG (X, y, lambda) trains linear regression using
%   the dataset (X, y) and regularization parameter lambda. Returns the
%   trained parameters theta.
%

m = size(X, 1);
% Initialize Theta

Theta1 = randInitializeWeights(input_layer_size, first_hidden_layer_size);
Theta2 = randInitializeWeights(first_hidden_layer_size, second_hidden_layer_size);
Theta3 = randInitializeWeights(second_hidden_layer_size, num_labels);
nn_params = [Theta1(:); Theta2(:); Theta3(:)];

% Create "short hand" for the cost function to be minimized
costFunction = @(nn_params) nnCostFunction(nn_params, input_layer_size, first_hidden_layer_size, second_hidden_layer_size, num_labels, X, y, lambda);
options = optimset('MaxIter', 500);
[nn_params1, cost] = fmincg(costFunction, nn_params, options);
Theta1 = reshape(nn_params1(1:first_hidden_layer_size * (input_layer_size + 1)), first_hidden_layer_size, (input_layer_size + 1));
Theta2 = reshape(nn_params1((1 + (first_hidden_layer_size * (input_layer_size + 1))):(((first_hidden_layer_size * (input_layer_size + 1))) + (second_hidden_layer_size * (first_hidden_layer_size + 1)))), second_hidden_layer_size, (first_hidden_layer_size + 1));
Theta3 = reshape(nn_params1((((1 + (first_hidden_layer_size * (input_layer_size + 1))) + (second_hidden_layer_size * (first_hidden_layer_size + 1)))):end), num_labels, (second_hidden_layer_size + 1));

end
