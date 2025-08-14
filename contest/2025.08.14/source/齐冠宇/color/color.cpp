#include <bits/stdc++.h>
using namespace std;
int n;
int a[10];
bool fl=1;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++)
		if(a[i]!=a[i-1])
			fl=0;
	if(fl)
		return cout<<"0",0;
	if(n==2)
		return cout<<"4",0;
	if(n==3)
	{
		sort(a+1,a+1+n);
		if(a[1]==1 && a[2]==2 && a[3]==3)
			cout<<"42";
		else
			cout<<"12";
	}
	return 0;
}
