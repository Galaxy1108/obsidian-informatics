#include<bits/stdc++.h> 
using namespace std;
int m,n;
char ch[1000][4096];
int vis[1000][4096];
int sum;
int ksm(int x,int y)
{
	int ans=1;
	int X=x,Y=y;
	while(Y)
	{
		if(Y%2) ans*=X;
		X*=X;
		Y/=2;
	}
	return ans;
}
int findx(int x)
{
	int h=sum;
	int ans=1;
	x--;
	while(x)
	{
		ans+=ceil(h/2);
		x--;
		h/=2;
	}
}
int findy(int x,int y)
{
	int xx=findx(x),cnt=0;
	for(int i=1;i<=2*sum-1;i++)
	{
		if(ch[xx][i]=='o') cnt++;
		if(cnt==y)
		{
			return i;
		}
	}
} 
void Delete(int x,int y)
{
	if(x>sum) return;
	ch[x][y]=' ';
	if(ch[x+1][y-1]=='/') Delete(x+1,y-1); 
	if(ch[x+1][y+1]=='\\') Delete(x+1,y+1); 
} 
int main()
{
	//freopen("binary.in","r",stdin);
	//freopen("binary.out","w",stdout);
	cin>>m>>n;
	
	if(m==1)
	{
		sum=1;
		ch[1][1]='o';
	} 
	else
	{
		sum=ksm(2,m-1)+ksm(2,m-2);
		for(int i=1;i<=2*sum-1;i++)
		{
			if(i%6==1||i%6==5) ch[sum][i]='o';
			else ch[sum][i]=' ';
		} 

		for(int i=sum-1;i>0;i--)
		{
			char lst='\\';
			for(int j=1;j<=2*sum-1;j++)	
			{
				if(j>=sum-i+1&&j<=sum+i-1)
				{
					if(ch[i+1][j-1]=='/'&&ch[i+1][j+1]=='\\') ch[i][j]='o';
				    else if((ch[i+1][j-1]=='/'||ch[i+1][j-1]=='o')&&lst=='\\'&&vis[i+1][j-1]==0)
				    {
				    	ch[i][j]='/';
						lst='/';
						vis[i+1][j-1]=1;
					}
						
					else if((ch[i+1][j+1]=='\\'||ch[i+1][j+1]=='o')&&lst=='/'&&vis[i+1][j+1]==0)
					{
						ch[i][j]='\\';
						lst='\\';
						vis[i+1][j+1]=1;
					}
					
					else ch[i][j]=' ';
				}
				else ch[i][j]=' ';
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		int xx=findx(x),yy=findy(x,y);
		ch[xx][yy]=' ';
		Delete(xx,yy);
		if(ch[xx-1][yy-1]=='\\')
		{
			xx--,yy--;
			while(ch[xx][yy]!='o'&&xx>0) ch[xx--][yy--]=' ';
		}
		else if(ch[xx-1][yy+1]=='/')
		{
			xx--,yy++;
			while(ch[xx][yy]!='o'&&xx>0) ch[xx--][yy++]=' ';
		}
	}
	for(int i=1;i<=sum;i++)
	{
		for(int j=1;j<=2*sum-1;j++)
		cout<<ch[i][j];
		cout<<endl;
	}
		

	return 0;
}
