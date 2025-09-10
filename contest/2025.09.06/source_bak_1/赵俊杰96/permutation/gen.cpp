#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],b[N],c[N],d[N],t[N];
int main()
{
	freopen("permutation.in","w",stdout);
	int n=100000;
	cout<<n<<'\n';
	for(int i=1;i<=n;i++)a[i]=i;
	//random_shuffle(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=i;
	random_shuffle(b+1,b+n+1);
	random_shuffle(b+1,b+n+1);
	for(int i=1;i<=n;i++)cout<<b[i]<<' ';cout<<'\n';
	for(int i=1;i<=n;i++)c[a[i]]=i;
	for(int i=1;i<=n;i++)t[i]=b[a[i]];
	for(int i=1;i<=n;i++)d[i]=c[t[i]];
	for(int i=1;i<=n;i++)cout<<d[i]<<' ';cout<<'\n';
	cout<<"YES\n";
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<'\n';
	return 0;
}
