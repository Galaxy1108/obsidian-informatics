#include<bits/stdc++.h>
#define int long long
#define N 200000
#define M 2000000
#define R(x) ((x)==n?1:(x)+1)
using namespace std;
int n,m[N+5],f[N+5],ans=LONG_LONG_MAX,tmp[N+5];
vector<int>a[N+5];
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
void dfs(int x){
	if(x>n){
		int sum=0,tot;
//		if(f[1]==2&&f[2]==3&&f[3]==3&&f[4]==3){
//		for(int i=1;i<=n;i++){
//			cout<<f[i]<<" ";
//		}
//		}
//		if(f[1]==2&&f[2]==3&&f[3]==3&&f[4]==3)cout<<"\n";
		for(int i=1;i<=n;i++){
//			cout<<f[i]<<" ";
			tot=0;
			tmp[++tot]=0;
			for(int j=f[i];j<=m[i];j++)tmp[++tot]=a[i][j];
			for(int j=1;j<f[R(i)];j++)tmp[++tot]=a[R(i)][j];
			tmp[++tot]=M;
			sort(tmp+1,tmp+1+tot);
//			for(int j=f[i];j<=m[i];j++){
//				sum+=(last-a[i][j])*(last-a[i][j]),last=a[i][j];
//				if(f[1]==2&&f[2]==3&&f[3]==3&&f[4]==3)cout<<a[i][j]<<" ";
//			}
//			if(f[1]==2&&f[2]==3&&f[3]==3&&f[4]==3)cout<<"\n";
//			for(int j=1;j<f[R(i)];j++)sum+=(last-a[R(i)][j])*(last-a[R(i)][j]),last=a[R(i)][j];
//			sum+=(M-last)*(M-last);
			for(int j=1;j<tot;j++)sum+=(tmp[j+1]-tmp[j])*(tmp[j+1]-tmp[j]);
//			if(f[1]==2&&f[2]==3&&f[3]==3&&f[4]==3)cout<<sum<<" "<<i<<"\n";
		}
//		if(f[1]==2&&f[2]==3&&f[3]==3&&f[4]==3)cout<<sum<<"\n";
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=m[x];i++)f[x]=i,dfs(x+1);
	return;
}
main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		m[i]=read(),a[i].push_back(0);
		for(int j=1;j<=m[i];j++)a[i].push_back(read());
	}
	dfs(1);
	print(ans);
	return 0;
}
