#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
#define re int
inline int read(){
	int x=0,ff=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')ff=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
	return x*ff;
}
int n,m,mn,f[3005][3005][2];
inline int md(int x){return x>=mn?x-mn:x;}
int main(){
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	f[0][0][1]=1;
	n=read();m=read();mn=read();
	for(re i=1;i<=n;i++)f[0][i][0]=1;
	for(re i=1;i<=m;i++){
		for(re j=0;j<=n;j++){
			int k=n-j;
			if(j>0){
				if(j==1){
					// f[i][j][0]=md(f[i][j][0]+f[i-1][j][0]);
					// f[i][j-1][0]=md(f[i][j-1][0]+f[i-1][j][0]);
					f[i][j][1]=md(f[i][j][1]+f[i-1][j][0]);
					f[i][j-1][1]=md(f[i][j-1][1]+f[i-1][j][0]);
					f[i][j][1]=md(f[i][j][1]+f[i-1][j][1]);
					f[i][j-1][1]=md(f[i][j-1][1]+f[i-1][j][1]);
				}
				else {
					f[i][j][0]=md(f[i][j][0]+f[i-1][j][0]);
					f[i][j-1][0]=md(f[i][j-1][0]+f[i-1][j][0]);
					f[i][j][1]=md(f[i][j][1]+f[i-1][j][1]);
					f[i][j-1][1]=md(f[i][j-1][1]+f[i-1][j][1]);
				}
			}
			if(k>0){
				f[i][j][0]=md(f[i][j][0]+f[i-1][j][0]);
				f[i][j+1][0]=md(f[i][j+1][0]+f[i-1][j][0]);
				f[i][j][1]=md(f[i][j][1]+f[i-1][j][1]);
				f[i][j+1][1]=md(f[i][j+1][1]+f[i-1][j][1]);
			}
		}
	}
	int ans=0;
	for(re i=0;i<=n;i++)ans=md(ans+f[m][i][1]);
	cout<<ans<<endl;
	return 0;
}