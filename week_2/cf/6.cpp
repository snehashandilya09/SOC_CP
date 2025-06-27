//football
#include<iostream>
#include<vector>
using namespace std;
  long long int tell(  long long int n){
      long long int sum=0;
    while(n!=0){
        if(n==1){
            sum=sum+1;
            n=0;
            break;
        }
        if(n%2!=0 ){
            sum=sum+1;
            if((n-1)%4==0 && n-1!=4){
                n=n-2;
            }
            else{
                n=(n-1)/2;
            }
        }
        else{
           if(n%4==0 && n!=4){
            sum=sum+1;
            n=n-2;
           }
           else{
            sum=sum+n/2;
            n=n/2 -1;
           }
        }
    }
    return sum;
}
 int main(){
    int t;
    cin>>t;
    vector<  long long int>v;
    for(int i=0;i<t;i++){
          long long int n;
        cin>>n;
        v.push_back(tell(n));
    }
    for(  long long int i:v){
        cout<<i<<endl;
    }
}