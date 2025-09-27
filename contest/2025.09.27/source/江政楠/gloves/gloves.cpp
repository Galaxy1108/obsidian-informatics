#include<bits/stdc++.h>
using namespace std;
int n,m;
long long total=0;
long long a[100005];
long long b[100005];
int main(){
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	/*for(int i=1;i<=n;i++) cout<<a[i];
	cout<<endl;
	for(int i=1;i<=m;i++) cout<<b[i];*/
	if(n<=m){
		int j=1;
		long long cha=1e10;
		for(int i=1;i<=n;i++){
			while(abs(a[i]-b[j])<cha){
				
				cha=abs(a[i]-b[j]);
				//cout<<i<<" "<<j<<" "<<cha<<endl;
				j++;
			}
			total=max(abs(a[i]-b[j-1]),total);
			cha=1e10;
		}
	}
	else{
		int j=1;
		long long cha=1e10;
		for(int i=1;i<=m;i++){
			while(abs(b[i]-a[j])<cha){
				cha=abs(b[i]-a[j]);
				//cout<<i<<" "<<j<<" "<<cha<<endl;
				j++;
			}
			total=max(abs(b[i]-a[j-1]),total);
			cha=1e10;
		}
	}
	cout<<total;
	return 0;
} 
