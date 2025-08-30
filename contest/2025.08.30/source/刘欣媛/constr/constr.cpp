#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int a[15]={0,1,2,3,4,5,6,7,8,9,10};
	cout<<5<<"\n";
	for(int i=0;i<=4;i++)
	{
		for(int j=1;j<=10;j++)
		{
			if(a[j]+2*i==10)
			{
				cout<<"10 ";
				continue;
			}
			cout<<(a[j]+2*i)%10<<" ";
		}
		cout<<"\n";
	}
	
	
	return 0;
} 
