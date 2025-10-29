#include <bits/stdc++.h>
using namespace std;
const int maxn=45;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)) {x=x*10+(c^48);c=getchar();}
	while(isdigit(c)) {if(c=='-') f=-1;c=getchar();}
}
int n,res[maxn<<1];
bool b[maxn];
string name[maxn];
inline bool dfs(int pos)
{
	while(res[pos]) pos++;
	if(pos==n*2+1) return 1;
	for(int i=n;i>=1;i--)
	{
		if(b[i]) continue ;
		if(pos+i>=2*n) continue ;
		if(res[pos+i+1]) continue ;
		b[i]=1;res[pos]=res[pos+i+1]=i;
		if(dfs(pos)) return 1;
		b[i]=0;res[pos]=res[pos+i+1]=0;
	}
	return 0;
}
int main()
{
//	freopen("flower.in","r",stdin);
//	freopen("flower.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>name[i];
	dfs(1);
	for(int i=1;i<=2*n;i++) cout<<name[res[i]]<<endl;
	return 0;
}
