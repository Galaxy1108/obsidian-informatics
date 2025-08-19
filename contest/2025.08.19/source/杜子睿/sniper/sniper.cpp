#include<bits/stdc++.h>
using namespace std;
int v[25]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int f[25005][25][2],n;
struct node{
	int w,u,t;
}a[8005];
int idx;
int main(){
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	memset(f,-0x3f3f3f3f,sizeof f);
	for(int i=0;i<=20;i++)
		f[0][i][0]=0;
	for(int i=0;i<n;i++){
		cin>>a[i].w>>a[i].u>>a[i].t;
		a[i].t++;
	}
	for(int i=1;;i++){
		for(int j=0;j<=20;j++){
			if(j>=1)
				f[i][j-1][0]=max(f[i][j-1][0],f[i-1][j][0]);
			if(j>=2)
				f[i][j-2][0]=max(f[i][j-2][0],f[i-1][j][0]);
			if(j<=18)
				f[i][j+2][0]=max(f[i][j+2][0],f[i-1][j][0]);
			if(j<=19)
				f[i][j+1][0]=max(f[i][j+1][0],f[i-1][j][0]);
			f[i][j][0]=max(f[i][j][0],f[i-1][j][0]);
		}
		int fl=0;
		while(a[idx].t==i){
			if(a[idx].w==15){
				fl=1;
				int ttt=f[i][a[idx].u][0];
				memset(f[i],-0x3f3f3f3f,sizeof f[i]);
				f[i][a[idx].u][1]=ttt+50;
			}
			else if(!fl)
				f[i][a[idx].u][1]=f[i][a[idx].u][0]+v[a[idx].w];
			idx++;
		}
		if(!fl)
			for(int j=0;j<=20;j++)
				f[i][j][0]=max(f[i][j][0],f[i-1][j][1]);
		if(idx==n){
			int maxn=-0x3f3f3f3f;
			for(int j=0;j<=20;j++)
				maxn=max(maxn,max(f[i][j][0],f[i][j][1]));
			cout<<maxn;
			return 0;
		}
	}
	return 0;
}
