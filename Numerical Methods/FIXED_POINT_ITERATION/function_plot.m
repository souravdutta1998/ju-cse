M=dlmread('fixed_point.txt'); %reading the matrix of data from the file
%M(1,:)=[];%neglecting the first row headers
[row,col]=size(M);%finding number of rows and columns in matrix M
fx=M(:,4); %extracting every row of column 4
figure;
plot(1:row,fx,'ro'); %ploting the iterations using red colour circles
for i=1:row
    text(i,fx(i,:)-0.2,num2str(i));
end
grid on;
hold on;
xlabel('iteration'),ylabel('function(x)'),title('Fixed Point Iteration Method');
plot(1:row,fx,'b');%plotting it using blue colour lines
