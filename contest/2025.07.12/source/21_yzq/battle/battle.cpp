#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
int n,maxx=-1,a,b,c,ans;
struct val
{
	int no,val;
}no1[N],no2[N],no3[N];
struct Node
{
	int x,y,z,no;
}joi[N];
bool cmp1(Node x,Node y)
{
	return x.x>y.x;
}
bool cmp2(Node x,Node y)
{
	return x.y>y.y;
}
bool cmp3(Node x,Node y)
{
	return x.z>y.z;
}
bool check(int a,int b,int c)
{
	
}
signed main()
{
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		cin>>joi[i].x>>joi[i].y>>joi[i].z;
		joi[i].no=i;
	}
	sort(joi+1,joi+n+1,cmp1);
	for(int i=1;i<=n;i++)  no1[i]={joi[i].no,joi[i].x};
	sort(joi+1,joi+n+1,cmp2);
	for(int i=1;i<=n;i++)  no2[i]={joi[i].no,joi[i].y};
	sort(joi+1,joi+n+1,cmp3);
	for(int i=1;i<=n;i++)  no3[i]={joi[i].no,joi[i].z};
	a=1,b=1,c=1;
	while(no1[a].no==no2[a].no) a++,b++;
	while(no1[a].no==no3[a].no) a++,c++;
	while(no2[b].no==no3[b].no) b++,c++;
	maxx=max(maxx,no1[a].val+no2[b].val+no3[c].val);
	if(no1[a].val==no1[a+1].val) a++;
	if(no1[a].no==no2[b].no||no1[a].no==no3[c].no||no2[b].no==no3[c].no) cout<<-1;
	cout<<maxx;
	return 0;
}

