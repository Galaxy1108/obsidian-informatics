#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define N 51

using namespace std;
typedef long long llg;

int n,w[51],nt[101];
char s[50][20];

void work(){
	for(int i=1;i<=n*2;i++)
		printf("%s\n",s[nt[i]]);
	exit(0);
}

void dfs(int u){
	if(u==n*2+1) work();
	if(nt[u]) dfs(u+1);
	else
		for(int i=min(n*2-u-1,n);i;i--)
			if(!w[i] && !nt[i+u+1]){
				w[i]++; nt[u]=nt[i+u+1]=i;
				dfs(u+1);
				w[i]--; nt[u]=nt[i+u+1]=0;
			}
}

int main(){
	File("flower");
	scanf("%d",&n);
	for(int i=n;i;i--)
		scanf("%s",s[i]);
	dfs(1);
}
