#include<bits/stdc++.h>
using namespace std;
int n,m,tot,ans;
int tag[110][110];
int main()
{
	freopen("oracle.in","r",stdin);
	freopen("oracle.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			++tot; 
			for(int k=i;k<=j;++k){
				tag[tot][k]=1;
			}
		}
	} 
	for(int S=0;S<(1<<tot);++S){
		if(__builtin_popcount(S)!=m) continue;
		int Tag=1;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				int Tag1=1;
				for(int k=1;k<=tot;++k){
					if(!(S>>(k-1)&1)) continue;
					if(tag[k][i]!=tag[k][j]) Tag1=0;
				}
				if(Tag1) {Tag=0;break;}
			}
		}
		ans+=Tag;
	}
	printf("%d\n",ans);
	return 0;
}
