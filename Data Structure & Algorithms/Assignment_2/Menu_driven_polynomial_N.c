#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max 10

extern int cant;
struct term{
 int exp;
 double coef;
};
struct term terms[max];
struct p{
   int maxt;
   struct term terms[max];
};
struct p polynomials[max];
int cant = 0;
void read_poly(int index){
     int i=0;
    while(1){
       scanf("%lf %d",&polynomials[index].terms[i].coef,&polynomials[index].terms[i].exp);
        if(polynomials[index].terms[i].coef == 0 && polynomials[index].terms[i].exp == 0){
            break;
        }
       i++;
    }
    polynomials[index].maxt = i;
    cant++;
}
void print_poly(int index){
     int j,x;
     x = polynomials[index].maxt;
     for(j=0;j<x;j++){
        if(polynomials[index].terms[j].coef != 0 && polynomials[index].terms[j].exp != 0)
        printf("%lf * x^%d + ",polynomials[index].terms[j].coef,polynomials[index].terms[j].exp);
        else if(polynomials[index].terms[j].exp == 0)
            printf("%lf",polynomials[index].terms[j].coef);
        else if(polynomials[index].terms[j].coef == 0){
            printf(" 0*(x^%d) + ",polynomials[index].terms[j].exp);
        }
        else{
            continue; }
     }
}
int is_zero(int index){
    int i,count=0;
    for(i=0;i<polynomials[index].maxt;i++){
      if(polynomials[index].terms[i].coef == 0){
        count++;
      }
    }
    if(count == polynomials[index].maxt)
        return 1;
    else
        return 0;
}
int get_deg(int index){
    int j,deg;
 if(is_zero(index))
        deg = INT_MIN;
 else{
    for(j =0;j<polynomials[index].maxt;j++){
      if(polynomials[index].terms[j].coef != 0){
        deg = polynomials[index].terms[j].exp;
         break;
        }
      else{
        continue;
        }
    }
  }
 return deg;
}
void mult_poly_const(int index,double k){
    int i,j=0;
    for(i=0;i<polynomials[index].maxt;i++){
       polynomials[cant].terms[j].coef = (k * polynomials[index].terms[i].coef);
        polynomials[cant].terms[j].exp = polynomials[index].terms[i].exp;
       j++;
      }
      polynomials[cant].maxt = j;
    printf("The new polynomial is :\n");
    print_poly(cant);
    cant++;
}
void add_poly(int a,int b){
    int i=0,j=0,k=0;
    while(i <polynomials[a].maxt && j< polynomials[b].maxt){
        if(polynomials[a].terms[i].exp == polynomials[b].terms[j].exp){
            polynomials[cant].terms[k].coef = polynomials[a].terms[i].coef + polynomials[b].terms[j].coef;
            polynomials[cant].terms[k].exp = polynomials[b].terms[j].exp;
            i++;  j++; k++;
        }
        else if(polynomials[a].terms[i].exp < polynomials[b].terms[j].exp){
            polynomials[cant].terms[k].coef = polynomials[b].terms[j].coef;
             polynomials[cant].terms[k].exp = polynomials[b].terms[j].exp;
            j++; k++;
        }
        else if(polynomials[a].terms[i].exp > polynomials[b].terms[j].exp){
            polynomials[cant].terms[k].coef = polynomials[a].terms[i].coef;
            polynomials[cant].terms[k].exp = polynomials[a].terms[i].exp;
            i++; k++;
        }
    }
    polynomials[cant].maxt = k;
    printf("The new polynomial is :\n");
    print_poly(cant);
    cant++;
}
void sub_poly(int a, int b){
    int i=0,j=0,k=0;
    while(i <polynomials[a].maxt && j< polynomials[b].maxt){
        if(polynomials[a].terms[i].exp == polynomials[b].terms[j].exp){
            polynomials[cant].terms[k].coef = polynomials[a].terms[i].coef - polynomials[b].terms[j].coef;
            polynomials[cant].terms[k].exp = polynomials[b].terms[j].exp;
            i++;  j++; k++;
        }
        else if(polynomials[a].terms[i].exp < polynomials[b].terms[j].exp){
            polynomials[cant].terms[k].coef = polynomials[a].terms[j].coef;
            polynomials[cant].terms[k].exp = - polynomials[b].terms[j].exp;
            j++; k++;
        }
        else if(polynomials[a].terms[i].exp > polynomials[b].terms[j].exp){
            polynomials[cant].terms[k].coef = polynomials[a].terms[i].coef;
            polynomials[cant].terms[k].exp = polynomials[a].terms[i].exp;
            i++; k++;
        }
    }
    polynomials[cant].maxt = k;
    printf("The new polynomial is :\n");
    print_poly(cant);
    cant++;
}
void mult_poly(int x,int y){
   int m = get_deg(x) + get_deg(y);
   int a,b;
   int k=0,i = m;
  while(i>=0){
       int d = 0;
    for(a=0;a<polynomials[x].maxt;a++){
     for(b=0;b<polynomials[y].maxt;b++){
        if(polynomials[x].terms[a].exp + polynomials[y].terms[b].exp == i){
           d = d + polynomials[x].terms[a].coef * polynomials[y].terms[b].coef;
         }
       }
    }
    polynomials[cant].terms[k].coef = d;
    polynomials[cant].terms[k].exp = i;
            k++;
    i--;
   }
    polynomials[cant].maxt = k;
    printf("The new polynomial is :\n");
    print_poly(cant);
    cant++;
}
int main(){
   int choice;
    while(1){
        // printing the options
        printf("\nCurrent index(starts with 0) = %d\n", cant);
        printf("1. Enter a polynomial\n");
        printf("2. Print a polynomial\n");
        printf("3. Find whether a polynomial is a zero polynomial\n");
        printf("4. Find the degree of a polynomial\n");
        printf("5. Multiply a polynomial with a constant\n");
        printf("6. Add two polynomials\n");
        printf("7. Subtract two polynomials\n");
        printf("8. Multiply two polynomials\n");
        printf("Enter  -1 to exit:\n ");
        printf("\n Enter the choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                printf("Terms should be entered in decreasing order of exponents.\n");
                printf("Each term should be entered as the coefficient and the exponent respectively, separated by a space.\n");
                printf("Enter the polynomial with each non-zero term in a line(Enter 0 0 in the next line after the last term):\n");
                read_poly(cant);
                break;
            }
            case 2: {
                printf("Enter the polynomial index: ");
                int index;
                scanf("%d", &index);
                print_poly(index);
                break;
            }
            case 3: {
                printf("Enter the polynomial index: ");
                int index;
                scanf("%d", &index);
                if (is_zero(index)) {
                    printf("It is a zero polynomial.\n");
                } else {
                    printf("It is not a zero polynomial.\n");
                }
                break;
            }
            case 4: {
                printf("Enter the polynomial index: ");
                int index;
                scanf("%d", &index);
                int deg = get_deg(index);
                if (deg == INT_MIN) { // for zero polynomial, degree is given as -inf
                    printf(" Degree is -inf(zero polynomial)\n");
                } else {
                    printf(" Degree is %d\n", deg);
                }
                break;
            }
            case 5: {
                printf("Enter the polynomial index and the constant respectively: ");
                int index;
                double k;
                scanf("%d %lf", &index, &k);
                mult_poly_const(index, k);
                break;
            }
            case 6: {
                int index1, index2;
                printf("Enter the indices of 1st polynomial: ");
                scanf("%d", &index1);
                printf("Enter the indices of 1st polynomial: ");
                scanf("%d", &index2);
                add_poly(index1, index2);
                break;
            }
            case 7: {
                int index1, index2;
                printf("Enter the 1st polynomial index of X (x-y form): ");
                scanf("%d", &index1);
                printf("Enter the 2nd polynomial index of Y (x-y form): ");
                scanf("%d", &index2);
                sub_poly(index1, index2);
                break;
            }
            case 8: {
                printf("Enter the polynomial indices: ");
                int index1, index2;
                scanf("%d %d", &index1, &index2);
                mult_poly(index1, index2);
                break;
            }
            default: {
                printf("Invalid option\n");
                break;
            }
       }
       if(choice == -1){
        break;
       }
    }

  return 0;
}


