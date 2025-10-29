#include<iostream>

using namespace std;
int a[50086],opt,n,m,l,r,ind,cnt;
int main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];
	cin >> m;
	for(int i=1;i<=m;i++){
		cin >> opt;
		if(opt==1){
			cin >> ind;
			a[ind]=!a[ind];
		}
		else {
			cin >> l >> r;
			int ans=0;
			for(int k=1;k<=r-l+1;k++){
				cnt=0;
				for(int i=l;i<=l+k-1;i++)cnt+=a[i];
				if(cnt%2==0||k+3>=(cnt*2))ans++;
				for(int i=l+1;i<=r-k+1;i++){
					cnt-=a[i-1];
					cnt+=a[i+k-1];
					if(cnt==1)continue;
					if(cnt%2==0||k+3>=(cnt*2))ans++;
				}
			}
			cout << ans<<'\n';
		}
	}
	return 0;
}
/*
4 
1 0 1 0 
3 
2 1 3 
1 3 
2 3 4
*/
