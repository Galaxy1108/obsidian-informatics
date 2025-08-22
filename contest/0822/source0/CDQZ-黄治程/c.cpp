#include<bits/stdc++.h>
namespace IO{
	inline char gc(){
		static const int Rlen=1<<18|1;static char buf[Rlen],*p1,*p2;
		return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,Rlen,stdin),p1==p2)?EOF:*p1++;
	}
	template<typename T>T get_integer(){
		char c;bool f=false;while(!isdigit(c=gc()))f=c=='-';T x=c^48;
		while(isdigit(c=gc()))x=((x+(x<<2))<<1)+(c^48);return f?-x:x;
	}
	inline int gi(){return get_integer<int>();}
}
using namespace std;
using namespace IO;
const int N=5010;
int n,a[N][N],vis[N],f[N],ans[N];
void gen(int n,int seed){
	mt19937 rnd(seed);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++){
			a[i][j]=j;
			swap(a[i][j],a[i][rnd()%j+1]);
		}
	}
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=gi();
	int seed=gi(),noww,nowww,minn;
	if(seed){
		gen(n,seed);
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n+1;j++){
				a[i][j]=gi();
			}
		}
	}
	for(int j=n;;){
		minn=1e9;
		for(int k=1;k<=n+1;k++){
			if(!vis[k]&&minn>a[j][k]){
				minn=a[j][k];
				f[j]=k;
			}
		}
		vis[f[j]]=1;
		j=(j-2+n)%n+1;
		if(j==n){
			break;
		}
	}
	for(int j=1;j<=n+1;j++){
		if(!vis[j]){
			ans[1]=nowww=j;
			break;
		}
	}
	for(int now=n;;){
		vis[f[now]]=0;
		noww=f[now];
		for(int j=(now-2+n)%n+1;;){
			if(a[j][noww]<a[j][f[j]]){
				swap(vis[noww],vis[f[j]]);
				swap(noww,f[j]);
			}
			j=(j-2+n)%n+1;
			if(j==now){
				break;
			}
		}
		if(a[now][nowww]<a[now][noww]){
			swap(nowww,noww);
		}
		f[now]=noww;
		vis[noww]=1;
		ans[now]=nowww;
		now=(now-2+n)%n+1;
		if(now==n){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
}