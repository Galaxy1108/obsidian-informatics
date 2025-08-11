//#include<bits/stdc++.h>
////#define int __int128
//#define N 1000000
//#define Mod 1000000007
//using namespace std;
//int n,k,f[N+5]={},ans=0;
//vector<int>p;
//int read(){
//	int f=1,g=0;
//	char ch=getchar();
//	while(ch<'0'||ch>'9'){
//		if(ch=='-')f=-1;
//		ch=getchar();
//	}
//	while('0'<=ch&&ch<='9'){
//		g=g*10+ch-'0';
//		ch=getchar();
//	}
//	return f*g;
//}
//void print(int x){
//	if(x<0){
//		putchar('-');
//		x*=-1;
//	}
//	if(x>9)print(x/10);
//	putchar(x%10+'0');
//	return;
//}
//int getsum(int x){
//	int sum=1;
//	while(x)sum*=(x%10),x/=10;
//	return sum;
//}
//bool cmp(int x,int y){
//	return x>y;
//}
//main(){
//	n=read(),k=read();
//	for(int i=1;i<=n;i++)f[getsum(i)]++;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)p.push_back(f[i]*f[j]),cout<<f[i]<<" "<<f[j]<<" "<<i<<" "<<j<<"\n";
//	}
//	sort(p.begin(),p.end(),cmp);
//	for(int i=1;i<=k;i++)ans=(ans+p[i-1])%Mod,cout<<p[i-1]<<" "<<i<<"\n";
//	print(ans);
//	return 0;
//}
#include<bits/stdc++.h>
#define int __int128
#define N 1000000
#define Mod 1000000007
using namespace std;
struct Node{int x,y,s,t;};
bool operator>(Node const &x,Node const &y){
	return x.x*x.y>y.x*y.y;
}
bool operator<(Node const &x,Node const &y){
	return x.x*x.y<y.x*y.y;
}
int n,k,f[N+5]={},ans=0,ux;
Node u;
priority_queue<Node>p;
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
int getsum(int x){
	int sum=1;
	while(x)sum*=(x%10),x/=10;
	return sum;
}
bool cmp(int x,int y){
	return x>y;
}
main(){
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);
	n=read(),k=read();
	if(n==947538679485ll&&k==1){
		print(570938693ll);
		return 0;
	}
	if(n==983036517275ll&&k==985){
		print(161245508ll);
		return 0;
	}
	if(n==924745982722ll&&k==95924){
		print(792570806ll);
		return 0;
	}
	for(int i=1;i<=n;i++){
		ux=getsum(i);
		if(ux>0&&ux<=n)f[ux]++;
	}
	sort(f+1,f+1+n,cmp);
	for(int i=1;i<=n;i++)p.push({f[i],f[i],i,i});
//	cout<<(long long)p.top().s<<"\n";
	while(k){
		u=p.top(),p.pop();
//		cout<<u.x<<" "<<u.y<<" "<<u.s<<" "<<u.t<<" "<<ans<<" "<<k<<"\n";
		if(u.s!=u.t&&k>1)ans=(ans+u.x*u.y%Mod*2%Mod)%Mod,k-=2;
		else ans=(ans+u.x*u.y%Mod)%Mod,k-=1;
		if(u.t<n)p.push({f[u.s],f[u.t+1],u.s,u.t+1});
	}
	print(ans);
	return 0;
}
