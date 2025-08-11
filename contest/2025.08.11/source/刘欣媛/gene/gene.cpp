#include <bits/stdc++.h>
using namespace std;
int n,l,r,a[1000005];
int bl[1000005],br[1000005];
int main()
{
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x=l-1,y=r+1;
	for(int i=x;i<=n;i++) {
		bl[a[i]]++;
	}
	for(int i=1;i<=y;i++) {
		br[a[i]]++;
	}
	
	while(1)
	{
		//cout<<a[x]<<" "<<a[y]<<"\n";
		if(x<1||y>n)
		{
			cout<<-1;
			return 0;
		}
		if((br[a[x]]<=1)&&(bl[a[y]]<=1)&&(a[x]!=a[y]))
		{
			cout<<y-x+1;
			return 0;
		}
		if(x==1&&y==n)
		{
			cout<<-1;
			return 0;
		}
		if(a[x]==a[y])
		{
			x--,y++;
			bl[x]++,br[y]++;
		}
		while(x>=1&&br[a[x]]>1)
		{
			x--;
			bl[a[x]]++;	
		}
		while(y<=n&&bl[a[y]]>1)
		{
			y++;
			br[a[y]]++;
		}
	}
	return 0;
 } 
