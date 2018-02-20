A=dlmread("multipoint_data.txt"); %reading the matrix from data file
A(1,:)=[]; %neglecting the first row headers
    x_a=A(:,2); %reading column 2 which is x
    x=[-1:.1:2.5];
    f_a=A(:,3); %reading column 3 which is f(x)
    fx=exp(x)-2.*x-1;
    plot(x,fx,"b"); %plotting the graph of f(x) using blue colour line
    hold on;
    plot(x_a,f_a,"go"); %plotting the points of f(x) using green colour circles
    hold on;
    grid on;
    legend("f(x) = exp(x)-2*x-1");
    xlabel('x'),ylabel('function(x)'),title("Multi-point method");
    hold on;
    grid on;