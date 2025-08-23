#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const int MOD=998244353;
ll b[N],pw[N],n,s,cnt[N];
priority_queue<int>q;
int get()
{
	ll sum=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		sum+=b[i];
		ans+=pw[i];
		if(sum>=s)
		{
			sum-=s;
			for(int j=i-1;j>=1;j--)
			{
				if(b[j]<=sum)
				{
					sum-=b[j];
					ans-=pw[j];
				}
			}
			break;
		}
	}
	return (ans%MOD+MOD)%MOD;
}
int main()
{
	freopen("imperishable.in","r",stdin);
	freopen("imperishable.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pw[0]=1;
	for(int i=1;i<N;i++)pw[i]=pw[i-1]*2%MOD;
	int id,T;
	cin>>id>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		q.push(b[i]);
		s=max(s,b[i]);
		cnt[b[i]]++;
	}
	cout<<get()<<'\n';
	cin>>T;
	while(T--)
	{
		int x,y;
		cin>>x>>y;
		cnt[b[x]]--;
		cnt[y]++;
		q.push(y);
		if(y>s)s=y;
		if(!cnt[b[x]]&&s==b[x])
		{
			while(1)
			{
				if(cnt[q.top()])
				{
					s=q.top();
					break;
				}
				q.pop();
			}
		}
		b[x]=y;
		cout<<get()<<'\n';
	}
	return 0;
}
