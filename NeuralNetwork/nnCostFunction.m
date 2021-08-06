function [J grad] = nnCostFunction(nn_params, ...
				   input_layer_size, ...
				   first_hidden_layer_size, ...
				   second_hidden_layer_size, ...
				   num_labels, ...
				   X, y, lambda)

%   NNCOSTFUNCTION Implements the neural network cost function for a three layer
%   neural network which performs classification
%   [J grad] = NNCOSTFUNCTON(nn_params, hidden_layer_size, num_labels, ...
%   X, y, lambda) computes the cost and gradient of the neural network. The
%   parameters for the neural network are "unrolled" into the vector
%   nn_params and need to be converted back into the weight matrices.
%
%   The returned parameter grad should be a "unrolled" vector of the
%   partial derivatives of the neural network.
%
%   Reshape nn_params back into the parameters Theta1, Theta2 and Theta3, the weight matrices
%   for our 3 layer neural network

Theta1 = reshape(nn_params(1:first_hidden_layer_size * (input_layer_size + 1)), ...
                 first_hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (first_hidden_layer_size * (input_layer_size + 1))):(((first_hidden_layer_size * (input_layer_size + 1))) + (second_hidden_layer_size * (first_hidden_layer_size + 1)))), ...
                 second_hidden_layer_size, (first_hidden_layer_size + 1));

Theta3 = reshape(nn_params((((1 + (first_hidden_layer_size * (input_layer_size + 1))) + (second_hidden_layer_size * (first_hidden_layer_size + 1)))):end), ...
		 num_labels, (second_hidden_layer_size + 1));

% Setup some useful variables
m = size(X, 1);

% You need to return the following variables correctly
J = 0;
Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));
Theta3_grad = zeros(size(Theta3));

% Add bias term
one = sum(eye(m), 2);

% Feedforward the neural network and return the cost in the
%         variable J.
a_1 = [one X];
Z_2 = a_1 * Theta1';
a_2 = [one sigmoid(Z_2)];
Z_3 = a_2 * Theta2';
a_3 = [one sigmoid(Z_3)];
Z_4 = a_3 * Theta3';
a_4 = sigmoid(Z_4);
K = size(a_4, 2);


% Evaluate J value
J = (-1 / m) * sum(sum(((log(a_4)' * y) + (log(1 - a_4)' * (1 - y))) .* eye(K)));


% Implement Regularization
J = J + (lambda / (m * 2)) * (sum(sum(Theta1(:, 2:end) .^ 2)) + sum(sum(Theta2(:, 2:end) .^ 2)) + sum(sum(Theta3(:, 2:end) .^ 2)));


% Implement the backpropagation algorithm to compute the gradients
%         Theta1_grad, Theta2_grad and Theta3_grad.
delta_4 = a_4 - y;
delta_3 = (delta_4 * Theta3(:, 2:end)) .* sigmoidGradient(Z_3);
delta_2 = (delta_3 * Theta2(:, 2:end)) .* sigmoidGradient(Z_2);
Delta_1 = delta_2' * a_1;
Delta_2 = delta_3' * a_2;
Delta_3 = delta_4' * a_3;
D_1 = (1 / m) * Delta_1;
D_2 = (1 / m) * Delta_2;
D_3 = (1 / m) * Delta_3;

Theta1_grad = D_1;
Theta2_grad = D_2;
Theta3_grad = D_3;

% Implement Regularization
Theta1_grad(:, 2:end) = Theta1_grad(:, 2:end) + (lambda / m) * Theta1(:, 2:end);
Theta2_grad(:, 2:end) = Theta2_grad(:, 2:end) + (lambda / m) * Theta2(:, 2:end);
Theta3_grad(:, 2:end) = Theta3_grad(:, 2:end) + (lambda / m) * Theta3(:, 2:end);


% Unroll gradients
grad = [Theta1_grad(:); Theta2_grad(:); Theta3_grad(:)];

end