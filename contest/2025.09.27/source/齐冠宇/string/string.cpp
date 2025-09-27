#include <bits/stdc++.h>
#define vi vector<int>
#define pb emplace_back
#define ppb pop_back
using namespace std;
constexpr int N=405;
string s;
int n;
int ct[3];
int f[N][3][N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++)
		ct[s[i]-48]++;
	for(int i=0;i<=2;i++)
		if(ct[i]>(n+1)/2)
			return cout<<"-1",0;
	memset(f,0x3f,sizeof f);
	f[1][s[1]-48][1]=0;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			for(int _=0;_<=2;_++)
			{
				if(_==s[i]-48)
					f[i][s[i]-48][j+1]=min(f[i][s[i]-48][j+1],f[i-1][_][j]);
				else
				{
					if(j>1)
						f[i][_][j-1]=min(f[i][_][j-1],f[i-1][_][j]+j-1);
					else if(j==1)
						f[i][s[i]-48][1]=min(f[i][s[i]-48][1],f[i-1][_][j]),
						f[i][_][1]=min(f[i][_][1],(s[i]!=s[i-2])?(f[i-1][_][j]+1):f[0][0][0]);
				}
			}
	int ans=f[0][0][0];
	for(int _=0;_<=2;_++)
		ans=min(ans,f[n][_][1]);
	cout<<ans;
	return 0;
}
