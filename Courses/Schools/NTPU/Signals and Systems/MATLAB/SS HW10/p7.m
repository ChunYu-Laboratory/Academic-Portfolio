a = rand( 1, 100 ) > 0.5;
b = rand( 1, 100 ) > 0.5;
c = bitxor( bitxor( a, b ), b );
d = ~bitxor( ~bitxor( a, b ), b );

isequal( a, c )
isequal( a, d )