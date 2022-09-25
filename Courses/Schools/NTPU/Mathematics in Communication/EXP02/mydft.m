function y = mydft(x)
    nx=length(x);
    y=zeros(size(x));
    %% Write your DFT here
    for k = 1:nx
        for n = 1:nx
            y(k) = y(k) + x(n)*exp(-1i*(2*pi/nx)*(k-1)*(n-1));
        end
    end