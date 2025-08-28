#include<bits/stdc++.h>
#define ls p*2
#define rs p*2+1
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N];
signed  main()
{
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(m--)
	{
		int l,r,c;
		cin>>l>>r>>c;
		for(int i=l;i<=r;i++)
		{
			if(c>a[i]) c--;
			else if(c<a[i]) c++;
		}
		cout<<c<<endl;
	}
	return 0;
}
