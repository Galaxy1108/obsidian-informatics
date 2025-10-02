#include<iostream>
using namespace std;
long long n,a[2000005],minn,maxx,maxxx;
int main(){
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		minn=a[i];
		maxx=a[i];
		maxxx=max(maxxx,a[i]);
		for(int j=i+1;j<=n;j++){
			minn=min(minn,a[j]);
			maxx=max(maxx,a[j]);
			maxxx=max(maxxx,maxx*minn*(j-i+1));
		}
	}
	cout<<maxxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
