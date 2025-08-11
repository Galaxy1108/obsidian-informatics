//你知道吗？模意义下的乘积最大值≠乘积最大值
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int XaoWa118 = 1000000007;
int f[15][40][30][16][16],n,k,di0[15],fin[50][50][50][50],findi;
int fa1[11]={0,0,1,0,2,0,1,0,3,0},fa2[11]={0,0,0,1,0,0,1,0,0,2},fa3[11]={0,0,0,0,0,1,0,0,0,0},fa4[11]={0,0,0,0,0,0,0,1,0,0};
int ten[15],tets;
int cc[5];

int anscnt,ans[500005];

void get(int x)
{
	while(x)
	{
		tets++;
		ten[tets]=x%10;
		x/=10;
	}
	return;
}
signed main()
{
	cin>>n>>k;
	get(n);
	f[1][0][0][0][0]=1;//1
	f[1][1][0][0][0]=1;//2
	f[1][0][1][0][0]=1;//3
	f[1][2][0][0][0]=1;//4
	f[1][0][0][1][0]=1;//5
	f[1][1][1][0][0]=1;//6
	f[1][0][0][0][1]=1;//7
	f[1][3][0][0][0]=1;//8
	f[1][0][2][0][0]=1;//9
	di0[1]=1;
	for(int i = 1; i <= 12; i++)
	{
		for(int j = 1; j <= 9; j++)
		{
			for(int a1 = 0; a1 <= 36; a1++)
			{
				for(int a2 = 0; a2 <= 24; a2++)
				{
					for(int a3 = 0; a3 <= 12; a3++)
					{
						for(int a4 = 0; a4 <= 12; a4++)
						{
							//if(a1+a2+a3+a4==0) continue;
							f[i+1][a1+fa1[j]][a2+fa2[j]][a3+fa3[j]][a4+fa4[j]]+=f[i][a1][a2][a3][a4];
						 } 
					}
				}
			}
		}
		//di0[i+1]=9*di0[i];
		for(int a1 = 0; a1 <= 36; a1++)
		{
			for(int a2 = 0; a2 <= 24; a2++)
			{
				for(int a3 = 0; a3 <= 12; a3++)
				{
					for(int a4 = 0; a4 <= 12; a4++)
					{
						//f[i+1][a1][a2][a3][a4]+=f[i][a1][a2][a3][a4];
						//f[i+1][a1][a2][a3][a4]%=XaoWa118;
						di0[i+1]+=f[i][a1][a2][a3][a4];
					 } 
				}
			}
		} 
		//di0[i+1]%=XaoWa118;
	}
	//cout<<di0[3]<<endl;
	/*for(int i = 1; i <= 2; i++)
	{
		for(int a1 = 0; a1 <= 6; a1++)
		{
			for(int a2 = 0; a2 <= 4; a2++)
			{
				for(int a3 = 0; a3 <= 2; a3++)
				{
					for(int a4 = 0; a4 <= 2; a4++)
					{
						if(pow(2,a1)*pow(3,a2)*pow(5,a3)*pow(7,a4)<=100&&f[i][a1][a2][a3][a4]) cout<<f[i][a1][a2][a3][a4]<<" "<<pow(2,a1)*pow(3,a2)*pow(5,a3)*pow(7,a4)<<endl;
					 } 
				}
			}
		}
		cout<<endl<<endl<<endl;
	}*/
	
	for(int i = tets; i >= 2; i--)
	{
		for(int j = 0; j < ten[i]; j++)
		{
			for(int a1 = 0; a1 <= 36; a1++)
			{
				for(int a2 = 0; a2 <= 24; a2++)
				{
					for(int a3 = 0; a3 <= 12; a3++)
					{
						for(int a4 = 0; a4 <= 12; a4++)
						{
							//if(a1+a2+a3+a4==0) continue;
							fin[a1+fa1[j]+cc[1]][a2+fa2[j]+cc[2]][a3+fa3[j]+cc[3]][a4+fa4[j]+cc[4]]+=f[i-1][a1][a2][a3][a4];
						 } 
					}
				}
			}
		}
		cc[1]+=fa1[ten[i]];
		cc[2]+=fa2[ten[i]];
		cc[3]+=fa3[ten[i]];
		cc[4]+=fa4[ten[i]];
		
		findi+=ten[i]*di0[i];
	}
	for(int j = 1; j <= ten[1]; j++)
	{
		fin[fa1[j]+cc[1]][fa2[j]+cc[2]][fa3[j]+cc[3]][fa4[j]+cc[4]]++;
	}
	for(int a1 = 0; a1 <= 36; a1++)
	{
		for(int a2 = 0; a2 <= 24; a2++)
		{
			for(int a3 = 0; a3 <= 12; a3++)
			{
				for(int a4 = 0; a4 <= 12; a4++)
				{
					//if(a1+a2+a3+a4==0) continue;
					if(pow(2,a1)*pow(3,a2)*pow(5,a3)*pow(7,a4)<=n&&fin[a1][a2][a3][a4]) cout<<fin[a1][a2][a3][a4]<<" "<<pow(2,a1)*pow(3,a2)*pow(5,a3)*pow(7,a4)<<endl;
					if(fin[a1][a2][a3][a4]!=0)
					{
						anscnt++;
						ans[anscnt]=fin[a1][a2][a3][a4];
					}
				} 
			}
		}
	}
	anscnt++;
	ans[anscnt]=findi;
}
