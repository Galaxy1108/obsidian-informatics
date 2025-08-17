#include<iostream>
#include<cstdio>
using namespace std;
long long s[5002][5002],x,l,r,u,d,n,m,q,mod=1e9+9;
int main(){
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m >> q;
	for(int i=1;i<=m;i++){
		cin >> l >> r >> x;
		x%=mod;
		for(int j=1;j<=n;j++){
			s[i][j]=s[i-1][j];
			s[i][j]%=mod;
		}
		s[i][l]+=x;
		s[i][r+1]-=x;
		s[i][l]%=mod;
		s[i][r+1]%=mod;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s[i][j]+=s[i][j-1];
			s[i][j]%=mod;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s[i][j]+=s[i][j-1];
			s[i][j]%=mod;	
		}
	}
	for(int i=1;i<=q;i++){
		cin >> u >> d >> l >> r;
		long long res=0;
		for(int j=u;j<=d;j++){
//			if(s[j][r]<s[j][l-1])swap(s[j][r],s[j][l-1]);
			res+=s[j][r]-s[j][l-1];			
//			cout << res << endl;
			res%=mod;
		}
		cout << res << endl;
	}
	return 0;
}
