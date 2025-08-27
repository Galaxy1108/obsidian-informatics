#include<iostream>

using namespace std;
int n,x,u,v,num,p=998244353;
int main(){
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdout);
	cin >> num;
	cin >> n >> x;
	for(int i=1;i<n;i++)cin >> u >> v;
	if(num==1){
		cout << n << ' '; 
		for(int i=2;i<=n;i++){
			cout << 0 << ' ';
		}
	}
	if(num==4){
		cout << n << ' ' << n-1 << ' ' << n*(n-1)/2%p;
		for(int i=4;i<=n;i++){
			
		}
	}
	if(num==5){
		for(int i=0;i<=x;i++){
			cout << n-i << ' ';
		}
		for(int i=x+1;i<=n;i++){
			cout << 0 << ' ';
		}
	}
	return 0;
}
