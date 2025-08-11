#include <bits/stdc++.h>
using namespace std;
//guai k[100005];
int a[100005],jss[100005],sumj[100005];
int main()
{
	//freopen("duel3.in","r",stdin);
	int js=1,qjs,kj=1;
	int n,ans;
	cin >> n; 
	ans=n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		/*cin >> k[i].g;
		k[i].f=k[i].g;
		k[i].ci=1;
		k[i].si=0;*/
	}
	sort(a+1,a+n+1);
	for (int i =1;i < n;i++)
	{
		if (a[i]==a[i+1])
		{
			js++;
		}
		else
		{
			jss[kj]=js;
			kj++;
			js=1;
		}
		//cout << ans << " "<< js << endl;
	}
	jss[kj]=js;
	kj++;
	js=1;
	for (int i = 1;i < kj;i++)
	{
		sumj[i] = sumj[i-1]+jss[i];
	} 
	for (int i = 2;i < kj;i++)
	{
		ans-=min(jss[i],sumj[i-1]);
		sumj[i]-=min(jss[i],sumj[i-1]);
		//cout << sumj[i] << endl;
	} 
	cout << ans;
	return 0;
}
