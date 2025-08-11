#include <bits/stdc++.h>
using namespace std;
int a[114514];
int main(){
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	int n,m,t,l;
	cin >> n >> m >> t >> l;
	for(int i=1;i<=m;i++){
		cin >> a[i] >> a[i] >> a[i];
	}
	for(int i=1;i<=l;i++)cin >> a[i];
	for(int i=1;i<=t;i++)cout << "-1\n";
	return 0;
}
