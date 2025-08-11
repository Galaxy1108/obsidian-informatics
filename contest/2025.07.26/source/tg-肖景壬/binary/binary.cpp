//~O(2^n) 
#include<bits/stdc++.h>
using namespace std;
int n,m,cc[1005],x,y,maxdep=0,maxyy=0;
int ch[1005][4005];
bool isfind[1005][5005];
void draw(int layer,int pos,int xx,int yy)
{
	if(layer>=n) return;
	int lc=xx*2-1,rc=xx*2,npx=pos,npy=pos;
	for(int i = 1; i <= cc[n-layer]; i++)
	{
		npx--;
		npy++;
		if(!isfind[layer+1][lc]) ch[yy+i][npx]=1;
		if(!isfind[layer+1][rc]) ch[yy+i][npy]=3;
	} 
	if(!isfind[layer+1][lc])
	{
		npx--;
		ch[yy+cc[n-layer]+1][npx]=2;
		maxdep=max(maxdep,yy+cc[n-layer]+1);
		maxyy=max(maxyy,npx);
		draw(layer+1,npx,lc,yy+cc[n-layer]+1);
	}
	if(!isfind[layer+1][rc])
	{
		npy++;
		maxdep=max(maxdep,yy+cc[n-layer]+1);
		maxyy=max(maxyy,npy);
		ch[yy+cc[n-layer]+1][npy]=2;
		draw(layer+1,npy,rc,yy+cc[n-layer]+1);
	}
}
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	cin>>n>>m;
	cc[1]=1;
	cc[2]=2;
	for(int i = 3; i <= 25; i++) cc[i]=cc[i-1]*2+1;
	for(int i = 1; i <= m; i++)
	{
		cin>>x>>y;
		isfind[x][y]=1;
	}
	ch[1][cc[n]+1]=2;
	draw(1,cc[n]+1,1,1);
	for(int i = 1; i <= maxdep; i++)
	{
		for(int j = 1; j <= maxyy; j++)
		{
			if(ch[i][j]==1) cout<<'/';
			else if(ch[i][j]==3) cout<<'\\';
			else if(ch[i][j]==2) cout<<'o';
			else cout<<' ';
		}
		cout<<'\n';
	}
 } 
