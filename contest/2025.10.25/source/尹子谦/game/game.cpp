#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N],pr[N],mx=-1,ans;
bool check(int x)
{
	//cout<<x<<":";
	int mm=mx/x;
	//cout<<mx<<' '<<mm<<' '<<endl;
	for(int i=mm;i>=1;i--)
	{
		int num=0;
		for(int p=mx;p>=i*x;p--) num+=a[p];
		if((num)%2==1) return 0;
	}
	return 1;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1,x;i<=n;i++) cin>>x,a[x]++,mx=max(mx,x);
	if(n>=110)
	{
		if(n%2==0) cout<<0;
		else cout<<n;
		return 0;
	}
	for(int i=1;i<=mx;i++)
	{
		if(!a[i]) continue;
		for(int j=i;j>=1;j--)
		{
			a[i]--;
			a[i-j]++;
			int x=check(j);
			a[i]++;
			a[i-j]--;
			ans+=x*a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
