//balanced ternary string 
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void tell(int n,vector<int>&arr){
    int k=n/3;
    unordered_map<int,int>mpp={{0,0},{1,0},{2,0}};
    unordered_map<int,int>mpp2;
    
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto &p:mpp){
        if(p.second>k){
            mpp2[p.first]=0;
        }
        else{
            mpp2[p.first]=p.second;
        }
    }
    for(int i=0;i<n;i++){
        if(mpp[arr[i]]>k){
            
            if(mpp[0]<k &&(0<arr[i]||mpp2[arr[i]]==k)){
                mpp[arr[i]]--;
                arr[i]=0;
                mpp[0]++;
                
            }
            else if(mpp[1]<k &&(1<arr[i]||mpp2[arr[i]]==k)){
                mpp[arr[i]]--;
                arr[i]=1;
                mpp[1]++;
                
            }
            else if(mpp[2]<k &&(2<arr[i]||mpp2[arr[i]]==k)){
                mpp[arr[i]]--;
                arr[i]=2;
                mpp[2]++;
                
            }
            else{
                mpp2[arr[i]]++;
            }
            
            
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>arr;
    for(char c:s){
        arr.push_back(c-'0');
    }
    tell(n,arr);
}
