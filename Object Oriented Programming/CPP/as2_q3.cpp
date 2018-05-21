#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <fstream>
using namespace std;

class LIBRARY{ //class to handle all operations
protected:  //protected members of class LIBRARY
    string bookname;
    string author;
    string issuedate;
    string cardno;
    string stucards[20][3];
    string faccards[20][3];
   // string book_id;
   // int quantity;
    string issuer_name;
    string type;
    int dd, mm, yyyy;
    int i, k1, k2, l;
    string issueno;
    //int publishdate, publishmonth, publishyear;
    string volumeno;
public:
	LIBRARY(){  //constructor
		k1 =0;
		k2 =0;
	}
    void issueBook(){  //function to issue book
        ifstream fi;
        string bookname1, author1, cardno1;
        int flag;
        cout<<"Are you a student or faculty member (s / f) ? "; cin>>type;
        if(type == "student" || type == "s")
        {
            cout<<"Enter the student library card number: ";
            cin>>cardno;
            i=0; l=0;
            while(i<k1){
                if(cardno == stucards[i][0]){
                    l++;
                }
                i++;
            }
            if(l<2){
                cout<<"You issued "<<l<<" books using this card number. You can issue.\n";
                cin.ignore();
                cout<<"Enter your name: ";
                getline(cin, issuer_name);
                cout<<"Enter name of the book: ";
                getline(cin, bookname);
                cout<<"Enter author's name: ";
                getline(cin, author);
                fi.open("Librarybook.txt",ios::in );
                flag =0;
                while(fi>>bookname1>>author1){
                    if(bookname == bookname1 && author == author1){
                        flag=1;
                        cout<<"\nBook found in library.\n";
                        break;
                    }
                }
                fi.close();
                if(flag ==0){
                    cout<<"\nBook not found in library.\n";
                }
                else{
                    time_t now = time(0);
                    issuedate = ctime(&now);
                    mm = month(issuedate);
                    dd = ((issuedate[8]-48)*10)+(issuedate[9]-48);
                    yyyy = ((issuedate[20]-48)*1000)+((issuedate[21]-48)*100)+((issuedate[22]-48)*10)+(issuedate[23]-48);

                    stucards[k1][0] = cardno;  //adding the cardno to string array of student cards
                    stucards[k1][1] = bookname;
                    stucards[k1++][2] = issuedate;
                    ofstream f("Student.txt", ios::out | ios::app);
                    f<<cardno<<"\t"<<issuer_name<<"\t"<<bookname<<"\t"<<author<<"\t"<<dd<<"/"<<mm<<"/"<<yyyy<<endl;
                    cout<<"\nYou have now issued this book. Please return within 15 days to avoid fine.\n";
                    f.close();
                }
            }
            else cout<<"More than 2 books cannot be issued with same card number.\n";
        }
        else if(type == "faculty" || type == "f")
        {
            cout<<"Enter the faculty library card number: ";
            cin>>cardno;
            i=0; l=0;
            while(i<k2){
                if(cardno == faccards[i][0]){
                    l++;
                }
                i++;
            }
            if(l<10){
                cout<<"You issued "<<l<<" books/journals using this card number. You can issue.\n";
                cin.ignore();
                cout<<"Enter your name: ";
                getline(cin, issuer_name);
                cout<<"Enter name of the book: ";
                getline(cin, bookname);
                cout<<"Enter author's name: ";
                getline(cin, author);
                fi.open("Librarybook.txt",ios::in );
                flag =0;
                while(fi>>bookname1>>author1){
                    if(bookname == bookname1 && author == author1){
                        flag=1;
                        cout<<"\nBook found in library.\n";
                        break;
                    }
                }
                fi.close();
                if(flag ==0){
                    cout<<"\nBook not found in library.\n";
                }
                else{
                    time_t now = time(0);
                    issuedate = ctime(&now);
                    mm = month(issuedate);
                    dd = ((issuedate[8]-48)*10)+(issuedate[9]-48);
                    yyyy = ((issuedate[20]-48)*1000)+((issuedate[21]-48)*100)+((issuedate[22]-48)*10)+(issuedate[23]-48);

                    faccards[k2][0] = cardno;  //adding the cardno to string array of student cards
                    faccards[k2][1] = bookname;
                    faccards[k2++][2] = issuedate;
                    ofstream f("Faculty.txt", ios::out | ios::app);
                    f<<cardno<<"\t"<<issuer_name<<"\t"<<bookname<<"\t"<<author<<"\t"<<dd<<" "<<mm<<" "<<yyyy<<endl;
                    cout<<"\nYou have now issued this book.\n";
                    f.close();
                }
            }
            else cout<<"More than 10 books/journals cannot be issued with same card number.\n";
        }
        else cout<<"INVALID INPUT.\n";
    }
    void issueJournal(){  //function to issue journal
        ifstream fi;
        string cardno1, bookname1,author1,volumeno1,issueno1;
        int flag;
        cout<<"Are you a student or faculty member (s / f) ? "; cin>>type;
        if(type == "student" || type == "s")
        {
            cout<<"Sorry! Students cannot issue journals from library."<<endl;
        }
        else if(type == "faculty" || type == "f")
        {
            cout<<"Enter the faculty library card number: "; cin>>cardno;
            i=0; l=0;
            while(i<k2){
                if(cardno == faccards[i][0]){
                    l++;
                }
                i++;
            }
            if(l<10){
                cout<<"You issued "<<l<<" books/journals using this card number. You can issue.\n";
                cin.ignore();
                cout<<"Enter your name: ";
                getline(cin, issuer_name);
                cout<<"Enter name of the journal: ";
                getline(cin, bookname);
                cout<<"Enter author's name: ";
                getline(cin, author);
                cout<<"Enter volume number of journal: ";
                cin>>volumeno;
                cout<<"Enter issue number of journal: ";
                cin>>issueno;

                fi.open("Libraryjournal.txt",ios::in );
                flag =0;
                while(fi>>bookname1>>author1>>volumeno1>>issueno1){
                    if(bookname == bookname1 && author == author1 && volumeno == volumeno1 && issueno == issueno1){
                        flag=1;
                        cout<<"\nJournal found in library.\n";
                        break;
                    }
                }
                fi.close();
                if(flag ==0){
                    cout<<"\nJournal not found in library.\n";
                }
                else{
                    time_t now = time(0);
                    issuedate = ctime(&now);
                    mm = month(issuedate);
                    dd = ((issuedate[8]-48)*10)+(issuedate[9]-48);
                    yyyy = ((issuedate[20]-48)*1000)+((issuedate[21]-48)*100)+((issuedate[22]-48)*10)+(issuedate[23]-48);

                    faccards[k2][0] = cardno;  //adding the cardno to string array of student cards
                    faccards[k2][1] = bookname;
                    faccards[k2++][2] = issuedate;
                    ofstream f("Faculty.txt", ios::out | ios::app);
                    f<<cardno<<"\t"<<issuer_name<<"\t"<<bookname<<"\t"<<author<<"\t"<<dd<<"/"<<mm<<"/"<<yyyy<<endl;
                    cout<<"\nYou have now issued this journal.\n";
                    f.close();
                }
            }
            else cout<<"More than 10 books/journals cannot be issued with same card number.\n";
        }
        else cout<<"INVALID INPUT.\n";
    }
    void returnBook(){  //function to return issued book
        int flag, valofi;
        int dd1, mm1, yyyy1;
        cout<<"Are you a student/faculty member (s / f)? ";
        cin>>type;
        if(type=="student" || type=="s"){
            cout<<"Enter the student library card number: ";
            cin>>cardno;
            i=0; l=0;
            while(i<k1){
                if(cardno == stucards[i][0]){
                    l++;
                }
                i++;
            }
            if(l==0) cout<<"No books issued using this library card number.\n";
            else{
                cout<<"You issued "<<l<<" books. Enter the details of the books which you want to return!"<<endl;
                cout<<"Enter the name of book: "; cin>>bookname;
                cout<<"Enter the author of book: "; cin>>author;
                i=0;  flag =1;
                while(i<k1){
                    if(cardno == stucards[i][0] && bookname == stucards[i][1]){
                        flag =0;
                        valofi = i;
                        break;
                    }
                    i++;
                }
                if(flag == 1) cout<<"This book has not been issued.\n";
                else{
                    mm = month(stucards[valofi][2]);
                    dd = ((stucards[valofi][2][8]-48)*10)+(stucards[valofi][2][9]-48);
                    yyyy = ((stucards[valofi][2][20]-48)*1000)+((stucards[valofi][2][21]-48)*100)+((stucards[valofi][2][22]-48)*10)+(stucards[valofi][2][23]-48);

                    //--------------enter date, validate it and calculate 15 days after issuedate(return date) and then fine from return date---
                    int *date, dd2, mm2, yyyy2; int arr[3];
                    date = addDays(dd,mm,yyyy, arr);
                    dd2 = *date;
                    mm2 = *(date +1);
                    yyyy2 = *(date +2);
                    cout<<"Actual return date is: "<<dd2<<"/"<<mm2<<"/"<<yyyy2<<endl;  //return date calculated
                    cout<<"Enter the date of returning the book(dd mm yyyy): ";
                    cin>>dd1>>mm1>>yyyy1;
                    int flag = calculateFine(dd2,mm2,yyyy2, dd1,mm1,yyyy1);  //validate and calc fine
                    //cout<<"\nThe book has been returned.\n";
                    if(flag == 1){
                        while(valofi<k1){
                            stucards[valofi][0] = stucards[valofi+1][0];  //card number
                            stucards[valofi][1] = stucards[valofi+1][1];  //book name
                            stucards[valofi][2] = stucards[valofi+1][2];  //issue date
                            valofi++;
                        }
                        k1--;
                    } else cout<<"Cannot be returned.\n";
                }
            }
        }
        else if(type=="faculty" || type=="f"){
            cout<<"Enter the faculty library card number: ";
            cin>>cardno;
            i=0; l=0;
            while(i<k2){
                if(cardno == faccards[i][0]){
                    l++;
                }
                i++;
            }
            if(l==0) cout<<"No books/journals issued using this library card number.\n";
            else{
                cout<<"You issued "<<l<<" books/journals. Enter the details of the books which you want to return!"<<endl;
                cout<<"Enter the name of book: "; cin>>bookname;
                cout<<"Enter the author of book: "; cin>>author;
                i=0;  flag =1;
                while(i<k2){
                    if(cardno == faccards[i][0] && bookname == faccards[i][1]){
                        flag =0;
                        valofi = i;
                        break;
                    }
                    i++;
                }
                if(flag == 1) cout<<"This book has not been issued.\n";
                else{

                    while(valofi<k2){
                        faccards[valofi][0] = faccards[valofi+1][0];  //card number
                        faccards[valofi][1] = faccards[valofi+1][1];  //book name
                        faccards[valofi][2] = faccards[valofi+1][2];  //issue date
                        valofi++;
                    }
                    k2--;
                    cout<<"\nThe book has been returned.\n";
                }
            }
        }
        else cout<<"INVALID INPUT.\n";
    }
    void returnJournal(){  //function to return issued journal
        int flag, valofi;
        cout<<"Are you a student/faculty member (s / f)? ";
        cin>>type;
        if(type=="student" || type=="s"){
            cout<<"You are a student. You didn't issue any journal.\n";
        }
        else if(type=="faculty" || type=="f"){
            cout<<"Enter the faculty library card number: ";
            cin>>cardno;
            i=0; l=0;
            while(i<k2){
                if(cardno == faccards[i][0]){
                    l++;
                }
                i++;
            }
            if(l==0) cout<<"No books/journals issued using this library card number.\n";
            else{
                cout<<"You issued "<<l<<" books/journals. Enter the details of the books which you want to return!"<<endl;
                cout<<"Enter the title of journal: "; cin>>bookname;
                cout<<"Enter the author of journal: "; cin>>author;
                i=0;  flag =1;
                while(i<k2){
                    if(cardno == faccards[i][0] && bookname == faccards[i][1]){
                        flag =0;
                        valofi = i;
                        break;
                    }
                    i++;
                }
                if(flag == 1) cout<<"This journal has not been issued.\n";
                else{

                    while(valofi<k2){
                        faccards[valofi][0] = faccards[valofi+1][0];  //card number
                        faccards[valofi][1] = faccards[valofi+1][1];  //book name
                        faccards[valofi][2] = faccards[valofi+1][2];  //issue date
                        valofi++;
                    }
                    k2--;
                    cout<<"\nThe journal has been returned.\n";
                }
            }
        }
        else cout<<"INVALID INPUT.\n";
    }
    int month(string a)  //function to return month number from given date string
    {
        if(a[4]=='J' && a[5]=='a' && a[6]=='n')
            return 1;
        else if(a[4]=='F' && a[5]=='e' && a[6]=='b')
            return 2;
        else if(a[4]=='M' && a[5]=='a' && a[6]=='r')
            return 3;
        else if(a[4]=='A' && a[5]=='p' && a[6]=='r')
            return 4;
        else if(a[4]=='M' && a[5]=='a' && a[6]=='y')
            return 5;
        else if(a[4]=='J' && a[5]=='u' && a[6]=='n')
            return 6;
        else if(a[4]=='J' && a[5]=='u' && a[6]=='l')
            return 7;
        else if(a[4]=='A' && a[5]=='u' && a[6]=='g')
            return 8;
        else if(a[4]=='S' && a[5]=='e' && a[6]=='p')
            return 9;
        else if(a[4]=='O' && a[5]=='c' && a[6]=='t')
            return 10;
        else if(a[4]=='N' && a[5]=='o' && a[6]=='v')
            return 11;
        else if(a[4]=='D' && a[5]=='e' && a[6]=='c')
            return 12;
        else return 0;
    }
    int *addDays(int day, int month, int year, int *arr){  //function to add 15 days to issue date
        int monthdays[] = {31,28,31,30,31,30,31,31,30,31,30,31};   //array holding # of days per month
        int addyears;    //number of years to add
        int leftoverdays; //days leftover after dividing by 365
        int dd = 14;    //number of days to add
        addyears = dd/365;
        leftoverdays = dd%365;
        year += addyears;
        for (int i = 0; i <= leftoverdays; i++)
            if (day < monthdays [month -1])
                day ++;
            else if ((day == monthdays [month-1]) && (month < 12)){
                day = 1;
                month ++;
            }
            else if ((day == monthdays [month-1]) && (month == 12)){
                day = 1;
                month = 1;
                year ++;
            }
            else
                cout << "Error setting date!";
        arr[0] = day;
        arr[1] = month;
        arr[2] = year;
        return arr;
    }
    int calculateFine(int day1, int mon1, int year1, int day2, int mon2, int year2){  //function to calculate fine
        int ref,dd1,dd2,i;
        if(day2<=31 && mon2<=12 ){
            ref = year1;
            if(year2<year1)
            ref = year2;
            dd1=0;
            dd1=dater(mon1);
            for(i=ref;i<year1;i++)
            {
                if(i%4==0)
                dd1+=1;
            }
            dd1=dd1+day1+(year1-ref)*365;
            dd2=0;
            for(i=ref;i<year2;i++)
            {
                if(i%4==0)
                dd2+=1;
            }
            dd2=dater(mon2)+dd2+day2+((year2-ref)*365);
            int dif = dd2-dd1;
            if(dif < -15){ cout<<"You entered a return date, which is < issue date.\n"; return 0; }
            else {
                if(dif < 0) cout<<"No fine.\n";
                else {
                    cout<<"The fine is Rs. "<<dif<<endl;
                }
                cout<<"\nThe book has been returned.\n";
                return 1;
            }
        }
        else{ cout<<"You entered invalid date.\n"; return 0; }
    }
    int dater(int x)  //function used in calculateFine()
    {   int y=0;
        switch(x)
        {
        case 1: y=0; break;
        case 2: y=31; break;
        case 3: y=59; break;
        case 4: y=90; break;
        case 5: y=120;break;
        case 6: y=151; break;
        case 7: y=181; break;
        case 8: y=212; break;
        case 9: y=243; break;
        case 10:y=273; break;
        case 11:y=304; break;
        case 12:y=334; break;
        default: printf("Invalid Inputnnnn"); exit(1);
        }
        return(y);
    }
};

int main()
{
    LIBRARY p;  //declaring an object of class LIBRARY
    ofstream fo;  //declaring output file stream
    ifstream fi;  //declaring input file stream
    string bookname, bookname1, author, author1;
    string title,title1, volno,volno1, issueno,issueno1;
    int choice, flag;
    do{ //loop which continues until user input choice number 5 to exit
        cout<<"\n---------------------------------------------------------\n";
        cout<<"1. Add new book to library\n";
        cout<<"2. Add new journal to library\n";
        cout<<"3. Issue book\n";
        cout<<"4. Issue journal\n";
        cout<<"5. Return book\n";
        cout<<"6. Return journal\n";
        cout<<"7. Exit!\n\n";
        cout<<"Enter a choice number: ";
        cin>>choice;
        switch(choice)
        {
        case 1:  //adding book to library
            fi.open("Librarybook.txt", ios::in);
            cin.ignore();
            cout<<"Enter the name of book : ";
            getline(cin, bookname);
            cout<<"Enter author's name: ";
            getline(cin, author);
            flag =0;
            while(fi>>bookname1>>author1){
                if(bookname == bookname1 && author == author1){
                    flag=1;
                    cout<<"\nThis book with same name and author already exists in library.\n";
                    break;
                }
            }
            fi.close();
            fo.open("Librarybook.txt",ios::out | ios::app );
            if(flag == 0){
                fo<<bookname<<"\t"<<author<<endl;
                cout<<"New book have been added to library successfully.\n";
            }
            else cout<<"You cannot add this book to library.\n";
            fo.close();
            break;
        case 2:  //adding journal to library
            fi.open("Libraryjournal.txt", ios::in );
            cin.ignore();
            cout<<"Enter the name of journal : ";
            getline(cin, bookname);
            cout<<"Enter author's name: ";
            getline(cin, author);
            cout<<"Enter volume number: ";
            getline(cin, volno);
            cout<<"Enter issue number: ";
            getline(cin, issueno);
            flag =0;
            while(fi>>bookname1>>author1>>volno1>>issueno1){
                if(bookname == bookname1 && author == author1 && volno == volno1 && issueno == issueno1){
                    flag=1;
                    cout<<"\nThis journal already exists in library.\n";
                    break;
                }
            }
            fi.close();
            fo.open("Libraryjournal.txt",ios::out | ios::app);
            if(flag == 0){
                fo<<bookname<<"\t"<<author<<"\t"<<volno<<"\t"<<issueno<<endl;
                cout<<"New journal have been added to library successfully.\n";
            }
            else cout<<"You cannot add this journal to library.\n";
            fo.close();
            break;
        case 3:  //issue book
            p.issueBook();
            break;
        case 4:  //issue journal
            p.issueJournal();
            break;
        case 5:  //return book
            p.returnBook();
            break;
        case 6:  //return journal
            p.returnJournal();
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
