#include <bits/stdc++.h>
#define N 150005
#define int long long
using namespace std;
int n;
int ia=1,ib=1,ic=1;
struct O
{
	int a,b,c;
}ori[N];
struct E
{
	int x,id;
}a[N],b[N],c[N];
bool cmp(E a,E b)
{
	if(a.x==b.x)return a.id<b.id;
	else return a.x>b.x;
}
bool ist(int x,int y,int z)
{
	if(ori[x].a<=ori[y].a || ori[x].a<=ori[z].a)return 0;
	if(ori[y].b<=ori[x].b || ori[y].b<=ori[z].b)return 0;
	if(ori[z].c<=ori[y].c || ori[z].c<=ori[x].c)return 0;
	return 1;
}
signed main()
{
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>b[i].x>>c[i].x;
		ori[i].a=a[i].x;
		ori[i].b=b[i].x;
		ori[i].c=c[i].x;
		a[i].id=b[i].id=c[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	sort(c+1,c+1+n,cmp);
	while(ia<=n && ib<=n && ic<=n)
	{
		//xia tiao
		if(a[ia].id==b[ib].id && c[ia].id==b[ib].id)ia++,ib++,ic++;
		else if(a[ia].id==b[ib].id)ia++,ib++;//ab中目前最强的是同一只 
		else if(a[ia].id==c[ib].id)ia++,ic++;//ac中目前最强的是同一只 
		else if(c[ia].id==b[ib].id)ic++,ib++;//cb中目前最强的是同一只 
		if(ist(a[ia].id,b[ib].id,c[ic].id))break;
	}
	if(ia>n || ib>n || ic>n)cout<<-1;
	else cout<<a[ia].x+b[ib].x+c[ic].x;
	return 0;
}
