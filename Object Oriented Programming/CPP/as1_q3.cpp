#include <iostream>
#include <cstdlib>
#include <cstring>
#include<iostream>
#include <cstdio>
using namespace std;

class ITEM{
    string code; //private members of class ITEM
    string name;
    int rate;
    int quantity;
public: //public member functions of class ITEM
    ITEM(){ //constructor which sets the rate and quantity to integer value 0
        rate = 0;
        quantity = 0;
    }
    void setCode(string c) //setter function to set code
    {
        code = c;
    }
    void setName(string n)  //setter function to set name
    {
        name = n;
    }
    void setRate(int r)  //setter function to set rate
    {
        rate = r;
    }
    void setQuantity(int q)  //setter function to set quantity
    {
        quantity = q;
    }
    string getCode(){ //getter function to return code
        return code;
    }
    string getName(){  //getter function to return name
        return name;
    }
    int getRate(){  //getter function to return rate
        return rate;
    }
    int getQuantity(){  //getter function to return quantity
        return quantity;
    }
};
int main()
{
    ITEM *itemlist[20]; //arrays of objects of class ITEM
    int i=0, j; //index variables
    string code1, name1;
    int rate1, quantity1;
    int choice, flag, flag1;
    do{ //loop which continues until user input choice number 6 to exit
        cout<<"\n------------------------------------------------------------------------\n";
        cout<<"1. Add an item\n";
        cout<<"2. Change rate of item\n";
        cout<<"3. Add quantity of existing item(Receive by shopkeeper)\n";
        cout<<"4. Remove quantity of existing item(Issue to customer)\n";
        cout<<"5. Enquire price and quantity of an item\n";
        cout<<"6. Exit!\n\n";
        cout<<"Enter a choice number: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            itemlist[i] = new ITEM;
            cout<<"Enter code of the item: ";
            cin>>code1;
            for(j=0;j<i;j++)
            {
                flag1=1;
                while(!flag){
                    if(itemlist[j]->getCode()==code1){
                    cout<<"Item code already exist. Please re-enter a different code!\n";
                    cout<<"Enter code of the item: ";
                    cin>>code1; flag1 =0;
                    break;
                    }else flag1 =1;
                }

            }
            itemlist[i]->setCode(code1);
            cout<<"Enter name of the item: ";
            cin>>name1;
            itemlist[i]->setName(name1);
            cout<<"Enter rate of the item: ";
            cin>>rate1;
            itemlist[i]->setRate(rate1);
            cout<<"Enter quantity of the item: ";
            cin>>quantity1;
            itemlist[i]->setQuantity(quantity1);
            i++; //increment number of item by one
            cout<<"Item added to list successfully!";
            break;
        case 2:
            flag =0;
            cout<<"Enter code of the item: ";
            cin>>code1;
            for(j=0;j<i;j++)
            {
                if(itemlist[j]->getCode()==code1){
                    cout<<"\nEnter new rate of the item: ";
                    cin>>rate1;
                    itemlist[j]->setRate(rate1);
                    cout<<"Rate changed successfully!\n";
                    flag = 1;
                    break;
                }
            }
            if(!flag)
                cout<<"Item not found.\n";
            break;
        case 3:
            flag =0;
            cout<<"Enter code of the item: ";
            cin>>code1;
            for(j=0;j<i;j++)
            {
                if(itemlist[j]->getCode()==code1){
                    if(itemlist[j]->getQuantity()==0)
                    {
                        cout<<"\nNo available quantity for this item! Enter quantity you want to add to available quantity: ";
                        cin>>quantity1;
                        itemlist[j]->setQuantity(quantity1);
                        cout<<"Quantity of the item added successfully.\n";
                    }
                    else
                    {
                        cout<<"\nEnter quantity you want to add to available quantity: ";
                        cin>>quantity1;
                        quantity1 += (itemlist[j]->getQuantity());
                        itemlist[j]->setQuantity(quantity1);
                        cout<<"Quantity of the item added successfully.\n";
                    }
                    flag = 1;
                    break;
                }
            }
            if(!flag)
                cout<<"Item not found.\n";
            break;
        case 4:
            flag =0;
            cout<<"Enter code of the item: ";
            cin>>code1;
            for(j=0;j<i;j++)
            {
                if(itemlist[j]->getCode()==code1){
                    flag = 1;
                    if(itemlist[j]->getQuantity()==0)
                    {
                        cout<<"\nNo available quantity for this item! You cannot issue this item.\n";
                    }
                    else
                    {
                        cout<<"\nThis item is available for issue.\n";
                        cout<<"Enter quantity you want to remove from available quantity: ";
                        cin>>quantity1;
                        quantity1 = (itemlist[j]->getQuantity()) - quantity1;
                        if(quantity1<0) cout<<"Sorry! Only "<<itemlist[j]->getQuantity()<<" quantity available. You cannot issue this item.\n";
                        else {
                            itemlist[j]->setQuantity(quantity1);
                            cout<<"Quantity of the item removed successfully.\n";
                        }
                    }

                    break;
                }
            }
            if(!flag)
                cout<<"Item not found.\n";
            break;
        case 5:
            flag =0;
            cout<<"Enter code of the item: ";
            cin>>code1;
            for(j=0;j<i;j++)
            {
                if(itemlist[j]->getCode()==code1){
                    flag = 1;
                    cout<<"\nName of existing item: "<<itemlist[j]->getName()<<endl;
                    cout<<"Rate of existing item: Rs. "<<itemlist[j]->getRate()<<endl;
                    cout<<"Quantity of existing item: "<<itemlist[j]->getQuantity()<<endl;
                    break;
                }
            }
            if(!flag)
                cout<<"Item not found.\n";
            break;
        case 6:
            delete itemlist;
            cout<<"Logged out!";
            exit(0);
        default:
            cout<<"\nPlease enter a valid choice.\n";
            break;
        }
    }while(1);
    return 0;
}
