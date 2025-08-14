#include<bits/stdc++.h>
#define int long long
#define N 100
#define M 10000
#define Mod 998244353
using namespace std;
int n,m,s,t,uu,uv,uw,f[N+5][M+5]={},e=0,ans=0,ver[N+5]={};
bool flag=0;
vector<pair<int,int>>edge[N+5];
queue<int>q;
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
int fpow(int x,int y){
	if(!y)return 1;
	if(y&1)return fpow(x*x%Mod,y>>1)*x%Mod;
	return fpow(x*x%Mod,y>>1);
}
void solve(int x){
//	cout<<x<<" run\n";
//	if(x==t)return;
	for(pair<int,int>i:edge[x]){
//		cout<<i.first<<" "<<i.second<<" "<<fpow(edge[x].size(),Mod-2)<<" "<<x<<" "<<ver[i.first]<<" dfs\n";
		if(!i.second)f[i.first][0]=(f[i.first][0]+fpow(edge[x].size(),Mod-2))%Mod;
		else{
//			cout<<x<<" "<<i.first<<" s\n";
			for(int j=1;j<=m;j++)f[i.first][j]=(f[i.first][j]+fpow(edge[x].size(),Mod-2)*f[x][j-1]%Mod)%Mod;
		}
		ver[i.first]--;
		if(!ver[i.first])q.push(i.first);
	}
	return;
}
main(){
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	n=read(),m=read(),s=read(),t=read();
	for(int i=1;i<=m;i++){
		uu=read(),uv=read(),flag|=uw=read();
//		if(uu==s&&uv==t)cout<<uw<<" asdfadsfasdfassadfd\n";
		ver[uv]++;
		edge[uu].push_back({uv,uw});
//		cout<<flag<<" "<<uw<<" "<<i<<"\n";
	}
	if(!flag){
		print(0),putchar(' '),print(0);
		return 0;
	}
//	cout<<"sadfdasfsdfas\n";
	f[s][0]=1;
	for(int i=1;i<=n;i++){
		if(!ver[i])q.push(i);
	}
	while(q.size()){
		solve(q.front());
		q.pop();
	}
	for(int i=0;i<=m;i++)e=(e+i*f[t][i]%Mod)%Mod;
//	cout<<3*fpow(2,Mod-2)%Mod<<"\n";
	print(e),putchar(' ');
	for(int i=0;i<=m;i++)ans=(ans+((i-e)%Mod+Mod)%Mod*(((i-e)%Mod+Mod)%Mod)%Mod*f[t][i]%Mod)%Mod;
	print(ans);
	return 0;
}
/*
4 5 1 4
1 2 0
2 3 1
1 3 1
2 4 0
3 4 1
*/
