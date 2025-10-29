#include<bits/stdc++.h>
#define gc getchar()
#define cin(a) a=read()
#define M 211
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
int n,P,ans;
int f[M][M*M],g[M][M*M];

#undef int
//== == == =main== == == =
int main(){
#define int long long
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	cin(n);cin(P);
	g[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i*i;j++){
			for(int k=1;k<=i;k++){
				for(int l=1;l<=i;l++){
					g[i][j]=(g[i][j]+g[i-1][abs(j+k-l)])%P;
					if(k>l)f[i][j]=(f[i][j]+g[i-1][j+k-l])%P;
					if(k==l)f[i][j]=(f[i][j]+f[i-1][j])%P;
				}
			}
		}
	}
	for(int j=1;j<=n*n;j++)ans=(ans+f[n][j])%P;
	cout<<ans<<'\n';
	return 0;
}
