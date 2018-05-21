#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class TIME{
    int hour; //private members of class TIME
    int minute;
    int second;
    string givetime;
public:  //public members of class TIME
    TIME(){  //constructor which sets the values of hour, minute, second to 0
        hour = 0;
        minute = 0;
        second = 0;
    }
    void setTime(){ //setter function to set time in the form of string and converts it to hour, minute and seconds
        cout<<"Enter time in am/pm format or 24-hour format : ";
        cin>> givetime;
        hour = ((givetime[0]-48)*10)+(givetime[1]-48);
        minute = ((givetime[3]-48)*10)+(givetime[4]-48);
        second = ((givetime[6]-48)*10)+(givetime[7]-48);
        if(hour<24 && minute<60 && second<60 && givetime[2]==':' && givetime[5]==':')
          //  if((givetime[8]=='a' ||  givetime[8]=='p')&&givetime[9]=='m')
                cout<<"\n";
            //else cout<<"You entered time in 24-hour format successfully!\n";
        else
            cout<<"\nPlease input a valid time!\n";
    }
    void getTime12(){ //getter function to print the time in am/pm format
        if(givetime[2]==':' && givetime[5]==':' && minute < 60 && second <60)
        {
            cout<<"The time in am/pm format is ";
            if(hour==0)
            {
                cout<<(hour+12)%24<<":"<<minute<<":"<<second<<"am"<<endl;
            }
            else if(hour<=12)
            {
                if(givetime[8] == 'a' || givetime[8] == 'A')
                {
                    cout<<(hour)%24<<":"<<minute<<":"<<second<<"am"<<endl;
                }
                else if(givetime[8] == 'p' || givetime[8] == 'P')
                {
                    cout<<(hour)%24<<":"<<minute<<":"<<second<<"pm"<<endl;
                }
                else if(hour == 12)
                    cout<<(hour)%24<<":"<<minute<<":"<<second<<"pm"<<endl;
                else
                    cout<<(hour)%24<<":"<<minute<<":"<<second<<"am"<<endl;
            }
            else if(hour>12)
            {
                cout<<(hour-12)%24<<":"<<minute<<":"<<second<<"pm"<<endl;
            }

        }
        else{ cout<<"You have entered time in incorrect format.\n"; }
    }
    void getTime24(){ //getter function to print the time in 24 hour format
        if(givetime[2]==':' && givetime[5]==':' && minute < 60 && second <60)
        {
            cout<<"The time in 24-hour format is ";
            if(givetime[8] == 'a' || givetime[8] == 'A')
            {
                if(hour == 12)
                    cout<<(hour-12)%24<<":"<<minute<<":"<<second<<endl;
                else
                    cout<<(hour)%24<<":"<<minute<<":"<<second<<endl;
            }
            else if(givetime[8] == 'p' || givetime[8] == 'P')
            {
                if(hour == 12)
                    cout<<(hour)%24<<":"<<minute<<":"<<second<<endl;
                    else if(hour>12 && hour<24) cout<<(hour)%24<<":"<<minute<<":"<<second<<endl;
                else
                    cout<<(hour+12)%24<<":"<<minute<<":"<<second<<endl;
            }
            else
            {
                cout<<(hour)%24<<":"<<minute<<":"<<second<<endl;
            }

        }
        else{ cout<<"You have entered time in incorrect format.\n"; }
    }
    void addTime(){ //function to add minutes to time value
        int min;
        cout<<"Enter minutes you want to add to time : ";
        cin >> min;
        if(min>=0)
        {
            minute = minute + min;
            if(minute>60)
            {
                hour = hour +(minute / 60);
                if(hour>23) hour = hour%24;
                minute = minute % 60;
                if(givetime[8]=='a')
                {
                    if(hour>11) givetime[8]='p';
                }
                else if(givetime[8]=='p')
                {
                    if(hour>11) givetime[8]='a';
                }
            }
        }
        else {cout<<"Sorry! You cannot add -ve minutes to time\n";}
    }
};
int main()
{
    TIME t; //define a class object
    int choice;
    do{ //loop which continues until user input choice number 5 to exit
        cout<<"\n---------------------------------------------------------\n";
        cout<<"1. Input a time in am/pm or 24-hour format\n";
        cout<<"2. Display time in am/pm format\n";
        cout<<"3. Display time in 24-hour format\n";
        cout<<"4. Add minutes to time\n";
        cout<<"5. Exit!\n\n";
        cout<<"Enter a choice number: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            t.setTime(); //calling setTime function of class TIME
            break;
        case 2:
            t.getTime12();  //calling getTime12 function of class TIME
            break;
        case 3:
            t.getTime24();  //calling getTime24 function of class TIME
            break;
        case 4:
            t.addTime();  //calling addTime function of class TIME
            break;
        case 5:
            cout<<"\nLogged out.\n";
            exit(0);
        default:
            cout<<"\nPlease enter a valid choice.\n";
            break;
        }
    }while(1);

    return 0;
}
