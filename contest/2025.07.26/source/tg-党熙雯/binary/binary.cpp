#include<bits/stdc++.h>
using namespace std;
int m,n;
char ch[2100][2100];
int vis[110][110];
int fread(){
	int x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;}
int ksm(int a,int b){ int ans=1; while(b) {if(b%2) ans*=a;a*=a,b/=2;} return ans;} 
void build(int p,int pos,int x,int y)//表示当前在第p层，第x列，第y行 
{
	if(p>n) return ;
//	cout<<p<<','<<pos<<':'<<x<<' '<<y<<endl;
	if(vis[p][pos]) return ;
//	cout<<endl;
	ch[y][x]='o';
	for(int i=x-1,j=y-1;i>x-ceil((y/2.0));i--,j--)
	{
		if(!vis[p+1][pos*2-1])
		ch[j][i]='/';
		if(!vis[p+1][pos*2])
		ch[j][2*x-i]='\\';
	}
	build(p+1,pos*2-1,x-ceil((y/2.0)),y>>1);
	build(p+1,pos*2,x+ceil(y/2.0),y>>1);
	return ;
}
void print()
{
	for(int i=3*ksm(2,n-2);i>=1;i--)
	{
		for(int j=1;j<=ksm(2,n-2)*6-1;j++)
		{
			if(ch[i][j]) putchar(ch[i][j]);
			else putchar(' ');
		}
		cout<<endl;
	}
}
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	n=fread(),m=fread();//n表示有几层，m要删几个 
//	cout.tie(0);
	if(n==0)
	{
		return 0;
	}
	if(n==1&&m==0)
	{
		cout<<'o';
		return 0;
	}
	if(n==1&&m==1)
	{
		int x=fread(),y=fread();
		if(x==1&&y==1)
		cout<<' ';
		return 0;
	}
	if(n==2)
	{
		if(m==0)
		{
			cout<<"  o  \n / \\\no   o";
			return 0;
		}
		if(m==1)
		{
			int x=fread(),y=fread();
			if(x==1) cout<<' ';
			else
			if(y==1)
			cout<<"  o  \n   \\ \n    o";
			else
			cout<<"  o  \n /   \no    ";
		}
		else
		cout<<' ';
		return 0;
	}
//	for(int i=1;i<=10;i++) cout<<ksm(2,i)<<' ';
//	cout<<ksm(2,n-3)*6<<endl;
//	cout<<n<<' '<<m<<endl;
//	cout<<ksm(2,n-3)*6<<endl;
	while(m--)
	{
		int lev=fread(),pos=fread();//第lev层第pos个
		vis[lev][pos]=1;
	}
	build(1,1,ksm(2,n-3)*6,3*ksm(2,n-2));
	print();
	return 0;
}
