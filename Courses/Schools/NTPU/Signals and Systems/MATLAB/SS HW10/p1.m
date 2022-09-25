% y = cos(m*arccos(x))

x = linspace( -1, 1, 100000 );
for m = 1:5
    y = cos( m*acos( x ) );
    plot( x, y, 'LineWidth', 3.5 );
    hold on
end
hold off
title('y = cos(m*arccos(x))')
legend('m = 1', 'm = 2', 'm = 3', 'm = 4', 'm = 5')