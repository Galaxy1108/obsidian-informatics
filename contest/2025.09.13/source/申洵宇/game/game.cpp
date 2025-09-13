#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define MOD 998244353
int k,n;
long long f[N],g[N];
void init(){

}
void solve(){
	cin>>n;
	if(k>=(n>>1)){
		cout<<n<<" 1\n";
		return ;
	}
	static long long ans1;ans1=0;
	for(int fst=1,lst;fst<=n;fst++){
		lst=min(n,n+fst-k-1);
		if(fst>lst)continue;
		f[fst]=1;
		static long long sum;sum=0;
		for(int i=fst+1;i<=lst;i++){
			if(i-k-1>=fst)sum+=f[i-k-1],sum-=sum>=MOD?MOD:0;
			f[i]=sum;
		}
		for(int i=max(lst-k,fst);i<=lst;i++){
			sum+=f[i],sum-=sum>=MOD?MOD:0;
		}
		ans1+=sum;
		ans1-=ans1>=MOD?MOD:0;
	}
	
	static long long ans2;ans2=0;
	for(int j=0;j<=n;j++)g[j]=0;
	g[0]=1;
	for(int i=k+1;i<=n;i++){
		for(int j=0;j+i<=n;j++){
			g[j+i]+=g[j];
			g[j+i]-=g[j+1]>=MOD?MOD:0;
		}
	}
	ans2=g[n];

	cout<<ans1<<' '<<ans2<<'\n';
	// cout.flush();
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>k;
	init();
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
