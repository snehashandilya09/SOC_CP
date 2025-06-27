//arrival on the general
#include<iostream>

using namespace std;
int main(){
    int n;
    cin>>n;
    int max=0;int min=0;
    int arr[n];
    int moves;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>arr[max]){
            max=i;
        }
        if(arr[i]<=arr[min]){
            min=i;
        }
    }
    if(max<min){
        moves=max+n-1-min;
    }
    else if(max>min){
        moves=max+n-2-min;
    }
    else{
        moves=0;
    }
    cout<<moves;
}