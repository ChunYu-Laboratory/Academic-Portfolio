% [V,D] = eig(A)
% A*V = V*D

for index = 1:10
    disp(['>> Random Matrix #', num2str(index)])
    A = rand(10)
    disp('# D : diagonal matrix of eigenvalues')
    disp('# V : whose columns are the corresponding right eigenvectors')
    [V,D] = eig(A)
    disp('--> A*V = V*D')
    disp('--> A*V - V*D = 0')
    A*V - V*D
    disp('# Approximately equal to zero')
    disp('# Answer is not exactly equal to zero due to floating point computation')
    fprintf('----------------------------------------\n');
end