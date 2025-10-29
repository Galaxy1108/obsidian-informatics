#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[1010];
bool flag=0;
void dfs(ll son,ll mum,ll cnt)
{
	if(son==1)
	{
		cout<<cnt<<endl;
		for(int i=1;i<cnt;i++) cout<<a[i]<<" ";
		cout<<mum<<" ";
		flag=1;
	}
	else
	{
		for(int i=2; ;i++)
		{
			if(flag) break;
			ll now_mum=i*mum,now_son=i*son-mum;
			if(now_son<0) continue;
			int v=__gcd(now_son,now_mum);
			now_son/=v,now_mum/=v;
			a[cnt]=i;
			dfs(now_son,now_mum,cnt+1);
		}
	}
	return ;
}
int main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	int a,b; cin>>a>>b;
	dfs(a,b,1);
	return 0;
}
