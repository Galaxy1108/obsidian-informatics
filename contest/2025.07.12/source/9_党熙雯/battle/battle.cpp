#include<bits/stdc++.h>
using namespace std;
const int mx=151000;
struct hl
{
	int id,x,y,z;
}a[mx],b[mx],c[mx];
int vis[mx];
bool cmp1(hl x,hl y)
{
	if(x.x==y.x) return x.id<y.id;
	return x.x>y.x;
}
bool cmp2(hl x,hl y)
{
	if(x.y==y.y) return x.id<y.id;
	return x.y>y.y;
}
bool cmp3(hl x,hl y)
{
	if(x.z==y.z) return x.id<y.id;
	return x.z>y.z;
}
int fread()
{
	int x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	x=x*10+(ch-'0'),ch=getchar();
	return x*w;
}
bool check(int p1,int p2,int p3)
{
	if(a[p1].id==b[p2].id||a[p1].id==c[p3].id||b[p2].id==c[p3].id)
	return 0;
	if(a[p1].x<b[p2].x||a[p1].x<c[p3].x) return 0;
	if(b[p1].y<a[p2].y||b[p1].y<c[p3].y) return 0;
	if(c[p1].z<b[p2].z||c[p1].z<a[p3].z) return 0;
	return 1;
	
}
int main()
{
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	int n=fread();
	for(int i=1;i<=n;i++)
	{
		a[i].x=fread(),a[i].y=fread(),a[i].z=fread(),a[i].id=i;
		b[i].x=a[i].x;b[i].y=a[i].y;b[i].z=a[i].z,b[i].id=i;
		c[i].x=a[i].x;c[i].y=a[i].y;c[i].z=a[i].z,c[i].id=i;
	}
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n+1,cmp2);
	sort(c+1,c+n+1,cmp3);
	int p1=1,p2=1,p3=1;
	while(1)
	{
		if(check(p1,p2,p3)) break;
		else
		{
			while(a[p1].id==b[p2].id)
			{
				vis[a[p1].id]++;
				p1++,p2++;
				while(vis[p1]) p1++;
				while(vis[p2]) p2++;
				while(vis[p3]) p3++;
				if(p1>n||p2>n||p3>n)
				{
					cout<<-1<<endl;
					return 0;
				}
			}
			while(b[p2].id==c[p3].id)
			{
				vis[b[p2].id]++;
				p2++,p3++;
				while(vis[p1]) p1++;
				while(vis[p2]) p2++;
				while(vis[p3]) p3++;
				if(p1>n||p2>n||p3>n)
				{
					cout<<-1<<endl;
					return 0;
				}
			}
			while(a[p1].id==c[p3].id)
			{
				vis[a[p1].id]++;
				p1++,p3++;
				while(vis[p1]) p1++;
				while(vis[p2]) p2++;
				while(vis[p3]) p3++;
				if(p1>n||p2>n||p3>n)
				{
					cout<<-1<<endl;
					return 0;
				}
			}
		}
	}
	int ans=a[p1].x+b[p2].y+c[p3].z;
	cout<<ans<<endl;
	return 0;
}
