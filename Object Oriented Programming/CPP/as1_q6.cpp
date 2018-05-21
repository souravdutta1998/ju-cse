#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class STRING{
    string str;  //private member of class STRING
public: //public members of class STRING
    STRING(){  //constructor with no argument initializes to null
        str = '\0';
    }
    STRING(const STRING &s){  //constructor to initialize with a const STRING object
        str = s.str;
    }
    STRING(string s){  //constructor to initialize with a string
        str = s;
    }
    void readString(){  //function to input string from the user
        getline(cin, str);
    }
    string getString(){  //function to return string
        return str;
    }
    void operator=(const string s){  //operator overloading for assignment with const string
        str = s;
    }
    void operator=(STRING s){  //operator overloading for assignment with STRING object
        str = s.str;
    }
    friend STRING operator+(STRING s1, STRING s2){  //operator overloading for concatenation of two STRING objects
        STRING s;
        s.str = s1.str +" " + s2.str;
        return s;
    }
    friend int operator<(STRING s1, STRING s2){  //operator overloading for comparing of two STRING objects if lesser
        if((s1.str).compare(s2.str)<0)
            return 1;
        else return 0;
    }
    friend int operator>(STRING s1, STRING s2){  //operator overloading for comparing of two STRING objects if greater
        if((s1.str).compare(s2.str)>0)
            return 1;
        else return 0;
    }
    friend int operator==(STRING s1, STRING s2){  //operator overloading for comparing of two STRING objects if equal
        if((s1.str).compare(s2.str)==0)
            return 1;
        else return 0;
    }

};
int main()
{
    STRING s1, s2, s3;  //objects of class STRING
    int choice;
    cout<<"Input first string: ";
    s1.readString();
    cout<<"Input second string: ";
    s2.readString();
    do{
        cout<<"\n-------------------------------------------------------\n";
        cout<<"1. Assigning first string to second string\n";
        cout<<"2. Assigning second string to first string\n";
        cout<<"3. Concatenation of two strings\n";
        cout<<"4. Compare two strings\n";
        cout<<"5. Want to enter the second string again?\n";
        cout<<"6. Print both the strings\n";
        cout<<"7. Exit!\n\n";
        cout<<"Enter a choice number: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            s2 = s1; //assignment
            cout<<"\nFirst string is      : "<<s1.getString();
            cout<<"\nSecond string is now : "<<s2.getString();
            break;
        case 2:
            s1 = s2;  //assignment
            cout<<"\nFirst string is now : "<<s1.getString();
            cout<<"\nSecond string is    : "<<s2.getString();
            break;
        case 3:
            s1 = s1 + s2;  //concatenating two strings
            cout<<"The resultant string is: "<<s1.getString();
            break;
        case 4:  //comparing
            if(s1==s2)
                cout<<"String 1 is equal to String 2"<<endl;
            else if(s1<s2)
                cout<<"String 1 is less than String 2"<<endl;
            else if(s1>s2)
                cout<<"String 1 is greater than String 2"<<endl;
            break;
        case 5:
            cin.ignore();
            cout<<"Input second string:  ";
            s2.readString();
            break;
        case 6:
            cout<<"String 1 is: "<<s1.getString()<<endl;
            cout<<"String 2 is: "<<s2.getString()<<endl;
            break;
        case 7:
            cout<<"\nLogged out.\n";
            exit(0);
        default:
            cout<<"\nPlease enter a valid choice.\n";
            break;
        }
    }while(1);
    return 0;
}
