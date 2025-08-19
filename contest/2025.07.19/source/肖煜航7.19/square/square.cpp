#include<cstdio>
#include<algorithm>
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch<='9'&&ch>='0') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int mod=1e9+7;
int qpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=1ll*ans*x%mod;
		y>>=1;
		x=1ll*x*x%mod;
	}
	return ans;
}
int pri[55]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int solve(int x){
	int ans=0;
	for(int i=0;i<19;i++){
		int op=0;
		while(x%pri[i]==0){
			x/=pri[i];
			op^=1;
		}
		ans+=op*(1<<i);
	}
	return ans;
}
int a[30];
int cnt;
void insert(int x){
	for(int i=18;i>=0;i--){
		if(x&(1<<i)){
			if(a[i]){
				x^=a[i];
			}
			else{
				a[i]=x;
				cnt++;
				return;
			}
		}
	}
}
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++) insert(solve(read()));
	int ans=qpow(2,n-cnt);
	ans--;
	ans=(ans%mod+mod)%mod;
	printf("%d",ans);
	return 0;
}
