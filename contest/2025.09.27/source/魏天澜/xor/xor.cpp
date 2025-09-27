#include<bits/stdc++.h>
using namespace std;
int a[2010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n; 
	for(int i = 1;i<=n;i++)cin>>a[i];
	int cnt = n;
	for(int i = 1;i<=n;i++){
		int maxn = a[i];
		int xorans = a[i];
		for(int j = i+1;j<=n;j++){
			maxn = max(maxn,a[j]);
			xorans = xorans^a[j];
			if(xorans<=maxn)cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
