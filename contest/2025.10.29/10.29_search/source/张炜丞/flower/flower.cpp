#include<bits/stdc++.h>
using namespace std;
const int N=45;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='1')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}

int a[N*2],n;
string s[N];
bool vis[N];

void dfs(int d){
    // cout<<" /dfs d:"<<d<<endl;
    if(d==2*n+1){
        // for(int i=1;i<=n*2;++i)cout<<a[i]<<" ";cout<<endl;
        // exit(0);
        for(int i=1;i<=n*2;++i){
            cout<<s[a[i]]<<endl;
        }
        exit(0);
    }
    if(a[d])return dfs(d+1);
    for(int i=n;i>=1;--i){
        if(vis[i])continue;
        if(d+i+1>n*2)return;
        if(!a[d+i+1]){
            a[d]=a[d+i+1]=i;
            vis[i]=1;
            dfs(d+1);
            vis[i]=0;
            a[d+i+1]=a[d]=0;
        }
    }
}

signed main(){
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i)cin>>s[i];
    dfs(1);
    return 0;
}
