#include<bits/stdc++.h>
using namespace std;
const int final_tries = 1000000;
int ans=1145141919,n,m,x,y,tmp,dep[305],nowdel,nsz[305],tot,oldsz,relsz,cpy[305],nans;
bool ismmdx[305];
vector<int> son[305],v[305];
int nowd[305],sz;
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	for(int i = 0; i < v[x].size(); i++)
	{
		if(v[x][i]!=fa)
		{
			son[x].push_back(v[x][i]);
			dfs(v[x][i],x);
		}
	}
	return;
}
int main()
{
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	srand(time(0));
	cin>>n>>m;
	m=n-1;
	for(int i = 1; i <= m; i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	for(int i = 1; i <= n; i++)
	{
		nsz[i]=son[i].size();
	}
	for(int i = 1; i <= final_tries; i++)
	{
		nans=0;
		nowd[1]=1;
		sz=1;
		while(sz)
		{
			tot=0;
			for(int j = 1; j <= sz; j++)
			{
				nans++;
				cpy[j]=nowd[j];
				tot+=nsz[nowd[j]];
			}
			oldsz=sz;
			sz=0;
			relsz=0;
			if(tot) nowdel=rand()%tot+1;
			for(int j = 1; j <= oldsz; j++)
			{
				for(int k = 0; k < nsz[cpy[j]]; k++)
				{
					sz++;
					if(sz==nowdel)
					{
						continue;
					}
					relsz++;
					nowd[relsz]=son[cpy[j]][k];
				}
			}
			sz=relsz;
		}
		ans=min(nans,ans);
	}
	cout<<ans<<endl;
}
