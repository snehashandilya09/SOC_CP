//minimal differnce
#include<iostream>
#include<map>
#include<vector>
using namespace std;
long int tell(long int n,long int arr[]){
    map<long int,long int>mpp;
    long int min=n+2;
    for(long int i=0;i<n;i++){
        if(mpp.count(arr[i])==0){
            mpp[arr[i]]=i;
        }
        else{
            if(min>(i-mpp[arr[i]])){
                min=i-mpp[arr[i]];
               
            }
            mpp[arr[i]]=i;
        }
    }
    if(min==n+2){
        ;
        return -1 ;
    }
    return min+1;
}
int main(){
    int t;
    cin>>t;
    vector<long int>v;
    for(int j=0;j<t;j++){
    long int n;
    cin>>n;
    long int arr[n];
    for(long int i=0;i<n;i++){
        cin>>arr[i];
    }
    long int x=tell(n,arr);
    v.push_back(x);
}
for(long int y:v){
    cout<<y<<endl;
}
    
}

