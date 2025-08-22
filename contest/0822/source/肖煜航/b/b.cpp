#include<cstdio>
#include<algorithm>
#define ll long long
#define fi first
#define se second 
using namespace std;
const int N=2005;
int n,tot;
ll a[N][N];
pair<ll,pair<int,int> > e[N*N];
ll solve(int x,int t){
	if(e[x].se.fi==t||e[x].se.se==t) return e[x].fi*(n-1);		
	return e[x].first*(n-2)+min(a[t][e[x].se.fi],a[t][e[x].se.se]);
	return 1e18;
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			a[j][i]=a[i][j];
			tot++;
			e[tot]=make_pair(a[i][j],make_pair(i,j));
		}
	}
	sort(e+1,e+tot+1);
	for(int i=1;i<=n;i++){
		ll ans=1e18;
		for(int j=1;j<=min(tot,7500);j++) ans=min(ans,solve(j,i));
		printf("%lld\n",ans);
	}
	return 0;
}
