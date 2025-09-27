#include<bits/stdc++.h>
//#define int long long 
using namespace std;
const int mx=410;
const int inf=1e8;

char ch[mx];
int cnt[5],a[mx];
int ans=0;

signed main() 
{
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n=0;bool flag=1;
	while(cin>>ch[++n])
	{
		if(ch[n]==ch[n-1]) flag=0;
		a[n]=ch[n]-'0';
		cnt[a[n]]++;
	}
	n--;
	if(flag) 
	{
		cout<<0;
		return 0;
	}
	if(cnt[0]>(n+1)/2||cnt[1]>(n+1)/2||cnt[2]>(n+1)/2)
	{
		cout<<-1;
		return 0;
	}
	queue<int> q;
	for(int i=2;i<=n;i++)
	{
		if(q.size()&&a[i]!=a[q.front()])
		{
			ans+=(i-q.front());
			swap(a[i],a[q.front()]);
			q.pop();
			int k=q.size();
			for(int i=1;i<=k;i++)
			{
				q.push(q.front()+1);
				q.pop();
			}
			continue;
		}
		if(a[i]==a[i-1]) q.push(i);
	}
	cout<<ans;
	return 0;
}
