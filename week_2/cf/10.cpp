//little girl and maxm sum
//time exceed

#include<iostream>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int tell(int n,int q,int arr[],vector<pair<int,int>> &v ){
    unordered_map<int,int>mpp;
    for(int i=0;i<v.size();i++){
        for(int j=v[i].first;j<=v[i].second;j++){
            mpp[j]++;
        }
    }
    priority_queue<int,vector<int>>s;
    for(auto &p:mpp){
        s.push(p.second);
    }
    priority_queue<int,vector<int>>qu;
    
    for(int i=0;i<n;i++){
        qu.push(arr[i]);
    }
    int sum=0;
    int i=0;
    while(!s.empty() && !qu.empty()){
        sum=sum+ s.top()*qu.top();
        s.pop();
        qu.pop();
        i++;
    }
    return sum;

}
int main(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<pair<int,int>>v;
    
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    cout<<tell(n,q,arr,v);
    
}