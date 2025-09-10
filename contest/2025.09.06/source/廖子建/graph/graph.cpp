#include<bits/stdc++.h>
#define int long long 
#define N 100000
#define M 300000
using namespace std;
int n,m,uu,uv,f[N+5],s[N+5],ans=0;
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
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void merge(int rx,int ry){
	if(s[rx]>s[ry])f[ry]=rx,s[rx]+=s[ry];
	else f[rx]=ry,s[ry]+=s[rx];
	return;
}
main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)f[i]=i,s[i]=1;
	for(int i=1;i<=m;i++){
		uu=find(read()),uv=find(read());
		if(uu!=uv)merge(uu,uv);
	}
	for(int i=1;i<=n;i++){
		if(flag[find(i)])continue;
		flag[find(i)]=1;
		ans+=(s[find(i)]-1)/2;
	}
	print(ans);
	return 0;
}
