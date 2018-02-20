A=dlmread("multipoint_data.txt"); %reading the matrix from data file
A(1:2,:)=[]; %neglecting the first two row headers
    i_a=A(:,1); %reading column 1 which is iteration
    itr=[min(i_a):1:max(i_a)];
    abs_error_a=A(:,4); %reading column 4 which is absolute error
    grid on;
    plot(i_a,abs_error_a,"ro"); %plotting the points of absolute errors using red colour circles
    hold on;
    plot(i_a,abs_error_a,"b"); %plotting the graph of absolute errors using blue colour line
    hold on;
    xlabel('iteration'),ylabel('absolute error'),title("Multi-point method");
    hold on;
    grid on;