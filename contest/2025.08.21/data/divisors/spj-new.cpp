#include <bits/stdc++.h>

using namespace std;

const int MAXN=2522;

int n,x,y;

int w[MAXN];

struct Edge{
	int to,nxt;
} es[MAXN<<1];
int cnt=0;

int first[MAXN];

void addE(int from,int to)
{
	es[++cnt]=(Edge){to,first[from]};
	first[from]=cnt;
}

int f[MAXN];

int Find(int p)
{
	return p==f[p]?p:f[p]=Find(f[p]);
}

int gcd(int p,int q)
{
	return q?gcd(q,p%q):p;
}

bool vis[MAXN];

void dfs(int p,int from,int g)
{
	g=gcd(g,w[p]);
	if(from && 1<=g && g<=n)
		vis[g]=true;
	for(int e=first[p];e;e=es[e].nxt)
		if(es[e].to!=from)
			dfs(es[e].to,p,g);
}

void setResult(double score)
{
	printf("%0.1lf\n",score);
	exit(0);
}

int main(int argc,char *argv[])
{
	freopen(argv[4],"w",stdout);
	FILE *fin=fopen(argv[1],"r");
	FILE *fout=fopen(argv[2],"r");
	fscanf(fin,"%d",&n);
	for(int i=1;i<=n;i++)
	{
		int tmp=fscanf(fout,"%d",&w[i]);
		if(tmp!=1 || w[i]<1 || w[i]>11000)
			setResult(0.0);
	}
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<n;i++)
	{
		int tmp=fscanf(fout,"%d%d",&x,&y);
		if(tmp!=2 || x<1 || x>n || y<1 || y>n)
			setResult(0.0);
		if(Find(x)==Find(y))
			setResult(0.0);
		f[Find(x)]=Find(y);
		addE(x,y),addE(y,x);
	}
	for(int i=1;i<=n;i++)
		dfs(i,0,0);
	for(int i=1;i<=n;i++)
		if(!vis[i])
			setResult(0.0);
	fclose(fin);
	fclose(fout);
	setResult(1.0);
	return 0;
}