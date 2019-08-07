#include <bits/stdc++.h>
using namespace std;
vector<int> memory;
vector<vector<int> > curblocks;
void displaytable() {
    curblocks.clear();
    int start = 1, end = 9999;
    int curprocess = memory[1];
    for(int i=1;i<10000;i++) {
        if(curprocess == memory[i]) {
            end = i;
        } else {
            curblocks.push_back({curprocess, start, end, end-start+1});
            curprocess = memory[i];
            start = i;
        }
    }
    curblocks.push_back({curprocess, start, end, end-start+1});
    cout<<"Current memory map : \n";
    cout<<"-----------------------------------------------------------------------------------------\n";
    cout<<"Block no.\t Status\t\t Process no.\t Start address\t End address\t Size\n";
    cout<<"-----------------------------------------------------------------------------------------\n";
    int i = 1;
    char status[15];
    for(auto it : curblocks) {
        if(it[0] == -1) {
            strcpy(status, "Unallocated");
            printf("%d\t\t %s\t \t\t %d\t\t %d\t\t %d\n", i, status, it[1], it[2], it[3]);
        }
        else {
            strcpy(status, "Allocated");
            printf("%d\t\t %s\t %d\t\t %d\t\t %d\t\t %d\n", i, status, it[0], it[1], it[2], it[3]);
        }
        i++;
    }
    cout<<"-----------------------------------------------------------------------------------------\n\n";
}
void allocate_process(int *p_start, int *p_size, int total) {
    for(int i=0;i<total;i++) {
        for(int j=p_start[i];j<p_start[i]+p_size[i];j++) {
            memory[j] = i;
        }
    }
}
void firstfit(int curprocess, int size) {
    for(auto it : curblocks) if(it[0]==-1) cout<<it[3]<<" "; cout<<endl;
    for(auto it : curblocks) {
        if(it[0]==-1 && it[3] >= size) {
            for(int i=it[1];i<it[1]+size;i++) {
                memory[i] = curprocess;
            }
            return;
        }
    }
}
bool compare(vector<int> x, vector<int> y) {
    if(x[3] < y[3]) return 1;
    return 0;
}
void bestfit(int curprocess, int size) {
    sort(curblocks.begin(), curblocks.end(), compare);
    for(auto it : curblocks) if(it[0]==-1) cout<<it[3]<<" "; cout<<endl;
    for(auto it : curblocks) {
        if(it[0]==-1 && it[3] >= size) {
            for(int i=it[1];i<it[1]+size;i++) {
                memory[i] = curprocess;
            }
            return;
        }
    }
}
int main() {
	int p_start[] = { 200 , 1000 , 1600 , 2000 };
	int p_size[] = { 500 , 400 , 250 , 800 };
	int process[] = {150, 100, 150}; 
	cout<<"________________________________________________________________________________________________\n";
	cout<<"\t\t\t\t FIRST FIT STRATEGY \n";
    cout<<"________________________________________________________________________________________________\n";
	memory.resize(10000, -1);
	displaytable();
	
	allocate_process(p_start, p_size, 4);
	printf("After allocating 4 given processes using firstfit strategy, ");
	displaytable();
	
	for(int i=0;i<3;i++) {
	    firstfit(i+10, process[i]);
	    printf("After allocating process %d with size %d bytes using first fit strategy, ", i+10, process[i]);
	    displaytable();
	}
	
	cout<<"________________________________________________________________________________________________\n";
	cout<<"\t\t\t\t BEST FIT STRATEGY \n";
    cout<<"________________________________________________________________________________________________\n";
	
    memory.clear();
    memory.resize(10000, -1);
	displaytable();
	
	allocate_process(p_start, p_size, sizeof(p_size)/sizeof(int));
	printf("After allocating 4 given processes using bestfit strategy, ");
	displaytable();
    
	for(int i=0;i<3;i++) {
	    bestfit(i+10, process[i]);
	    printf("After allocating process %d with size %d bytes using best fit strategy, ", i+10, process[i]);
	    displaytable();
	}
	return 0;
}
