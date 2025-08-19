#include<bits/stdc++.h>
using namespace std;
const int N=100005;
string s,t;
int f[N][25];
int main()
{
	freopen("distance.in","r",stdin);
	freopen("distance.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s>>t;
	int n=s.size(),m=t.size(),T;
	s=' '+s;
	t=' '+t;
	cin>>T;
	while(T--)
	{
		int l,r;
		cin>>l>>r;
		for(int i=l-1;i<=r;i++)
			for(int j=0;j<=m;j++)f[i][j]=0;
		for(int i=l;i<=r;i++)f[i][0]=i-l+1;
		for(int i=1;i<=m;i++)f[l-1][i]=i;
		for(int i=l;i<=r;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(s[i]==t[j])f[i][j]=f[i-1][j-1];
				else f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);
			}
		}
		cout<<f[r][m]<<'\n';
	}
	return 0;
}
