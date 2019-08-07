#include<bits/stdc++.h> 
using namespace std; 
/*  
int pageFaults(int pages[], int n, int capacity) 
{ 
    unordered_set<int> s; 
    unordered_map<int, int> indexes; 
  
    int page_faults = 0; 
    for (int i=0; i<n; i++) 
    { 
	bool flag = 0;
        if (s.size() < capacity) 
        { 
            if (s.find(pages[i])==s.end()) 
            { 
                s.insert(pages[i]); 
                page_faults++;
		flag =1; 
            } 
	    else {
		s.erase(pages[i]);
		s.insert(pages[i]);	
	    }
            indexes[pages[i]] = i; 
        } 
        else
        { 
            if (s.find(pages[i]) == s.end()) 
            { 
                int lru = INT_MAX, val; 
                for (auto it=s.begin(); it!=s.end(); it++) 
                { 
                    if (indexes[*it] < lru) 
                    { 
                        lru = indexes[*it]; 
                        val = *it; 
                    } 
                } 
  
		//unordered_set<int>::iterator it = s.end();
    		//--it;
    		s.erase(prev(s.end()));               	
                // insert the current page 
                s.insert(pages[i]); 
  
                // Increment page faults 
                page_faults++;
		flag = 1; 
            }
  	    else  {
		s.erase(pages[i]);
		s.insert(pages[i]);	
	    }
            // Update the current page index 
            indexes[pages[i]] = i; 
        }
	printf("After inserting %d, current set is: ", pages[i]);
	for(auto it: s) cout<<it<<" ";
	if(flag) cout<<"--page fault";
	else cout<<"--page hit";
	cout<<endl;
    } 
  
    return page_faults; 
} 
*/
int pageFaults1(int pages[], int n, int capacity) {
	int fault = 0;
	
	list<int> s;
	list<int>::iterator it;
	for(int i=0;i<n;i++) {
		//bool flag = 0;
		s.remove(pages[i]);
		s.insert(pages[i]);
		for(auto it : s) cout<<it<<" ";
		//if(flag) cout<<"page fault\n";
		//else cout<<"page hit\n";
	
	}
	return fault;
}
  
int main() 
{ 
    	int pages[] = {9,10,11,7,12,8,7,6,12,5,4,3,10,11,12,4,5,6,9,4,5}; 
    	int n = sizeof(pages)/sizeof(pages[0]); 
   	 
   	cout<<"WITH 4 FRAMES \n";
    	cout<<"Total page faults: " << pageFaults1(pages, n, 4)<<endl; 
    	cout<<endl;
	cout<<"WITH 5 FRAMES \n";
	cout<<"Total page faults: "<< pageFaults1(pages, n, 5)<<endl;
	return 0; 
} 
