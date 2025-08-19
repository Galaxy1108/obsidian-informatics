#include <bits/stdc++.h>
using namespace std;
/*
打了一个人（在第i秒），第i秒不能移动和再打，第i+1秒可以移动但不能再打 
*/
constexpr int TI=25005,U=25;
int n,mt,f[TI][U][2];//f[][][0/1]:0:可以打和移动，1:只能移动 
int p[TI][U],sni[TI];
int val[25]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int main(){
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int _w,_u,_t;
	mt=0;
	for(int i=1;i<=n;i++){
		cin>>_w>>_u>>_t;
		mt=max(mt,_t);
		if(p[_t][_u]==0||_w==15||val[p[_t][_u]]<val[_w])
			p[_t][_u]=_w;
		if(_w==15){
			sni[_t]=_u;
		}
	}
	memset(f,0xc0,sizeof(f));
	for(int j=1;j<=20;j++)f[0][j][0]=0;
	for(int i=0;i<=mt;i++){
		if(sni[i]!=0){
			//必须射击狙击手
			if(sni[i+1]==0)f[i+1][sni[i]][1]=max(f[i+2][sni[i]][1],f[i][sni[i]][0]+val[15]); 
		}
		else{
			for(int j=1;j<=20;j++){
				//在这一分钟移动/什么都不干 
				for(int k=max(1,j-2);k<=j+2&&k<=20;k++){
					f[i+1][k][0]=max(f[i+1][k][0],max(f[i][j][0],f[i][j][1]));
				} 
				//在这一分钟射击 
				if(p[i][j]!=0&&sni[i+1]==0){
					f[i+1][j][1]=max(f[i+1][j][1],f[i][j][0]+val[p[i][j]]);
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=20;i++){
		ans=max({ans,f[mt][i][0],f[mt][i][1],f[mt+1][i][0],f[mt+1][i][1]});
	}
	cout<<ans;
	return 0;
}

