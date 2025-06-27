//beautiful matrix
#include<iostream>

#include<algorithm>
using namespace std;
int tell(int x,int y){
    int moves=0;
    moves=moves+abs(x-3);
    moves=moves+abs(y-3);
    return moves;
}
int main(){
   
    int x,y;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int num;
            cin>>num;
            if(num==1){
                x=i+1;
                y=j+1;
            } 
        }
    }
    cout<<tell(x,y);
}