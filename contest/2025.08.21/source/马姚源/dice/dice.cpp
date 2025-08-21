#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[5005];
ll Mod=1e9+7;
bool cmp(int x,int y){
	return x>y;
}
ll qpow(ll a,ll b,ll p){
	ll res=1;
	while(b){
		if(b&1)res*=a,res%=p;
		a*=a;
		a%=p;
		b>>=1;
	}
	return res;
}
ll p[5005];
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll sum=0;
	while(a[n]-1>=1){
		n++;
		a[n]=a[n-1]-1;
	}
//	n--;
	p[n+1]=1;
	for(int i=n;i>=1;i--){
		p[i]=p[i+1]*a[i];
//		cout << p[i] << " ";
//		p[i]%=Mod;
	}
//	cout << endl;
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]){
			if(i==1){
				int j=a[i];
				while(j>a[i+1]){
					sum+=(i*j)*p[i+1];
					j--;
				}
			}
			else {
				int j=a[i];
				while(j>a[i+1]){
					sum+=(i*j-1)*j*p[i+1];
					j--;
				}
			}
		}
		else{
			while(a[i]==a[i+1])i++;
			sum+=((a[i]+a[i+1]+1)*(a[i]-a[i+1])/2)*i*p[i+1];
//			
//			cout <<114;
		}
//		cout << sum << "\n";
//		sum%=Mod;
	}
	sum++;
//	sum--;
//	cout << sum << " " << p[1] << endl;
//	cout << qpow(2,10,Mod) <<endl;
//	cout << qpow(p[1],Mod-2,Mod) << endl;
	cout <<((sum%Mod*qpow(p[1],Mod-2,Mod))%Mod) << endl;
	return 0;
}
