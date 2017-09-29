#include<bits/stdc++.h>
#define mx 100
using namespace std;

int main()
{
    int n;
    double x,y,z,a,c;
    vector<double>vec[mx];

    cout<<"What is the size of the system (n)?"<<endl;
    cin>>n;

    cout<<"Input coefficients a(i , j), row-wise:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a;
            vec[i].push_back(a);
        }
    }
    cout<<"Input vector b:"<<endl;
    for(int i=0;i<n;i++){
        cin>>a;
        vec[i].push_back(a);
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
                double pivot=vec[j][i]/vec[i][i];
                for(int k=0;k<n+1;k++){
                        vec[j][k]=vec[j][k]-pivot*vec[i][k];
                }
        }
    }
    int l=1;
    for(int i=n-1;i>=0;i--){
        int p=1;
        for(int j=i;j<n-1;j++){
            vec[i][n]=vec[i][n]-(vec[i][n-p]*vec[n-p][n]);
            p++;
        }
        vec[i][n]=vec[i][n]/vec[i][n-l];
        l++;
    }

    cout<<"Solution vector x:"<<endl;
    for(int i=0;i<n;i++){
        printf("%.4lf ",vec[i][n]);
    }
    cout<<endl;
    return 0;
}
