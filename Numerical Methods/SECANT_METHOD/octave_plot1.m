M=dlmread('data.txt'); %reading the matrix from data file
M(1,:)=[]; %neglecting the first row headers
[row,col]=size(M); %finding out number of rows and columns in matrix M
fy=M(:,5); %reading column 5 which is F(x2) 
fx=M(:,4); %reading column 4 which is x2 
figure;
plot(fx,fy,'go'); %plotting the points of f(x2) using green colour circles
for i=1:row
    text(fx(i,:),fy(i,:)+0.1,num2str(i));%numbering the points in order
end
grid on;
hold on;
xlabel('x2'),ylabel('function(x2)'),title('Secant method');
plot(fx,fy,'b'); %plotting the points of f(x2) using black colour circles