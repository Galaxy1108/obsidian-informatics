#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,ary[N];
int main()
{
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>ary[i];
	for(int i=1;i<=m;i++)
	{
		int l,r,c;
		cin>>l>>r>>c;
		for(int i=l;i<=r;i++)
		{
			if(c>ary[i])c--;
			else if(c<ary[i])c++;	
		} 
		cout<<c<<"\n";
	}
	
	return 0;
}
