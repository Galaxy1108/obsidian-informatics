#include<bits/stdc++.h>
using namespace std;
const int mx=200010;
int n,q;
long long a[mx];
void upd1(long long v)
{
	for(int i=1;i<=n;i++) a[i]=min(a[i],v);
}
void upd2()
{
	for(int i=1;i<=n;i++) a[i]+=i;
}
long long query(int l,int r)
{
	long long res=0;
	for(int i=l;i<=r;i++) res+=a[i];
	return res;
}
int main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int v;
			cin>>v;
			upd1(v);
		}
		if(op==2)
		{
			upd2();
		}
		if(op==3)
		{
			int l,r;
			cin>>l>>r;
			cout<<query(l,r)<<endl;
		}
	}
	return 0;
} 
/*
15 15 
6 14 14 6 3 6 4 13 10 3 12 5 11 9 6 
1 9 
1 2 
2 
2
2 
1 11 
3 4 6 
2 
1 6 
2 
1 9 
1 11 
1 11 
3 4 4 
3 2 13
*/

