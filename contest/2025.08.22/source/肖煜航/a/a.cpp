#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,mod;
int f[10000005],g[10000005];
int s1[10000005],s2[10000005];
int s3[10000005],s4[10000005];
inline int get(int x,int y){
	if(y==0) return 0;
	return (x-1)*m+y;
}
int jia(int x,int y){
	x+=y;
	if(x>mod) x-=mod;
	return x; 
}
int jian(int x,int y){
	x-=y;
	if(x<0) x+=mod;
	return x;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mod);
	for(int i=1;i<=m;i++){
		f[i]=(m-i+1)%mod;
		g[i]=i%mod;
	}
	for(int j=1;j<=m;j++){
			#define i 1
			s1[get(i,j)]=(s1[get(i,j-1)]+f[get(i,j)])%mod;
			s2[get(i,j)]=(s2[get(i,j-1)]+g[get(i,j)])%mod;
			s3[get(i,j)]=(s3[get(i,j-1)]+1ll*f[get(i,j)]*j%mod)%mod;
			s4[get(i,j)]=(s4[get(i,j-1)]+1ll*g[get(i,j)]*j%mod)%mod;
			#undef i
		}
	for(int i=2;i<=n;i++){
		int sum=s1[get(i-1,m)];
		for(int j=1;j<=m;j++){
			f[get(i,j)]=jia(jian(1ll*sum*(m-j+1)%mod,jia(1ll*s2[get(i-1,j-1)]*(m-j+1)%mod,jian(s3[get(i-1,m)],s3[get(i-1,j)]))),1ll*jian(s1[get(i-1,m)],1ll*s1[get(i-1,j)])*j%mod);
			g[get(i,j)]=jia(jian(1ll*sum*j%mod,jia(1ll*jian(s1[get(i-1,m)],s1[get(i-1,j)])*j%mod,1ll*s2[get(i-1,j-1)]*j%mod)),s4[get(i-1,j-1)]);
		}
		for(int j=1;j<=m;j++){
			s1[get(i,j)]=(s1[get(i,j-1)]+f[get(i,j)])%mod;
			s2[get(i,j)]=(s2[get(i,j-1)]+g[get(i,j)])%mod;
			s3[get(i,j)]=(s3[get(i,j-1)]+1ll*f[get(i,j)]*j%mod)%mod;
			s4[get(i,j)]=(s4[get(i,j-1)]+1ll*g[get(i,j)]*j%mod)%mod;
		}
	}
	printf("%d",s1[get(n,m)]);
	return 0;
}
