#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    double x,fx,int_x,fnl_x,h,result=0,odd=0,evn=0;
    vector<double>X,Fx;

    cout<<"Input number of data points :"<<endl;
    cin>>n;

    cout<<"Input table values, set by set "<<endl;
    for(int i=0;i<n;i++){
        cin>>x>>fx;

        X.push_back(x);
        Fx.push_back(fx);
    }

    cout<<"Initial value of x "<<endl;
    cin>>int_x;

    cout<<"Final value of x "<<endl;
    cin>>fnl_x;

    cout<<"What is the segment width? "<<endl;
    cin>>h;

    for(int i=1;i<n-1;i++){
        if(i%2==0){
            evn=evn+Fx[i];
        }
        else{
            odd=odd+Fx[i];
        }
    }

    result=(h/3.0)*(Fx[0]+4*odd+2*evn+Fx[n-1]);
    printf("Integral from %.4lf to %.4lf is %lf\n",int_x,fnl_x,result);

    return 0;
}

