#include<bits/stdc++.h>
using namespace std;
long long now,mx,ans,a[100005],n;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	/*ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	for(int i = 1; i < n; i++)
	{
		mx=a[i];
		now=a[i];
		for(int j = i+1; j <= n; j++)
		{
			while(a[j]>mx)
			{
				mx=a[j];
				break;
			}
			now^=a[j];
			if(mx>=now) ans++; 
		}
	}
	cout<<ans+n<<endl;
}
