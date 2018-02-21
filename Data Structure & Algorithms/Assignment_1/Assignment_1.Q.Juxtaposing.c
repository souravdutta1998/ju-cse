#include <stdio.h>
#include <string.h>
#include<math.h>
#define Max 30

int valid(char s[]){
    int i,size=strlen(s);
    for(i=0;i<size;i++){
        if(!((s[i]>=65 && s[i]<=90) || s[i]==32))
            return 0;
    }
    return 1;
}
int main(){
    char name[Max];
    int nm[Max];
    int sum[Max];
    char *ptr;
    int j,i,x,k=0;
    ptr = name;
    do{
        printf("Type your name(In capital Letter): \n");
        scanf("%[^\n]s",name);
        if(!valid(name))
            printf("Enter your name only in capital letter.\n");
        else
            break;
    }
    while(1);
    for(i=0;*ptr != '\0';ptr++,i++){
        if(name[i] == 32)
            continue;
        else{
            //name[i] = (name[i] - 'A');
            x = name[i];
            nm[k++] = x/10;
            nm[k++] = x%10;
        }
        //printf(" %d ",nm[i]);
 	}
 	nm[k] = '\0';
 	printf("Converted long integer is : ");
 	for(j=0;j<k;j++){
        printf("%d",nm[j]);
    }
    printf("\n");
    printf("Long integer is now divided into two integer:\n");
    printf("First Half: ");
    for(i=0;i<k/2;i++){
        printf("%d",nm[i]);
    }
    printf("\nAnd second Half: ");
    for(i=k/2;i<k;i++){
        printf("%d",nm[i]);
    }
    printf("\nAnd summed so that Result after Summation is :\n");
    int p,r=0;
    for(i=k/2-1,j = k-1,p=0;i>=0;i--,j--){
        sum[p++] = (nm[i]+nm[j]+r)%10;
        r = (nm[i]+nm[j]+r)/10;
    }
 	sum[p++] = r;
    sum[p] = '\0';
 	long int y=0;
    for(i=0;i<p;i++){
        y += sum[i]*pow(10,i);
    }
    long int d = y %3419 ;
    printf("--> %ld.\n",y);
    printf("If it is divided by Prime 3419, ");
    printf("Remainder is: %ld",d);

    return 0;
}
