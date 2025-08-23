#include<bits/stdc++.h>
using namespace std;
multiset<int> st;
int num,n,a[100005],q,op,x,y;
int main()
{
	freopen("imperishable.in","r",stdin);
	freopen("imperishable.out","w",stdout);
	cin>>num>>n;
	if(num==1)
	{
		cout<<2<<endl;
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
		st.insert(a[i]);
	}
	cout<<(*st.begin())<<'\n';
	cin>>q;
	while(q--)
	{
		cin>>x>>y;
		st.erase(st.find(x));
		st.insert(y);
		cout<<(*st.begin())<<'\n';
	}
	return 0;
}
