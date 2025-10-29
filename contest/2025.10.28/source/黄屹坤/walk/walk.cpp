#include<bits/stdc++.h>
#define INF 10000000000000007
#define gc getchar()
#define ll long long
#define I inline int
#define V inline void
#define LL inline long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
using namespace std;
I read(){
	int x=0;bool fl=0;char s=gc;
	while('0'>s||s>'9'){fl|=(s=='-');s=gc;}
	while('0'<=s&&s<='9'){x=x*10+s-48;s=gc;}
	return fl?-x:x;
}

const int N=200011;
int n,a[N],A1[N];
ll ans=INF,f1[N],f2[N],amt4[N],amt3[N],amt2[N],amt1[N]; 

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout); 
	
	n=read();
	FOR(i,1,n)a[i]=read();
	int s=n,t=0,tot=0;
	FOR(i,1,n)if(a[i]!=0){s=i;break;}
	ROF(i,n,1)if(a[i]!=0){t=i;break;}
	if(s>t){cout<<0;return 0;}
	FOR(i,s,t)A1[++tot]=a[i];
	FOR(i,1,tot)a[i]=A1[i];
	n=tot;
	
	FOR(i,1,n)amt1[i]=amt1[i-1]+(a[i]==0);
	FOR(i,1,n)amt2[i]=amt2[i-1]+(a[i]&1);
	FOR(i,1,n)amt3[i]=i-amt2[i];
	FOR(i,1,n)amt4[i]=amt4[i-1]+a[i];
		
	ll now=INF;
	FOR(i,0,n){
		now=min(now,amt4[i]-amt1[i]*2-amt2[i]);
		f1[i]=now+amt1[i]*2+amt2[i];	
	}
	now=INF;
	ROF(i,n,0){
		now=min(now,amt4[n]-amt4[i]+amt1[i]*2+amt2[i]);
		f2[i]=now-amt1[i]*2-amt2[i];
	}
	now=INF;
	FOR(i,0,n){
		now=min(now,f1[i]-amt3[i]);		
		ans=min(ans,now+amt3[i]+f2[i]);
	}
	cout<<ans;
	return 0;
} 
/*
4
1
0
2
3

5
0
7
2
4
8

*/

