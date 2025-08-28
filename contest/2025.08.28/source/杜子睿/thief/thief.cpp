#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++){
		int l,r,c;
		cin>>l>>r>>c;
		for(int j=l;j<=r;j++){
			if(a[j]>c)
				c++;
			else if(a[j]<c)
				c--;
		}
		cout<<c<<endl;
	}
	return 0;
}

