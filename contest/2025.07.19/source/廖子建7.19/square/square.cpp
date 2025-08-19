#include<bits/stdc++.h>
#define int long long
#define N 100000
#define M 70
#define Mod 1000000007
using namespace std;
int n,a[N+5],p[M+5],tot=0,cnt[M+5]={},sum[N+5][M+5]={},tmp[N+5],ucnt,ans=0,csum[N+5]={};
bool flag[M+5]={},f,df[N+5];
int fpow(int x,int y){
	if(!y)return 1;
	if(y&1)return fpow(x*x%Mod,y>>1)*x%Mod;
	return fpow(x*x%Mod,y>>1);
}
int C(int x,int y){
	if(y<0||x<y)return 0;
	return csum[x]*fpow(csum[x-y]*csum[y]%Mod,Mod-2)%Mod;
}
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
		for(int i=1;i<=tot;i++)cnt[i]=0;
		for(int i=1;i<=n;i++){
			if(!df[i])continue;
			for(int j=1;j<=tot;j++)cnt[j]+=sum[i][j];
		}
		for(int i=1;i<=tot;i++){
			if(cnt[i]%2)return;
		}
		ans++;
		return;
	}
	df[x]=0,dfs(x+1);
	df[x]=1,dfs(x+1);
	return;
}
main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	n=read(),csum[0]=1;
	for(int i=1;i<=n;i++)tmp[i]=a[i]=read();
	for(int i=1;i<=N;i++)csum[i]=csum[i-1]*i%Mod;
	for(int i=2;i<=M;i++){
		if(flag[i])continue;
		p[++tot]=i;
		for(int j=i*2;j<=M;j+=i)flag[j]=1;
	}
	for(int i=1;i<=n;i++){
		f=0;
		for(int j=1;j<=tot&&a[i]>1;j++){
			ucnt=0;
			while(a[i]%p[j]==0)ucnt++,a[i]/=p[j];
			cnt[j]+=ucnt%2;
			sum[i][j]+=ucnt;
			if(ucnt%2)f=1;
		}
		if(!f)ans++;
	}
	if(n<=20){
		ans=0,dfs(1);
		print(ans-1);
		return 0;
	}
	ans=fpow(2,ans);
	for(int i=1;i<=tot;i++){
		ucnt=0;
		for(int j=0;j<=cnt[i];j+=2)ucnt=(ucnt+C(cnt[i],j))%Mod;
		ans=ans*ucnt%Mod;
	}
	print(ans-1);
	return 0;
}
