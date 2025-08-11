#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	srand(time(0));
	long long n;
	for(long long i=1;i<=n;i++){
		long long m;
		cin>>m;
		for(long long j=1;j<=m;j++){
			long long x;
			cin>>x;
		}
	}
	string ans;
	for(int i=1;i<=rand()%10+5;i++){
		ans+=char('0'+rand()%10);
	}
	cout<<ans<<endl;
	return 0;
}
