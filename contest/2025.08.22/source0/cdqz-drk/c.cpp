#include <cstdio>
#include <iostream>
#include <random>
using namespace std;
const int N=5003;
bool bj[N*2][N];
int n,a[N*2][N],b[N*2][N],cur[N*2];
void gen(int seed){
    mt19937 rng(seed);
    for(int i=0;i<n;++i)
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            swap(a[i][j],a[i][rng()%j+1]);
        }
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int i,j,k,s1;
	scanf("%d%d",&n,&s1);
	if(s1>0) gen(s1);
	else for(i=0;i<n;i++)
		for(j=1;j<=n+1;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
		for(j=1;j<=n+1;j++)
			b[i][a[i][j]]=j;
	for(i=0;i<n;i++)
		for(j=1;j<=n+1;j++)
			a[i+n][j]=a[i][j];
	for(i=0;i<n;i++)
		for(j=1;j<=n+1;j++)
			b[i+n][j]=b[i][j];
	for(i=0;i<n*2;i++) cur[i]=1;
	for(i=n-1;i>=0;i--){
		while(bj[i][cur[i]]) cur[i]++;
		for(j=i;j>=0;j--)
			bj[j][a[j][b[i][cur[i]]]]=1;
	}
	for(i=cur[0]+1;i<=n+1;i++)
		if(!bj[0][i]) break;
	printf("%d ",b[0][i]);
	for(i=1;i<n;i++){
		for(j=i+n-1,k=-1;j>=i;j--)
			if(k>0&&!bj[j][a[j][k]])
				bj[j][a[j][k]]=1;
			else{
				while(bj[j][cur[j]]) cur[j]++;
				bj[j][cur[j]]=1,k=b[j][cur[j]];
			}
		for(j=cur[i]+1;j<=n+1;j++)
			if(!bj[i][j]) break;
		printf("%d ",b[i][j]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
