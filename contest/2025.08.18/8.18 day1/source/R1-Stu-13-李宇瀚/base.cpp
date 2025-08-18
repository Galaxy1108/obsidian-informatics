#include<bits/stdc++.h> //haven't tested yet / Why is the problem so hard? Life is hard,too.

using namespace std;

int f1[2001],f2[2001];
int s[3][2001];
int n;
int mapn[3][2001];

int main(){
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	cin>>n;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			cin>>mapn[i][j];
			s[i][j]=s[i][j-1]+mapn[i][j];
		}
	}
	for(int i=1;i<=n;i++) f1[i]=f2[i]=-999999999;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++) f1[i]=max(f1[i],s[1][i]+s[2][i]-s[1][j]-s[2][j]);
	}
	for(int i=n;i>=1;i--){
		for(int j=n;j>=i;j--) f2[i]=max(f2[i],s[1][j]+s[2][j]-s[1][i-1]-s[2][i-1]);
	}
	int maxans=-999999999;
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			maxans=max(maxans,f1[i]+f2[j]+s[1][j-1]-s[1][i]);
			maxans=max(maxans,f1[i]+f2[j]+s[2][j-1]-s[2][i]);
		}
	}
	cout<<maxans<<endl;
	return 0;
}
