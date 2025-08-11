#include<bits/stdc++.h>
using namespace std;
int m,n;
int x,y;
int kong[15];
char a[3000][3000];
bool tick[3000][3000];
int s=1,t=0;
struct node
{
	int x,y;
}pos[15][600];
int ax=1,ay=0;
int pow(int a,int b)
{
	if(b==0)
	{
		return 1;
	}
	else
	{
		int sum=1;
		for(int i=1;i<=b;i++)
		{
			sum*=a;
		}
		return sum;
	}
}
void print()
{
	kong[1]=0;
	kong[2]=2;
	for(int i=3;i<=m;i++)
	{
		kong[i]=2*kong[i-1]+1;
	}
	for(int i=m;i>=2;i--)
	{
		int num=pow(2,m-i);
		for(int j=1;j<=kong[i];j++)
		{
			//cout<<" ";
			a[s][++t]=char(32);
		}
		for(int j=1;j<num;j++)
		{
			//cout<<"o";
			a[s][++t]='o';
			pos[ax][++ay].x=s;
			pos[ax][ay].y=t;
			for(int k=1;k<=kong[i+1];k++)
			{
				//cout<<" ";
				a[s][++t]=char(32);
			}
		}
		//cout<<"o";
		a[s][++t]='o';
		pos[ax][++ay].x=s;
		pos[ax][ay].y=t;
		for(int j=1;j<=kong[i];j++)
		{
			//cout<<" ";
			a[s][++t]=char(32);
		}
		//cout<<endl;
		s++;
		t=0;
		ax++;
		ay=0;
		//------------
		int h=kong[i-1];
		for(int k=1;k<=h;k++)
		{
			for(int u=1;u<=num;u++)
			{
				int p;
				int l=kong[i]-k;
				int m=2*k-1;
				int r=l;
				for(p=1;p<=l;p++)
				{
					//cout<<" ";
					a[s][++t]=char(32);
				}
				//cout<<"/";
				a[s][++t]='/';
				for(p=1;p<=m;p++)
				{
					//cout<<" ";
					a[s][++t]=char(32);
				}
				//cout<<"\\";
				a[s][++t]='\\';
				for(p=1;p<=r;p++)
				{
					//cout<<" ";
					a[s][++t]=char(32);
				}
				//cout<<" ";
				a[s][++t]=char(32);
			}
			//cout<<endl;
			s++;
			t=0;
		}
	}
	int num=pow(2,m-2);
	for(int u=1;u<=num;u++)
	{
		//cout<<" / \\ ";
		//cout<<" ";
		a[s][++t]=char(32);
		a[s][++t]='/';
		a[s][++t]=char(32);
		a[s][++t]='\\';
		a[s][++t]=char(32);
		a[s][++t]=char(32);
	}
	//cout<<endl;
	s++;
	t=0;
	for(int u=1;u<=num;u++)
	{
		//cout<<"o   o";
		//cout<<" ";
		a[s][++t]='o';
		
		pos[ax][++ay].x=s;
		pos[ax][ay].y=t;
		
		a[s][++t]=char(32);
		a[s][++t]=char(32);
		a[s][++t]=char(32);
		a[s][++t]='o';
		
		pos[ax][++ay].x=s;
		pos[ax][ay].y=t;
		
		a[s][++t]=char(32);
	}
	//cout<<endl;
}
void BFS(int x,int y)
{
	if(x>s)
	{
		return;
	}
	else
	{
		if(x-1>=1&&y-1>=1&&a[x-1][y-1]!=char(32))
		{
			int h=x-1,g=y-1;
			while(a[h][g]!='o')
			{
				tick[h][g]=1;
				h--;
				g--;
			}
		}
		if(x-1>=1&&y+1>=1&&a[x-1][y+1]!=char(32))
		{
			int h=x-1,g=y+1;
			while(a[h][g]!='o')
			{
				tick[h][g]=1;
				h--;
				g++;
			}
		}
		if(a[x+1][y-1]!=char(32))
		{
			tick[x+1][y-1]=1;
			BFS(x+1,y-1);
		}
		if(a[x+1][y+1]!=char(32))
		{
			tick[x+1][y+1]=1;
			BFS(x+1,y+1);
		}
	}
}
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	cin>>m>>n;
	if(n==0)
	{
		print();
		for(int i=1;i<=s;i++)
		{
			for(int j=1;j<=t;j++)
			{
				cout<<a[i][j];
			}
			cout<<endl;
		}
	}
	else
	{
		print();
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y;
			int a=pos[x][y].x,b=pos[x][y].y;
			tick[a][b]=1;
			BFS(a,b);
		}
		
		
		
		for(int i=1;i<=s;i++)
		{
			for(int j=1;j<=t;j++)
			{
				if(tick[i][j]==0)
				{
					cout<<a[i][j];	
				}
				else
				{
					cout<<char(32);
				}
			}
			cout<<endl;
		}
	}
}  
