#include<stdio.h>
#include<math.h>
double fun(double x){ //abs not working ,fabs giving NAN
    return exp(-x)-3*log(x);
}
double mod(double x){
	if (x<=0){
		return -1*x;
	}
	else{
		return x;
	}
}

double regula(double first,double second,double error)
{
    double mid_second,mid_first,f_mid,f_first,f_second,abserr=0,abserr0,relerr=0,order=0;
    f_first=fun(first);
	f_second=fun(second);
    int i=1;
	FILE * data=fopen("data.txt","w");
	mid_first=(first*f_second-second*f_first)/(f_second-f_first);
	f_mid=fun(mid_first);
	fprintf(data,"Itr	lower	upper	midpoint	fun(midpoint)	abserror	relerror	order\n");
	fprintf(data,"%2d	%.6lf	%.6lf	%.6lf	%.6lf	%.6lf	%.6lf	%.6lf\n",i++,first,second,mid_first,f_mid,abserr,relerr,order);
       	while(second-first > error)
                {
                 if(f_first*f_mid<0)
                     second=mid_first;
                 else if(f_first*f_mid>0)
                    first=mid_first;
                 else
                    break;
                 	mid_second=(first*f_second-second*f_first)/(f_second-f_first);
                    f_mid=fun(mid_second);
                    abserr=mid_second-mid_first;
                    relerr=abserr0/mid_first;
                    order=log(mod(abserr0))/log(mod(abserr));
                    abserr0=abserr;
                    mid_first=mid_second;
                    fprintf(data,"%2d	%.6lf	%.6lf	%.6lf	%.6lf	%.6lf	%.6lf	%.6lf\n",i++,first,second,mid_first,f_mid,abserr,relerr,order);// writing the data in the file
                }
                fclose(data);
	return mid_second;
}

int main(void){
        double first,second,f_first,f_second,ans,error;
        printf("Enter the percision\n");
        scanf("%lf",&error);
        do{
                printf("Enter initial lower and upper bound for the root");
                scanf("%lf%lf",&first,&second);
                f_first=fun(first);
                f_second=fun(second);
        }while(f_first*f_second>=0);
        ans=regula(first,second,error);
        printf("\nThe root is :%lf",ans);
        return 0;
}
