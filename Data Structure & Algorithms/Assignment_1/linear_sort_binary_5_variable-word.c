#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
       int integer[5];
       float decimal[5];
       char words[5][20];
};

void linearsearch(struct data, int ,float ,char*);
void sort(struct data*);
void binarysearch(struct data ,int,float,char*);

int main(){
    struct data s;
    int t,a;
    float b;
    char c[20];
    int i,j;
    printf("ENTER any 5 integer:\n");
    for(j=0;j<5;j++){
        scanf("%d",&s.integer[j]);
    }
    printf("\n");
    printf("ENTER any 5 floating no.:\n");
    for(j=0;j<5;j++){
        scanf("%f",&s.decimal[j]);
    }
    printf("\n");
    printf("ENTER a string of 5 words:\n");
    for(i=0;i<5;i++){
        scanf("%s",s.words[i]);
    }
    printf("\n");
    printf("Input the searching integer,floating and words\n");
    scanf("%d",&a);
    scanf("%f",&b);
    scanf("%s",c);
    linearsearch(s,a,b,c);
    sort(&s);             //Selection sort.
    binarysearch(s,a,b,c);
    return 0;
}

void linearsearch(struct data m,int x,float y,char z[20]){
    int i,k;
    int flag1,flag2,flag3;  flag1=flag2=flag3=0;
    for(i=0;i<5;i++){
        if(x == m.integer[i]){
            printf("The integer %d is at position no. %d\n",x,i+1);
            flag1=1;
            break;
        }
    }
    if(!flag1)
    printf("YOUR integer was not found\n");
    for(i=0;i<5;i++){
        if(y == m.decimal[i]){
            printf("The floating number %f is at position no. %d\n",y,i+1);
            flag2= 1;
            break;
        }
    }
    if(!flag2)
    printf("Your floating no. was not found\n");
    for(k=0;k<5;k++){
        if(strcmp(m.words[k],z)==0){
            printf("The word %s is at position no. %d\n",z,k+1);
            flag3 = 1;
            break;
        }
    }
    if(!flag3)
        printf("Your words was not found.\n");

 }

void sort(struct data *x){
	 int i,j,temp,min,p;
	 for(j=0;j<4;j++){
        min = (*x).integer[j];
        p = j;
	    for(i=j+1;i<5;i++){
            if((*x).integer[i] < min){
	 		    min = (*x).integer[i];
	 		    p = i;
            }
        }
        temp = (*x).integer[j];
        (*x).integer[j]= (*x).integer[p];
        (*x).integer[p]= temp;
     }

     float tot,minf;
     for(j=0;j<4;j++){
	    minf =(*x).decimal[j];
	    p = j;
	    for(i=j+1;i<5;i++){
	 		if((*x).decimal[i] < minf){
                minf = (*x).decimal[i];
                p = i;
	 		}
        }
        tot = (*x).decimal[j];
       (*x).decimal[j]= (*x).decimal[p];
        (*x).decimal[p]= tot;
     }


     char ten[20];
     for(j=0;j<5;j++){
        for(i=0;i<5-j-1;i++){
	 		if(strcmp((*x).words[i], (*x).words[i+1])>0){
	 		    strcpy(ten,(*x).words[i]);
	 		    strcpy((*x).words[i],(*x).words[i+1]);
	 		    strcpy((*x).words[i+1],ten);
	 		}
        }
     }

}
void binarysearch(struct data x,int m,float n,char o[20]){
	int i,first,last,middle;
	int found1 = 0;
	first = 0;
	last = 4;
	middle = (first+last)/2;
    while(first<=last){
        middle = (first+last)/2;
	 	if(m < x.integer[middle])
	 	    last = middle-1;
        else if(m > x.integer[middle])
	 	    first = middle  + 1;
	 	else if(m == x.integer[middle]){
            found1 = 1;
            break;
        }
    }
    if(found1)
        printf("%d is at location %d\n", m,middle+1);
    else
        printf("Not found!! %d is not in the list\n",m);

    int found2;
    first = found2 = 0; last = 4;middle = (first+last)/2;
    while(first<=last){
        middle = (first+last)/2;
	 	if(n < x.decimal[middle] )
	 	    last = middle-1;
        else if(n > x.decimal[middle])
	 	    first = middle + 1;
	 	else if(n == x.decimal[middle]){
            found2 = 1;
	 	    break;
        }
    }
    if(found2 != 0)
        printf("%f is at location %d\n", n,middle+1);
    else
        printf("Not found!! %f is not in the list\n",n);

    int found3;
    first= found3 = 0;last = 4; middle=(first+last)/2;
    while(first<=last){
        middle = (first+last)/2;
	 	if(strcmp(o,x.words[middle]) < 0)
	 	    last = middle-1;
	 	else if(strcmp(o,x.words[middle]) > 0)
            first = middle +1;
        else if(strcmp(o,x.words[middle]) == 0){
            found3 =1;
	 	    break;
        }
    }
	if(found3)
	    printf("%s is at location %d\n", o,middle+1);
    else
        printf("Not found!! %s is not in the list\n",o);
}
