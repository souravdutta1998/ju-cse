#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

class STUDENT{
    string roll;  //private members of class STUDENT
    string name;
    string course;
    //string admission_date;
    // current date/time based on current system
    time_t now = time(0);
   
    // convert now to string form
    char* dt = ctime(&now);
    int marks[5]; //array which can contain 5 integer values
public:  //public member functions of class STUDENT
    void setRoll(string r){  //setter function to set roll
        roll = r;
    }
    void setName(string n){  //setter function to set name
        name = n;
    }
    void setCourse(string c){  //setter function to set course
        course = c;
    }
    void setMarks(int m[]){  //setter function to set marks
        for(int i=0;i<5;i++){
            marks[i] = m[i];
        }
    }
    string getRoll(){   //getter function to return roll
        return roll;
    }
    string getName(){  //getter function to return name
        return name;
    }
    string getCourse(){  //getter function to return course
        return course;
    }
    int *getMarks(){  //getter function to return marks
        return marks;
    }
    void displayDetails(){  //function display all the details of student except marks
        cout<<"\n\n";
        cout<<"------------------------------------------------------------------------"<<endl;
        cout<<"\t\t\tMARKSHEET"<<endl;
        cout<<"------------------------------------------------------------------------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Roll: "<<roll<<endl;
        cout<<"Course: "<<course<<endl;
        cout<<"Admission Date: "<<dt<<endl;
        cout<<"------------------------------------------------------------------------"<<endl;
    }
};

char grade_calc(int m) //function to calculate grade corresponding to each marks user enters
{
    if(m >= 91 && m <= 100)
        return 'S';
    else if(m >= 81 && m <= 90)
        return 'A';
    else if(m >= 71 && m <= 80)
        return 'B';
    else if(m >= 61 && m <= 70)
        return 'C';
    else if(m >= 51 && m <= 60)
        return 'D';
    else if(m >= 41 && m <= 50)
        return 'E';
    else
        return 'F';
}
int main()
{
    STUDENT *studentlist[20];  //defining array of objects of class STUDENT
    int choice,flag, flag1, i=0, j, total =0; //i and j are the index variables
    int dd,mm,yyyy;
    double cgpa;
    string roll1,name1,course1,admission_date1;
    int marks1[5];
    //string allcourse[3]={"arts","commerce","science"};
    string arts[5] = {"English","Political Sc.","Psychology","Sociology","History"};
    string commerce[5] = {"Business St.","Economics","Entrepreneur.","Accountancy","Mathematics"};
    string science[5] = {"Physics","Chemistry","Mathematics","Biology","Computer Sc."};
    do{ //loop which continues until user input choice number 4 to exit
        cout<<"\n------------------------------------------------------------------------\n";
        cout<<"1. Input student details and marks\n";
        cout<<"2. Display marksheet\n";
        cout<<"3. Display total number of students\n";
        cout<<"4. Exit!\n\n";
        cout<<"Enter a choice number: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            studentlist[i] = new STUDENT;

            cout<<"\nEnter roll: "; cin>>roll1;
            for(j=0;j<i;j++){ //loop to check if given roll already exists
                    flag1=0;
            while(!flag1){
                //flag1 =1;
                if(studentlist[j]->getRoll() == roll1){
                    cout<<"This roll already exists. Enter a different roll: ";
                    cin>>roll1;
                    flag1=0;
                }
                else flag1=1;
            }

            }
            studentlist[i]->setRoll(roll1);
            cout<<"Enter name: "; cin>>name1;
            studentlist[i]->setName(name1);
            cout<<"Enter course(arts/commerce/science): "; cin>>course1;
            flag1=0;
            while(!flag1){
                flag1 =1;
                if(course1 == "arts" || course1 == "commerce" || course1 == "science"){
                    studentlist[i]->setCourse(course1);
                    flag1 =1;
                }
                else {
                    cout<<"Not a valid course! Enter course again: "; cin>>course1;
                    studentlist[i]->setCourse(course1);
                    flag1=0;
                    }
            }
         /*   cout<<"Enter admission date(dd/mm/yyyy): "; cin>>admission_date1;
            studentlist[i]->setDate(admission_date1);

            flag1=0;
            while(!flag1){
                flag1 =1;
                if(admission_date1[2]=='/' && admission_date1[5]=='/' ){
                        flag1 =1;
                    dd=((admission_date1[0]-48)*10)+(admission_date1[1]-48);
                    mm=((admission_date1[3]-48)*10)+(admission_date1[4]-48);
                    yyyy=((admission_date1[6]-48)*1000)+((admission_date1[7]-48)*100)+((admission_date1[8]-48)*10)+(admission_date1[9]-48);

                    if(dd<=31 && mm<=12 && yyyy<=2018){
                        studentlist[i]->setCourse(course1);
                        flag1=1;
                    }
                    else{
                        cout<<"Not a valid date! Enter admission date(dd/mm/yyyy): "; cin>>admission_date1;
                        studentlist[i]->setDate(admission_date1);
                        flag1=0;
                    }
                }
                else {
                    cout<<"Not a valid date! Enter admission date(dd/mm/yyyy): "; cin>>admission_date1;
                    studentlist[i]->setDate(admission_date1);
                    flag1=0;
                    }
            }
*/

            if(studentlist[i]->getCourse() == "arts")
            {
                for(j=0;j<5;j++)
                {
                    cout<<"Enter marks of "<<arts[j]<<" : ";
                    cin>>marks1[j];
                    flag1=0;
                    while(!flag1){
                        flag1 =1;
                        if(marks1[j]> 100 || marks1[j]<0){
                            flag1=0;
                            cout<<"Invalid marks. Enter marks of "<<arts[j]<<" again: ";
                            cin>>marks1[j];
                        }
                    }
                }
                studentlist[i]->setMarks(marks1);
            }
            else if(studentlist[i]->getCourse() == "commerce")
            {
                for(j=0;j<5;j++)
                {
                    cout<<"Enter marks of "<<commerce[j]<<" : ";
                    cin>>marks1[j];flag1=0;
                    while(!flag1){
                        flag1 =1;
                        if(marks1[j]> 100 || marks1[j]<0){
                            flag1=0;
                            cout<<"Invalid marks. Enter marks of "<<commerce[j]<<" again: ";
                            cin>>marks1[j];
                        }
                    }
                }
                studentlist[i]->setMarks(marks1);
            }
            else if(studentlist[i]->getCourse() == "science")
            {
                for(j=0;j<5;j++)
                {
                    cout<<"Enter marks of "<<science[j]<<" : ";
                    cin>>marks1[j];
                    flag1=0;
                    while(!flag1){
                        flag1 =1;
                        if(marks1[j]> 100 || marks1[j]<0){
                            flag1=0;
                            cout<<"Invalid marks. Enter marks of "<<science[j]<<" again: ";
                            cin>>marks1[j];
                        }
                    }
                }
                studentlist[i]->setMarks(marks1);
            }
            i++;  //i is incremented as user enters details of new student
            break;
        case 2:
            cout<<"\nEnter roll of student: "; cin>>roll1;
            flag = 0 ;
            for(j=0;j<i;j++)
            {
                if(studentlist[j]->getRoll() == roll1)
                {
                    flag = 1; // flag variable is changed to 1 if roll is found
                    studentlist[j]->displayDetails();
                    cout<<"Subject \t\tMarks\t\t Grade\n";
                    if(studentlist[j]->getCourse()=="arts"){
                        for(int k=0;k<5;k++){
                            total += *(studentlist[j]->getMarks()+k);
                            cout<<arts[k]<<" \t\t "<<*(studentlist[j]->getMarks()+k)<<"\t\t   "<<grade_calc(*(studentlist[j]->getMarks()+k))<<endl;
                        }
                    }
                    else if(studentlist[j]->getCourse()=="commerce"){
                        for(int k=0;k<5;k++){
                            total += *(studentlist[j]->getMarks()+k);
                            cout<<commerce[k]<<" \t\t "<<*(studentlist[j]->getMarks()+k)<<"\t\t   "<<grade_calc(*(studentlist[j]->getMarks()+k))<<endl;
                        }
                    }
                    else if(studentlist[j]->getCourse()=="science"){
                        for(int k=0;k<5;k++){
                            total += *(studentlist[j]->getMarks()+k);
                            cout<<science[k]<<" \t\t "<<*(studentlist[j]->getMarks()+k)<<"\t\t   "<<grade_calc(*(studentlist[j]->getMarks()+k))<<endl;
                        }
                    }
                    cout<<"------------------------------------------------------------------------"<<endl;
                    cgpa = (double)total / 50;  //stores the value of cgpa
                    cout<<"\tCGPA : "<<cgpa<<endl;
                    total = 0;
                    cout<<"------------------------------------------------------------------------"<<endl;
                    break;
                }
            }
            if(!flag)
                cout<<"\nRoll number not found!\n";
            break;
        case 3:
            cout<<"\nTotal number of students admitted : "<< i;
            break;
        case 4:
            delete studentlist;
            cout<<"\nLogged out.\n";
            exit(0);
        default:
            cout<<"\nPlease enter a valid choice.\n";
            break;
        }
    }while(1);
    return 0;
}
