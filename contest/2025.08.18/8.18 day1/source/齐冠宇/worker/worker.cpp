#include <bits/stdc++.h>
using namespace std;
constexpr int N=105;
bool m1;
int n;
char str[N];
int f[N][11][11][11];
int s[N][3];
bool m2;
inline void chkmin(int& x,int y)
{
	x=min(x,y);
}
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>str[i];
		for(int j=0;j<3;j++)
			s[i][j]=s[i-1][j];
		s[i][str[i]-'A']++;
	}
	if(n<=10)
		return cout<<(s[n][0]>0)+(s[n][1]>0)+(s[n][2]>0),0;
	memset(f,0x3f,sizeof f);
	f[10][s[10][0]][s[10][1]][s[10][2]]=0;
	int inf=f[0][0][0][0];
	for(int i=1;i<=n;i++)
		for(int a=0;a<=10;a++)
			for(int b=0;b+a<=10;b++)
			{
				int c=10-a-b;
				if(f[i][a][b][c]==inf)
					continue;
				if(i+a<n)
					chkmin(f[i+a][s[i+a][0]-s[i][0]][b+s[i+a][1]-s[i][1]][c+s[i+a][2]-s[i][2]],f[i][a][b][c]+1);
				else
					chkmin(f[n][0][0][0],f[i][a][b][c]+1+((s[n][0]-s[i][0])>0)+((b+s[n][1]-s[i][1])>0)+((c+s[n][2]-s[i][2])>0));
				if(i+b<n)
					chkmin(f[i+b][a+s[i+b][0]-s[i][0]][s[i+b][1]-s[i][1]][c+s[i+b][2]-s[i][2]],f[i][a][b][c]+1);
				else
					chkmin(f[n][0][0][0],f[i][a][b][c]+1+((a+s[n][0]-s[i][0])>0)+((s[n][1]-s[i][1])>0)+((c+s[n][2]-s[i][2])>0));
				if(i+c<n)
					chkmin(f[i+c][a+s[i+c][0]-s[i][0]][b+s[i+c][1]-s[i][1]][s[i+c][2]-s[i][2]],f[i][a][b][c]+1);
				else
					chkmin(f[n][0][0][0],f[i][a][b][c]+1+((a+s[n][0]-s[i][0])>0)+((b+s[n][1]-s[i][1])>0)+((s[n][2]-s[i][2])>0));
			}
	cout<<f[n][0][0][0];
	return 0;
}
