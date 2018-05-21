#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;
class ACCOUNT{
protected: //protected members of class
    int accNum;
    float bal;
    string date;
public:  //public members of class
    ACCOUNT(){  //constructor which initializes the variables to 0
        accNum = 0;
        bal = 0;
        date = '\0';
    }
    int getAccNum(){  //function to return the account number
        return accNum;
    }
    float getBal(){  //function to return the balance
        return bal;
    }
    string getDate(){  //function to return the date
        return date;
    }
    void setBal(float b){  //setter function for balance
        bal = b;
    }
    void dateUpdate(string d){  //function to set the updated date
        date = d;
    }
};
class SAVINGS_ACCOUNT : public ACCOUNT{  //inheriting attributes from class ACCOUNT
public:   //public members of class
    float MIN_BALANCE = 500;
    void accountOpen(){   //opening a new savings account
        accNum = rand()%1000;
        cout<<"New savings account with account number "<<accNum<<" opened."<<endl;
    }
};
class CURRENT_ACCOUNT : public ACCOUNT{   //inheriting attributes from class ACCOUNT
public:   //public members of class
    float MAX_OVERDRAFT = -20000;
    void accountOpen(){  //opening a new current account
        accNum = rand()%1000;
        cout<<"New current account with account number "<<accNum<<" opened."<<endl;
    }
};
class TRANSACTION{
    int accNum;    //private members of class
    float bal;
    string date;
    float amount;
public:     //public members of class
    TRANSACTION(){  //constructor which initializes the variables to 0
        accNum = 0;
        bal = 0;
        date = '\0';
    }
    string getDate(){  //function to return date
        return date;
    }
    float withdraw(){   //function for withdraw
        time_t now = time(0);
        date = ctime(&now);
        cout<<"How much money you want to withdraw? : ";
        cin>>amount;
        return amount;
    }
    float deposit(){   //function for deposit
        time_t now = time(0);
        date = ctime(&now);
        cout<<"How much money you want to deposit? : ";
        cin>>amount;
        return amount;
    }
};

int main()
{
    TRANSACTION t;  //object of class TRANSACTION
    SAVINGS_ACCOUNT *s[20];  //array of objects of class SAVINGS_ACCOUNT
    CURRENT_ACCOUNT *c[20];  //array of objects of class CURRENT_ACCOUNT
    int i =0, k=0,choice, flag1;
    int acno;
    string type1;
    float amount1 =0;
    do{ //loop which continues until user input choice number 5 to exit
        cout<<"\n------------------------------------------------------------------------\n";
        cout<<"1. New Account Opening\n";
        cout<<"2. Deposit money\n";
        cout<<"3. Withdraw money\n";
        cout<<"4. View available balance & last date of update\n";
        cout<<"5. Exit!\n\n";
        cout<<"Enter a choice number: ";
        cin>>choice;
        switch(choice)
        {
        case 1:  //account opening
            cout<<"Enter type of account(savings/current)or(s/c): "; cin>>type1;
            if(type1 == "savings" || type1 == "s")
            {
                cout<<"While opening, ";
                amount1 = t.deposit();
                s[i] = new SAVINGS_ACCOUNT;
                if(amount1<(s[i]->MIN_BALANCE)){
                    cout<<"You have to deposit atleast Rs.500 in your account.\n";
                    cout<<"Enter amount again: "; cin>>amount1;
                }
                s[i]->setBal(amount1);
                s[i]->dateUpdate(t.getDate());
                s[i]->accountOpen();
                i++;
            }
            else if(type1 == "current" || type1 == "c")
            {
                cout<<"While opening, ";
                amount1 = t.deposit();
                c[k] = new CURRENT_ACCOUNT;
                c[k]->setBal(amount1);
                c[k]->dateUpdate(t.getDate());
                c[k]->accountOpen();
                k++;
            }
            else cout<<"INVALID TYPE!\n";
            break;
        case 2: //deposit
            cout<<"Enter type of account(savings/current)or(s/c): "; cin>>type1;
            if(type1 == "savings" || type1 == "s"){
                if(i==0) cout<<"No savings accounts in the bank! Open an account.\n";
                else{
                    cout<<"Enter the account number : "; cin>>acno;
                    for(int j=0;j<i;j++)
                    {
                        if(s[j]->getAccNum() == acno)
                        {
                            flag1 = 1;
                            amount1 = t.deposit();
                            cout<<"Rs. "<<amount1<<" has been deposited to your savings account.\n";
                            amount1 = (s[j]->getBal()) + amount1;
                            s[j]->setBal(amount1);
                            s[j]->dateUpdate(t.getDate());
                            break;
                        }
                        else flag1 =0;
                    }
                    if(flag1 ==0) cout<<"Account not found.\n";
                }
            }
            else if(type1 == "current" || type1 == "c"){
                if(k==0) cout<<"No current accounts in the bank! Open an account.\n";
                else{
                    cout<<"Enter the account number : "; cin>>acno;
                    for(int j=0;j<k;j++)
                    {
                        if(c[j]->getAccNum() == acno)
                        {
                            flag1 = 1;
                            amount1 = t.deposit();
                            cout<<"Rs. "<<amount1<<" has been deposited to your current account.\n";
                            amount1 = (c[j]->getBal()) + amount1;
                            c[j]->setBal(amount1);
                            c[j]->dateUpdate(t.getDate());
                            break;
                        }
                        else flag1 =0;
                    }
                    if(flag1 ==0) cout<<"Account not found.\n";
                }
            }
            else cout<<"INVALID TYPE.\n";
            break;
        case 3:  //withdraw
            cout<<"Enter type of account(savings/current)or(s/c): "; cin>>type1;
            if(type1 == "savings" || type1 == "s"){
                if(i==0) cout<<"No savings accounts in the bank! Open an account.\n";
                else{
                    cout<<"Enter the account number : "; cin>>acno;
                    for(int j=0;j<i;j++)
                    {
                        if(s[j]->getAccNum()==acno){
                            flag1 = 1;
                            amount1 = t.withdraw();
                            if(((s[j]->getBal()) - amount1) < (s[j]->MIN_BALANCE)){
                                if(s[j]->getBal()==0 || s[j]->getBal() < amount1)
                                    cout<<"No sufficient balance in the savings account! You cannot withdraw money.\n";
                                else
                                    cout<<"You need to maintain Rs.500 Minimum balance in your account. You cannot withdraw!";
                            }
                            else {
                                cout<<"Rs. "<<amount1<<" has been withdrawn from your savings account.\n";
                                amount1 = (s[j]->getBal()) - amount1;
                                s[j]->setBal(amount1);
                                s[j]->dateUpdate(t.getDate());
                            }
                            break;
                        }
                        else flag1 = 0;
                    }
                    if(flag1 ==0 ) cout<<"Account not found.\n";
                }
            }
            else if(type1 == "current" || type1 == "c"){
                if(k==0) cout<<"No current accounts in the bank! Open an account.\n";
                else{
                    cout<<"Enter the account number : "; cin>>acno;
                    for(int j=0;j<k;j++)
                    {
                        if(c[j]->getAccNum()==acno){
                            flag1 = 1;
                            amount1 = t.withdraw();
                            if((c[j]->getBal()-amount1) < (c[j]->MAX_OVERDRAFT)){
                                cout<<"You will exceed your maximum overdraft amount. You cannot withdraw anymore!\n";
                            }
                            else {
                                cout<<"Rs. "<<amount1<<" has been withdrawn from your current account.\n";
                                amount1 = (c[j]->getBal()) - amount1;
                                c[j]->setBal(amount1);
                                c[j]->dateUpdate(t.getDate());
                            }
                            break;
                        }
                        else flag1 = 0;
                    }
                    if(flag1 ==0 ) cout<<"Account not found.\n";
                }
            }
            else cout<<"INVALID TYPE\n";
            break;
        case 4:  //display amount and date
            cout<<"Enter type of account(savings/current)or(s/c): "; cin>>type1;
            if(type1 == "savings" || type1 == "s"){
                if(i==0) cout<<"No savings accounts in the bank! Open an account.\n";
                else{
                    cout<<"Enter the account number : "; cin>>acno;
                    for(int j=0;j<i;j++)
                    {
                        if(s[j]->getAccNum()==acno){
                            flag1 = 1;
                            cout<<"\nACCOUNT BALANCE: Rs. "<<s[j]->getBal()<<endl;
                            cout<<"LAST DATE OF UPDATE: "<<s[j]->getDate()<<endl;
                            break;
                        }
                        else flag1 = 0;
                    }
                    if(flag1 ==0 ) cout<<"Account not found.\n";
                }
            }
            else if(type1 == "current" || type1 == "c"){
                if(k==0) cout<<"No current accounts in the bank! Open an account.\n";
                else{
                    cout<<"Enter the account number : "; cin>>acno;
                    for(int j=0;j<k;j++)
                    {
                        if(c[j]->getAccNum()==acno){
                            flag1 = 1;
                            if(c[j]->getBal() < 0){
                                cout<<"\nACCOUNT BALANCE: Rs. 0"<<endl;
                                cout<<"OVERDRAFT: Rs. "<<(-1)*c[j]->getBal()<<endl;
                            }
                            else{
                                cout<<"\nACCOUNT BALANCE: Rs. "<<c[j]->getBal()<<endl;
                                cout<<"OVERDRAFT: Rs. 0"<<endl;
                            }
                            cout<<"LAST DATE OF UPDATE: "<<c[j]->getDate()<<endl;
                            break;
                        }
                        else flag1 = 0;
                    }
                    if(flag1 ==0 ) cout<<"Account not found.\n";
                }
            }
            else cout<<"INVALID TYPE.\n";
            break;
        case 5:  //exit
            cout<<"\nLogged out.\n";
            delete s;
            delete c;
            exit(0);
        default:
            cout<<"\nPlease enter a valid choice.\n";
            break;
        }
    }while(1);
    return 0;
}
