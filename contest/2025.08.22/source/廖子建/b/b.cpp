#include<bits/stdc++.h>
#define int long long
#define N 2000
#define M 8
#define K 256
using namespace std;
int n,m,a[N+5][N+5],uw,tmp[N*N+5],tot=0,len,dp[M+5][M+5][K+5];
bool flag[N+5],debug,ver[M+5][M+5][K+5];
int read(){
    int f=1,g=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        g=g*10+ch-'0';
        ch=getchar();
    }
    return f*g;
}
void print(int x){
    if(x<0){
        putchar('-');
        x*=-1;
    }
    if(x>9)print(x/10);
    putchar(x%10+'0');
    return;
}
int dfs(int x,int minn,int dep){
    int sum=0,ans=INT_MAX;
    if(minn==1)return tmp[1]*(n-dep);
    // if(debug)cout<<"x="<<x<<" minn="<<minn<<" dep="<<dep<<"\n";
    for(int i=1;i<=n;i++){
        if(flag[i])continue;
        if(!sum)sum=i;
        else if(a[x][sum]>a[x][i])sum=i;
    }
    if(!sum)return 0;
    for(int i=1;i<=n;i++){
        if(flag[i]||a[x][sum]<minn&&a[x][sum]<a[x][i])continue;
        flag[i]=1;
        ans=min(ans,dfs(i,min(minn,a[x][sum]),dep+1));
        flag[i]=0;
    }
    // if(debug)cout<<"x="<<x<<" ans="<<ans<<" a["<<x<<"]["<<sum<<"]="<<a[x][sum]<<" minn="<<minn<<"\n";
    return ans+tmp[min(a[x][sum],minn)];
}
int dfs2(int x,int minn,int y){
    if(y==m-1)return 0;
    if(ver[x][minn][y])return dp[x][minn][y];
    ver[x][minn][y]=1;
    int sum=0,ans=INT_MAX;
    for(int i=1;i<=n;i++){
        if((y>>(i-1))&1)continue;
        if(!sum)sum=i;
        else if(a[x][sum]>a[x][i])sum=i;
    }
    if(!sum)return dp[x][minn][y]=0;
    for(int i=1;i<=n;i++){
        if(((y>>(i-1))&1)||a[x][sum]<minn&&a[x][sum]<a[x][i])continue;
        ans=min(ans,dfs2(i,min(minn,a[x][sum]),y^(1<<(i-1))));
    }
    return dp[x][minn][y]=ans+tmp[min(a[x][sum],minn)];
}
main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    n=read(),m=(1<<n);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            uw=read();
            a[i][j]=a[j][i]=uw;
            tmp[++tot]=uw;
        }
    }
    sort(tmp+1,tmp+1+tot);
    len=unique(tmp+1,tmp+1+tot)-tmp-1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            a[i][j]=a[j][i]=lower_bound(tmp+1,tmp+1+len,a[i][j])-tmp;
        }
    }
    for(int i=1;i<=n;i++){
        flag[i]=1;
        // cout<<i<<" fufefe\n";
        // return 0;
        if(n<=8)print(dfs2(i,n+1,1<<(i-1)));
        else print(dfs(i,n+1,1));
        // print(dfs(i,n+1,1));
        putchar('\n');
        flag[i]=0;
    }
    return 0;
}
