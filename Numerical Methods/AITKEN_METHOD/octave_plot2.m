A=dlmread("aitken.txt"); %reading the matrix from data file
A(1,:)=[]; %neglecting the first row headers
B=dlmread("fixed_point.txt"); %reading the matrix from data file
%B(1,:)=[]; %neglecting the first row headers
    x_aitken=A(:,3); %reading column 3 which is x
    x_fixed_pt=B(:,2); %reading column 2 which is x
    x=[min(min(x_aitken),min(x_fixed_pt)):.1:max(max(x_aitken),max(x_fixed_pt))];
    f_aitken=A(:,2); %reading column 2 which is f(x)
    f_fixed_pt=B(:,4); %reading column 2 which is f(x)
    fx=exp(x)-4.*x.*x; %the given f(x)
    grid on;
    plot(x,fx,"b"); %plotting the graph of f(x) using blue colour line
    hold on;
    plot(x_aitken,f_aitken,"ko"); %plotting the points of f(x) using black colour dots (aitken)
    hold on;
    plot(x_fixed_pt,f_fixed_pt,"g."); %plotting the points of f(x2) using green colour dots (fixed point iteration)
    hold on;
    grid on;
    legend("" ,"Aitken","Fixed point iteration");
    xlabel('x'),ylabel('function(x)');
    hold on;