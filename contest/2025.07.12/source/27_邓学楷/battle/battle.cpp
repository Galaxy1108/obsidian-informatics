#include <bits/stdc++.h>
using namespace std;

const int N=150010;
int n;
bool block[N];

struct node
{
	int id;
	long long num;
	bool operator <(const node &other) const
	{
		return num<other.num;
	}
};

int main()
{
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	long long a,b,c;
	node l,m,t;
	priority_queue<node> luck,move,think;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		luck.push({i,a});
		move.push({i,b});
		think.push({i,c});
	}
	while (!luck.empty() && !move.empty() && !think.empty())
	{
		if (block[luck.top().id])
		{
			luck.pop();
			continue;
		}
		if (block[move.top().id])
		{
			move.pop();
			continue;
		}
		if (block[think.top().id])
		{
			think.pop();
			continue;
		}
		l=luck.top(),m=move.top(),t=think.top();
		if (l.id!=m.id && l.id!=t.id && m.id!=t.id)
		{
			printf("%lld\n",l.num+m.num+t.num);
			return 0;
		}
		if (l.id==m.id)
			block[l.id]=1;
		if (l.id==t.id)
			block[l.id]=1;
		if (t.id==m.id)
			block[t.id]=1;
	}
	printf("-1\n");
	return 0;
}
