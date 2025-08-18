#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,suma[1005],sumb[1005],sumc[1005];
int memal[15][15][15][125];
bool visal[15][15][15][125];
#define mem memal[la][lb][lc][pos]
#define vis visal[la][lb][lc][pos]
int dfs(int la,int lb,int lc,int pos)
{
	if(vis)return mem;
	vis=true;
	if(pos+9>=n+1&&la==0&&lb==0&&lc==0)return mem=0;
	int res=0x3f3f3f3f;
	if(la!=0)res=min(res,dfs(suma[pos+9+la]-suma[pos+9],lb+sumb[pos+9+la]-sumb[pos+9],lc+sumc[pos+9+la]-sumc[pos+9],pos+la)+1);
	if(lb!=0)res=min(res,dfs(la+suma[pos+9+lb]-suma[pos+9],sumb[pos+9+lb]-sumb[pos+9],lc+sumc[pos+9+lb]-sumc[pos+9],pos+lb)+1);
	if(lc!=0)res=min(res,dfs(la+suma[pos+9+lc]-suma[pos+9],lb+sumb[pos+9+lc]-sumb[pos+9],sumc[pos+9+lc]-sumc[pos+9],pos+lc)+1);
	return mem=res;
}
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		suma[i]=suma[i-1];
		sumb[i]=sumb[i-1];
		sumc[i]=sumc[i-1];
		if(ch=='A')suma[i]++;
		if(ch=='B')sumb[i]++;
		if(ch=='C')sumc[i]++;
	}
	for(int i=n+1;i<=n+20;i++)
	{
		suma[i]=suma[n];
		sumb[i]=sumb[n];
		sumc[i]=sumc[n];
	}
	if(n<10)cout<<((suma[n]>0)+(sumb[n]>0)+(sumc[n]>0));
	else cout<<dfs(suma[10],sumb[10],sumc[10],1);
	
	return 0;
} 
