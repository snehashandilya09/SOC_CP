//watermelon
#include<iostream>
using namespace std;
void tell(int w){
    if(w%2!=0){
        cout<<"NO";
    }
    else{
        if(w==0 || w==2){
            cout<<"NO";
        }
        else{
            cout<<"YES";
        }
    }
}
int main(){
    int w;
    cin>>w;
    tell(w);
}