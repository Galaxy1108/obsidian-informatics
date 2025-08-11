#include<cstdio>
#include<algorithm>
using namespace std;
const int N=205;
const int mod=1e9+7;
int n,k;
int a[N];
int f[201][7][6][5][4][3][2];
int ans; 
int b[10];
void dfs(int x,int y,int z,int h){
	if(x==k+1){
		if(y) return;
		f[z][b[2]][b[3]][b[4]][b[5]][b[6]][b[7]]=(f[z][b[2]][b[3]][b[4]][b[5]][b[6]][b[7]]+h)%mod;
		return;
	}
	dfs(x+1,y,z,h);
	if(y){
		b[x]++;
		dfs(x+1,y-1,z,h);
		b[x]--;
	}
	
}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[0][0][0][0][0][0][0]=1; 
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int x1=0;x1<max(1,min(7,k))&&x1<=a[i];x1++){
			for(int x2=0;x2<max(1,min(6,k-1))&&x1+x2<=a[i];x2++){
				for(int x3=0;x3<max(1,min(5,k-2))&&x1+x2+x3<=a[i];x3++){
					for(int x4=0;x4<max(1,min(4,k-3))&&x1+x2+x3+x4<=a[i];x4++){
						for(int x5=0;x5<max(1,min(3,k-4))&&x1+x2+x3+x4+x5<=a[i];x5++){
							for(int x6=0;x6<max(1,min(2,k-5))&&x1+x2+x3+x4+x5+x6<=a[i];x6++){
								if(f[i-1][x1][x2][x3][x4][x5][x6]==0) continue;
								int cnt=a[i]-x1-x2-x3-x4-x5-x6; 				
								b[1]=x1,b[2]=x2;
								b[3]=x3;
								b[4]=x4;
								b[5]=x5;
								b[6]=x6;
								dfs(1,cnt,i,f[i-1][x1][x2][x3][x4][x5][x6]);
							}
						}
					}
				}
			}
		}
	}
	for(int x1=0;x1<7;x1++) for(int x2=0;x2<6;x2++) for(int x3=0;x3<5;x3++) for(int x4=0;x4<4;x4++) for(int x5=0;x5<3;x5++) for(int x6=0;x6<2;x6++) ans=(ans+f[n][x1][x2][x3][x4][x5][x6])%mod;
	printf("%d",ans);
	return 0;
} 
