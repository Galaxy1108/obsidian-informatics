#include<bits/stdc++.h>
using namespace std;
const int maxn=1086;
int a[maxn];
int a1[maxn];
int n,cnt=1111,cc,xx;
inline int read()
{
	int num=0,f=1;
	char ss=getchar();
	while('0'>ss||'9'<ss) { if(ss=='-')f=-f;ss=getchar();}
	while('0'<=ss&&ss<='9'){num=(num<<3)+(num<<1)+(ss^48);ss=getchar();}
	return num;
}
int mm()
{   int cnt1;
	while(cnt>1)
	{
		cnt=0;
		for(int i=1;i<=n;i++) if(a[i]>=1) cnt++;
		if(cnt>1)
		{
		for(int i=1;i<=n;i++) if(a[i]>=1) a[i]-=(cnt-1);
	//	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	//	cout<<endl;
		cnt1=cnt-1;
	    }
	}
//	for(int i=1;i<=n;i++) if(a[i]+cnt1>=1) a[i]+=cnt1;
	cnt=0;
	for(int i=1;i<=n;i++) if(a[i]>=1) cnt++;
	return cnt;
}
void dfs(int x)
{
	if(x>=n+1)
	{
		//cc++;
		cnt=1111;
	    for(int i=1;i<=n;i++) {a[i]=a1[i];}
		if(mm()!=1){
	    cc++;
//	for(int i=1;i<=n;i++)cout<<a1[i]<<' ';
//	 cout<<endl;
	 }
	  return;
	} 
	for(int i=1;i<=xx;i++){
	a1[x]=i;
//	cout<<x<<' '<<i<<endl; 
	dfs(x+1);
    }
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
    n=read();xx=read();
	dfs(1);
	cout<<cc<<endl;
	return 0;
 } 
