#include<bits/stdc++.h>
using namespace std;
int n,V=1000000;
int a[1000010],sum[1000010],cnt[2000010],Cnt[1000010];
long long ans;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i],++cnt[a[i]];
	for(int i=1;i<=2*V;++i) sum[i]=sum[i-1]+cnt[i];

	for(int i=1;i<=V;++i){
		int lst=i-1,tot=0,N=(V/i);
		for(int j=2*i-1,x=1;x<=N;j+=i,++x){
			Cnt[x]=sum[j]-sum[lst];
			if(Cnt[x]&1) ++tot;
			lst=j;
		}
		if(tot==1&&(Cnt[1]&1)) ans+=Cnt[1];
		if(tot==2){
			for(int i=2;i<=N;++i){
				if((Cnt[i]&1)&&(Cnt[i-1]&1)) ans+=Cnt[i];
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
