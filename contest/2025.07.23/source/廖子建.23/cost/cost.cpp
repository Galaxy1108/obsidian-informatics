#include<bits/stdc++.h>
#define int long long
#define N 1024ll
using namespace std;
int n,m,f[N+5][N+5],c[N+5],a[N+5],ans=INT_MAX*N;
bool flag[N+5];
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
int cnta(int x){
	if(x>=(1ll<<n)){
//		cout<<x<<" "<<(x-(1ll<<n)+1)<<" "<<a[x-(1ll<<n)+1]<<"\n";
		return a[x-(1ll<<n)+1]^1;
	}
	return cnta(x<<1)+cnta((x<<1)+1);
}
int cntb(int x){
	if(x>=(1ll<<n))return a[x-(1ll<<n)+1];
	return cntb(x<<1)+cntb((x<<1)+1);
}
int lca(int x,int y){
	int lx=0,ly=0,ux=x,uy=y,sum=0;
	while(ux)lx++,ux>>=1;
	while(uy)ly++,uy>>=1;
//	cout<<x<<" "<<y<<" "<<m<<" lca\n";
//	if(x==19&&y==23)cout<<lx<<" "<<ly<<"\n";
	for(int i=1;i<=min(lx,ly);i++){
//		if(x==19&&y==23)cout<<((x>>(lx-i))&1)<<" "<<((y>>(ly-i))&1)<<" "<<i<<" "<<sum<<"\n";
		if(((x>>(lx-i))&1)!=((y>>(ly-i))&1))break;
		sum=sum*2+((x>>(lx-i))&1);
	}
	return sum;
}
void dfs(int x){
	if(x>m){
		int sum=0,l,ca,cb;
		for(int i=1;i<=m;i++)a[i]^=flag[i],sum+=c[i]*flag[i];
//		a[1]=0;
//		cout<<sum<<"\n";
		for(int i=1;i<m;i++){
			for(int j=i+1;j<=m;j++){
				l=lca(i+m-1,j+m-1);
				ca=cnta(l),cb=cntb(l);
//				cout<<i<<" "<<j<<" "<<l<<" "<<ca<<" "<<cb<<" ";
				if(ca<cb){
					if(a[i]==0&&a[j]==0)sum+=2*f[i][j];
					else if(a[i]==1&&a[j]==0)sum+=1*f[i][j];
					else if(a[i]==0&&a[j]==1)sum+=1*f[i][j];
				}
				else{
					if(a[i]==1&&a[j]==1)sum+=2*f[i][j];
					else if(a[i]==1&&a[j]==0)sum+=1*f[i][j];
					else if(a[i]==0&&a[j]==1)sum+=1*f[i][j];
				}
//				cout<<sum<<"\n";
			}
		}
		for(int i=1;i<=m;i++)a[i]^=flag[i];
		ans=min(ans,sum);
//		cout<<sum<<"\n"; 
//		exit(0);
		return;
	}
	flag[x]=0,dfs(x+1);
	flag[x]=1,dfs(x+1);
	return;
}
main(){
	freopen("cost.in","r",stdin);
	freopen("cost.out","w",stdout);
	n=read(),m=(1ll<<n);
	for(int i=1;i<=m;i++)a[i]=read();
	for(int i=1;i<=m;i++)c[i]=read();
	for(int i=1;i<m;i++){
		for(int j=i+1;j<=m;j++)f[i][j]=f[j][i]=read();
	}
	dfs(1),print(ans);
	return 0;
}
