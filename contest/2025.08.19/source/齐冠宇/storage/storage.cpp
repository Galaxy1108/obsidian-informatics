#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1e6+5;
typedef double db;
int n;
int x[N],p[N],c[N];
int sp[N],spd[N];
int f[N];
inline int Y(int i)
{
	return f[i]+spd[i];
}
inline int X(int i)
{
	return sp[i];
}
inline db xl(int i,int j)
{
	return 1.0*(Y(j)-Y(i))/(X(j)-X(i));
}
inline int gt(int* s,int l,int r)
{
	return s[r]-s[l-1];
}
int q[N];
int h,t;
signed main()
{
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>p[i]>>c[i];
		sp[i]=sp[i-1]+p[i];
		spd[i]=spd[i-1]+p[i]*x[i];
	}
	q[h=t=1]=0;
	for(int i=1;i<=n;i++)
	{
		while(h<t && x[i]>xl(q[h],q[h+1]))
			h++;
		f[i]=f[q[h]]+x[i]*gt(sp,q[h]+1,i-1)-gt(spd,q[h]+1,i-1)+c[i];
		while(h<t && xl(q[t-1],q[t])>xl(q[t],i))
			t--;
		q[++t]=i;
	}
	cout<<f[n];
	return 0;
}

