A=dlmread("newton_raphson.txt"); %reading the matrix from data file
A(1,:)=[]; %neglecting the first row headers
B=dlmread("double_root_newton.txt"); %reading the matrix from data file
B(1,:)=[]; %neglecting the first row headers
    x_a=A(:,2); %reading column 2 which is x
    x_b=B(:,2); %reading column 2 which is x
    x=[min(min(x_a),min(x_b)):.1:max(max(x_a),max(x_b))];
    f_a=A(:,3); %reading column 3 which is f(x)
    f_b=B(:,3); %reading column 3 which is f(x)
    fx=x.^3-2*(x.^2)-4*x+8;
    plot(x,fx,"b"); %plotting the graph of f(x) using blue colour line
    hold on;
    plot(x_a,f_a,"ko"); %plotting the points of f(x) using black colour circles (a)
    hold on;
    plot(x_b,f_b,"go"); %plotting the points of f(x) using green colour circles (b)
    hold on;
    grid on;
    legend("" ,"Newton Raphson","","Double root Newton Raphson"),title("function(x) vs x");
    xlabel('x'),ylabel('function(x)');
    hold on;
    grid on;
