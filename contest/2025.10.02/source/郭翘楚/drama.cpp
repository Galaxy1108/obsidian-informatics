#include <bits/stdc++.h>
using namespace std;
long long h[2000005];
long long r_min[2000005];//第i个数左边第一个比h[i]小的 
long long l_min[2000005];//第i个数右边第一个比h[i]小的 
long long r_max[2000005];//第i个数左边第一个比h[i]大的 
long long l_max[2000005];//第i个数右边第一个比h[i]大的 
__int128 ans;
long long n;
stack<long long> st; 
void write(__int128 x)
{
    static long long sta[129];
    long long top = 0;
    do 
    {
        sta[top++] = x % 10, x /= 10;
    }while (x);
    while(top) putchar(sta[--top] + 48);
}
void init()
{
	for(long long i=1;i<=n;i++)
	{
		while(!st.empty() and h[st.top()]>=h[i])
		{
			st.pop();
		}
		l_min[i]=st.empty()?0:st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(long long i=n;i>=1;i--)
	{
		while(!st.empty() and h[st.top()]>=h[i])
		{
			st.pop();
		}
		r_min[i]=st.empty()?n+1:st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(long long i=1;i<=n;i++)
	{
		while(!st.empty() and h[st.top()]<=h[i])
		{
			st.pop();
		}
		l_max[i]=st.empty()?0:st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(long long i=n;i>=1;i--)
	{
		while(!st.empty() and h[st.top()]<=h[i])
		{
			st.pop();
		}
		r_max[i]=st.empty()?n+1:st.top();
		st.push(i);
	}
	for(long long i=1;i<=n;i++)
	{
		ans=max(ans,(__int128)h[i]*h[i]);
	}
	for(long long j=1;j<=n;j++)
	{
		long long s=l_max[j]+1;
		long long e=j-1;
		if(s>e) continue;
		for(long long i=s;i<=e;i++)
		{
			if(r_min[i]>j)
			{
				long long L=max(l_min[i],l_max[j])+1;
				long long R=min(r_min[i],r_max[j])-1;
				long long leng=R-L+1;
				__int128 can=h[i]*h[j]*leng;
				if(can>ans) ans=can;
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		long long s=l_min[i]+1;
		long long e=i-1;
		if(s>e) continue;
		for(long long j=s;j<=e;j++)
		{
			if(r_max[j]>i)
			{
				long long L=max(l_min[i],l_max[j])+1;
				long long R=min(r_min[i],r_max[j])-1;
				long long leng=R-L+1;
				__int128 can=h[i]*h[j]*leng;
				if(can>ans) ans=can;
			}
		}
	}
}
signed main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	init();
	write(ans);
	return 0;
 } 
