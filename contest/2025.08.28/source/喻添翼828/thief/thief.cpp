#include<bits/stdc++.h>
using namespace std;
const int mx=5e5+10;
int a[mx],n,m;
int l[mx],r[mx],c[mx];
/*
int t[mx];
int lowbit(int x)
{
	return x&(-x);
}
void add(int p,int k)
{
	for(int i=p;i<=n;i+=lowbit(i)) t[i]+=k; 
}
int query(int p)
{
	int res=0;
	for(int i=p;i;i-=lowbit(i)) res+=t[i];
	return res;
}
*/
int main()
{
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool flag=1;
	for(int i=1;i<=m;i++) 
	{
		cin>>l[i]>>r[i]>>c[i];
		if(l[i]!=1) flag=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=l[i];j<=r[i];j++)
		{
			if(a[j]>c[i]) c[i]++;
			if(a[j]<c[i]) c[i]--;
		}
		cout<<c[i]<<endl;
	} 
	return 0;
} 
