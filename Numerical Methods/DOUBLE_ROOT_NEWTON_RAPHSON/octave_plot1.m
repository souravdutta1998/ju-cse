A=dlmread("newton_raphson.txt"); %reading the matrix from data file
A(1,:)=[]; %neglecting the first row headers
B=dlmread("double_root_newton.txt"); %reading the matrix from data file
B(1,:)=[]; %neglecting the first row headers
    i_a=A(:,1); %reading column 1 which is iteration
    i_b=B(:,1); %reading column 1 which is iteration 
    itr=[min(min(i_a),min(i_b)):1:max(max(i_a),max(i_b))];
    abs_error_a=A(:,4); %reading column 4 which is absolute error
    abs_error_b=B(:,4); %reading column 4 which is error
    grid on;
    plot(i_a,abs_error_a,"bo"); %plotting the points of absolute errors using blue colour circles (a)
    hold on;
    plot(i_a,abs_error_a,"b"); %plotting the graph of absolute errors using blue colour line (a)
    hold on;
    plot(i_b,abs_error_b,"go"); %plotting the points of absolute errors using green colour circles (b)
    hold on;
     plot(i_b,abs_error_b,"g"); %plotting the graph of absolute errors using green colour line (b)
    hold on;
    legend("Newton Raphson","" ,"Double root Newton Raphson"),title("Absolute error vs Iteration");
    xlabel('iteration'),ylabel('absolute error');
    hold on;
    grid on;
