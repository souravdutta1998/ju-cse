M1=dlmread('x-exp(-x)_bisection.txt'); % reading the matrix of data from the file
M2=dlmread('x-exp(-x)_falsi.txt'); % reading the matrix of data from the file
[row1,col1]=size(M1); % finding number of rows and columns in matrix M
[row2,col2]=size(M2); % finding number of rows and columns in matrix M
abs1=abs(M1([3:24],6));
abs2=abs(M2([3:25],6));
i1=M1([3:24],1);
i2=M2([3:25],1);

plot(i1,abs1,'ro');
hold on;
plot(i2,abs2,'go');
hold on;
%plot(mid2,con2,'yo');
hold on;

%figure;
%plot(X1,Y1,'v');
%plot(X2,Y2,'y');
%hold on;
%plot(mid1,fmid1,'ro');
%plot(mid2,fmid2,'g');
grid on;
hold on;
xlabel('iteration'),ylabel('absolute value'),title('convergence comparison(blue-bisection,red-false position)');

plot(i1,abs1);
plot(i2,abs2);

