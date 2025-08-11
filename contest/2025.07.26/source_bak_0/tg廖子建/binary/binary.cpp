#include<bits/stdc++.h>
#define int long long
#define N 10
using namespace std;
int n,m,l,r,h[N+5]={},a[15]={0,0,2,5,11,23,47,95,191,383,767},cnt[N+5]={},ux,uy;
char ans[2000][2000];
bool flag[2000][2000],u;
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
bool dfs(int x,int y,int z,int b){
	if(x>r)return 0;
//	cout<<x<<" "<<y<<" "<<z<<" "<<b<<" "<<ans[235][1]<<"\n";
//	if(x==235&&y==1)cout<<x<<" "<<y<<" "<<z<<" "<<b<<"\n";
	if(x==h[z]){
		cnt[z]++;
		if(flag[z][cnt[z]])return 0;
		ans[x][y]='o';
		dfs(x+1,y-1,z+1,0),dfs(x+1,y+1,z+1,1);
		return 1;
	}
	if(!b){
		ans[x][y]='/';
		u=dfs(x+1,y-1,z,0);
//		cout<<u<<" "<<x<<" "<<y<<" "<<z<<" "<<b<<"\n";
		if(!u)ans[x][y]=' ';
		return u;
	}
//		if(y==1)cout<<x<<" "<<y<<" "<<z<<" "<<b<<"   asdasdqsdsad\n";
	ans[x][y]='\\';
	u=dfs(x+1,y+1,z,1);
//	cout<<u<<" "<<x<<" "<<y<<" "<<z<<" "<<b<<"\n";
	if(!u)ans[x][y]=' ';
	return u;
}
main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	m=read(),n=read();
	l=(a[m]+1)*2-1,r=(a[m]+1);
	for(int i=1;i<=r;i++){
		for(int j=1;j<=l;j++)ans[i][j]=' ';
	}
	for(int i=1;i<=m;i++)h[i]=a[m]+1-a[m-i+1];
	for(int i=1;i<=n;i++){
		ux=read(),uy=read();
		flag[ux][uy]=1;
	}
//	cout<<l<<" "<<r<<" "<<a[m]+1<<"\n";
//	cout<<ans[235][1]<<"\n";
	dfs(1,(a[m]+1),1,1);
//	cout<<ans[235][1]<<"\n";
	for(int i=1;i<=r;i++){
		for(int j=1;j<=l;j++){
			cout<<ans[i][j];
		}
		cout<<"\n";
	}
	return 0;
}
