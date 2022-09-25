X = rand(1, 1000) - 0.5 ;
Y = rand(1, 1000) - 0.5 ;
MeanX = mean(X)
MeanY = mean(Y)

%  [A] = [  3.464101615           0 ][X]
%  [B]   [ -2.424871131 2.473863375 ][Y]

A = 3.464101615 * X + 0 * Y ;
B = -2.424871131 * X + 2.473863375 * Y ;
MeanA = mean(A)
MeanB = mean(B)

plot(A, B, 'o')
CovAB = cov(A, B)