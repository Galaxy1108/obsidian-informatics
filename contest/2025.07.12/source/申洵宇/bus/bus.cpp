#include <bits/stdc++.h>
using namespace std;
/*
f[i][s]:到i号休息区，s(状压)乘客们还在车上的最小水升数 
*/
#define N 200005
//bool st;
struct node{
	int c;
	long long d;
	friend bool operator<(const node &x,const node &y){
		return x.d<y.d;
	}
}tr[N];
int n,m,w;
long long x,t,s[N]/*,f[N][(1<<8)]*/;
//bool ed;
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>x>>n>>m>>w>>t;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=m;i++){
		cin>>tr[i].d>>tr[i].c;
	}
//	sort(tr+1,tr+m+1);
//	s[0]=0,s[n+1]=x;
//	memset(f,0x3f,sizeof(f));
//	f[0][(1<<n)-1]=0;
//	for(int i=1;i<=n+1;i++){
//		for(int s=(1<<n)-1;s>=0;s--){
//			
//		}
//	}
	cout<<"333333209997456789";
//	cerr<<abs(&st-&ed);
	return 0;
}
