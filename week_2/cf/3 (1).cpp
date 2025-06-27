//equal rectangles
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int tell(int n,int arr[]){
    unordered_map<int,int>mpp;
    for(int i=0;i<4*n;i++){
        mpp[arr[i]]++;
    }
    //mpp contains the sides and the count 
    vector<int>v;
    for(auto p:mpp){
        if(p.second %2!=0){
            return -1;
        }
        for(int i=0;i<p.second/2;i++){
            v.push_back(p.first);
        }
    }
    sort(v.begin(),v.end());
    int val=v[0]*v[2*n-1];
    for(int i=0;i<n;i++){
        if(val!=v[i]*v[2*n-1-i]){
            return -1;
        }
    }
    return 1;
}
int main(){
    int t;
    cin>>t;
    vector<int>v;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        int arr[4*n];
        for(int j=0;j<4*n;j++){
            cin>>arr[j];
        }
        v.push_back(tell(n,arr));
    }
    for(int i:v){
        if(i==-1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}