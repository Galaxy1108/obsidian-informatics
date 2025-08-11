#include<bits/stdc++.h>
#define N 600
#define Mod 1000000007
using namespace std;
int n,a[N+5]={},f[N+5],ans=0,cnt[N+5],b[N*2+5],tmp[N*2+5];
bool flag[N+5];
vector<int>p;
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
	if(x>2*n){
		for(int i=1;i<=2*n;i++)tmp[i]=b[i];
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++)flag[j]=0;
//			cout<<i<<"\n";
//			for(int j=1;j<=2*n;j++)cout<<tmp[j]<<" ";
//			cout<<"\n";
			for(int j=2*n;j>0;j--){
				if(!tmp[j])continue;
				if(flag[tmp[j]])tmp[j]--;
				else flag[tmp[j]]=1;
			}
//			for(int j=1;j<=2*n;j++)cout<<tmp[j]<<" ";
//			cout<<"\n";
		}
//		cout<<"\n";
		for(int i=1;i<=2*n;i++){
			if(f[i]&&!tmp[i])return;
			if(!f[i]&&tmp[i])return;
		}
		ans=(ans+1)%Mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!cnt[i])continue;
		cnt[i]--,b[x]=i;
		dfs(x+1),cnt[i]++;
	}
	return;
}
main(){
	freopen("ruin.in","r",stdin);
	freopen("ruin.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),f[a[i]]=1,cnt[i]=2;
	dfs(1);
	print(ans);
	return 0;
}
