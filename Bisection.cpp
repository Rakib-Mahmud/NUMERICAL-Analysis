#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
    double x=0,a=0,b=0,y=0,z=0,dif=0;

    for(double i=0,j=1;;i++,j++){
        x=i;
        y=pow(x,3)-2*x-5;
        x=j;
        z=pow(x,3)-2*x-5;
        if(y<0&&z>0){
            a=i;b=j;
            break;
        }
    }

    dif=b-a;
    int i=1;
    printf("\n  \t n \t a \t b \t    x \t     f(x) \n");
        printf(" \t--- \t---\t---\t   ---\t  --------\n");
    while(dif>0.001){
        x=(a+b)/2;
        z=pow(x,3)-2*x-5;
        dif=fabs(b-a);
        printf("\n\t %d\t%.3lf \t%.3lf \t%lf  %lf \n",i,a,b,x,z);
        if(z>0){
            b=x;
        }
        else{
            a=x;
        }
        i++;
    }

    printf("\n\tResult is = %lf\n",x);

    return 0;
}
