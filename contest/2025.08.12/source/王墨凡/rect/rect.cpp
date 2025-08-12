#include<iostream>
#include<cstdio>
using namespace std;
int n,m,map[1086][1086],last,cnt=1,llast,ans[1086][1086];
char c;
int main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> c;
			if(c=='C')map[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m+1;j++){
			if(ans[i][j]==0){
				if(map[i][j-1]==0 and map[i][j]==1){
					ans[i][j]=cnt;
				}
				else if(map[i][j-1]==1 and map[i][j]==1){
					ans[i][j]=ans[i][j-1];
				}
				if(map[i][j-1]==1 and map[i][j]==0 and ans[i][j-1]==cnt){
					cnt++;
				}
			}
			if(ans[i][j]!=ans[i][j-1] and ans[i][j-1]==cnt)cnt++;
		}
		int last=0,flag=0;
		for(int j=1;j<=m+1;j++){	
			if(ans[i][j]!=ans[i][j-1])last=j,flag=1;
			if(map[i+1][j]==0)flag=0;
			if(ans[i][j+1]!=ans[i][j] and flag==1 and map[i+1][j+1]!=1){
				for(int k=last;k<=j;k++){
					ans[i+1][k]=ans[i][j];
				}
			}
		}

	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
