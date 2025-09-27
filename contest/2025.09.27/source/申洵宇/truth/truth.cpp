#include <bits/stdc++.h>
using namespace std;
#define N 50005
#define K 35
#define INF 0x3f3f3f3f
int n,k,m,a[N],nxt[K];
int main(){
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int op,p,v;
	while(m--){
		cin>>op;
		if(op==1){
			cin>>p>>v;
			a[p]=v;
		}
		else if(op==2){
			int ans=INF,maxn=0;
			for(int j=1;j<=k;j++)nxt[j]=0;
			for(int i=1;i<=n;i++){
				maxn=0;
				for(int j=1;j<=k;j++){
					nxt[j]=max(nxt[j],i);
					while(nxt[j]<=n&&a[nxt[j]]!=j)nxt[j]++;
					if(nxt[j]>n)maxn=INF;
					else maxn=max(maxn,nxt[j]-i+1);
				}
				ans=min(ans,maxn);
			}
			if(ans==INF){
				cout<<"-1\n";
			}
			else{
				cout<<ans<<'\n';
			}
		}
	}
	return 0;
}