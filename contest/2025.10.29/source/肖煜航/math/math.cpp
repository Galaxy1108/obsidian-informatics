#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,M=1e7;
int aa,bb,ans[N],fl,k[N],maxdep;
int cnt1;
void dfs(int now,int a,int b,int lim,int dep){
	if(now==lim+1){
		if(a!=0)
			return;
		if(ans[1]==0||k[lim]<ans[lim]){
			for(int i=1;i<=lim;i++)
				ans[i]=k[i];
			fl=1;
		}
		return;
	}
	int l=max(k[now-1]+1,(b+a-1)/a);
	int r=min(dep,b*(lim-now+1)/a);
	for(int i=l;i<=r;i++){
		int na=a*i-b,nb=b*i,c=__gcd(na,nb);
		na/=c,nb/=c;
		k[now]=i;
		dfs(now+1,na,nb,lim,dep);
	}
}
signed main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>aa>>bb;
	int gg=__gcd(aa,bb);
	aa/=gg,bb/=gg;
	if(aa==1)return cout<<"1\n"<<bb,0;
	while(aa>bb) aa-=bb,cnt1++;
	for(int i=2;;i++){
		ans[i]=INT_MAX;
		maxdep=100;
		while(maxdep<=M){
			dfs(1,aa,bb,i,maxdep);
			if(fl){
				cout<<i+cnt1<<'\n';
				while(cnt1--)cout<<"1 ";
				for(int j=1;j<=i;j++)
					cout<<ans[j]<<' ';
				return 0;
			}
			maxdep*=10;
		}
	}
	return 0;
}
