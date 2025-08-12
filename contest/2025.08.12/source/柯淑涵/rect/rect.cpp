#include <bits/stdc++.h>
using namespace std;
int T,n,m,k;
char a[501][501];
int b[501][501],c[501][501]={};
int cnt=0;
void f(int x,int y,int s){
//	cout<<x<<" "<<y<<" "<<s<<endl; 
	int i;
	for(i=x+1;i<=n;i++){
		if(b[i][y]<s) break;
	}
	i--;
	//cout<<i<<endl;
	cnt++;
	for(int j=x;j<=i;j++){
		for(int k=y-s+1;k<=y;k++){
			//cout<<j<<" "<<k<<" "<<cnt<<endl;
			c[j][k]=cnt;
		}
	}
}
int main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='C') b[i][j]=b[i][j-1]+1;
		}
	} 
	int fl=0,cnt1=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='C'&&c[i][j]==0){
				fl=1;
				cnt1++;
				if(j==m){
					f(i,j,cnt1);
					fl=0;
					cnt1=0;
				}
			}
			else if(fl==1){
				f(i,j-1,cnt1);
				fl=0;
				cnt1=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	} 
	return 0;
}
/*
4 5 
CCBCB
CCBBB
CCCBB
CCCBB

7 5 
CCCBB 
BCBBB 
BCCCB 
BCCCB 
CCCCC 
BBBBB 
BCCCB
*/
