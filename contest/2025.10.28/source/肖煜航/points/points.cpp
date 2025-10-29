#include <bits/stdc++.h>
#define mkp make_pair
#define pb emplace_back
using namespace std;
typedef long long ll;
constexpr int N=2e5+5,inf=1e9;
constexpr ll Inf=1e18;
int n,m;
int a[N];
pair<int,int> ln[N];
vector<pair<int,int>> e;
ll f[2][N];
void minn(ll& x,ll y){
	if(x>y) x=y;
}
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.first==y.first?x.second>y.second:x.first<y.first;
}
void solve(){
ll le=0,ri=0;
	if(e[0].second<a[1])le=a[1]-e[0].second;
	f[0][1]=2ll*le,f[1][1]=le;
	int i=0,j=0;
	while(j<e.size()&&e[j].second<a[1])j++;i=j;
	for(int k=2;k<=n;k++,i=j){
		while(j<e.size() && e[j].second<a[k])j++;
		for(int kk=i;kk<=j;kk++){
			le=ri=0;
			if(kk^i)le=e[kk-1].first-a[k-1];
			if(kk^j)ri=a[k]-e[kk].second;
			minn(f[0][k],f[0][k-1]+le+2ll*ri);
			minn(f[0][k],f[1][k-1]+le*2+ri*2);
			minn(f[1][k],f[0][k-1]+le+ri);
			minn(f[1][k],f[1][k-1]+le*2+ri);
		}
	}
	ri=0;
	if(e.back().first>a[n]) ri=e.back().first-a[n];
	ll ans=min(f[0][n]+ri,f[1][n]+ri*2);
	cout<<ans;
}
void init(){
	sort(ln+1,ln+1+m,cmp);
	sort(a+1,a+1+n);
	for(int i=m,ri=inf;i;i--){
		int pos=lower_bound(a+1,a+n+1,ln[i].first)-a;
		if(a[pos]<=ln[i].second||ln[i].second>=ri)continue;
		e.pb(ln[i]);
		ri=min(ri,ln[i].second);
	}
	if(!e.size()){
		cout<<"0";
		exit(0);
	}
	reverse(e.begin(),e.end());
	for(int i=0;i<=n;i++) f[0][i]=f[1][i]=Inf;
	
}
int main(){
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[n+1]=inf;
	for(int i=1;i<=m;i++) cin>>ln[i].first>>ln[i].second;
	init();
	solve();
	return 0;
}
