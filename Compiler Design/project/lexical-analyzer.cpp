#include<bits/stdc++.h>
using namespace std;

#define p pair<string,string>
#define pp pair<p,int>
#define ppp pair<string,pp>
#define sett set<string>

sett kwords,relOp;
set<char> arthOp;
map<string,int> declare;
vector<ppp> symtable;
sett errormsg;
vector<string> line;

void scanKeyword(){
	ifstream fs("kywords.txt",ios::in);
	string s;
	if(fs.is_open())
		while(fs >> s)
			kwords.insert(s);
	fs.close();
}

void scanrelOperator(){
	ifstream fs("relop.txt",ios::in);
	string s;
	if(fs.is_open())
		while(fs >> s)
			relOp.insert(s);
	fs.close();
}

void scanarthOperator(){
	ifstream fs("arthop.txt",ios::in);
	char c;
	if(fs.is_open())
		while(fs >> c)
			arthOp.insert(c);
	fs.close();
}

bool is_key(string s){
	for(auto i=kwords.begin();i!=kwords.end();i++)
		if(s == (*i))
			return true;
	return false;
}

bool is_arthOperator(char c){
	for(auto i=arthOp.begin();i!=arthOp.end();i++)
		if(c == (*i))
			return true;
	return false;
}

bool is_alpha(char c){
	if(c >= '0' && c <= '9')
		return true;
	return false;
}

bool is_az(char c){
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	return false;
}

void scantokens(){
	ifstream f("input.pas",ios::in);
	ofstream ff("output.txt",ios::out);
	string s,str,type="None";
	bool dflag=false;
	int vcheck=0,vcheck1=0,vcheck2=0;
	int row=0,col=0;
	int count = 0;
	if(f.is_open() && ff.is_open()){
		while(getline(f,s)){
			int i=0; row++;
			line.push_back(s);
			cout<<"s = "<<s<<endl;
			for(;i<s.length();i++){
				if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
					str = "";
					while(i < s.length() && isalnum(s[i]))
						str += s[i],i++;
					if(is_key(str)){
						if(count) ff<<" ";
						count++;
						ff << str;
						if(str == "begin")
							vcheck++;
						if(str == "end")
							vcheck--;
						dflag = (str == "var" || str == "const" || str == "function")?true:false;
						if(str == "var" || str == "const" || str == "function" || str == "uses" || str == "program")
							type = str;
					}
					else{
						auto it = declare.find(str);
						if(dflag == false && vcheck > 0){
							if(it == declare.end()){
								errormsg.insert("input.pas:"+to_string(row)+": error: \'"+str+"\' was not declared in this scope\n\t"+s);
							}
							if(count) ff << " ";
							ff << "id";
							count++;
						}
						else if(it != declare.end()){
							errormsg.insert("input.pas:"+to_string(row)+
								": \'ERROR\': redeclaration of \'"+str+"\'\n\t"+s+
								"\ninput.pas:"+to_string((*it).second)+": \'NOTE\': \'"+str+
								"\' previously declared here\n\t"+line[(*it).second-1]);

						}
						else{	
							string ty = type;
							if(count) ff << " ";
							count++;
							ff << "id";
							int k=i; string tt=""; bool found = false;
							while(k < s.length() && (is_az(s[k]) || s[k] == ':' || s[k] == ',' || s[k] == ' ') ){
								if(s[k] == ':')
									found = true;
								if(found == true && is_az(s[k]))
									tt += s[k];
								else if(found == true && s[k] == ',')
									break;
								k++;
							}

							if(tt != "" && tt != "integer" && tt != "real" ){
								errormsg.insert("input.pas:"+to_string(row)+": \'ERROR\': \'"+tt+"\' was not declared in this scope\n\t"+s);
							}
							else{
								declare[str] = row;
								if(type == "program" || type == "uses" || type == "function" || type == "const")
									swap(tt,type);
								if(tt == "const")
									tt = "constant";
								if(type == "integer" || type == "real")
									swap(tt,type);
								symtable.push_back(make_pair(str,make_pair(make_pair(tt,type),row)));
							}
							type = ty;
						}
					}
					i--;
				}
				else if(is_alpha(s[i])){
					bool valid = true; string ss = "";
					while(i < s.length() && (isalnum(s[i]) || (s[i] == '.' && i+1 < s.length() && isalnum(s[i+1]) ) ) ){
						if(is_az(s[i]))
							valid = false;
						ss += s[i]; i++;
					}
					if(valid){
						if(count) ff << " ";
						count++;
						ff << "Numeral";
					}
					else{
						errormsg.insert("input.pas:"+to_string(row)+": \'ERROR\': expected unqualified-id before numeric constant\n\t"+s);
					}
					i--;
					str == "Numeral";
				}
				else if(is_arthOperator(s[i])) {
					if(count) ff << " ";
					count++;
					ff << s[i];
				}
				else{
					for(auto j=relOp.begin();j!=relOp.end();j++){
						string ss = (*j);
						if(ss.size() == 1 && ss[0] == s[i] && s[i+1] != '='){
							if(count) ff << " ";
							count++;
							ff << ss ;
							break;
						}
						else if(ss.size() > 1 && ss[0] == s[i] && ss[1] == s[i+1]){
							if(count) ff << " ";
							count++;
							ff << ss ,i++;
							break;
						}
					}	
				}
			}
			if(i != 0){
				ff << "";
				if(s[s.length()-1] == ')')
					continue;
				else if(is_key(str) && str != "end" && str != "integer" && str != "real" && s[s.length()-1] == ';')
					errormsg.insert("input.pas:"+to_string(row)+": \'ERROR\': unexpected \';\' after token "+str+"\n\t"+s);
				else if((!is_key(str) || str == "integer" || str == "real") &&
							(type != "function" || (vcheck > 0)) && s[s.length()-1] != ';')
					errormsg.insert("input.pas:"+to_string(row)+": \'ERROR\': expected \';\' after token "+str+"\n\t"+s);
			}
		}	
	}
	f.close();
	ff.close();
}

void show_symTable(){
	ofstream fo("symTable.txt",ios::out);
	if(!fo.is_open())
		return;
	cout<<"---------------------------SymbolTable---------------------------\n";
	cout<<"Identifier\tTypeCasting\tDeclaration\tRow\n";
	cout<<"-----------------------------------------------------------------\n";
	for(auto i=0;i<symtable.size();i++){		
		cout<<"\t"<<symtable[i].first<<"\t"<<symtable[i].second.first.first<<"\t\t";
		cout<<symtable[i].second.first.second<<"\t\t"<<symtable[i].second.second<<endl;

		fo << symtable[i].first<<" "<<symtable[i].second.first.first<<" "<<symtable[i].second.first.second<<" "<<symtable[i].second.second<<endl;;
	}
	fo.close();
	cout<<"-----------------------------------------------------------------\n";
}

void show_error(){
	ofstream fo("output.txt",ios::out);
	if(!fo.is_open())
		return;
	cout<<"\t\tCompilation ERROR\n";
	cout<<"----------------------------------------------------\n";
	cout<<"Error Declaration and its row number.\n";
	cout<<"----------------------------------------------------\n";
	for(auto i=errormsg.begin();i!=errormsg.end();i++){
		cout<<(*i)<<endl;
		fo << (*i) <<endl;
	}
	fo.close();
	cout<<"----------------------------------------------------\n";
}

int main(){
	scanKeyword();
	scanrelOperator();
	scanarthOperator();	
	scantokens();
	if(errormsg.size() == 0)
		show_symTable();
	else{
		show_error();
	}
}
