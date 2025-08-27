#include<bits/stdc++.h>
using namespace std;
__int128 s=1,res=1;
long long ans=1;
int n,p;
long long check(long long x){
	long long k=0;
	for(long long i=1;i*i<=x;i++){
		if(x%i==0){
			k=(k+i)%p;
			if(i*i!=x)
				k=(k+x/i)%p;
		}
	}
	return k;
}
__int128 power(__int128 x,__int128 y){
	__int128 kkk=1;
	for(int i=1;i<=y;i++)
		kkk*=x;
	return kkk;
}
int main(){
	freopen("gonna.in","r",stdin);
    freopen("gonna.out","w",stdout);
	cin>>n>>p;
	for(int i=2;i<=n;i++){
		res*=power(i,i);
		s*=i;
		res/=s;
		ans+=check(res);
		ans=ans%p;
	}
	cout<<ans;
	return 0;
}
