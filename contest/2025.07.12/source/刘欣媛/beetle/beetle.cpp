#include <bits/stdc++.h>
using namespace std;
long long s[2500005],f[2500005],cj[30],bj[2500005];
struct node{
	long long e,sum,t;
};
deque <node>q,qe;
int main()
{
//	freopen("w","beetle.in",stdin);
//	freopen("r","beetle.out",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&s[i]);
		bj[i]=i;
	} 
	for(int i=1;i<=k;i++)
	{
		while(q.size()&&q.back().sum<f[i-1]){
			q.pop_back();
		}
		if(q.size()&&q.front().e>=s[i-1])
			q.push_back((node{q.front().e ,f[i-1],i-1}));
		else
		{
			q.push_back((node{s[i-1] ,f[i-1],i-1}));
		}
		while(q.size()&&q.front().t+k<=i)
		{
			q.pop_front();
		}
		f[i]=max(s[i],f[i-1]);
		
	}
	for(int i=k+1;i<=n;i++)
	{
		
		while(q.size()&&q.back().sum<f[i-1]){
			q.pop_back();
		}
		if(q.size()&&q.front().e>=s[i-1])
			q.push_back((node{q.front().e ,f[i-1],i-1}));
		else
		{
			q.push_back((node{s[i-1] ,f[i-1],i-1}));
		}
		int w;
		if(q.size()&&q.front().t+k<=i)
		{
			w=q.front().sum;
		}
		while(q.size()&&q.front().t+k<=i)
		{
			q.pop_front();
		}
		if(q.size()&&q.back().e>=s[i])
			f[i]=q.back().sum;
		else
		{
			f[i]=q.back().sum+s[i]; 
		}
			
	}
	for(int i=1;i<=n;i++)
	{
		cout<<f[i]<<" ";
	}
	cout<<"\n";
	cj[0]=1;
	long long p=1e9;
	p+=7;
	for(int i=1;i<=23;i++)
	{
		cj[i]=cj[i-1]*23%p;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=(cj[n-i]*(f[i]%p))%p;
	}
	printf("%lld",ans);
	return 0;
 } 
