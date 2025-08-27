#include <bits/stdc++.h>
using namespace std;
constexpr int N=205;
int T;
int m,s,n;
int a[N];
bitset<1005>f[505];
int main()
{
	freopen("give.in","r",stdin);
	freopen("give.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T; 
	while(T--)
	{
		cin>>m>>s>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=0;i<=m;i++)
			f[i].reset();
		f[0][0]=1;
//		cerr<<"!";
		for(int i=1;i<=m;i++)
			for(int j=0;j<=s;j++)
				for(int k=1;k<=n;k++)
				{
					if(a[k]>j)break;
					f[i][j]=f[i][j]^f[i-1][j-a[k]];
				}
		cout<<f[m][s]<<'\n';
	}
	return 0;
}
