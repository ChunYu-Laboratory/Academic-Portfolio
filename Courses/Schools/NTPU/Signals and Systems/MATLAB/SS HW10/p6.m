% stochastic matrix
% a square matrix used to describe the transitions of a Markov chain
% Each of its entries is a nonnegative real number representing a probability
A = [ 0.3, 0.1, 0.2; 0.2, 0.7, 0.4; 0.5, 0.2, 0.4 ]

% initial state with n = 1
n = 1
TEMP = A % A^n
A = A * A % A^(n+1)

while A ~= TEMP % Compare whether A^(n+1), A^n are identical or not
    TEMP = A
    A = A * A
    n = n + 1
end