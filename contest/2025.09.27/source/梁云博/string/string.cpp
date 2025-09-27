#include <bits/stdc++.h>
#define N 405
#define int long long
using namespace std;
string s;
bool isa()
{
    for(int i=1;i<s.size();i++)if(s[i]==s[i-1])return 0;
    return 1;
}
int cnt()
{
    int t[3]={0};
    for(char c:s)t[c-'0']++;
    return max({t[1],t[0],t[2]});
}

int f[N][N][N][3];
int w[N][N][3];//在i放置j的最小代价
int a[N],n,cnt1,cnt2,cnt0;
int p0[N],p1[N],p2[N],x,y,z; 


int find0(int st)
{
	static int idx=1;
	for(idx=max(idx,st);idx<=n;idx++)if(a[idx]==0)return idx;
}
int find1(int st)
{
	static int idx=1;
	for(idx=max(idx,st);idx<=n;idx++)if(a[idx]==1)return idx;
}
int find2(int st)
{
	static int idx=1;
	for(idx=max(idx,st);idx<=n;idx++)if(a[idx]==2)return idx;
}

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s;
    n=s.size();
    if(isa())cout<<0;
    else if(cnt()>(s.size()+1)/2)cout<<-1;
    else
    {
        for(int i=1;i<=n;i++)
        {
            a[i]=s[i-1]-'0';
            if(a[i]==1)cnt1++;
            else if(a[i]==2)cnt2++;
            else cnt0++;
        }
        for(int i=1;i<=n;i++)//第x个0的位置 
        {
            if(a[i]==0)p0[++x]=i;
        }
		for(int i=1;i<=n;i++)//第y个1的位置 
        {
            if(a[i]==1)p1[++y]=i;
        }
		for(int i=1;i<=n;i++)//第z个2的位置 
        {
            if(a[i]==2)p2[++z]=i;
        }
		//处理出代价
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=x;j++)w[i][j][0]=max(0ll,p0[j]-i);
			for(int j=1;j<=y;j++)w[i][j][1]=max(0ll,p1[j]-i);
			for(int j=1;j<=z;j++)w[i][j][2]=max(0ll,p2[j]-i);
		}
		
        for(int r=0;r<=cnt0;r++)
        	for(int b=0;b<=cnt1;b++)
        		for(int c=0;c<=cnt2;c++)
        			for(int k=0;k<3;k++)
        				f[r][b][c][k]=1e18;
        f[0][0][0][1]=f[0][0][0][2]=f[0][0][0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int r=0;r<=cnt0;r++)
            {
                for(int b=0;b<=cnt1;b++)
                {
                    int c=i-r-b;
                    if(c>cnt2)continue;
                    if(c<0)break;
                    for(int k=0;k<3;k++)
                    {
                        if(k!=0)
                        {
                            if(r)
							{
								f[r][b][c][0]=min(f[r-1][b][c][1]+w[i][r][0],f[r][b][c][0]);//this place 0
								f[r][b][c][0]=min(f[r-1][b][c][2]+w[i][r][0],f[r][b][c][0]);//this place 0
							} 
                        }
                        if(k!=1)
                        {
                            if(b)
							{
								f[r][b][c][1]=min(f[r][b-1][c][0]+w[i][b][1],f[r][b][c][1]);//this place 1
								f[r][b][c][1]=min(f[r][b-1][c][2]+w[i][b][1],f[r][b][c][1]);//this place 1
							}
                        }
                        if(k!=2)
                        {
                            if(c)
							{
								f[r][b][c][2]=min(f[r][b][c-1][0]+w[i][c][2],f[r][b][c][2]);//this place 2
								f[r][b][c][2]=min(f[r][b][c-1][1]+w[i][c][2],f[r][b][c][2]);//this place 2
							}
                        }
                    }
                    
                }
            }
        }
        cout<<min({f[cnt0][cnt1][cnt2][0],f[cnt0][cnt1][cnt2][1],f[cnt0][cnt1][cnt2][2]});
    }
    return 0;
}