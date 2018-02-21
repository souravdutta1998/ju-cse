#include<iostream>
using namespace std;
#define Max 11

struct hash_struct{
    int value;
    int check_flag;
}hash_table[Max];

int hash_function1(int num,int ind){
    return ind;
}
int hash_function2(int num,int ind){
    return (num%Max);
}
int hash_function(int num,ind){
    return hash_function1(num,ind)+hash_function2(num,ind);
}

void hash_insertion(int num){
    int form,i=0;
    while(1){
        form = hash_function(num,i);
        if(hash_table[form].check_flag == 0 || hash_table[form].check_flag == 2){
            hash_table[form].value = num;
            if(hash_table[index].check_flag == 0)
                hash_table[form].check_flag = 1;
            break;
        }
        else
            i++;
        if(i >= Max)
            i = i-Max;
    }
}

void hash_search(int num){
    int index,i=0;
    while(1){
        index = hash_function(num,i);
        if(hash_table[index].value == num){
            cout<<"The searching key is present at Hash-table index "<<hash_table[index].check_flag;
            break;
        }
        else if(hash_table[index].check_flag == 0 || i>Max){
            cout<<"The searching key is not present in Hash-table";
            break;
        }
        else{
            i++;
        }
    }
}

void delete_hash(int num){
    int i=0,index;
    while(1){
        int index = hash_function(num,i);
        if(hash_table[index].check_flag == 1 && hash_table[index].value == num){
            hash_table[index].check_flag = 2;
            hash_table[index].value = 0;
            break;
        }
        else if(hash_table[index].check_flag == 0 || i>Max){
            cout<<"The deletion key is not present in Hash-table";
            break;
        }
        else{
            i++;
        }
    }
}

void print_hash_table(){
    int i;
    cout<<"Tableindex"<<"\t"<<"Value Stored"<<"\n";
    for(i=0;i<Max;i++){
        if(hash_table[i].check_flag == 1)
            cout<<i<<"\t\t"<<hash_table[i].value<<"\n";
    }
}

int main(){
    int x,i;
    for(i=0;i<Max;i++){
        hash_table[i].check_flag = 0;
    }
    cout<<"1.Press -1 to exit."<<"\n";
    cout<<"2.Flag value 0 show emptiness."<<"\n";
    cout<<"3.Flag value 1 show engaged position."<<"\n";
    cout<<"4.Flag value 2 show deleted position."<<"\n";
    cout<<"5.Our Function is hi(key) = h1() + h2() where, h1=i,h2=(key)mod 11"<<"\n";
    cout<<"Enter your data's one by one to store in a hashing table:"<<"\n";
    while(1){
        cin>>x;
        if(x == -1)
            break;
        hash_insertion(x);
    }
    print_hash_table();
    return 0;

}
