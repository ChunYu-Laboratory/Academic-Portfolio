x = [ 1, -2, 3, -4, 5, 0, 2 ]

% for-loop method
total = 0;
for i = 1:length(x)
    if x(i) < 0
        continue;
    end
    total = total + x(i);
end

% while-loop method
total = 0;
k = 1;
while k <= length(x)
    if x(k) < 0
        k = k + 1;
        continue;
    end
    total = total + x(k);
    k = k + 1;
end