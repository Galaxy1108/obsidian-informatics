#include<bits/stdc++.h>
using namespace std;
int n,m,p;
long long po(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1)
			res=(x*res)%p;
		x=(x*x)%p;
		y>>=1;
	}
	return res;
}
int main(){
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>p;
	cout<<po(2,min(n+m,2*m));
	return 0;
} 
