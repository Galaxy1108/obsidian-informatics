#include<iostream>
#include<queue>
using namespace std;
int s[100005],a[100005];
priority_queue<int> q[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,i,j;
	long long cnt=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(i=1;i<=n;i++)
	    for(j=0;j<=i;j++)
	        q[i].push(a[j]);
	for(i=1;i<=n;i++)
	    for(j=i;j<=n;j++)
	    {
	    	s[j]=s[j]^a[i-1];
	    	if(q[j].top()==a[i-1])
	    	    q[j].pop();
	    	if(s[j]<=q[j].top())
	    	    cnt++;
		}
	cout<<cnt;
	return 0;
}
