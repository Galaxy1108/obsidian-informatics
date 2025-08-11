#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
char s[805][2005];
int t,n,m,book[12][2000],l[12]={0,1,2,5,11,23,47,95,191,383,767},c[12];
pair<int,int> a[15];
void dfs(int x,int y,int q,int p,int la){
	if(x==n&&y%2)
		la=p-1;
	for(int i=la;i<p;i++)
		s[q][i]='*';
	if(book[x][y])
		s[q][p]=' ';
	else
		s[q][p]='o';
	if(x==n){
		t=q;
		return;
	}
	for(int i=1;i<=l[n-x];i++){
		if(!la)
			for(int j=0;j<p-i;j++)
				s[q+i][j]='*';
		else
			for(int j=la+i;j<p-i;j++)
				s[q+i][j]='*';
		if(!book[x][y]&&!book[x+1][y*2-1])
			s[q+i][p-i]='/';
		else
			s[q+i][p-i]=' ';
	}
	for(int i=1;i<=l[n-x];i++){
		for(int j=p+i-1;j>=p+i-2*i+1;j--)
			s[q+i][j]='*';
		if(!book[x][y]&&!book[x+1][y*2])
			s[q+i][p+i]='\\';
		else
			s[q+i][p+i]=' ';
	}
	if(book[x][y]){
		book[x+1][y*2-1]=1;
		book[x+1][y*2]=1;
	}
	dfs(x+1,y*2-1,q+l[n-x]+1,p-(l[n-x]+1),max(0,p-l[n-x]*3-2));
	dfs(x+1,y*2,q+l[n-x]+1,p+l[n-x]+1,p-(l[n-x]+1)+1);
}
int main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a[i].fi>>a[i].se;
		book[a[i].fi][a[i].se]=1;
	}
	for(int i=2;i<=n;i++)
		c[i]=c[i-1]*2;
	dfs(1,1,1,l[n],0);
	for(int i=1;i<=t;i++,cout<<endl){
		for(int j=0;;j++){
			if(s[i][j]!=' '&&s[i][j]!='o'&&s[i][j]!='/'&&s[i][j]!='\\'&&s[i][j]!='*')
				break;
			if(s[i][j]=='*')
				cout<<" ";
			else
				cout<<s[i][j];
		}
	}
	return 0;
}
