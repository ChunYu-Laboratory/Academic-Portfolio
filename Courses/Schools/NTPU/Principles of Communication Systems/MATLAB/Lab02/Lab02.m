df = 0.01 ;
fs = 10 ;
ts = 1/fs ;
t = -5:ts:5 ;

% Creating Signals
x1 = zeros(size(t)) ;
x1(41:51) = t(41:51) + 1 ;
x1(52:61) = -t(52:61) + 1 ;
x2 = zeros(size(t)) ;
x2(51:71) = x1(41:61) ;

plot(t, x1, t, x2, '--', 'LineWidth', 3)
axis( [-3, 3, -1, 2] ) ;
legend('x1(t)', 'x2(t)')
figure

% Demonstrate how a time shift reflects in the phase of FFT

[X1, x11, df1] = fftseq(x1, ts, df) ;
[X2, x21, df2] = fftseq(x2, ts, df) ;
X11 = X1/fs ;
X21 = X2/fs ;
f = [0:df1:df1*(length(x11)-1)] - fs/2 ;

plot(f, fftshift(abs(X11)), 'LineWidth', 3)
legend('| X1(f) | = | X2(f) |')
figure
plot(f(500:525), fftshift(angle(X11(500:525))), f(500:525), fftshift(angle(X21(500:525))), '--', 'LineWidth', 3)
legend('<X1(f)', '<X2(f)')