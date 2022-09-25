X = rand(1, 1000) - 0.5 ;
Y = rand(1, 1000) - 0.5 ;
%  [A] = [ 0.5 0.5 ][X]
%  [B]   [ 0.1 0.9 ][Y]
A = 0.5 * X + 0.5 * Y ;
B = 0.1 * X + 0.9 * Y ;
plot(A, B, 'o')
R = corrcoef(A, B)