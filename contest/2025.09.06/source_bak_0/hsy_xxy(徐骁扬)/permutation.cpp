#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
typedef pair<int,int> pr;
int n,i,lim;
int p[100010],q[100010],h[100010];
bool vis[100010];
vector<pr> P,Q;
int get_plen(int a)
{
	if(vis[a]) return 0;
	else return vis[a]=true,get_plen(p[a])+1;
}
int get_qlen(int a)
{
	if(vis[a]) return vis[a]=false,get_qlen(q[a])+1;
	else return 0;
}
void mp(int pa,int qa)
{
	if(vis[pa]) return;
	h[qa]=pa,vis[pa]=true;
	return mp(p[pa],q[qa]);
}
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	n=Qread();
	for(i=1;i<=n;i++)
		p[i]=Qread();
	for(i=1;i<=n;i++)
		q[i]=Qread();
	for(i=1;i<=n;i++)
		if(!vis[i])
			P.push_back(make_pair(get_plen(i),i));
	for(i=1;i<=n;i++)
		if(vis[i])
			Q.push_back(make_pair(get_qlen(i),i));
	sort(P.begin(),P.end());
	sort(Q.begin(),Q.end());
	if(P.size()!=Q.size()) printf("NO\n");
	else
	{
		lim=P.size();
		for(i=0;i<lim;i++)
		{
			if(P[i].first!=Q[i].first)
			{
				printf("NO\n");
				return 0;
			}
			mp(P[i].second,Q[i].second);
		}
		printf("YES\n");
		for(i=1;i<=n;i++)
			printf("%d ",h[i]);
		printf("\n");
	}
	return 0;
}