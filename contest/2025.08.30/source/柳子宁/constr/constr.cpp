#include<bits/stdc++.h>
using namespace std;
int n,p[110],tag[110];
void dfs(int x){
	if(x>n){
		for(int i=1;i<=n;++i) printf("%d ",p[i]);
		printf("\n");
	}
	int tot=0;
	for(int i=1;i<=n;++i){
		if(tag[i]==0){
			++tot;
			if(tot&1){
				p[x]=i,tag[i]=1;
				dfs(x+1);
				p[x]=0,tag[i]=0;
			}
		}
	}
}
int main()
{
	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
	n=10;
	printf("14400\n"); 
	dfs(1);
	return 0;
}
