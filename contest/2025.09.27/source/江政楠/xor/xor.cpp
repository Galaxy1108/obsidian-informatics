#include<bits/stdc++.h>
using namespace std;
int a[100005];
int cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int all=a[i];
			int maxn=0;
			for(int k=i;k<=j;k++){
				maxn=max(maxn,a[k]);
			}
			for(int k=i+1;k<=j;k++){
				all^=a[k];
			}
			if(all<=maxn){
				//cout<<i<<" "<<j<<endl;
				cnt++;
			} 
		}
	}
	cout<<cnt;
	return 0;
}
