function [error_train, error_cross] = ...
    learningCurve(X, y, X_cross, y_cross, lambda)
%LEARNINGCURVE Generates the train and cross validation set errors needed 
%to plot a learning curve
%   [error_train, error_val] = ...
%       LEARNINGCURVE(X, y, Xval, yval, lambda) returns the train and
%       cross validation set errors for a learning curve. In particular, 
%       it returns two vectors of the same length - error_train and 
%       error_val. Then, error_train(i) contains the training error for
%       i examples (and similarly for error_val(i)).
%
%   In this function, you will compute the train and test errors for
%   dataset sizes from 1 up to m. In practice, when working with larger
%   datasets, you might want to do this in larger intervals.
%

% Number of training examples
m = size(X, 1);

% You need to return these values correctly
error_train = zeros(m, 1);
error_val   = zeros(m, 1);

input_layer_size = 9;
first_hidden_layer_size = 36;
second_hidden_layer_size = 36;
num_labels = 1;

for i = 1:m,
	[Theta1, Theta2, Theta3] = trainNN(input_layer_size, first_hidden_layer_size, second_hidden_layer_size, num_labels, ...
	                                   X(1:i, :), y(1:i), lambda);
	nn_params = [Theta1(:); Theta2(:); Theta3(:)];
	error_train(i, 1) = nnCostFunction(nn_params, input_layer_size, first_hidden_layer_size, second_hidden_layer_size, num_labels, ...
	                                   X(1:i, :), y(1:i, :), 0)(1);
	error_val(i, 1) = nnCostFunction(nn_params, input_layer_size, first_hidden_layer_size, second_hidden_layer_size, num_labels, ...
	                                 X_cross, y_cross, 0)(1);

end
% -------------------------------------------------------------

plot(1:m, error_train, 1:m, error_val);
title('Learning curve for linear regression')
legend('Train', 'Cross Validation')
xlabel('Number of training examples')
ylabel('Error')
% axis([0 13 0 150])

% =========================================================================

end
