//tasks and deadline 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long int task(long int n,vector<pair<long int,long int>> &v){
    sort(v.begin(),v.end());
    long int reward=0;
    long int finish=0;
    for(long int i=0;i<n;i++){
        finish=finish+v[i].first;
        reward=reward +v[i].second-finish;
    }
    return reward;
}
int main(){
    long int n;
    cin>>n;
    vector<pair<long int,long int>>v;
    for(long int i=0;i<n;i++){
        long int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    cout<<task(n,v);
}
