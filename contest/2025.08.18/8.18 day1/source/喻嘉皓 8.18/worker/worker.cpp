#include<bits/stdc++.h>
#define Min(a,b) (a=min(a,b))
using namespace std;
int suma[110],sumb[110],sumc[110];
int f[110][11][11][11];
char c[110];
int n;
int main(){
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		suma[i]=suma[i-1];
		sumb[i]=sumb[i-1];
		sumc[i]=sumc[i-1];
		if(c[i]=='A') suma[i]++;
		else if(c[i]=='B') sumb[i]++;
		else sumc[i]++;
	}
	memset(f,0x3f,sizeof(f));
	int ans=1061109567;
	if(n<=10){
		ans=0;
		if(suma[n]) ans++;
		if(sumb[n]) ans++;
		if(sumc[n]) ans++;
		cout<<ans;
		return 0;
	}
	f[10][suma[10]][sumb[10]][sumc[10]]=0;
	for(int i=10;i<=n;i++){
		for(int j=0;j<=10;j++){//A 
			for(int k=0;k<=10-j;k++){//B 
				for(int t=0;t<=10-j-k;t++){//C
					int top1=min(n,i+j),top2=min(n,i+k),top3=min(n,i+t);
					//װA
					if(j) Min(f[top1][suma[top1]-suma[i]][k+sumb[top1]-sumb[i]][t+sumc[top1]-sumc[i]],f[i][j][k][t]+1);
					//װB 
					if(k) Min(f[top2][j+suma[top2]-suma[i]][sumb[top2]-sumb[i]][t+sumc[top2]-sumc[i]],f[i][j][k][t]+1);
					//װC
					if(t) Min(f[top3][j+suma[top3]-suma[i]][k+sumb[top3]-sumb[i]][sumc[top3]-sumc[i]],f[i][j][k][t]+1);
				}
			} 
		}
	}
	for(int j=0;j<=10;j++){
		for(int k=0;k<=10-j;k++){
			for(int t=0;t<=10-j-k;t++){
				int cnt=0;
				if(j) cnt++;
				if(k) cnt++;
				if(t) cnt++;
				Min(ans,f[n][j][k][t]+cnt);
			}
		}
	}
	cout<<ans;
	return 0;
}

