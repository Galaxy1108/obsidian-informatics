#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct Node
{
	int val;
	int sign;
}num[50005];
int cnt[50005];
queue<Node> Q;
int ans,curr;
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	int n,k,m;
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i].val;
		num[i].sign=i;
	}
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int p,v;
			cin>>p>>v;
			num[p].val=v;
		}
		else
		{
			ans=1e9;
			curr=1;
			memset(cnt,0,sizeof(cnt));
			Q.push(num[1]);
			cnt[num[1].val]++;
			int pos=2;
			while(Q.size()&&pos<=n)
			{
				while(cnt[Q.front().val]>1&&Q.size())
				{
					cnt[Q.front().val]--;
					Q.pop();
				}
				Q.push(num[pos]);
				if(!cnt[num[pos].val])
				{
					curr++;
				}
				cnt[num[pos].val]++;
				if(curr==k)
				{
					ans=min(ans,num[pos].sign-Q.front().sign+1);
				}
				pos++;
			}
			while(Q.size())
			{
				Q.pop();
			}
			if(ans==1e9) ans=-1;
			cout<<ans<<endl;
		}
	}
	return 0;
}
