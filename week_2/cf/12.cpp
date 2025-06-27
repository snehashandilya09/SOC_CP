//fourier transform 
#include<iostream>
#include<vector>
using namespace std;
vector<int>tell(int n,vector<float>&v){
    vector<int>ans;
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum=sum+(int)v[i];
        ans.push_back((int)v[i]);
    }
    if(sum==0){
        return ans;
    }
    else if (sum>0){
        for(int i=0;i<v.size();i++){
            if(v[i]!=(int)v[i] && (int)v[i]<0){
                ans[i]=ans[i]-1;
                sum=sum-1;
                if(sum==0){
                    return ans;
                }
            }
        }
    }
    else if (sum<0){
        for(int i=0;i<v.size();i++){
            if(v[i]!=(int)v[i] && v[i]>0){
                ans[i]=ans[i]+1;
                sum=sum+1;
                if(sum==0){
                    return ans;
                }
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<float>v;
    for(int i=0;i<n;i++){
        float val;
        cin>>val;
        v.push_back(val);
    }
    vector<int>ans=tell(n,v);
    for(int i:ans){
        cout<<i<<endl;
    }

}