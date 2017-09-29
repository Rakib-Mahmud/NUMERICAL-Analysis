#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
#define mx 1000

int main()
{
    vector<int>matrix[mx];
    int n,m;
    cout<<"Enter the number of columns(1st) & rows :\n";
    cin>>m>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            matrix[j].push_back(x);
        }
    }
    cout<<"The Matrix is :\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl<<endl;
    }
    cout<<"Upper-Triangular Matrix :\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                if(i>j){
                    cout<<0<<"  ";
                }
                else{
            cout<<matrix[i][j]<<"  ";
            }
        }
        cout<<endl<<endl;
    }

    cout<<"Lower-Triangular Matrix :\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                if(i<j){
                    cout<<0<<"  ";
                }
                else{
            cout<<matrix[i][j]<<"  ";
            }
        }
        cout<<endl<<endl;
    }
    cout<<"Diagonal Matrix :\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                if(i==j){
                    cout<<matrix[i][j]<<"  ";
                }
                else{
                    cout<<0<<"  ";
            }
        }
        cout<<endl<<endl;
    }
}
