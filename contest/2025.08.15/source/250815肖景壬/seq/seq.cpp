#include<bits/stdc++.h>
using namespace std;
#define XaoWa118 13131
#define awa 1000002
int a[1000005],b[1000005],c[1000005],n,m,cnt,ans;
bool isfind[1000005];
bool chk()
{
	for(int i = 1; i <= min(m,cnt); i++)
	{
		if(c[i]>b[i]) return 0;
		if(c[i]<b[i]) return 1;
	}
	if(cnt<m) return 1; 
	else return 0;
}
int gethash()
{
	int hs=0;
	for(int i = 1; i <= cnt; i++)
	{
		hs*=XaoWa118;
		hs+=c[i];
		hs%=awa;
	}
	return hs;
}
void dfs(int layer)
{
	if(layer>n)
	{
		if(chk())
		{
			if(!isfind[gethash()])
			{
				ans++;
				isfind[gethash()]=1;
				/*for(int i = 1; i <= cnt; i++)
				{
					cout<<c[i];
				}
				cout<<endl;*/
			}
		}
		return;
	}
	cnt++;
	c[cnt]=a[layer];
	dfs(layer+1);
	cnt--;
	dfs(layer+1);
	return;
}
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	cin>>m;
	for(int i = 1; i <= m; i++) cin>>b[i];
	dfs(1);
	cout<<ans<<endl;
}
