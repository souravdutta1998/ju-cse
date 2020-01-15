#include<iostream>
#include<fstream>
#include<set>
using namespace std;
set<char> punctuationSet, operatorSet;
set<string> keywordSet, symbolTable;

//Helper function to retrieve and store keywords in set, stored in "keywords.txt"
void buildKeywordSet() {
	ifstream fi("keywords.txt", ios::in);
	string str;
	if(fi.is_open())
		while(fi >> str)
			keywordSet.insert(str);
	fi.close();
}

//Helper function to retrieve and store punctuations in set, stored in "punctuations.txt"
void buildPunctuationSet() {
	ifstream fi("punctuations.txt", ios::in);
	char ch;
	if(fi.is_open())
		while(fi >> ch)
			punctuationSet.insert(ch);
	fi.close();
}

//Helper functions to retrieve and store operators in set, stored in "operators.txt"
void buildOperatorSet() {
	ifstream fi("operators.txt", ios::in);
	char ch;
	if(fi.is_open()) 
		while(fi >> ch) 
			operatorSet.insert(ch);
	fi.close();
}

//Retrieve each line from "input.c" input file, 
//and find if current character is either a operator or punctuation
//and check for keyword existence
void computeTokens() {
	ifstream fi("input.c", ios::in);
	string str;
	int row = 1, col, startidx, endidx;
	string token, type;
	if(fi.is_open()) {
		cout<<"----------------------------------------------------------------------\n";
		printf("\tToken \t\tType \t\tRow \t\tColumn \n");
		cout<<"----------------------------------------------------------------------\n";
		while(getline(fi,str)) {
			startidx = -1;
			for(int i=0;i<=str.size();i++) {
				if(i==str.size() || str[i]==' ') {
					if(startidx!=-1) {
						token = str.substr(startidx,endidx-startidx+1);
						col = startidx+1;
						if(keywordSet.find(token) != keywordSet.end()) {
							type = "keyword";
						}
						else {
							type = "identifier";
							symbolTable.insert(token);
						}
						cout<<"\t"<<token<<"\t\t"<<type<<" \t"<<row<<"\t"<<"\t"<<col<<"\n";
					}
					startidx=-1;
				}
				else if(str[i]=='\t') continue;
				else if(operatorSet.find(str[i]) != operatorSet.end()) {
					if(startidx!=-1) {
						token = str.substr(startidx,endidx-startidx+1);
						col = startidx+1;
						if(keywordSet.find(token) != keywordSet.end()) {
							type = "keyword";
						}
						else {
							type = "identifier";
							symbolTable.insert(token);
						}
						cout<<"\t"<<token<<"\t\t"<<type<<" \t"<<row<<"\t"<<"\t"<<col<<"\n";
					}
					token = str[i];
					col = i+1;
					type = "operator";
					cout<<"\t"<<token<<"\t\t"<<type<<" \t"<<row<<"\t"<<"\t"<<col<<"\n";
					startidx=-1;
				}
				else if(punctuationSet.find(str[i]) != punctuationSet.end()) {
					if(startidx!=-1) {
						token = str.substr(startidx,endidx-startidx+1);
						col = startidx+1;
						if(keywordSet.find(token) != keywordSet.end()) {
							type = "keyword";
						}
						else {
							type = "identifier";
							symbolTable.insert(token);
						}
						cout<<"\t"<<token<<"\t\t"<<type<<" \t"<<row<<"\t"<<"\t"<<col<<"\n";
					}
					token = str[i];
					col = i+1;
					type = "punctuation";
					cout<<"\t"<<token<<"\t\t"<<type<<" \t"<<row<<"\t"<<"\t"<<col<<"\n";
					startidx=-1;
				}
				else if(startidx==-1) startidx=endidx=i;
				else endidx=i;
			}
			row++;
		}
		cout<<"----------------------------------------------------------------------\n";
	}
	fi.close();
}

//Store all user-defined variables in "symboltable.txt"
void generateSymbolTableFile() {
	ofstream fo("symboltable.txt",ios::out | ios::trunc);
	if(fo.is_open()) 
		for(auto str : symbolTable) 
			fo << str << "\n";
	fo.close();
}
int main() {
	buildKeywordSet();
	buildPunctuationSet();
	buildOperatorSet();
	computeTokens();
	generateSymbolTableFile();
	
	//clearing all the sets
	keywordSet.clear();
	operatorSet.clear();
	punctuationSet.clear();
	return 0;
}