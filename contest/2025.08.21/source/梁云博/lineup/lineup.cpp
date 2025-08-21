#include <bits/stdc++.h>
using namespace std;
int a[55];
int n;
struct node{
	int i,d;
}b[55];
bool cmp(node a,node b)
{
	if(a.d==b.d)return a.i<b.i;
	else return a.d<b.d;
}
int main()
{
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    cin>>n;
    int flg=0;
    for(int i=1;i<=n;i++)cin>>a[i],b[i].d=a[i],b[i].i=i;
    sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++)a[b[i].i]=i;
	int ans=0; 
	for(int i=1;i<=n;i++)ans+=abs(a[i]-i);
	cout<<ans;
    return 0;
}
