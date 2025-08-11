#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='-')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}

int n,a[N],b[N];
bool vis[N];

signed main(){
    freopen("las.in","r",stdin);
    freopen("las.out","w",stdout);
    n=read();
    queue<int> q;
    for(int i=1;i<=n;++i)a[i]=read()*2;a[n+1]=a[1];
    for(int i=1;i<=n;++i){
        if(a[i%n+1]/2>a[i]||a[i]/2>a[i+1]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        if(b[u])continue;
        int x=u,y=u%n+1;
        if(a[x]/(vis[x]?1:2)>a[y]){
            b[u]=x;if(!vis[x])vis[x]=1,a[x]/=2;
            vis[y]=1;q.push(u==1?n:u-1);q.push(u==n?1:u+1);
        }
        else if(a[y]/(vis[y]?1:2)>a[x]){
            b[u]=y;if(!vis[y])vis[y]=1,a[y]/=2;
            vis[x]=1;q.push(u==1?n:u-1);q.push(u==n?1:u+1);
        }
    }
    for(int i=1;i<=n;++i){
        if(!b[i])b[i]=i;
    }
    for(int i=1;i<=n;++i){
        print(b[i]);putchar(' ');
    }
    return 0;
}
