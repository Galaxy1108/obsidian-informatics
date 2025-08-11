#include<bits/stdc++.h>
#define int long long
#define N 1000000
using namespace std;
int n,m,u=0,ux,to[N+5];
bool flag[1<<22]={};
string s;
pair<int,int>v;
queue<pair<int,int> >p;
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
bool check(int x){
	int cnt,pa=0,pb=-1,tx=x,ua;
	if(x&1^1)return 0;
	for(int i=0;i<2*n;i++){
		if(tx&1)pa=to[pa+1]=i,to[pa+1]=-1;
		if(tx&1^1)pb=to[pb+1]=i,to[pb+1]=-1;
//		cout<<pa<<" "<<pb<<" "<<i<<"\n";
		tx>>=1;
	}
	pa=0,pb=to[0];
//	cout<<pa<<" "<<pb<<"\n";
	for(int i=1;i<=m;i++){
		cnt=0;
		while(pa>=0&&pa<pb)pa=to[pa+1],cnt++;
//		cout<<cnt<<" "<<i<<"\n";
		if(!cnt)return 0;
		for(int j=1;j<=cnt;j++)pb=to[pb+1];
	}
	return pa<0;
}
main(){
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	for(int i=2*n-1;i>=0;i--)u=u*2+(s[i]=='A');
	p.push({u,0}),flag[u]=1;
	while(!p.empty()){
		v=p.front(),p.pop(),u=v.first;
//		for(int i=0;i<2*n;i++)cout<<((u>>i)&1);
//		cout<<" "<<check(u)<<" "<<v.second<<"\n";
		if(check(u)){
			print(v.second);
			return 0;
		}
		for(int i=0;i<2*n-1;i++){
//			cout<<i<<" "<<(u&1)<<" "<<((u>>1)&1)<<" "<<((u&1)^((u>>1)&1))<<"\n";
			if(1^(u&1)^((u>>1)&1)){
				u>>=1;
				continue;
			}
			u>>=1;
//			for(int j=0;j<2*n;j++)cout<<(((3<<i)>>j)&1);
//			cout<<"\n";
			ux=v.first^(3<<i);
			if(flag[ux])continue;
			p.push({ux,v.second+1}),flag[ux]=1;
		}
	}
	return 0;
}
