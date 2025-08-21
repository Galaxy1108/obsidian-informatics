#include<cstdio>
#include<algorithm>
using namespace std;
const int N=45;
const int mod=998244353;
int n,m,S;
int l[N],r[N];
int f[45][1050];
int b[N];
bool check(int x){
	for(int i=1;i<=m;i++){
		if(x&(1<<(i-1))) b[i]=1;
		else b[i]=0;
	} 
	for(int i=1;i<=m;i++){
		if(b[i]!=b[m-i+1]) return 0;
	}
	return 1;
}
int main(){
	freopen("far.in","r",stdin);
	freopen("far.out","w",stdout);
	scanf("%d%d",&n,&m);
	S=1<<m;
	S--;
	for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
	int ans=0;
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=l[i];j<=r[i];j++){
			for(int k=0;k<=S;k++){
				f[i][j^k]=(f[i][j^k]+f[i-1][k])%mod;
			}
		}
		ans=0;
		for(int j=0;j<=S;j++){
			if(check(j)){
				ans=(ans+f[i][j])%mod;	
			}
		}
		printf("%d\n",ans);
	} 
	return 0;
}
