#include<bits/stdc++.h>

using namespace std;
const int mx=2e6+10;
int n;
int h[mx];
int q1[mx],q2[mx];
long long getans(int k)
{
	long long res=-1;
	int H1=0,T1=1,H2=0,T2=1;
	q1[H1]=q1[T1]=q2[H2]=q2[T2]=0;
	for(int i=1;i<=k;i++)
	{
		while(h[q1[T1]]<=h[i]&&H1<=T1) T1--;
		while(h[q2[T2]]>=h[i]&&H2<=T2) T2--;
		q1[++T1]=i;
		q2[++T2]=i;
		while(q1[T1]-q1[H1]>=k) H1++;
		while(q2[T2]-q2[H2]>=k) H2++;
		res=max(res,1ll*h[q1[H1]]*h[q2[H2]]);
	}
	for(int i=k+1;i<=n;i++)
	{
		while(h[q1[T1]]<=h[i]&&H1<=T1) T1--;
		while(h[q2[T2]]>=h[i]&&H2<=T2) T2--;
		q1[++T1]=i;
		q2[++T2]=i;
		while(q1[T1]-q1[H1]>=k) H1++;
		while(q2[T2]-q2[H2]>=k) H2++;
		res=max(res,1ll*h[q1[H1]]*h[q2[H2]]);
	}

	return res*k;
}

long long ans=-1e18;
int main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int len=1;len<=n;len++)
	{
		ans=max(ans,getans(len));
	}
	cout<<ans;
	return 0;
} 
