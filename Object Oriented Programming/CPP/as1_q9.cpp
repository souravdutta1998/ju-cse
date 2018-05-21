#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;
class BALANCE{
protected:
    int accNum;  //protected members of class
    float bal;
    string date;
public:  //public members of class
    BALANCE(){  //constructor which initializes the variables to 0
        accNum = 0;
        bal = 0;
        date = '\0';
    }
    int getAccNum(){  //function to return account number
        return accNum;
    }
    float getBal(){  //function to return balance
        return bal;
    }
    string getDate(){  //function to return date
        return date;
    }
    void setBal(float b){  //setter function to set date
        bal = b;
    }
    void accountOpen(){  //function to open a new account
        accNum = rand()%1000;
        cout<<"New account with account number "<<accNum<<" opened."<<endl;
    }
    void dateUpdate(string d){  //function to set updated date
        date = d;
    }
};
class TRANSACTION : public BALANCE{    //inheriting attributes of class BALANCE
    float amount;   //private member of class
public:  //public members of class
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
    BALANCE *b[20];   //array of objects of class BALANCE
    int i =0, choice, flag1;
    int acno;
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
        case 1:  //new account opening
            b[i] = new BALANCE;
            cout<<"While opening ";
            amount1 = t.deposit();
            b[i]->setBal(amount1);
            b[i]->dateUpdate(t.getDate());
            b[i]->accountOpen();
            i++;
            break;
        case 2:  //deposit
            if(i==0) cout<<"No accounts in the bank! Open an account.\n";
            else
            {cout<<"Enter the account number : "; cin>>acno;
            for(int j=0;j<i;j++)
            {
                if(b[j]->getAccNum() == acno)
                {
                    flag1 = 1;
                    amount1 = t.deposit();
                    cout<<"Rs. "<<amount1<<" has been deposited.\n";
                    amount1 = (b[j]->getBal()) + amount1;
                    b[j]->setBal(amount1);
                    b[j]->dateUpdate(t.getDate());
                    break;
                }
                else flag1 =0;
            }
            if(flag1 ==0) cout<<"Account not found.\n";
            }
            break;
        case 3:  //withdraw
            if(i==0) cout<<"No accounts in the bank! Open an account.\n";
            else
            {cout<<"Enter the account number : "; cin>>acno;
            for(int j=0;j<i;j++)
            {
                if(b[j]->getAccNum()==acno){
                    flag1 = 1;
                    amount1 = t.withdraw();
                    if(b[j]->getBal()==0 || b[j]->getBal() < amount1){
                        cout<<"No sufficient balance in the account! You cannot withdraw money.\n";
                    }
                    else {
                        cout<<"Rs. "<<amount1<<" has been withdrawn.\n";
                        amount1 = (b[j]->getBal()) - amount1;
                        b[j]->setBal(amount1);
                        b[j]->dateUpdate(t.getDate());
                    }
                    break;
                }
                else flag1 = 0;
            }
            if(flag1 ==0 ) cout<<"Account not found.\n";
            }
            break;
        case 4:  //display balance and last update date
            if(i==0) cout<<"No accounts in the bank! Open an account.\n";
            else{
                cout<<"Enter the account number : "; cin>>acno;
                for(int j=0;j<i;j++)
                {
                    if(b[j]->getAccNum()==acno){
                        flag1 = 1;
                        cout<<"\nACCOUNT BALANCE: Rs. "<<b[j]->getBal()<<endl;
                        cout<<"LAST DATE OF UPDATE: "<<b[j]->getDate()<<endl;
                        break;
                    }
                    else flag1 = 0;
                }
                if(flag1 ==0 ) cout<<"Account not found.\n";
            }
            break;
        case 5:  //exit
            cout<<"\nLogged out.\n";
            exit(0);
        default:
            cout<<"\nPlease enter a valid choice.\n";
            break;
        }
    }while(1);
    return 0;
}
