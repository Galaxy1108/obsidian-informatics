#include<bits/stdc++.h>

using namespace std;

int mapn[1001][1001];
int ans[2];
int ty,n,m,k;
int Q,q;
int del[5][2]={{0,0},{-1,0},{0,-1},{1,0},{0,1}};

void dfs(int nown,int zt,int cnt){
    int x=(nown-1)/m+1,y=(nown-1)%m+1;
    if(cnt==q){
        ans[0]=x;
        ans[1]=y;
        return;
    }
    int nx=x,ny=y;
    if(mapn[nx][ny]) nx+=del[zt][0],ny+=del[zt][1];
    while(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mapn[nx][ny]!=1) nx+=del[zt][0],ny+=del[zt][1];
    if(nx==n+1||ny==m+1){
        if(nx==n+1) ans[0]=n+1,ans[1]=ny;
        if(ny==m+1) ans[0]=nx,ans[1]=m+1;
        return;
    }
    if(mapn[nx][ny]){
        int newn=(nx-1)*m+ny;
        int nt=0;
        if(zt==3) nt=4;
        if(zt==4) nt=3;
        dfs(newn,nt,cnt+1);
        return;
    }
    return;
}


int main(){
    freopen("corridor.in","r",stdin);
    freopen("corridor.out","w",stdout);
    cin>>ty>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        mapn[x][y]=1;
    }
    cin>>Q;
    while(Q--){
        int op;
        cin>>op;
        if(op==1){
            int x,y;
            cin>>x>>y;
            mapn[x][y]=1;
        }
        else{
            int x,y;
            cin>>x>>y>>q;
            if(x==0) dfs(y,3,0);
            if(y==0) dfs((x-1)*m+1,4,0);
            cout<<ans[0]<<" "<<ans[1]<<endl;
        }
    }
    return 0;
}