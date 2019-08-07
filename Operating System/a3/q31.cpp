#include<bits/stdc++.h> 
using namespace std; 

int pageFaults1(int pages[], int n, int capacity) {
	int fault = 0;
	
	list<int> l;
	set<int> st;
	for(int i=0;i<n;i++) {
		if(l.size() < capacity) {
			if(st.find(pages[i]) == st.end()) {
				st.insert(pages[i]);
				l.push_back(pages[i]);
				fault++;	
			} else {
				l.remove(pages[i]);
				l.push_back(pages[i]);
			}
		} else {
			if(st.find(pages[i]) == st.end()) {
				st.insert(pages[i]);
				st.erase(st.find(l.front()));
				l.pop_front();
				l.push_back(pages[i]);
				fault++;
			} else {
				l.remove(pages[i]);
				l.push_back(pages[i]);
			}
		}
		for(auto it : l) cout<<it<<" ";
		cout<<endl;
	}
	return fault;
}
  
int main() 
{ 
    	int pages[] = {9,10,11,7,12,8,7,6,12,5,4,3,10,11,12,4,5,6,9,4,5}; 
    	int n = sizeof(pages)/sizeof(pages[0]); 
   	 
   	cout<<"WITH 4 FRAMES \n";
    	cout<<pageFaults1(pages, n, 4); 
    	cout<<endl;
	cout<<"WITH 5 FRAMES \n";
	cout<<pageFaults1(pages, n, 5);
	return 0; 
} 
