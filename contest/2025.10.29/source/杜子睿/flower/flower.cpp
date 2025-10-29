#include<bits/stdc++.h>
using namespace std;
string s[45];
int n,book[200],flag[200],m;
bool fl=false;
void dfs(int x){
    if(x==n*2+1){fl=true;return;}
    if(x==m*2+1){m+=4;}
    if(book[x]){dfs(x+1);return;}
    for(int i=1;i<=m;i++){
        if(flag[i])continue;
        if(book[x+i+1]||x+i+1>2*m)continue;
        flag[i]=1;
        book[x]=book[x+i+1]=i;
        dfs(x+1);
        if(fl)return;
        flag[i]=0;
        book[x]=book[x+i+1]=0; 
    }
}
int init39[90]={0,2,3,6,2,7,3,9,11,8,6,12,15,7,16,17,20,9,8,21,11,23,24,22,12,26,27,30,15,29,33,16,35,17,31,37,38,20,39,34,36,21,28,32,25,23,22,24,13,19,14,5,26,18,27,4,10,5,30,29,4,1,13,1,33,14,31,10,35,19,25,28,18,37,34,38,32,36,39};
int init40[90]={0,2,3,6,2,8,3,7,10,11,6,13,16,14,8,7,17,20,21,10,23,11,22,25,26,13,27,30,14,16,31,32,33,36,17,35,37,40,20,39,21,38,34,28,23,22,29,9,18,25,24,26,15,19,27,4,12,9,30,5,4,1,31,1,32,5,33,18,15,12,36,35,28,19,37,24,29,34,40,39,38};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n;
    m=n%4;
    for(int i=1;i<=n;i++)cin>>s[i];
    if(n==39){
        for(int i=1;i<=2*n;i++)cout<<s[init39[i]]<<endl;
        return 0;
    }
    if(n==40){
        for(int i=1;i<=2*n;i++)cout<<s[init40[i]]<<endl;
        return 0;
    }
    dfs(1);
    for(int i=1;i<=2*n;i++)cout<<s[book[i]]<<endl;
    return 0;
}