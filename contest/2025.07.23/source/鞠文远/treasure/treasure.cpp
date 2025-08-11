#include<bits/stdc++.h>
using namespace std;
const int N=205,mod=1e9+7;
int n,k,ary[N];
int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>ary[i];
	if(k==1)
	{
		bool pd=true;
		for(int i=1;i<=n;i++)
			if(ary[i]>1||ary[i]<0)
			{
				pd=false;
				break;
			}
		cout<<(pd?1:0);
		return 0; 
	}
	cout<<0; 
	
	return 0;
} 
