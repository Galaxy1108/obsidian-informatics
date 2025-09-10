#include<bits/stdc++.h>
using namespace std;
int w,b;
double f[1001][1001][2];
int main() {
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	cin>>w>>b;
	f[0][0][1]=1.0;
	f[0][0][0]=0.0;
	for(int cnt=1;cnt<=w+b;cnt++)
		for(int i=0;i<=cnt&&i<=w;i++){
			int j=cnt-i;
			f[i][j][0]=1.0*i/(i+j)+1.0*j/(1.0*i+j)*f[i][j-1][1];
			if(cnt>=2)f[i][j][1]=1.0*(1.0*j/(i+j))*(1.0*(i*1.0/(i+j-1))*f[i-1][j-1][0]+1.0*((j-1)*1.0/(i+j-1))*(j>=2)*f[i][j-2][0]);
			else f[i][j][1]=0;
		}
	printf("%.9lf",f[w][b][0]);
}
