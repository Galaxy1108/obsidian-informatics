#include<bits/stdc++.h>
#define ri register
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define fil(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
using namespace std;
inline int rd(){
	register int x=0,f=1;
	register char c=getchar();
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
inline int re(){
	ri char c=getchar();
	while(c==' '||c=='\n'||c=='\r') c=getchar();
	return c-'A'+1;	
}
inline void wt(int n){
	if(n<0) putchar('-'),n=-n;
	if(n>10) wt(n/10);
	putchar(n%10+48);
	return;
}
int n,cd[105],ans,minn;
inline int dfs(int a,int b,int c,int i0){
	if(i0>=n){
		return (a!=0)+(b!=0)+(c!=0);
	}
	int cnt=n;
	int aa[4]={0};
	if(a){
		aa[0]=aa[1]=aa[2]=aa[3]=0;
		for(int i=i0+1;i<=min(n,i0+a);i++) aa[cd[i]]++;
		cnt=min(cnt,dfs(aa[1],aa[2]+b,aa[3]+c,min(i0+a,n))+1);		
	}
	if(b){
		aa[0]=aa[1]=aa[2]=aa[3]=0;
		for(int i=i0+1;i<=min(n,i0+b);i++) aa[cd[i]]++;
		cnt=min(cnt,dfs(aa[1]+a,aa[2],aa[3]+c,min(i0+b,n))+1);		
	}
	if(c){
		aa[0]=aa[1]=aa[2]=aa[3]=0;
		for(int i=i0+1;i<=min(n,i0+c);i++) aa[cd[i]]++;
		cnt=min(cnt,dfs(aa[1]+a,aa[2]+b,aa[3],min(i0+c,n))+1);		
	}
	return cnt;
}
int main(){
	fil("worker");
	n=rd();
	for(ri int i=1;i<=n;i++) cd[i]=re();
	int a[4]={0};
	for(ri int i=1;i<=min(10,n);i++) a[cd[i]]++;
	wt(dfs(a[1],a[2],a[3],min(10,n)));
	return 0;
}
