#include<bits/stdc++.h>
using namespace std;
int T,n,m,x,y,w;
long long V[200010],ans;
bool cmp(long long x,long long y) {return x>y;}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	// clock_t st=clock();
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		memset(V,0,sizeof(V));
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=m;++i){
			cin>>x>>y>>w;
			V[x]+=w,V[y]+=w;
		}
		sort(V+1,V+n+1,cmp);
		for(int i=1;i<=n;++i){
			if(i&1) ans+=V[i];
			else ans-=V[i];
		}
		cout<<(ans>>1)<<'\n';
	}
	// cerr<<(clock()-st)*1.0/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}
