%graphics_toolkit gnuplot;
clear all;
close all;

nx=65536;
x=randn(nx,1); 
xdft=mydft(x); % write your own dft function with name "mydft"
xfft=fft(x);
max(abs(xdft-xfft))

figure(1);
plot(abs(xdft-xfft));
xlabel('index','fontsize',12,'fontname','Helvetica');
ylabel('absolute error','fontsize',12,'fontname','Helvetica');
title('Difference between mydft and fft (410887040)','fontsize',12,'fontname','Helvetica');
fname = 'prob_fourier_2_1(410887040).png';  %<-- Fill your id
print (fname, '-dpng'); 

nlist=[3:13];
timedft=zeros(size(nlist));
timefft=zeros(size(nlist));

for k=1:length(nlist)
    nx=2^nlist(k);
    %nx = 2^(k+2)
    total_dft=0;
    total_fft=0;
    for m=1:10
        x=randn(nx,1);   
        tic();
        xdft=mydft(x);
        total_dft = total_dft + toc();
        tic();
        xfft=fft(x);
        total_fft = total_fft + toc();        
    end
    timedft(k) = total_dft/10;
    timefft(k) = total_fft/10;   
end


figure(2);
semilogy(nlist,timedft,'-o',nlist,timefft,'-x');
grid;
legend(['dft';'fft']); 
xlabel('transform size (2^n)','fontsize',16,'fontname','Helvetica');
ylabel('Elapsed time (sec)','fontsize',16,'fontname','Helvetica');
title('Comparsion of elapsed times (410887040)','fontsize',16,'fontname','Helvetica');
fname = 'prob_fourier_2_2(410887040).png';  %<-- Fill your id
print (fname, '-dpng'); 
