#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,m,l[2000086],r[2000086],ans;
bool checkl(long long x){
	int cntr=0;
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=cntr+1;j<=m;j++){
			if(abs(l[i]-r[j])<=x){
				flag=0;
				cntr=j;
				break;
			}
		}
		if(flag)return 0;
	}
}
bool checkr(long long x){
	int cntl=0;
	for(int i=1;i<=m;i++){
		bool flag=1;
		for(int j=cntl+1;j<=n;j++){
			if(abs(r[i]-l[j])<=x){
				flag=0;
				cntl=j;
				break;
			}
		}
		if(flag)return 0;
	}
	return 1;
}
int main(){
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m ;
	for(int i=1;i<=n;i++)cin >> l[i];
	for(int i=1;i<=m;i++)cin >> r[i];
	sort(l+1,l+1+n);
	sort(r+1,r+1+m);
	if(n<=m){
		long long s=0,e=10000001;
		while(s<e){
			long long mid=s+((e-s)>>1);
			if(checkl(mid))e=mid;
			else s=mid+1;
		}
		cout << s;
	}
	else{
		long long s=0,e=10000001;
		while(s<e){
			long long mid=s+((e-s)>>1);
			if(checkr(mid)) e=mid;
			else s=mid+1;
		}
		cout << s;
	}
	return 0;
}  

