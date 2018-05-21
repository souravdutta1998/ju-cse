#include <iostream>
#include <cstdlib>
using namespace std;
class TOLLTAX{
    int toll;  //private members of class TOLLTAX
    int amount;
    int num,num_bike, num_car, num_truck; //variables for storing the total vehicles, and number of each vehicle
public:  //public members
    TOLLTAX(){ //constructor which sets the integer value of each variable to 0
        toll = 0;
        amount = 0;
        num_bike = 0;
        num_car = 0;
        num_truck = 0;
    }
    void receiveToll(){  //function to receive toll from the vehicle owner
        int choice;
        cout<<"1. Bike/scooty (Rs.10)\n";
        cout<<"2. Car (Rs.20)\n";
        cout<<"3. Truck (Rs.30)\n";
        cout<<"Enter a choice number: ";
        cin>>choice;
        switch(choice) //for three different vehicles
        {
        case 1:
            cout<<"Received Rs. 10 from the vehicle owner!\n";
            amount += 10;
            num_bike++;
            break;
        case 2:
            cout<<"Received Rs. 20 from the vehicle owner!\n";
            amount += 20;
            num_car++;
            break;
        case 3:
            cout<<"Received Rs. 30 from the vehicle owner!\n";
            amount += 30;
            num_truck++;
            break;
        default:
            cout<<"\nPlease input a valid choice\n";
            break;
        }
    }
    void totalVehicles(){  //function to output the total number of vehicles and each type of vehicle
        num = num_bike + num_car + num_truck;
        if(num ==0) cout<<"NO VEHICLES PASSED!"<<endl;
        else
        {
            cout<<"Number of bikes: "<<num_bike<<endl;
            cout<<"Number of cars: "<<num_car<<endl;
            cout<<"Number of trucks: "<<num_truck<<"\n\n";
            cout<<"TOTAL NUMBER OF VEHICLES: "<<num<<endl;
        }
    }
    int getAmount(){ //function to print the total amount of toll collected
        if(amount == 0) cout<<"No amount collected"<<endl;
        else
        cout<<"Total amount collected is: Rs. "<<amount<<endl;
    }
};
int main()
{
    TOLLTAX t;
    int choice;
    do{ //loop which continues until user input choice number 4 to exit
        cout<<"\n---------------------------------------------------------\n";
        cout<<"1. Receive toll\n";
        cout<<"2. Display number of vehicles that crossed the bridge\n";
        cout<<"3. Display the amount of toll collected\n";
        cout<<"4. Exit!\n\n";
        cout<<"Enter a choice number: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            t.receiveToll();  //calling the receivetoll function of class TOLLTAX
            break;
        case 2:
            t.totalVehicles();  //calling the totalvehicles function of class TOLLTAX
            break;
        case 3:
            t.getAmount();  //calling the getamount function of class TOLLTAX
            break;
        case 4:
            cout<<"\nLogged out.\n";
            exit(0);
        default:
            cout<<"\nPlease enter a valid choice.\n";
            break;
        }
    }while(1);
    return 0;
}
