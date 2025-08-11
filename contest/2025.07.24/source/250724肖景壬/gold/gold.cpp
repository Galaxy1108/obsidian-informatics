#include<bits/stdc++.h>
using namespace std;
struct pp
{
	int num,id;
};
pp f[10000005];
bool cmp(pp x,pp y)
{
	if(x.num!=y.num) return x.num>y.num;
	return x.id<y.id;
}
int get(int x)
{
	int ans=1;
	while(x)
	{
		ans*=(x%10);
		x/=10;
	}
	return ans;
}
int n,k;
int main()
{
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);
	cin>>n>>k;
	for(int i = 1; i <= n; i++)
	{
		f[get(i)].num++;
		f[i].id=i;
	}
	sort(f+1,f+n+1,cmp);
	cout<<f[1].num*f[1].num;
 } 
