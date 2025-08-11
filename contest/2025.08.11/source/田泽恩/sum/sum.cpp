#include <bits/stdc++.h>
using namespace std;
long long t,s,k,a[1919810],b[1919810],now;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>s>>k;
		if(s&1){
			if(2*k<s) cout<<2*k<<endl;
			else puts("-1");
		}
		else{
			memset(b,0,sizeof(b));
			memset(a,0,sizeof(a));
			now=0;
			for(int i=3;i<s;++i){
				if(s%i==0) continue;
				if(b[s-i]) continue;
				a[++now]=i;
				for(int j=1;j*i<=s;++j) b[j*i]=1;
				if(now==k){
					break;
				}
			}
			if(now<k) puts("-1");
			else cout<<a[now]<<endl;
		}
	}
	return 0;
}
