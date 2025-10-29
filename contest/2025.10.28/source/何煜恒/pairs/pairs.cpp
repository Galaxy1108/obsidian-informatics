#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,mod,fff[4000000];
void work(int x,int* f){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			fff[x]+=(f[i]>f[j]);
		}
	}
}
int kkk[4000000];
int qry(int x){int ret=0;while(x)ret+=kkk[x],ret%=mod,x-=x&-x;return ret;}
void ins(int x,int cnt){while(x<cnt+1)kkk[x]++,x+=x&-x;}
signed main(){
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	scanf("%lld%lld",&n,&mod);
	if(n<=10){
		int cnt=1,ans=0;
		int ff[n+1];
		for(int i=1;i<=n;i++)cnt*=i,ff[i]=i;
		for(int i=1;i<=cnt;i++){
			next_permutation(ff+1,ff+n+1);
			work(i,ff);
		}
		for(int i=cnt-1;i;i--){
			ans=((ans+(qry(fff[i]))%mod)%mod+mod)%mod;
			ins(fff[i]+1,cnt+1);
		}
		cout<<ans<<endl;
	}else puts("YZY AK IOI");
	return 0;
}
