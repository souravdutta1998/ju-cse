#include<bits/stdc++.h>
using namespace std;

vector<string> grammar;
map<string, set<vector<string> > > productions;
map<int, vector<string> > getprodleft;
string startsymbol;
void buildProductions(string filename) {
	ifstream fi;
	fi.open(filename);
	if(!fi.is_open()){
		cout << "File not found!\n";
		return;
	}
	string str;
	while(getline(fi, str)) grammar.push_back(str);
	fi.close();
	int idx = 1;
	for(auto prod : grammar) {
		//cout<<prod<<"\n";
		string tmp = "";
		prod += '~';
		bool flag = 0;
		string left;
		vector<string> right;
		for(auto ch : prod) {
			if(ch == ' ' or ch == '~') {
				if(flag==0) left = tmp;
				else if(tmp != "->") right.push_back(tmp);
				tmp = "";
				flag = 1;
				
			}
			else tmp += ch;
		}
		//cout<<left<<" ";
		//for(auto str : right)  cout<<str<<" ";
		//cout<<"\n";
		productions[left].insert(right);
		flag = 0;
		for(auto it : getprodleft) {
			if(it.second[0] == left) {
				flag = 1;
				break;
			}
		}
		if(flag == 0) {
			getprodleft[idx].push_back(left);
			idx++;
		}
	}
	startsymbol = getprodleft[1][0];
}
void printProductions() {
	cout<<"The production rules are: \n";
	for(auto idx : getprodleft) {
		for(auto str : idx.second) {
			cout<<str<<" -> ";
			bool flag = 0;
			for(auto it : productions[str]) {
				if(flag) cout<<" | ";
				flag = 1;
				for(auto it1 : it) cout<<it1<<" ";
			}
			cout<<"\n";
		}
	}
	cout<<"\n";
}
void removeLeftRecursion() {
	int n = getprodleft.size();
	vector<string> lefti, leftj;
	for(int i = 1;i <= n;i++) {
		lefti = getprodleft[i];
		for(int j = 1;j <= i-1;j++) {
			
			leftj = getprodleft[j];
			for(auto templeft : lefti) {
				set<vector<string>> prod = productions[templeft];
				
				for(auto vec : prod) {
					for(auto templeftj : leftj) {
						if(templeftj == vec[0]) {
							vector<string> prevp = vec;
							productions[templeft].erase(productions[templeft].find(prevp));
							vector<string> remaining, rem;
							for(int i=1;i<vec.size();i++)
								remaining.push_back(vec[i]);
							
							for(auto st : productions[templeftj]) {
								vector<string> rm;
								for(auto it : st){
									rm.push_back(it);
								}
								rm.insert(rm.end(),remaining.begin(),remaining.end());
								productions[templeft].insert(rm);
							}
						}
					}
				}
			}
		}
		//eliminate all immediate left recursion
		bool flag = 0;
		for(auto templeft : lefti) {
			set<vector<string>> prod = productions[templeft];
			productions.erase(productions.find(templeft));
			set<int> eraseidx;
			int idx =0;
			for(auto it : prod) {
				if(it[0] == templeft) {
					flag = 1;
					eraseidx.insert(idx);
					vector<string> remaining;
					for(int i=1;i<it.size();i++) 
						remaining.push_back(it[i]);
					remaining.push_back(templeft+"'");
					productions[templeft+"'"].insert(remaining);
					remaining.clear();
					remaining.push_back("epsilon");
					productions[templeft+"'"].insert(remaining);
				}
				idx++;
			}
			if(flag) {
				set<vector<string>> newprod;
				idx = 0;
				for(auto it : prod) {
					if(eraseidx.find(idx) == eraseidx.end()) {
						newprod.insert(it);
					}
					idx++;
				}
				getprodleft[i].push_back(templeft+"'");
				for(auto vec : newprod) {
					if(vec[0] == "epsilon") vec.clear();
					vec.push_back(templeft+"'");
					productions[templeft].insert(vec);
				}
			} else {
				productions[templeft] = prod;
			}
		}
		
	}
}
set<string> nonterminals, terminals;
map<string, set<string> > first;
bool containsEpsilon(set<string> prod) {
	for(auto it : prod)
		if(it == "epsilon") return 1;
	return 0;
}
void computeFirst() {
	for(auto it : productions)
		nonterminals.insert(it.first);
	for(auto it : productions) {
		for(auto it1 : it.second) {
			for(auto str : it1) {
				if(nonterminals.find(str) == nonterminals.end() and str!="epsilon"){
					terminals.insert(str);
					first[str].insert(str);
				}
				else if(str == "epsilon") {
					first[it.first].insert(str);
				}
			}
		}
	}
	cout<<"Non Terminals are: ";for(auto it : nonterminals) cout<<it<<" "; cout<<"\n\n";
	cout<<"Terminals are: "; for(auto it : terminals) cout<<it<<" "; cout<<"\n\n";
	
	int cnt = 0;
	map<string, set<string> > recprod;
	for(auto prod : productions) {
		//cout<<prod.first<<" ";
		for(auto vec : prod.second) {
			for(auto str : vec) {
				if(terminals.find(str) != terminals.end()) {
					first[prod.first].insert(str);
					break;
				}
				else if(nonterminals.find(str) != nonterminals.end()) {
					recprod[prod.first].insert(str);
				}
				if(str!="epsilon" and containsEpsilon(first[str])==0) 
					break;
			}
		}
		
	}
	/*for(auto it : recprod) {
		cout<<it.first<<" : ";
		for(auto it1 : it.second) cout<<it1<<" ";
		cout<<"\n";
	}*/
	bool flag = 0;
	while(1) {
		flag = 0;
		for(auto it : recprod) {
			for(auto it1 : it.second) {
				for(auto f : first[it1]) {
					if(f!="epsilon" and first[it.first].find(f) == first[it.first].end()) {
						first[it.first].insert(f);
						flag = 1;
					}
				}
			}
		}
		if(!flag) break;
	}
	for(auto prod : productions) {
		for(auto vec : prod.second) {
			cnt = 0;
			for(auto str : vec) {
				if(str!="epsilon" and containsEpsilon(first[str])==0)
					break;
				cnt++;
			}
			if(cnt == vec.size()) 
				if(!(vec.size() == 1 and vec[0] == "epsilon")){
					first[prod.first].insert("epsilon");
				}
		}
		
	}
}
void printFirst() {
	cout<<"---------------------------------\n";
	cout<<"Symbol \t\tFIRST Set\n";
	cout<<"---------------------------------\n";
	for(auto it : first){
		cout<<it.first<<" \t\t{ ";
		bool flag = 0;
		for(auto it1 : it.second) {
			if(flag) cout<<" , ";
			flag = 1;
			cout<<it1;
		}
		cout<<" }\n";
	}
	cout<<"---------------------------------\n\n";
}

map<string, set<string>> follow;
void computeFollow() {
	follow[startsymbol].insert("$");
	map<string, set<string> > folunion;
	string cur, nex;
	for(auto prod : productions) {
		for(auto vec : prod.second) {
			//cout<<prod.first<<" ";
			for(int i=0;i<vec.size();i++) {
				cur = vec[i];
				if(nonterminals.find(cur) != nonterminals.end()){
					if(i == vec.size()-1) {
						if(cur != prod.first) folunion[cur].insert(prod.first);
					} else {
						set<string> fr;
						bool ep = 1;
						for(int j = i+1;j<vec.size();j++) {
							nex = vec[j];
							bool tempep = 0;
							for(auto it : first[nex]) {
								if(it == "epsilon") tempep = 1;
								else follow[cur].insert(it);
							}
							ep = ep and tempep;
							if(ep == 0) break;
						}
						if(ep) folunion[cur].insert(prod.first);
					}
				}
				
			}
		}
	}
	/*for(auto it : folunion){
		cout<<it.first<<":";
		for(auto it1 : it.second) cout<<it1<<" ";
		cout<<"\n";
	}*/
	bool flag = 0;
	while(1) {
		flag = 0;
		for(auto it : folunion) {
			for(auto it1 : it.second) {
				for(auto f : follow[it1]) {
					if(f!="epsilon" and follow[it.first].find(f)==follow[it.first].end()) {
						flag = 1;
						follow[it.first].insert(f);
					}
				}
			}
		}
		if(!flag) break;
	}
}
void printFollow() {
	cout<<"---------------------------------\n";
	cout<<"Symbol \t\tFOLLOW Set\n";
	cout<<"---------------------------------\n";
	for(auto it : follow){
		cout<<it.first<<" \t\t{ ";
		bool flag = 0;
		for(auto it1 : it.second) {
			if(flag) cout<<" , ";
			flag = 1;
			cout<<it1;
		}
		cout<<" }\n";
	}
	cout<<"---------------------------------\n\n";
}
map<string,int> tmap;
map<string, vector<vector<string>>> parsetable;
void buildParsingTable() {
	int len = terminals.size();
	vector<vector<string>> dum(len+1);
	for(auto it : nonterminals) {
		parsetable[it] = dum;
	}
	tmap["$"] = 0;
	int idx = 1;
	for(auto it : terminals) {
		tmap[it] = idx++;
	}
	first["epsilon"].insert("epsilon");
	for(auto prod : productions) {
		for(auto vec : prod.second) {
			bool ep = 1;
			set<string> tfset;
			for(int i=0;i<vec.size();i++) {
				bool tempep = 0;
				for(auto it : first[vec[i]]){
					if(it == "epsilon") tempep = 1;
					else tfset.insert(it);
				}
				ep = ep and tempep;
				if(ep==0) break;
			}
			//for terminals a in first, adding prod to M[A,a]
			for(auto t : tfset) {
				int idx = tmap[t];
				for(auto str : vec){
					parsetable[prod.first][idx].push_back(str);
				}
			}
			//first contains epsilon
			if(ep) {
				for(auto f : follow[prod.first]){
					int idx = tmap[f];
					for(auto str : vec) {
						parsetable[prod.first][idx].push_back(str);
					}
				}
			}
			
		}
		for(auto t : tmap){
			bool fl = 0;
			if(parsetable[prod.first][t.second].size() == 0){
				if(t.first == "$") {
					parsetable[prod.first][t.second].push_back("POP");
					fl = 1;
				} else {
					for(auto fol : follow[prod.first]){
						if(t.first == fol){
							parsetable[prod.first][t.second].push_back("POP");
							fl = 1;
							break;
						}
					}
				}
				if(fl==0) {
					if(first[prod.first].find(t.first) != first[prod.first].end()){
						parsetable[prod.first][t.second].push_back(startsymbol);
					}
					else {
						parsetable[prod.first][t.second].push_back("SCAN");
					}
				}
					
			}
		}
	}
	
}
void printParsingTable() {
	cout<<"---------------------------------\nNon-terminals\t | ";
	for(auto it : tmap) cout<<it.first<<" \t | "; cout<<"\n";
	cout<<"---------------------------------\n";
	for(auto it : parsetable) {
		cout<<it.first<<"\t\t | ";
		for(auto it2 : it.second) {
			for(auto it3 : it2) cout<<it3<<" ";
			cout<<"\t | ";
		}
		cout<<"\n";
	}
	cout<<"---------------------------------\n";
}

void parseTokens(string filename) {
	int len, idx, lines = 1;
	
	string str, tmp = "";
	vector<string> input;
	ifstream fi;
	fi.open(filename);
	if(!fi.is_open()) {
		cout<<"File not found!\n";
		return;
	}
	getline(fi,str);
	input.clear();
	tmp = "";
	str += "~";
	//cout<<str<<" ";
	for(auto ch : str) {
		if(ch == ' ' or ch == '~') {
			input.push_back(tmp);
			tmp = "";
		}
		else tmp += ch;
	}	
	
	input.push_back("$");
	len = input.size();
	idx = 0;
	stack<string> stck;
	stck.push("$");
	stck.push(startsymbol);
	int error = 0;
	for( ;idx < len and !stck.empty(); ) {
		string stop = stck.top();
		if(stop == input[idx]) {
			cout<<"Token number: "<<idx+1<<", Token: "<<input[idx]<<", Message: ";
			cout<<"Parsed successfully\n";
			idx++;
			stck.pop();
			continue;
		} 
		if(stop == "$") {
			error = 1;
			cout<<"Token number: "<<idx+1<<", Token: "<<input[idx]<<", Message: ";
			cout<<"ERROR! Top of stack is $, but does not match with input token\n";
			break;
		}
		if(terminals.find(stop)!=terminals.end()){
			error = 1;
			cout<<"Token number: "<<idx+1<<", Token: "<<input[idx]<<", Message: ";
			cout<<"ERROR! Front of input is a terminal, but does not match with top of stack\n";
			break;
		}
		int ntidx = tmap[input[idx]];
		vector<string> prod = parsetable[stop][ntidx];
		int plen = prod.size();
		if(prod[0] == "epsilon") {
			stck.pop();
			continue;
		}
		if(prod[0]=="POP"){
			stck.pop();
			error = 1;
			cout<<"Token number: "<<idx+1<<", Token: "<<input[idx]<<", Message: ";
			cout<<"ERROR! Parsing is started after popping from stack\n";
			continue;
		}
		if(prod[0]=="SCAN") {
			error = 1;
			cout<<"Token number: "<<idx+1<<", Token: "<<input[idx]<<", Message: ";
			cout<<"ERROR! Parsing is started after popping tokens from input\n";
			while(idx<len and prod[0]=="SCAN"){
				ntidx = tmap[input[idx]];
				prod = parsetable[stop][ntidx];
				plen = prod.size();
				idx++;
			}
			continue;
		}
		stck.pop();
		for(int i=plen-1;i>=0;i--)
			stck.push(prod[i]);
		
	} 
	cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
	cout<<"RESULT : ";
	if(idx < len or !stck.empty()) cout<<"Could not be parsed! ";
	else{
		cout<<"Parsed successfully! ";
		if(error) cout<<"Error is found. ";
		else cout<<"No Error is found. ";
	}
	cout<<"\n";
	lines++;
	fi.close();
}
int main() {
	string filename;
	cout<<"Input the filename which contains grammar : ";
	cin>>filename;
	buildProductions(filename); // grammar.txt
	//printProductions();
	removeLeftRecursion();
	cout<<"After removing left recursion, ";
	printProductions();
	computeFirst();
	printFirst();
	computeFollow();
	printFollow();
	buildParsingTable();
	//printParsingTable();
	cout<<"Input the filename which contains tokens to be parsed : ";
	cin>>filename;
	parseTokens(filename);  // output.txt
	return 0;
}
