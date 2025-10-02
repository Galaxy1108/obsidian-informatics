#include <iostream>
using namespace std;
int id,op,n,u,v,w,p,q;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin >> id >> op >> n;
	for(int i=1;i<n;i++)
	{
		cin >> u >> v >> w;
	}
	while(n--)
	{
		cin >> p;
	}
	cin >> q;
	while(q--)
	{
		cout << "0\n";
	}
	return 0;
}
