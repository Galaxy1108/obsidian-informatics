#include<bits/stdc++.h>
using namespace std;
string str;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cout<<-1;
	//cin>>str;
	/*n=str.size();
	for(int i = 1; i <= n; i++)
	{
		a[i]=str[i-1]-'0';
	}
	for(int i = 1; i <= n; i++)
	{
		sz[a[i]]++;
	}
	for(int i = 1; i <= n; i++)
	{
		now[a[i]]++;
		cnt[a[i]][now[a[i]]][0]=now[0];
		cnt[a[i]][now[a[i]]][1]=now[1];
		cnt[a[i]][now[a[i]]][2]=now[2];
	}
	memset(f,0x3f,sizeof(f));
	for(int i = 0; i <= sz[0]; i++)
	{
		for(int j = 0; j <= sz[1]; j++)
		{
			for(int k = 0; k <= sz[2]; k++)
			{
				if(i+j+k==0)
				{
					f[i][j][k][0]=f[i][j][k][1]=f[i][j][k][2]=0;
					continue;
				}
				//now=0
				if(i>=1)
				{
					f[i][j][k][0]=min(f[i][j][k][0],f[i-1][j][k][1]+cnt[0][i][1]+cnt[0][i][2])
				}
			 } 
		} 
	}*/
}
