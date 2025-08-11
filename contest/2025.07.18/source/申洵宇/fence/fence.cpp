#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define MOD 1000000007ll
int n,cnt,h[N],w[N],hi[N];
namespace sub1{
	inline long long calc(long long cs,long long ts,long long tw){
		return (tw*(tw+1ll)/2ll%MOD)*(cs*(2ll*ts-cs+1ll)/2ll%MOD)%MOD;
	}
	void solve(){
		long long ans=0;
		for(int i=1;i<=cnt;i++){
			static long long sw;
			sw=0;
			for(int j=1;j<=n;j++){
				if(h[j]>=hi[i]){
					sw=(sw+w[j])%MOD;
				}
				else{
					if(sw>0)ans=(ans+calc(hi[i]-hi[i-1],hi[i],sw))%MOD;
					sw=0;
				}
			}
			if(sw!=0){
				ans=(ans+calc(hi[i]-hi[i-1],hi[i],sw))%MOD;
			}
		}
		printf("%lld",ans);
		return ;
	}
}
namespace sub2{
	long long sw[N];
	vector<int>ne[N];
	set<pair<int,int>>st;
	inline long long calch(long long i){
		return (hi[i]-hi[i-1])*(hi[i]+hi[i-1]+1ll)/2ll%MOD;
	}
	inline long long calcw(long long l,long long r){
		static long long tw;
		tw=(sw[r]-sw[l-1]+MOD);
		if(tw>=MOD)tw-=MOD;
		return tw*(tw+1ll)/2ll%MOD;
	}
	void solve(){
		for(int i=1;i<=n;i++){
			sw[i]=(sw[i-1]+w[i])%MOD;
		}
		for(int i=1;i<=n;i++){
			ne[lower_bound(hi+1,hi+cnt+1,h[i])-hi].emplace_back(i);
		}
		long long ans=0,val=0;
		st.emplace(1,n);
		val=calcw(1,n);
		set<pair<int,int>>::iterator it;
		pair<int,int> t,p1,p2; 
		for(int i=1;i<=cnt;i++){
			ans=(ans+calch(i)*val%MOD)%MOD;
			for(auto v:ne[i]){
				it=st.upper_bound(make_pair(v,1000000000));
				assert(it!=st.begin());
				t=*prev(it);
				st.erase(prev(it));
				val=(val-calcw(t.first,t.second)+MOD)%MOD;
				p1.first=t.first,p1.second=v-1;
				p2.first=v+1,p2.second=t.second;
				if(p1.first<=p1.second){
					st.emplace(p1);
					val=(val+calcw(p1.first,p1.second))%MOD;
				}
				if(p2.first<=p2.second){
					st.emplace(p2);
					val=(val+calcw(p2.first,p2.second))%MOD;
				}
			}
		}
		printf("%lld",ans);
		return ;
	}
	
}
int main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
		hi[i]=h[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	sort(hi+1,hi+n+1);
	cnt=unique(hi+1,hi+n+1)-hi-1;
	if(1ll*n*cnt<=10000000){
		sub1::solve();
	}
	else{
		sub2::solve();
	}
	return 0;
}
