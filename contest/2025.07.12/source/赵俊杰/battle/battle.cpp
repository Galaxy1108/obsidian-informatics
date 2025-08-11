#include<bits/stdc++.h>
using namespace std;
const int N=150005;
struct T
{
	int x,y,z,id;
}a[N],b[N],c[N];
bool cmp1(T a,T b)
{
	return a.x<b.x;
}
bool cmp2(T a,T b)
{
	return a.y<b.y;
}
bool cmp3(T a,T b)
{
	return a.z<b.z;
}
int main()
{
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].id=i;
		b[i]=a[i];
		c[i]=a[i];
	}
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n+1,cmp2);
	sort(c+1,c+n+1,cmp3);
	int u=n,v=n,w=n;
	while(1)
	{
		while(u&&(a[u].y>=b[v].y||a[u].z>=c[w].z))u--;
		while(v&&(b[v].x>=a[u].x||b[v].z>=c[w].z))v--;
		while(w&&(c[w].x>=a[u].x||c[w].y>=b[v].y))w--;
		if(!u||!v||!w)
		{
			cout<<"-1\n";
			return 0;
		}
		if(a[u].y<b[v].y&&a[u].z<c[w].z&&b[v].x<a[u].x&&b[v].z<c[w].z&&c[w].x<a[u].x&&c[w].y<b[v].y)
		{
			cout<<a[u].x+b[v].y+c[w].z<<'\n';
			return 0;
		}
	}
	return 0;
}
