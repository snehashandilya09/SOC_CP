//boy or a girl
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
void tell(string name){
    unordered_set<char>s;
    for(auto it: name){
        s.insert(it);
    }
    int x= s.size();
    if(x%2!=0){
        cout<<"IGNORE HIM!";
    }
    else{
        cout<<"CHAT WITH HER!";
    }
}
int main(){
    string name;
    cin>>name;
    tell(name);
}