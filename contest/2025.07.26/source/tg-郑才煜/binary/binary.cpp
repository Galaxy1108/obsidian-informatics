#include<bits/stdc++.h>
using namespace std;
int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		sum=(sum<<3)+(sum<<1)+c-'0';
		c=getchar();
	}
	return sum*f;
}
int m,n;
int lowbit(int x)
{
	return x&-x;
}
bool check(int num)
{
	if(lowbit(num)==num) return true;
	else return false;
}
bool loog(int x)
{
	int cnt=0;
	while(x)
	{
		x>>=1;
		++cnt;
	}
	return cnt;
}
const int N=2e3;
char st[N][N];
int a[N],wid;
bool f[N],book[N][N];
void dfs(int p,int q)
{
	if(st[p][q]==' ') return;
	st[p][q]=' ';
	if(p+1>wid) return;
	if(q+1>2*wid) return;
	if(q-1<=0) return;
	if(st[p+1][q-1]!=' ') dfs(p+1,q-1);
	if(st[p+1][q+1]!=' ') dfs(p+1,q+1);
}
void rc(int o,int p)
{
	while(st[--o][--p]!='o') st[o][p]=' ';
	return;
}
void lc(int o,int p)
{
	while(st[--o][++p]!='o') st[o][p]=' ';
	return;
}
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	m=read();
	n=read();
	int i,j,k,point=1<<(m-1),last=1,num=0,x,y;
	wid=point*3/2;
	for(i=1;i<wid;++i)
	{
		if(wid%(wid-i+1)==0&&check(wid/(wid-i+1)))
		{
			for(j=1;j<=wid-i;++j) st[i][++a[i]]=' ';
			int t=wid/(wid-i+1);
			for(j=1;j<=t;++j)
			{
				st[i][++a[i]]='o';
				book[i][a[i]]=true;
				if(j==t) break;
				for(k=1;k<=2*(wid-i)+1;++k) st[i][++a[i]]=' ';
			}
			last=i;
			++num;
			f[i]=true;
		}
		else
		{
			int t=1<<(num-1);
			for(j=1;j<=t;++j)
			{
				for(k=1;k<=wid-i;++k) st[i][++a[i]]=' ';
				st[i][++a[i]]='/';
				for(k=1;k<=2*(i-last)-1;++k) st[i][++a[i]]=' ';
				st[i][++a[i]]=92;
				if(j==t) break;
				for(k=1;k<=wid-i+1;++k) st[i][++a[i]]=' ';
			}
		}
	}
	for(i=1;i<=point/2;++i)
	{
		st[wid][(i-1)*6+1]='o';
		st[wid][(i-1)*6+2]=' ';
		st[wid][(i-1)*6+3]=' ';
		st[wid][(i-1)*6+4]=' ';
		st[wid][(i-1)*6+5]='o';
		st[wid][i*6]=' ';
		book[wid][(i-1)*6+1]=true;
		book[wid][(i-1)*6+5]=true;
	}
	f[wid]=true;
	a[wid]=2*wid;
	while(n--)
	{
		x=read();
		y=read();
		int dep=1,g=1;
		for(i=0;i<x&&dep<=wid;++dep) if(f[dep]) ++i;
		--dep;
		for(i=0;i<y&&g<=2*wid;++g) if(book[dep][g]) ++i;
		--g;
		if(st[dep][g]==' ') continue;
		dfs(dep,g);
		if(y&1) lc(dep,g);
		else rc(dep,g);
	}
	for(i=1;i<=wid;++i)
	{
		for(j=1;j<=a[i];++j) cout<<st[i][j];
		if(i==wid) return 0;
		cout<<endl;
	}
}
