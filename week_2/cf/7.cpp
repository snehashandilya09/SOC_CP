//llya and matrices
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    long long int x;
    cin>>x;
    vector<long long int>v;
    for(long long int i=0;i<x;i++){
        long long int y;
        cin>>y;
        v.push_back(y);
    }
    sort(v.begin(),v.end(),greater <long long int>());
    if(x==1){
        cout<<v[0];
        exit(0);
    }
    long long int sum=0;
    long long int m=1;
    while(m<=x){
        
        for(long long int i=0;i<m;i++){
            sum=sum+v[i];
        }
        m=m*4;
    }
    cout<<sum;
}