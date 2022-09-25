% v = rand(1,50) >= 0.4
% v = 1:50 > 20 % not random
% v = randi(50,1,50) > 20

for index = 1:100
    disp(['>> Random Vector #', num2str(index)])
    v = rand(1,50) >= 0.4;
%    disp('Length(v) :')
    l = length(v);
%    disp('Number of 1s :')
    one = nnz(v);
%    disp('Number of 0s :')
    zro = l - one;
    disp('probability of appearance of 1s :')
    p1 = one/l
    disp('probability of appearance of 0s :')
    p0 = 1-p1
end