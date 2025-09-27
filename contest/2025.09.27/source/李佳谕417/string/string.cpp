#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    cin>>s;
    string s1=s;
    int cnt=0;
    for(int i=1;i<s.size();i++){
        if(s[i-1]==s[i]){
            bool flag=0;
            for(int j=i+1;j<s.size();j++){
                if(s[j]!=s[i]){
                    flag=1;
                    swap(s[j],s[i]);
                    cnt+=j-i;
                    break;
                }
            }
            if(!flag){
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<cnt;
    return 0;
}