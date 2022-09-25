a = [ 0.5, -0.5 ];
w = linspace( -2.2*pi, 2.2*pi, 1000000 );

for index = 1:2
    subplot( 1, 2, index );
    X = ( (1 - a(index)*cos(w)) + i*a(index)*sin(w) ).^-1;
    abs_X = abs(X);
    plot( w, abs_X, 'LineWidth', 3.5 )
    title( [ 'a = ', num2str( a(index) ) ] )
    axis( [-2.2*pi, 2.2*pi, 0, 2.5] );
    grid on
end