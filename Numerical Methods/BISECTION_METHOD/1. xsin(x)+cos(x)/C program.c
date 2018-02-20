# include  <stdio.h>
# include <math.h>
double fun(double x){ //abs not working ,fabs giving NAN
    return x*sin(x)+cos(x);
}
double mod(double x){
	if (x<=0){
		return -1*x;
	}
	else{
		return x;
	}
}


double bisection(double first, double second,double error){
    double mid_second,mid_first,f_mid,f_first,f_second,abserr=0,abserr0,relerr=0,order=0;
	f_first=fun(first);
	f_second=f(second);
    int i=1;
	FILE * data=fopen("data.txt","w");
	mid_first=(first+second)/2;
	f_mid=f(mid_first);
    	fprintf(data,"Itr	lower	upper	mid	fun(midpoint)	abserror	relerror	order\n");
	fprintf(data,"%2d	%.6lf	%.6lf	%.6lf	%.6lf	%.6lf	%.6lf	%.6lf\n",i++,first,second,mid_first,f_mid,abserr,relerr,order);
       	while(second-first > error){
		if(f_mid*f_first>0){
			first=mid_first;
			f_first=fun(a);
		}
		else if(f_mid*f_second>0){
			second=mid_first;
			f_second=fun(second);
		}
		else{
			break;
		}
		mid_second=(first+second)/2;
		f_mid=fun(mid_second);
		abserr=mid_second-mid_first;
		relerr=abserr0/mid_second;
		order=log(mod(abserr0))/log(mod(abserr));
		abserr0=abserr;
		mid_first=mid_second;
		fprintf(data,"%2d	%.6lf	%.6lf	%.6lf	%.6lf	%.6lf	%.6lf	%.6lf\n",i++,first,second,mid_second,f_mid,abserr,relerr,order);// writing the data in the file
	}
	fclose(data);
	return mid_second;
}


int main(void){
        double first, second,f_first,f_second,root,error;
        printf("Enter the percision\n");
        scanf("%lf",&error);
        do{
                printf("Enter lower by upper bound");
                scanf("%lf%lf",&a,&b);
                f_first=fun(first);
                f_second=fun(second);
        }while(f_first*f_second>=0);
        root=bisection(first,second,error);
        printf("\nThe root is :%lf",root);
        return 0;
}

