#include<bits/stdc++.h>
using namespace std;

class treenode	{ // node structure
	public:
	char alpha;		
	int pos;
	bool nullable;
	vector<int> fpos,lpos;
	treenode *left,*right;
	treenode() {
		
	}
	treenode(char ch, int p) {
		alpha = ch;
		pos = p;
		left = right = NULL;
		fpos.clear();
		lpos.clear();
	}
};
bool isOperator(char ch){ //to check if character is an operator
	if(ch == '|' || ch == '/'  || ch == '*' || ch == '.')
		return true;
	return false;

}
void printVector(vector<int> v){
	for(int i = 0 ; i < v.size();i++) cout<<v[i]<<" ";
}
void postOrder(treenode *root) {		// For Traversing The treenode
	if(!root) return;
	string s("	    	");
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->alpha<<s<<root->pos<<s<<root->nullable<<s<<"{ ";printVector(root->fpos);cout<<" }"<<s<<s<<"{ ";printVector(root->lpos);cout<<" }"<<endl;
}
int posIndex,followPosIndex;		// for finding  position and follow position index
vector<int> followPos[30],Dstate[30];	// followPos store the follow position and Dstate store total no of Dstates
map<int,char> intMapsChar;	
set<char> charSet;
vector<int> operator +(vector<int> a,vector<int> b) {	// operator Overloading for vector Additions
	a.insert(a.end(),b.begin(),b.end());
	sort(a.begin(),a.end());		// required for making unique element
	a.erase(unique(a.begin(),a.end()),a.end()); //for finding unique element within vector
	return a;
}
void buildDFA(treenode *root,string input){	// Finding DFA
	int num_state = 1,cur_state = 1;
	char ch = 'A';
	vector<int> temp;
	map< vector<int> , char> out_state;	// Out_state used for removing Redundant States
	map< vector<int> , map< char , vector<int> > >  re_dfa;  //for Storing The final DFA Dstate
	Dstate[num_state++] = root->fpos;	// total number of Dstate , Starting with root's First position
	out_state[root->fpos] = ch++ ;
	while(1){
		for(int i = 0 ; i < input.size() ; i++){
			for(int j = 0 ; j < Dstate[cur_state].size() ; j++){
				if(intMapsChar[Dstate[cur_state][j]] == input[i])
					temp = temp + followPos[Dstate[cur_state][j] ];
				if(out_state[temp] == 0 && temp.size() > 0){
					out_state[temp] = ch++;
					Dstate[num_state++] = temp; 
				}
			}
			re_dfa[Dstate[cur_state]][input[i]] = temp;
			temp.clear();
		}
		if(cur_state == num_state - 1)
			break;
		cur_state++;
	}
	cout<<"\n\nDeteministic Finite Automata :\n\n"; // for Displaying the Final DFA states
	for(auto a : re_dfa){
		cout<<"{ "; 
		for(auto b : a.first)
			cout<<b<<" "; 
		cout<<" } ";
		for(auto b : a.second){
			cout<<" on input: "<<b.first<<" { ";
			for(auto c:b.second)
				cout<<c<<" ";
			cout<<" } ";
		}
		cout<<endl;
	}
}
int main()
{
	treenode *tnode;
	stack<treenode *> s;
	string str,sp("		"),input;
	cout<<"\nInput a Regular Expression (in postfix form): ";
	cin>>str;
	for(int i = 0 ; i < str.size() ; i++){
		if(!isOperator(str[i])){
			posIndex++;
			if(str[i] != '#'){
				followPosIndex++;
				intMapsChar[followPosIndex] = str[i];
				charSet.insert(str[i]);	
			}
			tnode = new treenode(str[i],posIndex); //create(str[i],0);
			tnode->nullable = false;
			tnode->fpos.push_back(posIndex);tnode->lpos.push_back(posIndex);			
		}
		else if(str[i] == '*'){
			tnode = new treenode(str[i],0); //create(str[i],0);
			tnode->left = s.top() , s.pop();
			tnode->nullable = true;
			tnode->fpos = tnode->left->fpos;
			tnode->lpos = tnode->left->lpos;
			for(int i = 0 ; i < tnode->lpos.size() ; i++)
				followPos[tnode->lpos[i]] = followPos[tnode->lpos[i]] + tnode->fpos;
		}
		else if(str[i] == '.'){
			tnode = new treenode(str[i],0); //create(str[i],0);
			tnode->right = s.top() , s.pop();
			tnode->left = s.top() , s.pop();
			tnode->nullable = tnode->right->nullable && tnode->left->nullable;
			if(tnode->left->nullable)
				tnode->fpos = tnode->right->fpos + tnode->left->fpos;
			else
				tnode->fpos = tnode->left->fpos;
			if(tnode->right->nullable)
				tnode->lpos = tnode->right->lpos + tnode->left->lpos;
			else
				tnode->lpos = tnode->right->lpos;
			for(int i = 0 ; i < tnode->left->lpos.size() ; i++)
				followPos[tnode->left->lpos[i]] = followPos[tnode->left->lpos[i]] + tnode->right->fpos;
		}
		else{
			tnode = new treenode(str[i],0); //create(str[i],0);
			tnode->right = s.top() , s.pop();
			tnode->left = s.top() , s.pop();
			tnode->nullable = tnode->right->nullable && tnode->left->nullable;
			tnode->fpos = tnode->right->fpos + tnode->left->fpos;
			tnode->lpos = tnode->right->lpos + tnode->left->lpos;
		}
		s.push(tnode);		
	}
	for(auto t:charSet)
		input.push_back(t);			

	cout<<"\n-----------------------------------------------------------------------------------------";
	cout<<"\n\nNODE"<<sp<<"Position"<<"       "<<"Nullable"<<"        "<<"First position"<<"		   "<<"Last position"<<endl;
	postOrder(tnode);
	cout<<"\n-----------------------------------------------------------------------------------------";
	cout<<"\n\nFollow Position Table :"<<endl;
	for(int i = 1 ; i <= followPosIndex ; i++)	{// Display of Follow Position
		cout<<i<<sp<<intMapsChar[i]<<sp<<"{ ";
		for(int j = 0; j < followPos[i].size() ; j++){
			cout<<followPos[i][j]<<" ";
		}
		cout<<" }\n";
	}
	cout<<"\n-----------------------------------------------------------------------------------------";
	buildDFA(tnode,input);
	cout<<"\n-----------------------------------------------------------------------------------------";
	return 0;

}