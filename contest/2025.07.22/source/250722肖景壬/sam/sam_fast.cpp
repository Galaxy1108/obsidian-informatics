#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int XaoWa118 = 1000000007;
int f[1000005][11],k; 
signed main()
{
	cin>>k;
	for(int i = 0; i <= 9; i++) f[1][i]=1;
	for(int i = 2; i <= k; i++)
	{
		f[i][0]=(f[i-1][0]+f[i-1][1]+f[i-1][2])%XaoWa118;
		f[i][1]=(f[i-1][0]+f[i-1][1]+f[i-1][2]+f[i-1][3])%XaoWa118;
		f[i][9]=(f[i-1][7]+f[i-1][8]+f[i-1][9])%XaoWa118;
		f[i][8]=(f[i-1][6]+f[i-1][7]+f[i-1][8]+f[i-1][9])%XaoWa118;
		for(int j = 2; j <= 7; j++)
		{
			f[i][j]=(f[i-1][j-2]+f[i-1][j-1]+f[i-1][j]+f[i-1][j+1]+f[i-1][j+2])%XaoWa118;
		}
		//cout<<i<<" "<<f[i][1]+f[i][2]+f[i][3]+f[i][4]+f[i][5]+f[i][6]+f[i][7]+f[i][8]+f[i][9]<<endl;
		/*for(int j = 0; j <= 9; j++)
		{
			cout<<f[i][j]<<" ";
		}
		cout<<endl;*/
	 } 
	int finans=0;
	for(int i = 1; i <= 9; i++)
	{
		finans+=f[k][i];
	}
	cout<<finans%XaoWa118<<endl;
}
