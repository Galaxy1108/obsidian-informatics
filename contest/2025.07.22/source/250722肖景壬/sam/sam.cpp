//40 8:24
//AC 9:06

#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int XaoWa118 = 1000000007;
int f[15][15][101],k,cacans[15][15],isfst=0,tmp[15][15];//f[i][j][k]=Í·iÎ²j£¬len=2^k 
int pow2[65];

signed main()
{
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
	cin>>k;
	for(int i = 0; i <= 9; i++) f[i][i][0]=1;
	pow2[0]=1;
	for(int i = 1; i <= 63; i++)
	{
		pow2[i]=pow2[i-1]*2;
	}
	for(int i = 1; i <= 64; i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			for(int nk = 0; nk <= 9; nk++)//head
			{
				for(int nl = 0; nl <= 9; nl++)
				{
					if(j==0)
					{
						f[nk][nl][i]+=f[nk][0][i-1]*f[0][nl][i-1]+f[nk][0][i-1]*f[1][nl][i-1]+f[nk][0][i-1]*f[2][nl][i-1];
					}
					else if(j==1)
					{
						f[nk][nl][i]+=f[nk][1][i-1]*f[0][nl][i-1]+f[nk][1][i-1]*f[1][nl][i-1]+f[nk][1][i-1]*f[2][nl][i-1]+f[nk][1][i-1]*f[3][nl][i-1];
					}
					else if(j==8)
					{
						f[nk][nl][i]+=f[nk][8][i-1]*f[6][nl][i-1]+f[nk][8][i-1]*f[7][nl][i-1]+f[nk][8][i-1]*f[8][nl][i-1]+f[nk][8][i-1]*f[9][nl][i-1];
					}
					else if(j==9)
					{
						f[nk][nl][i]+=f[nk][9][i-1]*f[7][nl][i-1]+f[nk][9][i-1]*f[8][nl][i-1]+f[nk][9][i-1]*f[9][nl][i-1];
					}
					else
					{
						f[nk][nl][i]+=f[nk][j][i-1]*f[j-2][nl][i-1]+f[nk][j][i-1]*f[j-1][nl][i-1]+f[nk][j][i-1]*f[j][nl][i-1]+f[nk][j][i-1]*f[j+1][nl][i-1]+f[nk][j][i-1]*f[j+2][nl][i-1];
					}
					f[nk][nl][i]%=XaoWa118;
					//cout<<i<<" "<<nk<<" "<<j<<" "<<nl<<" "<<f[nk][nl][i]<<endl;
				}
			}
		}
	 } 
	/*for(int i = 0; i <= 3; i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			for(int nk = 0; nk <= 9; nk++)
			{
				cout<<f[j][nk][i]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}*/
	int finans=0;
	//cout<<((1<<62)-pow(10,18))<<endl;
	//cout<<(1<<62)<<endl;
	for(int i = 62; i >= 0; i--)
	{
		if((k&pow2[i])>0)
		{
			//cout<<i<<endl;
			if(isfst==0)//no 0
			{
				for(int ni = 1; ni <= 9; ni++)
				{
					for(int nj = 0; nj <= 9; nj++)
					{
						cacans[ni][nj]=f[ni][nj][i];
					}
				}
				isfst=1;
			}
			else
			{
				memset(tmp,0,sizeof(tmp));
				for(int nk = 1; nk <= 9; nk++)
				{
					for(int nj = 0; nj <= 9; nj++)
					{
						for(int nl = 0; nl <= 9; nl++)
						{
							if(nj==0)
							{
								tmp[nk][nl]+=cacans[nk][0]*f[0][nl][i]+cacans[nk][0]*f[1][nl][i]+cacans[nk][0]*f[2][nl][i];
							}
							else if(nj==1)
							{
								tmp[nk][nl]+=cacans[nk][1]*f[0][nl][i]+cacans[nk][1]*f[1][nl][i]+cacans[nk][1]*f[2][nl][i]+cacans[nk][1]*f[3][nl][i];
							}
							else if(nj==8)
							{
								tmp[nk][nl]+=cacans[nk][8]*f[6][nl][i]+cacans[nk][8]*f[7][nl][i]+cacans[nk][8]*f[8][nl][i]+cacans[nk][8]*f[9][nl][i];
							}
							else if(nj==9)
							{
								tmp[nk][nl]+=cacans[nk][9]*f[7][nl][i]+cacans[nk][9]*f[8][nl][i]+cacans[nk][9]*f[9][nl][i];
							}
							else
							{
								tmp[nk][nl]+=cacans[nk][nj]*f[nj-2][nl][i]+cacans[nk][nj]*f[nj-1][nl][i]+cacans[nk][nj]*f[nj][nl][i]+cacans[nk][nj]*f[nj+1][nl][i]+cacans[nk][nj]*f[nj+2][nl][i];
							}
							//tmp[ni][nk]=cacans[ni][nj]*f[nj-1]
							tmp[nk][nl]%=XaoWa118;
						}
					}
				}
				for(int nj = 0; nj <= 9; nj++)
				{
					for(int nk = 0; nk <= 9; nk++)
					{
						cacans[nj][nk]=tmp[nj][nk];
					}
				}
			}
		}
	}
	
	for(int i = 1; i <= 9; i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			finans+=cacans[i][j];
			finans%=XaoWa118;
		}
	}
	
	/*for(int i = 1; i <= 9; i++)
	{
		finans+=f[k][i];
	}*/
	cout<<finans%XaoWa118<<endl;
}
