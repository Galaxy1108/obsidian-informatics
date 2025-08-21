#include <bits/stdc++.h>
using namespace std;
const int N=100;
int a[N];int n;
int dfs(int l,int r){
	
	
	if(l==r){
//		cout << 0 << endl;
		return 0;
	}
//	if(l+1==r){
//		int k=0;
//		if(a[l]>a[r])swap(a[l],a[r]),k++;
////		cout << k << endl;
//		return k;
//	}
	int ans=0;
	int mid=(l+r)>>1;
	ans=dfs(l,mid)+dfs(mid+1,r);
//	cout << "\n---\n\n";
	for(int i=mid+1;i<=r;i++){
		for(int j=l;j<=r;j++){
			if(a[i]<a[j]){
				for(int k=i;k>j;k--){
					swap(a[k],a[k-1]);
					ans++;
				}
				break;
			}
		}
	}
//	cout << l << " " << r << endl;for(int i=1;i<=n;i++)cout << a[i] << " ";
//	cout << endl;
//	cout << ans << endl;
	return ans;
}
int main(){
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];
//	int ans=0;
	cout << dfs(1,n) << '\n';
//	for(int i=1;i<=n;i++)cout << a[i] << " ";
//	cout << endl;
//	cout << ans << endl;
	return 0;
} 
