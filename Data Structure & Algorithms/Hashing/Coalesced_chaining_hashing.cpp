#include<iostream>
using namespace std;
#define Max 11

struct hash_struct{
    int value;
    int flag_index;
    int next_index;
}hash_table[Max];

int hash_function(int num){
    return (num%Max);
}
void hash_insertion(int num){
    int form,i=0,j;
    form = hash_function(num);
    while(1){
        if(hash_table[form].flag_index != 1){
            hash_table[form].value = num;
            if(hash_table[form].flag_index == 0)
                hash_table[form].flag_index = 1;
            break;
        }
        else if(hash_table[form].next_index == -1 && hash_table[form].flag_index == 1){
            j = Max-1;
            while(1){
                if(hash_table[j].flag_index != 1){
                    hash_table[form].next_index = i;
                    hash_table[j].value = num;
                    cout<<j;
                    if(hash_table[form].flag_index == 0)
                        hash_table[form].flag_index = 1;
                    break;
                }
                j--;
                if(j < 0)
                    break;
            }
        }
        else{
            form = hash_table[form].next_index;
        }
    }
}

void hash_search(int num){
    int index,i=0;
    index = hash_function(num);
    while(1){
        if(hash_table[index].value == num){
            cout<<"The searching key is present at Hash-table index "<<index;
            break;
        }
        else if(hash_table[index].next_index != -1)
            index = hash_table[index].next_index;
        else
            break;

    }
}

void delete_hash(int num){
    int index = hash_function(num);
    while(1){
        if(hash_table[index].value == num){
            if(hash_table[index].next_index != 2)
                hash_table[index].flag_index = 2;
            hash_table[index].value = 0;
            break;
        }
        else if(hash_table[index].flag_index == 0){
            cout<<"The deletion key is not present in Hash-table";
            break;
        }
        else{
            index = hash_table[index].next_index;
        }
    }
}

void print_hash_table(){
    int i;
    cout<<"Tableindex"<<"\t"<<"Value Stored"<<"\n";
    for(i=0;i<Max;i++){
        if(hash_table[i].flag_index != 0)
            cout<<i<<"\t\t"<<hash_table[i].value<<"\n";
    }
}

int main(){
    int x,i;
    for(i=0;i<Max;i++){
        hash_table[i].flag_index = 0;
        hash_table[i].next_index = -1;
    }
    cout<<"1.Press -1 to exit."<<"\n";
    cout<<"2.Assumption collision case key fill up from rightmost side."<<"\n";
    cout<<"3.Our Function is hi(key) = (key+i)mod 11"<<"\n";
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
