#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
    double x=0,a=0,b=0,y=0,z=0,dif=1,x1=0.00001;

    for(double i=0,j=1;;i++,j++){
        x=i;
        y=pow(x,2.2)-69;
        x=j;
        z=pow(x,2.2)-69;
        if(y<0&&z>0){
            a=i;b=j;
            break;
        }
    }
    int i=1;
    printf("\n  \t n \t a \t b \t    x \t     f(x) \n");
        printf(" \t--- \t---\t---\t   ---\t  --------\n");
    while(dif>0.0001){
        z=pow(b,2.2)-69;
        y=pow(a,2.2)-69;
        x=(a*z-b*y)/(z-y);
        z=pow(x,2.2)-69;
        printf("\n\t %d\t%.3lf \t%.3lf \t%lf  %lf \n",i,a,b,x,z);
        dif=x-x1;
        x1=x;
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

