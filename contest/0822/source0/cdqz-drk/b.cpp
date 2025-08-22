#include <cstdio>
#include <iostream>
using namespace std;
const int N=2003,PIN=1e9;
bool bin[N];
int n,a[N][N],dis[N];
void Dijkstra(){
	bool bj[N]={0};
	int i,j,s1,s2;
	for(i=1;i<=n;i++){
		s1=PIN*2,s2=-1;
		for(j=1;j<=n;j++)
			if(!bj[j]&&dis[j]<s1)
				s1=dis[j],s2=j;
		bj[s2]=1;
		for(j=1;j<=n;j++)
			if(!bj[j]&&dis[s2]+a[s2][j]<dis[j])
				dis[j]=dis[s2]+a[s2][j];
	}
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int i,j,minn=PIN,s1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			a[j][i]=a[i][j];
	for(i=1;i<=n;i++) a[i][i]=PIN;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			minn=min(minn,a[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j) a[i][j]-=minn;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]==0) bin[i]=bin[j]=1;
	for(i=1;i<=n;i++){
		for(j=1,s1=PIN;j<=n;j++)
			s1=min(s1,a[i][j]);
		dis[i]=min(s1*2,PIN);
	}
	Dijkstra();
	for(i=1;i<=n;i++)
		printf("%lld\n",(long long)minn*(n-1)+dis[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
