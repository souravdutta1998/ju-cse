A=dlmread("aitken.txt"); %reading the matrix from data file
A(1,:)=[]; %neglecting the first row headers
B=dlmread("fixed_point.txt"); %reading the matrix from data file
%B(1,:)=[]; %neglecting the first row headers
    i_aitken=A(:,1); %reading column 1 which is iteration
    i_fixed_pt=B(:,1); %reading column 1 which is iteration 
    itr=[min(min(i_aitken),min(i_fixed_pt)):1:max(max(i_aitken),max(i_fixed_pt))];
    abs_error_aitken=A(:,6); %reading column 6 which is absolute error
    abs_error_fixed_pt=B(:,5); %reading column 6 which is error
    grid on;
    plot(i_aitken,abs_error_aitken,"b."); %plotting the points of f(x) using blue colour dots (aitken)
    hold on;
    plot(i_aitken,abs_error_aitken,"b"); %plotting the graph of f(x) using blue colour line (aitken)
    hold on;
    plot(i_fixed_pt,abs_error_fixed_pt,"g."); %plotting the points of f(x2) using green colour dots (fixed point iteration)
    hold on;
     plot(i_fixed_pt,abs_error_fixed_pt,"g"); %plotting the graph of f(x) using green colour line (fixed point iteration)
    hold on;
    legend("Aitken","" ,"Fixed point iteration");
    xlabel('iteration'),ylabel('absolute error');
    hold on;