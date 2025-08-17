#include<bits/stdc++.h>
#define int long long
#define N 1000000
#define M 100000
#define A 3000
#define B 3000
#define Mod 998244353
using namespace std;
int n,m,a[N+5],b[N+5],sum[N+5]={},ans=0,maxn=0;
vector<vector<int>>to;
int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	n=read();
	to.resize(n+2);
	for(int i=1;i<=n;i++)a[i]=read(),maxn=max(maxn,a[i]);
	for(int i=1;i<=n+1;i++)to[i].resize(maxn+1);
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>0;j--){
			to[j][a[i]]=i;
			if(a[j]==a[i])break;
		}
//		cout<<i<<" sadfadsfasdf\n";
	}
	for(int i=1;i<=n;i++){
		if(!to[n+1][a[i]])to[n+1][a[i]]=i;
	}
	m=read();
	for(int i=1;i<=m;i++)b[i]=read();
	for(int i=n;i>0;i--){
		sum[i]=1;
		for(int j=1;j<=maxn;j++)sum[i]=(sum[i]+sum[to[i][j]])%Mod;
//		cout<<sum[i]<<" "<<i<<" sum\n";
	}
	int now=n+1,k=1;
	while(now&&k<=m){
//		cout<<now<<" "<<k<<" "<<ans<<" sadfsadfasdf\n";
		for(int i=1;i<=maxn&&i<b[k];i++)ans=(ans+sum[to[now][i]])%Mod;
		if(k<m)ans=(ans+1)%Mod;
		now=to[now][b[k]],k++;
	}
//	if(now!=n+1&&k<=m)
	print(ans+1);
	return 0;
}
