# include <stdio.h>
# include <stdlib.h>
# define Maxlen 20

char *String[10];
int Count=0;

void  readstr(char **str){
	*str=(char *)(malloc(Maxlen*sizeof(char)));
	printf("Enter String(Maxlen=%d):",Maxlen-1);
	scanf("\n%[^\n]s",*str);

}

int lenstr(char * str){
	int i=0;
	while(str[i]!='\0'){
		i++;
	}
	return i;
}

int compstr(char * str1,char * str2){
	int i=0;
	while(str1[i]!='\0' && str2[i]!='\0'){
		if(str1[i]!=str2[i]){
 			return str1[i]-str2[i];
		}
		i++;
	}
	if(str1[i]=='\0' && str2[i]=='\0'){
		return 0;
	}
	else if(str1[i]=='\0' && str2[i]!='\0'){
		return -1;
	}
	else{
		return 1;
	}
}

char * concatstr(char * str1,char *str2){
	char * str;
	int len1=lenstr(str1),len2=lenstr(str2);
	str=(char *)(malloc((len1+len2+1)*sizeof(char)));
	int i=0,j=0;
	while(str1[j]!='\0'){
		str[i]=str1[j];
		i++;
		j++;
	}
	j=0;
	while(str2[j]!='\0'){
		str[i]=str2[j];
		i++;
		j++;
	}
	str[i]='\0';
	return str;
}

char * rmwsp(char *str){
	char *strsp;
	int len=lenstr(str),i=0,j=0;
	strsp=(char *)(malloc(len * sizeof(char))); 
	while(str[i]!='\0'){
		if(str[i]!=' '){
			strsp[j]=str[i];
			j++;
		}
		i++;
	}
	strsp[i]='\0';
	return strsp;
}

int countword(char * str){
	int i=0,count=0;
	while(str[i]!='\0'){
		if(str[i]==' '){
			count++;
		}
		i++;
	}
	return count+1;
}

int issub(char *str1,char *str2){
	int i,j,k,len1=lenstr(str1),len2=lenstr(str2),flag=0;
	if(len1>len2){
		return 0;
	}
	else{
		for(i=0;i<len2;i++){
			k=i;
			flag=1;
			for(j=0;j<len1;j++){
				if(str2[k]!=str1[j]){
					flag=0;
					break;
				}
				k++;
			}
			if(flag){
				return 1;
			}
		}
		return 0;
	}
}


char * revstr(char * str){
	int i,len=lenstr(str);
	char * revstr;
	revstr=(char *)(malloc((len+1)*sizeof(char)));
	for(i=0;i<len;i++){
		revstr[i]=str[len-i-1];
	}
	revstr[len]='\0';
	return revstr;
}


void replace(char ** str,char oldchar,char newchar){
	int i=0,count=0;
	while(*str[i]!='\0'){
		if(*str[i]==oldchar){
			*str[i]=newchar;
			count++;
		}
		i++;
	}
	printf("%d charecters replaced\n",count);
}

void copystr(char *str1,char *str2){
	int i=0;
	while(str2[i]!='\0'){
		str1[i]=str2[i];
		i++;
	}
	str1[i]='\0';
}

int main(){
	int choice,index1,index2,value;
	while(1){
		printf("Enter Choice\n--------------------\n0.Print List Of Strings\n");
		printf("1.Create A String\n2.Find Length Of String\n3.Compare 2 Strings\n4.Concatenate 2 Strings\n5.Copy 1 String into another\n");
		printf("6.Search for a substring\n7.Find Frequency Of Charecters\n8.Change Case Of String\n9.Replace any letter with another in a string\n");
		printf("10.Count Number Of Words In the String\n11.Remove Space from String\n12.Reverse A String\n13.Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				if(Count==0){
					printf("List Is Empty\n");
				}
				else{
					int i=0;
					while(i<Count){
						printf("%d . %s\n",i,String[i]);
						i++;
					}
				}
				break;
			case 1:
				readstr(&String[Count]);
				Count++;
				printf("%s\n",String[0]);
				break;
			case 2:
				printf("Enter i to print length of Str[i]\n");
				scanf("%d",&index1);
				if(index1<Count){
					printf("Length = %d\n",lenstr(String[index1]));
				}
				else{
					printf("Index Out Of Range\n");
				}
				break;
			case 3:
				printf("Enter i, j to compare Str[i] & Str[j]\n");
				scanf("%d %d",&index1,&index2);
				if(index1<Count && index2<Count){
					value=compstr(String[index1],String[index2]);
					printf("%d\n",value);
					if(value==0){
						printf("Both Are Equal\n");
					}
					else if (value>0){
						printf("%s > %s\n",String[index1],String[index2]);
					}
					else{
						printf("%s < %s\n",String[index1],String[index2]);

					}
				}
				else{
					printf("Index Out Of Range\n");
				}
				break;
			case 4:
                                printf("Enter i, j to concatinate Str[i] & Str[j]\n");
                                scanf("%d %d",&index1,&index2);
                                if(index1<Count && index2<Count){
					int l1=lenstr(String[index1]),l2=lenstr(String[index2]);
					String[Count]=(char *)(malloc((l1+l2+1)*sizeof(char)));
                                        copystr(String[Count],concatstr(String[index1],String[index2]));
					Count++;
					printf("The Concatinated String is :\n%s\n",String[Count-1]);
                                }
                                else{
                                        printf("Index Out Of Range\n");
                                }
				break;
			case 5:
                                printf("Enter i, j to copy Str[j] in Str[i]\n");
                                scanf("%d %d",&index1,&index2);
                                if(index1<Count && index2<Count){
                                        copystr(String[index1],String[index2]);
                                        printf("Copied %s into Str[%d]\n",String[index2],index1);
                                }
                   	   	else{
                                        printf("Index Out Of Range\n");
                                }
				break;
			case 6:
                                printf("Enter i, j to find if Str[i] is Substring of Str[j]\n");
                                scanf("%d %d",&index1,&index2);
                                if(index1<Count && index2<Count){
                                        if(issub(String[index1],String[index2])){
						printf("Substring\n");
					}
					else{
                                        	printf("Not A Substring\n");
                               		}
				 }
                                else{
                                        printf("Index Out Of Range\n");
                                }
				break;
			case 9:
                                printf("Enter i to replace in Str[i]\n");
                                scanf("%d",&index1);
                                if(index1<Count){
					char oldchar,newchar;
                                        printf("Enter the charecter to be replaced :");
					scanf("%c",&oldchar);
					printf("enter the new charecter to be replaced by :");
					scanf("%c",&newchar);
					replace(&String[index1],oldchar,newchar);
                                        printf("The Changed String is :\n%s\n",String[index1]);
                                }
                                else{
                                        printf("Index Out Of Range\n");
                                }
				break;
			case 10:
                                printf("Enter i to find number of words in Str[i]\n");
                                scanf("%d",&index1);
                                if(index1<Count){
                                        printf("The number of words in %s is %d",String[index1],countword(String[index1]));
                                }
                                else{
                                        printf("Index Out Of Range\n");
                                }
                                break;
			case 11:
                                printf("Enter i to remove spaces in Str[i]\n");
                                scanf("%d",&index1);
                                if(index1<Count){
                                     	copystr(String[index1],rmwsp(String[index1]));
                                        printf("The Changed String is :\n%s\n",String[index1]);
                                }
                                else{
                                        printf("Index Out Of Range\n");
                                }
                                break;

			case 12:
                                printf("Enter i to reverse Str[i]\n");
                                scanf("%d",&index1);
                                if(index1<Count){
                                        copystr(String[index1],revstr(String[index1]));
                                        printf("The Reversed String is :\n%s\n",String[index1]);
                                }
                                else{
                                        printf("Index Out Of Range\n");
                                }
                                break;


			case  13:
				exit(0);
			}
			}
			free(String);
			return 0;
}
