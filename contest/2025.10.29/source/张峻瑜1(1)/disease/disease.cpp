#include <bits/stdc++.h>
using namespace std;
vector <int> tu[305];
vector <int> de[305];
int fa[305],dep[305],maxd=-1;
bool ha[305],tag[305];
void dfs2(int k,int f,int d)
{
	ha[k]=1;
	dep[k]=d;
	maxd=max(maxd,d);
	fa[k]=f;
	for (int i = 0;i < tu[k].size();i++)
	{
		if (ha[tu[k][i]])
		{
			continue;
		}
		dfs2(tu[k][i],k,d+1);
	}
	return;
}
bool pan(int k)
{
	if (tag[k])
	{
		return 1;
	}
	if (fa[k] == k)
	{
		return 0;
	}
	return pan(fa[k]);
}
int bfs[50005],ans=INT_MAX;int n,p,x,y;
void solve()
{
	int l=1,r=1,cnt=1;
	bfs[l]=1;
	bfs[r]=1;
	for (int i = 1;i <= n;i++)
	{
		ha[i]=0;
	}
	ha[1]=1;
	while (l <= r)
	{
		for (int i = 0;i < tu[bfs[l]].size();i++)
		{
			if (ha[tu[bfs[l]][i]] or tag[tu[bfs[l]][i]])
			{
				continue;
			}
			r++;
			cnt++;
			bfs[r]=tu[bfs[l]][i];
			ha[bfs[r]]=1;
		}
		l++;
	}
	ans=min(ans,cnt);
	return;
}
int ansd=INT_MAX;
void dfs(int d)
{
	if (d > maxd)
	{
		solve();
		return;
	}
	if (d > ansd)
	{
		return;
	}
	bool flag=0;
	for (int i = 0;i < de[d].size();i++)
	{
		//cout << de[d][i] << endl;
		if (pan(de[d][i]) == 0)
		{
			tag[de[d][i]]=1;
			flag=1;
			dfs(d+1);
			tag[de[d][i]]=0;
		}
	}
	if (flag == 0)
	{
		solve();
		ansd=d;
		return;
	}
	return;
}
int main()
{
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	cin >> n >> p;
	for (int i = 1;i <= p;i++)
	{
		cin >> x >> y;
		tu[x].push_back(y);
		tu[y].push_back(x);
	}
	fa[1]=1;
	dfs2(1,1,1);
	/*for (int i = 1;i <= n;i++)
	{
		cout << dep[i] << endl;
	}*/
	for (int i = 1;i <= n;i++)
	{
		de[dep[i]].push_back(i);
	}
	dfs(2);
	cout << ans;
	return 0;
 } 
