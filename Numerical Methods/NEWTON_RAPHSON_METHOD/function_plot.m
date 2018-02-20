M=dlmread('newton_raphson.txt');%reading data as matrix in M
%M(1,:)=[];%neglecting the first row headers
[row,col]=size(M);%finding number of rows and columns in matrix M
X=[0:0.1:5];%considering range of x-axis
Y=equation(X);%value of the function(equation) correspoding to x values
figure;
plot(X,Y,'b');%ploting the function
hold on;
grid on;
xlabel('x'),ylabel('function(x)'),title('Newton-Raphson Method');
xp=M(:,2);%extracting every row of column 2  
for i=1:row-1
    plot([xp(i) xp(i)],[equation(xp(i)) 0],'g');%ploting a perpendicular line to x-axis from the tangent point on the function
    hold on;
    plot(xp(i),0,'co');%marking the roots found using newton-raphson method on the x-axis
    text(xp(i),-10,num2str(i));%value of xi point
    hold on;
    plot([xp(i+1) xp(i)],[0 equation(xp(i))],'r');%drawing the tangent
end