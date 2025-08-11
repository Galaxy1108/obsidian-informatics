#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=185,P=998244353;

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

int n,s[N],b[N],f[N][N],ans;
bool vis[N];

int power(int x,int y){
    int ans=1;
    while(y){
        if(y&1)ans=ans*x%P;
        x=x*x%P;
        y>>=1;
    }
    return ans;
}

int find(int *a,int x,int l,int r){
    while(l<r){
        int mid=l+r+1>>1;
        if(a[x]>=mid)l=mid;
        else r=mid-1;
    }
    return l;
}

int find(int x,int v){
    for(int i=x;i<=n*3;++i){
        if(vis[i])continue;
        if(b[i]==v)return i;
        //cout<<" i:"<<i<<" b:"<<b[i]<<endl;
    }
   // cout<<" /find x:"<<x<<" v:"<<v<<endl;
    return -1;
}

bool check(){
    //cout<<" /check b:";for(int i=1;i<=n*3;++i)cout<<b[i]<<" ";cout<<endl;
    for(int i=1;i<=n*3;++i)vis[i]=0;
    for(int i=1;i<=n*3;++i){
        if(vis[i])continue;
        vis[i]=1;
        if(b[i]==1){
            int y=find(i+1,2),z=find(y+1,3);
            if(y==-1||z==-1)return 0;
            //cout<<" /abc i:"<<i<<" y:"<<y<<" z:"<<z<<endl;
            vis[y]=vis[z]=1;
        }
        else if(b[i]==2){
            int z=find(i+1,3),x=find(z+1,1);
            //cout<<" /bca i:"<<i<<" z:"<<z<<" x:"<<x<<endl;
            if(z==-1||x==-1)return 0;
            vis[z]=vis[x]=1;
        }
        else{
            int x=find(i+1,1),y=find(x+1,2);
            //cout<<" /cab i:"<<i<<" x:"<<x<<" y:"<<y<<endl;
            if(x==-1||y==-1)return 0;
            vis[x]=vis[y]=1;
        }
    }
    return 1;
}

void dfs(int d){
    //cout<<" /dfs d:"<<d<<endl;
    if(d==n*3+1){
        ans+=check();return;
    }
    if(s[d]){
        b[d]=s[d];dfs(d+1);
    }
    else{
        b[d]=1;dfs(d+1);
        b[d]=2;dfs(d+1);
        b[d]=3;dfs(d+1);
        b[d]=0;
    }
}



signed main(){
    freopen("abc.in","r",stdin);
    freopen("abc.out","w",stdout);
    n=read();
    //work();
    char c=getchar();
    while(c!='A'&&c!='B'&&c!='C'&&c!='?')c=getchar();
    int cnt=0;
    for(int i=1;i<=n*3;++i){
        if(c=='?')s[i]=0,++cnt;
        else s[i]=c-'A'+1;
        c=getchar();
    }
    if(cnt==0){
        for(int i=1;i<=n*3;++i)b[i]=s[i];
        print(check());putchar('\n');return 0;
    }
    else if(n<=3){
        dfs(1);
        print(ans);putchar('\n');return 0;
    }
    else{
        puts("0");return 0;
    }
}