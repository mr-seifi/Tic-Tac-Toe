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

% ====================== YOUR CODE HERE ======================
% Instructions: Fill in this function to return training errors in 
%               error_train and the cross validation errors in error_val. 
%               i.e., error_train(i) and 
%               error_val(i) should give you the errors
%               obtained after training on i examples.
%
% Note: You should evaluate the training error on the first i training
%       examples (i.e., X(1:i, :) and y(1:i)).
%
%       For the cross-validation error, you should instead evaluate on
%       the _entire_ cross validation set (Xval and yval).
%
% Note: If you are using your cost function (linearRegCostFunction)
%       to compute the training and cross validation error, you should 
%       call the function with the lambda argument set to 0. 
%       Do note that you will still need to use lambda when running
%       the training to obtain the theta parameters.
%
% Hint: You can loop over the examples with the following:
%
%       for i = 1:m
%           % Compute train/cross validation errors using training examples 
%           % X(1:i, :) and y(1:i), storing the result in 
%           % error_train(i) and error_val(i)
%           ....
%           
%       end
%

% ---------------------- Sample Solution ----------------------




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