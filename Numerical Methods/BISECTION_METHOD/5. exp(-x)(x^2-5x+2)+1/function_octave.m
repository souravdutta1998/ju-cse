M=dlmread('x^4-x-10.txt'); % reading the matrix of data from the file
%M(1,:)=[];% deleting the header row containing strings
[row,col]=size(M); % finding number of rows and columns in matrix M
fmid=M(:,5); % vector containing mid y
mid=M(:,4); % vector containing mid x
X=[M(1,2):0.1:M(1,3)];
Y=equation(X); % values of function inside domain
%plot(X,Y,'b',mid,fmid,'ro'); % plotting the function and the middle points
figure;
plot(X,Y,'b');
hold on;
plot(mid,fmid,'ro');
grid on;
hold on;
xlabel('x'),ylabel('function(x)'),title('Bisection Method');
a=M(:,2);% vector containing starting y
b=M(:,3);% vector containing ending x
YA=equation(a);% vector containing starting y
YB=equation(b);% vector containing ending y
s=min(Y);
for i=1:row
  %plot([a(i) b(i)],[YA(i) YB(i)],'g');% line joining starting and ending points
  hold on;
  plot([a(i) b(i)],[s s],'r');
  text(a(i),s,num2str(i));
  s=s-2;
  hold on;
end
