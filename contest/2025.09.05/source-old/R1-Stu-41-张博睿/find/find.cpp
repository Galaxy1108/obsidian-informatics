#include<bits/stdc++.h>
#include<map>
#include<queue>
using namespace std;
#define re register

const int N=1e3+10;
map< pair<int,int> , int > mp;
priority_queue<int> q;
int n,k;

inline int cal(int x)
{
	int res=1;
	while(x)
	{
		res*=x%10;
		x/=10;
	}
	return res;
}
int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=n;j++)
		{
			int x=cal(i),y=cal(j);
			if(x<1||x>n||y<1||y>n)continue;
			mp[make_pair(x,y)]++;
		}
	}
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=n;j++)
		{
			q.push( mp[make_pair(i,j)] ) ;
		}
	}
	int ans=0;
	for(re int i=1;i<=k;i++)
	{
		ans+=q.top();
		q.pop();
	}
	cout<<ans<<endl;
	return 0;
}
