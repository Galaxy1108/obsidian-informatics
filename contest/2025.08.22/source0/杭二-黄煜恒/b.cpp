#include<bits/stdc++.h>
#define db double
#define pb push_back
#define fi first
#define se second
#define mkp make_pair
#define pii pair<int,int>
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f; 
}
struct node{
	int pos,val;
	bool operator<(const node &x)const{
		return val>x.val;
	}
};
priority_queue<node>q;
int n,E[2010][2010],mn,dis[2010];
bool vis[2010];
signed main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)
    	dis[i]=1e10;
    mn=1e10;
    for(int i=1;i<=n;i++)
    	for(int j=i+1;j<=n;j++){
    		E[i][j]=E[j][i]=read();
    		mn=min(mn,E[i][j]);
    	}
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(i==j)continue;
    		E[i][j]-=mn,dis[i]=min(dis[i],E[i][j]);
    	}
    }
    // for(int i=1;i<=n;i++)
    // 	q.push((node){i,dis[i]*2}),dis[i]*=2;
    // while(!q.empty()){
    // 	node t=q.top();q.pop();
    // 	if(vis[t.pos])continue;
    // 	vis[t.pos]=1;
    // 	for(int i=1;i<=n;i++){
    // 		if(i==t.pos)continue;
    // 		if(dis[i]>dis[t.pos]+E[i][t.pos]){
    // 			dis[i]=dis[t.pos]+E[i][t.pos];
    // 			q.push((node){i,dis[i]});
    // 		}
    // 	}
    // }
    for(int i=1;i<=n;i++)
        dis[i]*=2;
    dis[0]=1e10;
    for(int i=1;i<=n;i++){
        int mn=0;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&dis[j]<dis[mn])mn=j;
        vis[mn]=1;
        for(int j=1;j<=n;j++){
            if(j==mn)continue;
            dis[j]=min(dis[j],dis[mn]+E[j][mn]);
        }
    }
    for(int i=1;i<=n;i++)
    	printf("%lld\n",dis[i]+(n-1)*mn);
    return 0;
}