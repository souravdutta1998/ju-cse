#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
using namespace std;

class COMPLEX{
    int real; //private members of class COMPLEX
    int imaginary;
public:  //public members of class COMPLEX
    COMPLEX(){
        real = 0;
        imaginary = 0;
    }
    COMPLEX operator+(COMPLEX x) //using operator overloading for addition
    {
        COMPLEX y;
        y.real = real + x.real;
        y.imaginary = imaginary + x.imaginary;
        return y;
    }
    COMPLEX operator-(COMPLEX x)  //using operator overloading for subtraction
    {
        COMPLEX y;
        y.real = real - x.real;
        y.imaginary = imaginary - x.imaginary;
        return y;
    }
    void setData(){ //setter function to enter a complex number in appropriate format
    	real =0; imaginary =0;
    	if((scanf("%d",&real))==1)
        {
            if((scanf("-i%d",&imaginary))==1)
                imaginary = (-1)*imaginary;
            else if((scanf("+i%d",&imaginary))!=1)
                cout<<"";
        }
        else if((scanf("i%d",&imaginary))==1)
            cout<<"";
        else if((scanf("-i%d",&imaginary))==1)
            imaginary = (-1)*imaginary;


        else cout<<"Please enter the complex in a+ib form!!\n";
    }
    void getData(){  //getter function to print a complex number
        if(imaginary>0)
        {
            if(real==0)
                cout<<"+i"<<imaginary;
            else
                cout<<real<<"+i"<<imaginary;
        }
        else if(imaginary<0)
        {
            if(real==0)
                cout<<"-i"<<imaginary*(-1);
            else
                cout<<real<<"-i"<<imaginary*(-1);
        }
        else if(imaginary ==0)
        {
            cout<<real;
        }
    }
};
int main()
{
    COMPLEX c1,c2,c3; //defining class objects
    int choice;
    int flag; //flag variable
    do{
        cout<<"Enter first complex number(a+ib format):  ";
        c1.setData();
        cin.ignore();
        cout<<"Enter second complex number(a+ib format):  ";
        c2.setData();
        do{
            cout<<"\n-------------------------------------------------------\n";
            cout<<"1. Addition of two numbers\n";
            cout<<"2. Subtraction of two numbers\n";
            cout<<"3. Want to enter the second array again\n";
            cout<<"4. Want to re-enter the two number?\n";
            cout<<"5. Display the first and second complex numbers\n";
            cout<<"6. Exit!\n\n";
            cout<<"Enter a choice number: ";
            cin>>choice;
            flag = 0;
            switch(choice)
            {
            case 1:
                c1 = c1 + c2;  //using operator overloading for addition
                cout<<"Addition successful!\n";
                cout<<"The resultant of complex numbers  is :  ";
                c1.getData();  //calling getData function of class COMPLEX to print number
                break;
            case 2:
                c1 = c1 - c2;  //using operator overloading for subtraction
                cout<<"Subtraction successful!\n";
                cout<<"The resultant of complex numbers is :  ";
                c1.getData();  //calling getData function of class COMPLEX to print number
                break;
            case 3:
                cout<<"Enter second complex number(a+ib format):  ";
        	c2.setData();
                break;
            case 4:
                flag = 1; //changing the value to 1 to exit from the present loop and re-enter the two numbers again
                break;
            case 5:
                cout<<"The first complex number is: ";
                c1.getData();
                cout<<"\nThe second complex number is: ";
                c2.getData();
                break;
            case 6:
                cout<<"\nLogged out.\n";
                exit(0);
            default:
                cout<<"\nPlease enter a valid choice.\n";
                break;
            }
            if(flag ==1) break;
        }while(1);
    }while(1);
    return 0;
}
