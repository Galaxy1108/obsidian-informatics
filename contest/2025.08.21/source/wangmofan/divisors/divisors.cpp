#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main(){
	freopen("divisors.in","r",stdin);
	freopen("divisors.out","w",stdout);
	cin >> n;
	cout << 7560 << ' ';	
	for(int i=2;i<=n;i++)cout << i << ' ';
	cout << endl;
	for(int i=2;i<=n;i++)cout << i << ' ' << 1 << endl; 
	return 0;
}

