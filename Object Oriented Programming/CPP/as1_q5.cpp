#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class ARRAY{
    int size;  //private members of class ARRAY
    double *arr;
public:  //public member functions of class ARRAY
    ARRAY(int s){ //constructor which takes size as argument
        size = s;
        arr = new double[size];
        for(int i=0;i<size;i++){
            arr[i] = 0;
        }
    }
    void print(){  //function to print the array
        for(int i =0;i<size;i++)
            cout<<arr[i]<<"  ";
        cout<<"\n";
    }
    int getSize(){  //getter function to return the size of array
        return size;
    }
    ARRAY operator+(ARRAY p){ //operator overloading for performing addition of two ARRAT objects
        ARRAY q(size);
        for(int i=0;i<size;i++){
            q.arr[i] = arr[i] + p[i];
        }
        return q;
    }
    void operator=(ARRAY p){  //operator overloading for assigning one ARRAY object to another
        int size1 = p.getSize();
        if(size1 > size) size1 = size;
        for(int i=0;i<size1;i++){
            arr[i] = p.arr[i];
        }
    }
    void operator=(double p[]){  //operator overloading for assigning an array to another array
        for(int i=0;i<size;i++){
            arr[i] = p[i];
        }
    }
    double operator[](int p){  //operator overloading for returning ith variable of an ARRAY object
        if(p < size){
            return arr[p];
        }
        else {
                cout<<"ERROR: There's no value at this index of array!"; return 0;}
    }
    friend ARRAY operator*(double constant, ARRAY p){  //operator overloading for performing multiplication in C*a
        return p*constant;
    }
    ARRAY operator*(double constant){  //operator overloading for performing multiplication in a*C
        ARRAY q(size);
        for(int i=0;i<size;i++){
            q.arr[i] = constant * arr[i];
        }
        return q;
    }
};

int main()
{
    int choice,size1,num1,num2;
    double C; //variable for multiplication
    cout<<"How many elements you want the arrays to have? Enter the size: ";
    cin>>size1;
    ARRAY a(size1),b(size1),c(size1); double *f;
    f = new double[size1];
            cout<<"Enter first array: \n";
            for(int i=0;i<size1;i++)
                cin>>f[i];
            a = f;
            cout<<"Enter second array: \n";
            for(int i=0;i<size1;i++)
                cin>>f[i];
            b = f;
            do{
                cout<<"\n-----------------------------------------------------------------\n";
                cout<<"1. a+b (Add corresponding elements of arrays)\n";
                cout<<"2. a=b (Assignment of an array to another array)\n";
                cout<<"3. a[i] (Return ith element of an array)\n";
                cout<<"4. a*C (Multiply all elements of an array with value C)\n";
                cout<<"5. C*a (Multiply all elements of an array with value C)\n";
                cout<<"6. Print both the arrays\n";
                cout<<"7. EXIT!\n\n";
                cout<<"Enter a choice number: "; cin>>choice;
                switch(choice)
                {
                case 1: //addition
                    c = a+b;
                    cout<<"ADDED SUCCESSFULLY!\n";
                    cout<<"The resultant array is : ";
                    c.print();
                    break;
                case 2:  //assignment
                    cout<<"Array M will be assigned to array N. Enter M (1 or 2): " ;
                    cin>>num1 ;
                    cout<<"Enter N (1 or 2): ";
                    cin>>num2;
                    if(num1 ==1 && num2 == 2){
                        b=a;
                        cout<<"Array "<<num1<<" has been assigned to Array"<<num2<<".\n";
                        cout<<"Array 2 is now: \n";
                        b.print();
                    }else if(num1 ==2 && num2 == 1){
                        a=b;
                        cout<<"Array "<<num1<<" has been assigned to Array"<<num2<<".\n";
                        cout<<"Array 1 is now: \n";
                        a.print();
                    }else if(num1 == num2) cout<<"M and N cannot be same. Input again.";
                    else
                        cout<<"Input a valid choice again";
                    break;
                case 3:  //returning ith element
                    cout<<"ith element of which array do you want? (1 or 2): "; cin>>num2;
                    cout<<"Enter index i: "; cin>>num1;
                    if(num2 == 1){
                        cout<<"ith element is: "<<a[num1];
                    }else if(num2 == 2){
                        cout<<"ith element is: "<<b[num1];
                    }else cout<<"Invalid input!\n";
                    break;
                case 4:  //multiplication in a*C
                    cout<<"Choose the array! (1 or 2): ";
                    cin>>num1;
                    cout<<"Enter the multiplier constant value to be multiplied: ";
                    cin>>C;
                    if(num1 ==1){
                        a= a*C;
                        cout<<"Array 1 is now : ";
                        a.print();
                    }else if(num1 ==2){
                        b= b*C;
                        cout<<"Array 2 is now : ";
                        b.print();
                    }else cout<<"Invalid input!\n";
                    break;
                case 5:  //multiplication in C*a
                    cout<<"Choose the array! (1 or 2): ";
                    cin>>num1;
                    cout<<"Enter the multiplier constant value to be multiplied: ";
                    cin>>C;
                    if(num1 ==1){
                        a= C*a;
                        cout<<"Array 1 is now : ";
                        a.print();
                    }else if(num1 ==2){
                        b= C*b;
                        cout<<"Array 2 is now : ";
                        b.print();
                    }else cout<<"Invalid input!\n";
                    break;
                case 6:  //printing two arrays
                    cout<<"Array 1 is : ";
                    a.print();
                    cout<<"\nArray 2 is : ";
                    b.print();
                    break;
                case 7:
                    cout<<"\nLogged out.\n";
                    exit(0);
                    break;
                default:
                    cout<<"\nPlease enter a valid choice.\n";
                    break;
                }
            }while(1);
    return 0;
}
