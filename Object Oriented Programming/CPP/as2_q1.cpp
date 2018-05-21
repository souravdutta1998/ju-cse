#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class COIN{
    int flip;  //private members of class COIN
    int cnt;
    int i;
public:   //public member functions of class COIN
    void toss(){  //function to toss and execute the loop until 3 consecutive heads
        i=0; cnt =0;
        srand(time(0));  //seeding current time value
        while(i<3){
            flip = rand()%2;  //gives either 0 or 1
            if(flip == 0){
                cout<<"heads"<<endl; i++;  //increment i if heads
            }
            else{
                cout<<"tails"<<endl; i=0;  //set i = 0 if tails
            }
            cnt++;
        }
        cout<<"\nIt took "<<cnt<<" flips to get 3 consecutive heads.\n";
    }
};
int main()
{
    COIN c;  //object of class COIN
    int choice;
    do{ //loop which continues until user input choice number 2 to exit
        cout<<"\n---------------------------------------------------------\n";
        cout<<"1. Do you want to toss?\n";
        cout<<"2. Exit!\n\n";
        cout<<"Enter a choice number: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            c.toss(); //calling toss function of class COIN
            break;
        case 2:
            cout<<"\nLogged out.\n";
            exit(0);
        default:
            cout<<"\nPlease enter a valid choice.\n";
            break;
        }
    }while(1);
    return 0;
}
