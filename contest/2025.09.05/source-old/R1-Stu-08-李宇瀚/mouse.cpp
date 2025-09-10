#include<bits/stdc++.h>

using namespace std;

double f[1001][1001][2];
int w,b;

double dfs(int w,int b,int nown){
	if(f[w][b][nown]!=-1) return f[w][b][nown];
	if(nown==0) f[w][b][nown]=(w*1.0/(w+b))+(b*1.0/(w+b))*dfs(w,b-1,nown^1);
	else{
		if(b==1) f[w][b][nown]=(b*1.0/(w+b));
		else if(w==1) f[w][b][nown]=(b*1.0/(w+b))*((b-1)*1.0/(w+b-1))*dfs(w,b-2,nown^1);
		else f[w][b][nown]=(b*1.0/(w+b))*((b-1)*1.0/(w+b-1)*dfs(w,b-2,nown^1)+(w*1.0/(w+b-1))*dfs(w-1,b-1,nown^1));
	}
	return f[w][b][nown];
}

int main(){
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	cin>>w>>b;
	if(w==0){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<=w;i++){
		for(int j=0;j<=b;j++) f[i][j][0]=f[i][j][1]=-1;
	}
	for(int i=0;i<=b;i++) f[0][i][0]=f[0][i][1]=0;
	for(int i=1;i<=w;i++) f[i][0][0]=1,f[i][0][1]=0;
	f[1][1][1]=0;
	dfs(w,b,0);
	printf("%.9lf",f[w][b][0]);
	return 0;
}
