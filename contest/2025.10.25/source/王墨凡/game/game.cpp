#include<iostream>

using namespace std;
int n,a[1000086]; 
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];
	cout << n << '\n';
	return 0;
}
