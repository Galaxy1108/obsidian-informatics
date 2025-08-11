#include<cstdio>
#include<set>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=2e5+5;
int n;
int len[N];
vector<int> a[N];
vector<ll> f[N];
ll sum=0;
multiset<ll> s; 
ll b[N],tot;
int g[N][N];
void add(ll x){
	if(s.size()==0){
		s.insert(x);
		return;
	}
	auto r=s.lower_bound(x);
	if(r==s.end()){
		r--;
		sum+=((*r)-x)*((*r)-x); 
	}	
	else if(r==s.begin()){
		sum+=((*r)-x)*((*r)-x);
	}
	else{
		auto l=r;
		l--;
		sum-=((*l)-(*r))*((*l)-(*r));
		sum+=((*l)-x)*((*l)-x);
		sum+=((*r)-x)*((*r)-x);
	}
	s.insert(x);
}
int main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		len[i]=read();
		a[i].push_back(0);
		f[i].push_back(0);
		for(int j=1;j<=len[i];j++){
			int x=read();
			a[i].push_back(x);
			f[i].push_back(0);
		}
	} 
	ll ans=1e18;
	for(int T=1;T<=len[1];T++){
		for(int i=1;i<=len[1];i++){
			f[1][i]=1e18;
		}
		f[1][T]=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=len[i];j++){
				f[i][j]=1e18;
				sum=0;
				s.clear();
				add(0);
				add(2000000);
				for(int k=j-1;k;k--){
					add(a[i][k]);
				}
				for(int k=len[i-1];k;k--){
					add(a[i-1][k]);
					f[i][j]=min(f[i][j],f[i-1][k]+sum);
				}
			}
		}
		int id=0;
		for(int j=1;j<=len[n];j++){
			sum=0;
			s.clear();
			add(0);
			add(2000000);
			for(int i=1;i<T;i++) add(a[1][i]);
			for(int i=j;i<=len[n];i++) add(a[n][i]);
			ans=min(ans,f[n][j]+sum);
		}
//		dfs(3,3);printf("\n");
	}
	printf("%lld",ans);
	return 0;
} 
