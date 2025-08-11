#include <bits/stdc++.h>
//#define int long long
using namespace std;
int m,n;
const int maxn=3000;
char mp[maxn][maxn];
bool index[maxn];
int sum_index;
int read()
{
	int f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}
void init()
{
	for(int i=1;i<maxn;i++){
		for(int j=1;j<maxn;j++){
			mp[i][j]=' ';
		}
	} 
}
void dfs(int u)
{
	if(u>sum_index){
		return ;
	}
	index[u]=1;
	dfs(2*u);
	dfs(2*u+1);
}
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	m=read();n=read();
	sum_index=pow(2,m)-1;
	int max_row=pow(2,m-2)*6-1;
	init();
	for(int i=1;i<=n;i++){
		int a=read();int b=read();
		int hh=pow(2,a-1);
		dfs(hh+b-1);
	}
	int last=max_row;
	int line=1;
	for(int i=1;i<=m;i++){
		int now=last/2;
		if(i!=1) line+=now+1;
		if(i>m-1) now=0,last=3;
		for(int j=pow(2,i-1);j<=pow(2,i)-1;j++){
			if(!index[j])
			{
				int kk=pow(2,i-1);
				if(i<=m-1)
				mp[line][now+(last+1)*(j-kk)+1]='o';
				else{
					int in=j-kk+1;
					if(in&1)mp[line][(in-1)/2*6+1]='o';
					else mp[line][(in-1)/2*6+1+4]='o';
				}
				
				int l=line;
				if(!index[2*j])
				{
					int pp=pow(2,i-1);
					
					for(int k=1;k<=now/2;k++){
						l++;
						mp[l][now+(last+1)*(j-kk)+1-k]='/';
					}	
				}
				l=line;
				if(!index[2*j+1])
				{
					int qq=pow(2,i-1);
					for(int k=1;k<=now/2;k++){
						l++;
						mp[l][now+(last+1)*(j-kk)+1+k]='\\'; 
					}	
				}
			}
		}
		last/=2;
	}
	for(int i=1;i<=line;i++){
		for(int j=1;j<=max_row;j++){
			printf("%c",mp[i][j]);
		}
		printf("\n");
	}
	return 0;
}
