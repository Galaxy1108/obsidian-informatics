#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;
int n,cnt1,cnt2,cnt3,ans,x;
int s[110],sum1[110],sum2[110],sum3[110];
int f[110][12][12][12];
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		char st=getchar();
		while(!((st=='A')||(st=='B')||(st=='C'))) st=getchar();
		s[i]=st-'A'+1;
		sum1[i]=sum1[i-1];
		sum2[i]=sum2[i-1];
		sum3[i]=sum3[i-1];
		
		if(s[i]==1) ++sum1[i];
		if(s[i]==2) ++sum2[i];
		if(s[i]==3) ++sum3[i];
		if(i<=10){
			if(s[i]==1) ++cnt1;
			if(s[i]==2) ++cnt2;
			if(s[i]==3) ++cnt3;
		}
	}
	for(int i=0;i<=n;++i){
		for(int a=0;a<=10;++a){
			for(int b=0;b<=10;++b){
				for(int c=0;c<=10;++c){
					f[i][a][b][c]=1000000000;
				}
			}
		}
	}
	f[min(n,10)][cnt1][cnt2][cnt3]=0;
	for(int i=0;i<=n;++i){
		for(int a=10;a>=0;--a){
			for(int b=10;b>=0;--b){
				for(int c=10;c>=0;--c){
					if(f[i][a][b][c]==inf) continue;
					x=min(n,i+a);
					cnt1=sum1[x]-sum1[i];
					cnt2=b+sum2[x]-sum2[i];
					cnt3=c+sum3[x]-sum3[i];
					f[x][cnt1][cnt2][cnt3]=min(f[x][cnt1][cnt2][cnt3],f[i][a][b][c]+1);
					
					x=min(n,i+b);
					cnt1=a+sum1[x]-sum1[i];
					cnt2=sum2[x]-sum2[i];
					cnt3=c+sum3[x]-sum3[i];
					f[x][cnt1][cnt2][cnt3]=min(f[x][cnt1][cnt2][cnt3],f[i][a][b][c]+1);
					
					x=min(n,i+c);
					cnt1=a+sum1[x]-sum1[i];
					cnt2=b+sum2[x]-sum2[i];
					cnt3=sum3[x]-sum3[i];
					f[x][cnt1][cnt2][cnt3]=min(f[x][cnt1][cnt2][cnt3],f[i][a][b][c]+1);
				}
			}
		}
	}
	printf("%d\n",f[n][0][0][0]);
	
	return 0;
}
