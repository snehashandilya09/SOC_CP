//room allocation
//use priority queue
#include<iostream>
#include<tuple>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void tell(long int n,vector<pair<long int,long int>>&v){   //v is arrival departture
    vector<tuple<long int ,long int,long int>> customer;
    for(long int i=0;i<n;i++){
        customer.push_back({v[i].first,v[i].second,i});
    }           //customer arrival departure index
    sort(customer.begin(),customer.end());
    priority_queue<pair<long int,long int>,vector<pair<long int,long int>>,greater<>>pq ;    //pq will store departure and index;
    long int totalroom=0;
    vector<long int>roomno(n);
    for(auto[arr,dep,indx]:customer){
        if(!pq.empty() && pq.top().first<arr){
            auto[time,room]=pq.top();
            pq.pop();
            pq.push({dep,room});
            roomno[indx]=room;
        }
        else{
            totalroom++;
            roomno[indx]=totalroom;
            pq.push({dep,totalroom});
        }
    }
    cout<<totalroom<<endl;
    for(long int i:roomno){
        cout<<i<<" ";
    }
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
    tell(n,v);
}
