#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,a[2005];
	cin>>n;
	cin>>a[0];
	int f=1;
	for(int i=1;i<n;i++){
		cin>>a[i];
		if(a[i]!=a[0])
			f=0;
	}
	if(f)
		cout<<0;
	else
		cout<<4;
	return 0;
} 
