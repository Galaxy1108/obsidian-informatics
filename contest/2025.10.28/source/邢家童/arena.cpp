#include<bits/stdc++.h>
#define gc getchar()
#define cin(a) a=read()
#define M 511
#define P 998244353
#define int long long
using namespace std;

//== == == =read== == == =
int read(){
	int x=0;bool fl=0;char s=gc;
	while(!isdigit(s)){if(s=='-')fl=1;s=gc;}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=gc;
	return fl?-x:x;
}

//== == == =type== == == =
int n,x,ans;
int dp[M][M],h[M],inv[M];

//== == == =ksm== == == =
int ksm(int x,int y){
	int res=1;
	if(!x)return 1;
	while(y){
		if(y&1)res=res*x%P;
		y>>=1;x=x*x%P;
	}
	return res;
}

//== == == =init== == == =
void init(){
	h[0]=1;
	for(int i=1;i<=n;i++)h[i]=h[i-1]*i%P;
	inv[n]=ksm(h[n],P-2);
	for(int i=n-1;i>=0;i--)inv[i]=(i+1)*inv[i+1]%P;
}

//== == == =C== == == =
int C(int x,int y){
	return h[x]*inv[y]%P*inv[x-y]%P;
}

#undef int
//== == == =main== == == =
int main(){
#define int long long
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin(n);cin(x);init();
	for(int i=1;i<=x;i++)dp[i][1]=n;
	for(int i=1;i<=x;i++){
		for(int j=2;j<=i&&j<=n;j++){
			for(int k=1;k<=j;k++){
				dp[i][j]=(dp[i][j]+dp[i-j+1][k]*ksm(j-1,j-k)%P*C(n-k,j-k))%P;
			}
		}
	}
	for(int i=1;i<=x;i++)ans=(ans+dp[i][n])%P;
	cout<<(ksm(x,n)-ans+P)%P<<'\n';
	return 0;
}
