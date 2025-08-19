#include<bits/stdc++.h>
using namespace std;
long long p[1000005],f[1000005],s[1000005];
int x[1000005],c[1000005],que[1000005];
double slope(int j,int k)
{
	double y=f[k]-f[j]+s[k]-s[j];
	return(p[k]==p[j]?(!y?0:(y>0?1e19:-1e19)):y/double(p[k]-p[j]));
}
int main()
{
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	int n,head,tail;
	cin>>n;
	head=tail=1;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>p[i]>>c[i];
		s[i]=s[i-1]+x[i]*p[i];
		p[i]+=p[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		while(head<tail and slope(que[head],que[head+1])<=x[i])
		{
			head++;
		}
		f[i]=f[que[head]]+x[i]*(p[i]-p[que[head]])-(s[i]-s[que[head]])+c[i];
		while(head<tail and slope(que[tail-1],que[tail])>=slope(que[tail-1],i))
		{
			tail--;
		}
		que[++tail]=i;
	}
    cout<<f[n]<<endl;
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const long long N=1000005;
long long x[N],p[N],c[N];
long long f[N];
long long zjj[N];
long long sbzjj[N];
main()
{
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>x[i]>>p[i]>>c[i];
		zjj[i]=zjj[i-1]+p[i];
		sbzjj[i]=sbzjj[i-1]+p[i]*x[i];
	}
	f[0]=0;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=0;j<i;j++)
		{
			long long sum=0;
			sum=sum+x[i]*(zjj[i-1]-zjj[j])-sbzjj[i-1]+sbzjj[j];
//			for(long long k=j+1;k<i;k++)
//			{
//				sum+=p[k]*x[i]-p[k]*x[k];
//			}
			f[i]=min(f[i],f[j]+c[i]+sum);
		}
	}
	cout<<f[n];
	return 0;
} 
*/
