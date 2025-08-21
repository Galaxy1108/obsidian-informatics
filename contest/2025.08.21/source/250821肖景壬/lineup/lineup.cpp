//kill what
#include<bits/stdc++.h>
using namespace std;
struct pp
{
	int num,id;
};
pp p[55];
bool cmp(pp x,pp y)
{
	if(x.num!=y.num) return x.num<y.num;
	return x.id<y.id;
}
int a[55],n;
int main()
{
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
		p[i].id=i;
		p[i].num=a[i];
	}
	sort(p+1,p+n+1,cmp);
	int ans=0;
	for(int i = 1; i <= n; i++)
	{
		ans+=abs(i-p[i].id);
	}
	cout<<ans<<endl;
}
