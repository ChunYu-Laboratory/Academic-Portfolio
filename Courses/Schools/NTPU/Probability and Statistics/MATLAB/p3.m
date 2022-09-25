x = 0:0.1:40000;

% chip 1
mu1 = 20000;
sigma1 = 5000;
pd1 = makedist( 'Normal', 'mu', mu1, 'sigma', sigma1 )
y1_pdf = pdf( pd1, x );
y1_cdf = cdf( pd1, x );

% chip 2
mu2 = 22000;
sigma2 = 1000;
pd2 = makedist( 'Normal', 'mu', mu2, 'sigma', sigma2 )
y2_pdf = pdf( pd2, x );
y2_cdf = cdf( pd2, x );

figure(1)
plot( x, y1_pdf, 'LineWidth', 3.5 )
hold on
plot( x, y2_pdf, 'LineWidth', 3.5 )
hold off
title('PDF')
legend('chip 1', 'chip 2')
grid on

figure(2)
plot( x, y1_cdf, 'LineWidth', 3.5 )
hold on
plot( x, y2_cdf, 'LineWidth', 3.5 )
hold off
title('CDF')
legend('chip 1', 'chip 2')
grid on