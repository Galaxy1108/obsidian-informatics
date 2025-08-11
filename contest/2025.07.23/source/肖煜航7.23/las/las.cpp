#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+5;
int f[N][5];
int n,a[N];
int ans[N];
int main(){
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[n+1]=a[1];
	for(int i=1;i<5;i++){
		memset(f,0,sizeof f);
		f[1][i]=1;
		for(int j=2;j<=n+1;j++){ 
			if(a[j-1]<=a[j]*2){
				if(f[j-1][1]) f[j][1]=1;
			}
			if(a[j-1]<=a[j]) if(f[j-1][1]) f[j][3]=1;
			if(a[j]<=a[j-1]*2) if(f[j-1][2]) f[j][2]=2;
			if(a[j]<=a[j-1]){
				if(f[j-1][2]) f[j][4]=2;
				if(f[j-1][3]) f[j][2]=3;
			}
			if(a[j-1]>=2*a[j]) if(f[j-1][3]) f[j][4]=3;
			if(a[j-1]<=a[j]) if(f[j-1][4]) f[j][1]=4;
			if(a[j-1]*2<=a[j]) if(f[j-1][4]) f[j][3]=4;
		}
		if(f[n+1][i]){ 
			int now=i;
			for(int j=n+1;j;j--){
				if(now==1) ans[j-1]=j; 
				if(now==2) ans[j]=j;
				if(now==3) ans[j-1]=ans[j]=j;
				now=f[j][now];
			}
			for(int j=1;j<=n;j++){
				printf("%d ",(ans[j]-1)%n+1);
			}
			return 0;
		}
	}
	printf("NIE");
	return 0;
}
