#include <bits/stdc++.h>
using namespace std;
#define ll long long 
string s;
vector<int> pos0,pos1,pos2;
int dp[405][405][405][4],cnt0,cnt1,cnt2;
int cost0[405][405][405];
int cost1[405][405][405];
int cost2[405][405][405];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s;
	int n=s.size();
	memset(dp,0x3f3f3f3f,sizeof(dp));
	bool flag=true;
	for(int i=0;i<s.size();i++)
	{
		if(i>0 and s[i]==s[i-1])
		{
			flag=false;
		}
		if(s[i]=='0')
		{
			pos0.push_back(i);
			cnt0++;
		}
		if(s[i]=='1')
		{
			pos1.push_back(i);
			cnt1++;
		}
		if(s[i]=='2')
		{
			pos2.push_back(i);
			cnt2++;
		}
	}
	if(flag)
	{
		cout<<0;
		return 0;
	}
	if(cnt0>cnt1+cnt2+1 or cnt1>cnt0+cnt2+1 or cnt2>cnt1+cnt0+1)
	{
		cout<<-1;
		return 0;
	}
	for(int i=0;i<=cnt0;i++)
	{
		for(int j=0;j<=cnt1;j++)
		{
			for(int k=0;k<=cnt2;k++)
			{
				if(i<cnt0)
				{
					int p=pos0[i];
					int used=0;
					for(int ti=0;ti<i;ti++) if(pos0[ti]<p) used++;
					for(int tj=0;tj<j;tj++) if(pos1[tj]<p) used++;
					for(int tk=0;tk<k;tk++) if(pos2[tk]<p) used++;
					cost0[i][j][k]=p-used;
				}
				if(j<cnt1)
				{
					int p=pos1[j];
					int used=0;
					for(int ti=0;ti<i;ti++) if(pos0[ti]<p) used++;
					for(int tj=0;tj<j;tj++) if(pos1[tj]<p) used++;
					for(int tk=0;tk<k;tk++) if(pos2[tk]<p) used++;
					cost1[i][j][k]=p-used;
				}
				if(k<cnt2)
				{
					int p=pos2[k];
					int used=0;
					for(int ti=0;ti<i;ti++) if(pos0[ti]<p) used++;
					for(int tj=0;tj<j;tj++) if(pos1[tj]<p) used++;
					for(int tk=0;tk<k;tk++) if(pos2[tk]<p) used++;
					cost2[i][j][k]=p-used;
				}
			}
		}
	}
	dp[0][0][0][3]=0;
	for(int i=0;i<=cnt0;i++)
	{
		for(int j=0;j<=cnt1;j++)
		{
			for(int k=0;k<=cnt2;k++)
			{
				for(int pre=0;pre<4;pre++)
				{
					if(dp[i][j][k][pre]>=0x3f3f3f3f) continue;
					if(i<cnt0 and pre!=0)
					{
						dp[i+1][j][k][0]=min(dp[i+1][j][k][0],dp[i][j][k][pre]+cost0[i][j][k]);
					}
					if(j<cnt1 and pre!=1)
					{
						dp[i][j+1][k][1]=min(dp[i][j+1][k][1],dp[i][j][k][pre]+cost1[i][j][k]);
					}
					if(k<cnt2 and pre!=2)
					{
						dp[i][j][k+1][2]=min(dp[i][j][k+1][2],dp[i][j][k][pre]+cost2[i][j][k]);
					}
				}
			}
		}
	}
	int ans=INT_MAX;
	for(int pre=0;pre<3;pre++)
	{
//		cout<<dp[cnt0][cnt1][cnt2][pre]<<endl;
		ans=min(ans,dp[cnt0][cnt1][cnt2][pre]);
	}
	cout<<ans;
//	if(cnt0>=1)
//	{
//		dp[1][0][0]=pos0[0];
//	}
//	if(cnt1>=1)
//	{
//		dp[0][1][0]=pos1[0];
//	}
//	if(cnt2>=1)
//	{
//		dp[0][0][1]=pos2[0];
//	}
//	for(int a=0;a<=cnt0;a++)
//	{
//		for(int b=0;b<=cnt1;b++)
//		{
//			for(int c=0;c<=cnt2;c++)
//			{
//				int i=a+b+c;
//				if(i<=1) continue;
//				if(a>=1)
//				{
//					if(b>=1)
//					{
//						dp[a][b][c]=min(dp[a][b][c],dp[a-1][b][c]+abs(i-pos1[b-1]));
//					}
//					if(c>=1)
//					{
//						dp[a][b][c]=min(dp[a][b][c],dp[a-1][b][c]+abs(i-pos2[c-1]));
//					}
//				}
//				if(b>=1)
//				{
//					if(a>=1)
//					{
//						dp[a][b][c]=min(dp[a][b][c],dp[a][b-1][c]+abs(i-pos0[a-1]));
//					}
//					if(c>=1)
//					{
//						dp[a][b][c]=min(dp[a][b][c],dp[a][b-1][c]+abs(i-pos2[c-1]));
//					}
//				}
//				if(c>=1)
//				{
//					if(b>=1)
//					{
//						dp[a][b][c]=min(dp[a][b][c],dp[a][b][c-1]+abs(i-pos1[b-1]));
//					}
//					if(a>=1)
//					{
//						dp[a][b][c]=min(dp[a][b][c],dp[a][b][c-1]+abs(i-pos0[a-1]));
//					}
//				}
////				cout<<a<<" "<<b<<" "<<c<<endl;
////				cout<<dp[a][b][c]<<endl; 
//			}
//		}
//	}
//	cout<<dp[cnt0][cnt1][cnt2];
}
