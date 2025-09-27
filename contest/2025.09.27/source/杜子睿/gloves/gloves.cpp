#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005];
bool check(int x){
	if(n>m){
		int id=1;
		for(int i=1;i<=m;i++){
			while(abs(a[id]-b[i])>x&&id<=n)
				id++;
			if(id==n+1||(i!=m&&id==n))
				return false;
			id++;
		}
	}
	else{
		int id=1;
		for(int i=1;i<=n;i++){
			while(abs(a[i]-b[id])>x&&id<=m)
				id++;
			if(id==m+1||(i!=n&&id==m))
				return false;
			id++;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=1;j<=m;j++)
		cin>>b[j];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	int l=0,r=1e9;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout<<l;
	return 0;
}
