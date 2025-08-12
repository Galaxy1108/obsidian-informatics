#include<bits/stdc++.h>
using namespace std;
int n,m,tot;
int v[510][510],sum[510][510],col[510][510];
char s[510];
int Sum(int p,int q,int x,int y){
	return sum[x][y]+sum[p-1][q-1]-sum[x][q-1]-sum[p-1][y];
}
int main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%s",s+1); 
		for(int j=1;j<=m;++j){
			v[i][j]=(s[j]=='B');
			sum[i][j]=sum[i][j-1]+v[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			sum[i][j]=sum[i-1][j]+sum[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(v[i][j]==0&&col[i][j]==0){
				int p=0,q=0;
				for(int k=j;j<=m;++k){
					if(Sum(i,j,i,k)==0) p=k;
					else break;
				}
				for(int k=i;k<=n;++k){
					if(Sum(i,j,k,p)==0) q=k;
					else break;
				}
				++tot;
				for(int k=i;k<=q;++k){
					for(int l=j;l<=p;++l){
						col[k][l]=tot;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%d ",col[i][j]);
		}
		printf("\n");
	}
	cerr<<tot<<' ';
	return 0;
}
