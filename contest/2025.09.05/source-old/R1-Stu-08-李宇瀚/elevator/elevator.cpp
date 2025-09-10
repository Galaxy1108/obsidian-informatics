#include<bits/stdc++.h>

using namespace std;

int f[2001][9][9][9];
int n;
int st[2001],ed[2001];
int vis[5];
int tmp[5];
const int inf=0x3f3f3f3f;

bool cmp(int a,int b){
	return a<b;
}

void dfs(int nown,int k){
	for(int i=1;i<=n;i++){
		
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>st[i]>>ed[i];
	f[1][0][0][0]=st[i];
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=9;j++){
			for(int k=1;k<=9;k++){
				for(int l=1;l<=9;l++){
					if(f[i][j][k][l]==inf) continue;
					tmp[1]=j,tmp[2]=k,tmp[3]=l,tmp[4]=ed[i];
					int j=1;
					while(tmp[j]==0) j++;
					j=4-j+1;
					
				}
			}
		}
	}
}
