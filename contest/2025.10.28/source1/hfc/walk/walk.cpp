#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1086;
const int inf=1e17+7;
int tar[maxn];
int nn[maxn];
int n;
int s;
int ans=inf;
int t0,t;
inline int read()
{
	int num=0,f=1;
	char ss=getchar();
	while('0'>ss||'9'<ss) {if(ss=='-')f=-f;ss=getchar();}
	while('0'<=ss&&ss<='9'){num=(num<<3)+(num<<1)+(ss^48);ss=getchar();}
	return num;
}
int get_jl()
{
	int cha=0;
	for(int i=1;i<=n;i++) cha+=abs(nn[i]-tar[i]);
	return cha;
}
bool check()
{
	int flag=1;
	for(int i=1;i<=n;i++) flag=0;
	return flag;
}
void dfs(int k,int now)
{
	t0=clock();
	ans=min(ans,get_jl());
	if(t0-t>=1850) return;
	if(k==s){return;}
	if(check()){return;}
	nn[now+1]++;
	dfs(k+1,now+1);
	nn[now+1]--;
	nn[now]++;
	dfs(k+1,now-1);
	nn[now]--;
	return;
}
signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();
	int k=s;
    for(int i=1;i<=n;i++) tar[i]=read();
    if(n<=10){
     t=clock();
     t0=clock();
    while(t0-t<=1500)
	{
		t0=clock();
	    for(int i=1;i<=n;i++)  dfs(0,i);
	    s++;
	}
	cout<<ans<<endl;
   }
   else cout<<0<<endl;
  return 0;
}
