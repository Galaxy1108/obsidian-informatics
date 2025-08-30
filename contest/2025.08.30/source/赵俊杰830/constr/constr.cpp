#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,bool>mp;
int c[140000][12],top,a[12],x[12],b[12];
inline ll to(int a[])
{
	ll sum=0;
	for(int i=1;i<=10;i++)
		sum=sum*10+a[i]-1;
	return sum;
}
void run(int k,ll s)
{
	if(k>10)
	{
		mp[s]=1;
		return;
	}
	if(!b[a[k]])
	{
		b[a[k]]=1;
		x[k]=a[k];
		run(k+1,s*10+a[k]-1);
		b[a[k]]=0;
	}
	if(!b[a[k]-1])
	{
		b[a[k]-1]=1;
		x[k]=a[k]-1;
		run(k+1,s*10+a[k]-2);
		b[a[k]-1]=0;
	}
	if(!b[a[k]+1])
	{
		b[a[k]+1]=1;
		x[k]=a[k]+1;
		run(k+1,s*10+a[k]);
		b[a[k]+1]=0;
	}
}
int main()
{
	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=10;i++)a[i]=i;
//	random_shuffle(a+1,a+11);
//	random_shuffle(a+1,a+11);
//	random_shuffle(a+1,a+11);
//	random_shuffle(a+1,a+11);
//	random_shuffle(a+1,a+11);
	b[0]=1;b[11]=1;
	for(int i=1;i<=592500;i++)
	{
		next_permutation(a+1,a+11);
		//random_shuffle(a+1,a+11);
		if(mp[to(a)])continue;
		run(1,0);
		top++;
		for(int j=1;j<=10;j++)c[top][j]=a[j];
	}
	cout<<top<<'\n';
	for(int i=1;i<=top;i++)
	{
		for(int j=1;j<=10;j++)cout<<c[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}
