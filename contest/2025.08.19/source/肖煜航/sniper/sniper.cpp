#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int val[25]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int n;
int f[25005][25];
int w[8005],pos[8005],t[8005];
int tmp[25];
int main(){
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&w[i],&pos[i],&t[i]);
	memset(f,-0x3f,sizeof f);
	memset(f[0],0,sizeof f[0]);
	int now=0;
	for(int i=0;i<=25002;i++){
		int id=0;
		memcpy(tmp,f[i],sizeof tmp);
		for(int j=1;j<=20;j++){
			f[i][j]=max(f[i][j],max(tmp[j+1],max(tmp[j+1],tmp[j-1])));
			f[i][j]=max(f[i][j],tmp[j+2]); 
			if(j>2) f[i][j]=max(f[i][j],tmp[j-2]);
		}
		while(now<n&&t[now+1]==i){
			now++;
			f[i+2][pos[now]]=max(f[i+2][pos[now]],f[i][pos[now]]+val[w[now]]);
			if(w[now]==15) id=pos[now];
		}
		if(id){
			memset(f[i+2],-0x3f,sizeof f[i+2]);
			f[i+2][id]=max(f[i+2][id],f[i][id]+50);
			memset(f[i],-0x3f,sizeof f[i]);
			memset(f[i+1],-0x3f,sizeof f[i+1]);
		}
		else{
			for(int j=1;j<=20;j++) f[i+1][j]=max(f[i+1][j],f[i][j]);
		}
	}
	int ans=0;
	for(int i=1;i<=20;i++) ans=max(ans,max(f[25002][i],max(f[25001][i],f[25003][i])));
	printf("%d",ans);
	return 0;
}
