X = rand(1, 1000) - 0.5 ;
Y = -2 * X ;
plot(X, Y, 'x')
MeanX = mean(X)
MeanY = mean(Y)
R = corrcoef(X,Y)