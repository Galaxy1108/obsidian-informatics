#include <bits/stdc++.h>
using namespace std;
#define V 16000005
#define MX 20
#define N (MX+5)
long long f[N];
vector<int>pr,lcm[N];
vector<pair<int,int>>val[N];
bitset<V>book;
void init(){
	book[0]=book[1]=1;
	for(int i=2;i<=16000000;i++){
		if(!book[i]){
			pr.emplace_back(i);
		}
		for(const int& v:pr){
			if(1ll*i*v>16000000)break;
			book[i*v]=1;
			if(i%v==0)break;
		}
	}
	long long t;
	f[1]=1,f[2]=2;
	lcm[1].resize(pr.size());
	lcm[2].resize(pr.size());
	lcm[2][0]=1;
	for(int i=3;i<=MX;i++){
		f[i]=(f[i-1]<<1)+f[i-2];
		t=f[i];
		lcm[i].resize(pr.size());
		for(int j=0;j<pr.size()&&t>1;j++){
			while(t%pr[j]==0){
				lcm[i][j]++;
				t/=pr[j];
			}
		}
		for(int j=0;j<pr.size();j++){
			lcm[i][j]=max(lcm[i-1][j],lcm[i][j]);
		}
	}
	for(int i=1;i<=MX;i++){
		for(int j=0;j<pr.size();j++){
			if(lcm[i][j]>0){
				val[i].emplace_back(pr[j],lcm[i][j]);
			}
		}
	}
}
long long mpow(long long base,long long p,long long MOD){
	long long res=1;
	while(p){
		if(p&1)res=res*base%MOD;
		p>>=1;
		base=base*base%MOD;
	}
	return res;
}
int main(){
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	int T,n;
	long long MOD,ans,now;
	cin>>T;
	while(T--){
		cin>>n>>MOD;
		ans=0;
		for(int i=1;i<=n;i++){
			now=i%MOD;
			for(auto v:val[i]){
				now=now*mpow(v.first,v.second,MOD)%MOD;
			}
			ans=(ans+now)%MOD;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

