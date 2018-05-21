#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int factorial(int x)  //function to calculate factorial of x
{
    int f = 1;
    for(int i =1 ;i<=x;i++)
        f=f*i;
    return f;
}
int ncr(int n, int r)  //function of calculate the value of ncr
{
    int c;
    c = factorial(n) / (factorial(n-r) * factorial(r));
    return c;
}
int pascal(int row,int column) //function to calculate ncr using recursion
{
    if(column==0) // The 0th column element is assumed to 0
        return 0;
    else if(row==1 && column==1)
        return 1;
    else if(column>row) // assuming the element is zero (no of columns> no of rows)
        return 0;
    else
        return (pascal(row-1,column-1)+pascal(row-1,column));
}
int main()
{
    int choice;
    int row, col;
    do{ //loop which continues until user input choice number 4 to exit
        cout<<"\n---------------------------------------------------------\n";
        cout<<"1. Print pascal triangle using combinational function\n";
        cout<<"2. Print pascal triangle using dynamic programming\n";
        cout<<"3. Display an element of pascal triangle using row and column value\n";
        cout<<"4. Exit!\n\n";
        cout<<"Enter a choice number: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter number of rows : "; cin>>row;
            for(int i =0;i<row;i++){
                for(int j =0;j<row-i;j++)
                    cout<<"   ";
                for(int j=0;j<=i;j++)
                    printf("%3d   ",ncr(i,j));
                cout<<"\n\n";
            }
            break;
        case 2:
            cout<<"Enter number of rows : "; cin>>row;
            for(int i=1;i<=row;i++){
                for(int j=0;j<row-i;j++)
                    cout<<"   ";
                for(int j=1;j<=i;j++)
                    printf("%3d   ",pascal(i,j));
                cout<<"\n\n";
            }
            break;
        case 3:
            cout<<"Enter row number : "; cin>>row;
            cout<<"Enter column number : "; cin>>col;
            cout<<"The value at row " <<row <<" and column "<<col<<" is: "<<pascal(row, col);
            break;
        case 4:
            cout<<"\nLogged out.\n";
            exit(0);
        default:
            cout<<"\nPlease enter a valid choice.\n";
            break;
        }
    }while(1);
}
