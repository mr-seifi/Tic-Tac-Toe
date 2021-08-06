function p = predict(Theta1, Theta2, Theta3, X)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, Theta3, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2, Theta3)

% Useful values
m = size(X, 1);
num_labels = size(Theta3, 1);

p = zeros(size(X, 1), 1);

h1 = sigmoid([ones(m, 1) X] * Theta1');
h2 = sigmoid([ones(m, 1) h1] * Theta2');
h3 = sigmoid([ones(m, 1) h2] * Theta3');
%[dummy, p] = max(h2, [], 2);
p = h3;

end
