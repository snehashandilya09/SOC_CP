//random teams
#include<iostream>
using namespace std;
long long int nc2(long long int n){
    return n*(n-1)/2;
}
void tell(long long int n,long long int m){
    //n is the no of participants and m is the no of teams 
    long long int max;
    max=nc2(n-(m-1));
    long long int min;
    long long int x=n/m;
    long long int more=n-m*x;
    min=(m-more)*(nc2(x))+more*nc2(x+1);
    cout<<min<<" "<<max;
}
int main(){
    long long int n,m;
    cin>>n>>m;
    tell(n,m);
}