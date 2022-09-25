X = rand(1, 1000) - 0.5 ;
Y = rand(1, 1000) - 0.5 ;
A = 1.5 * X - 0.5 * Y ;
B = 0.8 * X + 0.2 * Y ;
plot(A, B, 'o')
R = corrcoef(A, B)