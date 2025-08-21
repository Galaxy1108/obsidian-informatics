#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v[2505];
int main()
{
    freopen("divisors.in","r",stdin);
    freopen("divisors.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n;
	v[1]={1};
	v[2]={1,2};
	v[3]={2,6,3};
	v[4]={3,6,8,12};
	v[5]={10,15,6,8,4};
	v[6]={10,15,12,6,8,4};
	v[7]={7,35,15,12,6,8,4};
	v[8]={7,35,15,12,6,8,16,4};
	v[9]={9,63,35,15,12,6,8,16,4};
	v[10]={10,90,63,35,15,12,6,8,16,4};
	int a[2505]={0,4,16,8,6,12,15,35,63,90,10};
	if(n>10)
	{
		for(int i=11;i<=n;i++)
		{
			a[i]=i;
			a[i-1]*=a[i];
		}
		for(int i=n;i>=1;i--) cout<<a[i]<<" ";
		cout<<"\n";
	}
	else
	{
		for(int i:v[n])
		{
			cout<<i<<" ";
		}
		cout<<"\n";
	}
	
	for(int i=1;i<n;i++)
	{
		cout<<i<<" "<<i+1<<"\n";
	}
    return 0;
}
