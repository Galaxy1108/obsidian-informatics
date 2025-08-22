#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2010;
int n;
bitset<N>las[N];
ll a[N][N],dis[N];
void dij(int u){
	priority_queue<pair<ll,int> >q;
	for(int i=1;i<=n;i++){
		dis[i]=1e18;
		las[i]=0;
	}
	q.push({0,u});
	las[u][u]=1;
	while(!q.empty()){
		u=q.top().second;
		q.pop();
		for(int i=1;i<=n;i++){
			if(dis[i]>min(dis[u],a[u][i])&&!las[u][i]){
				dis[i]=min(dis[u],a[u][i]);
				las[i]=las[u];
				las[i][i]=1;
				q.push({-dis[i],i});
			}
		}
	}
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int vis=1,vis1=0;
	ll sum;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i][i]=1e18;
		for(int j=i+1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			a[j][i]=a[i][j];
			if(a[i][j]!=1&&a[i][j]!=1e9){
				vis=0;
			}
			if(a[i][j]==1){
				vis1=1;
			}
		}
	}
	if(vis){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&a[i][j]==1){
					printf("%d\n",n-1);
					goto lass;
				}
			}
			if(vis1){
				printf("%d\n",(int)1e9+n-2);
			}
			else{
				printf("%lld\n",(ll)1e9*(n-1));
			}
			lass:;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		dij(i);
		sum=0;
		for(int j=1;j<=n;j++){
			if(i!=j){
				sum+=dis[j];
			}
		}
		printf("%lld\n",sum);
	}
}