X = rand(1, 1000) - 0.5 ;
Y = rand(1, 1000) - 0.5 ;
plot(X, Y, 'x')
MeanX = mean(X)
MeanY = mean(Y)
R = corrcoef(X, Y)