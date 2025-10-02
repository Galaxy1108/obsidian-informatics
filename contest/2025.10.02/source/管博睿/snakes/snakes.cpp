#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t,n,ans,x,y;
vector<int> a,b;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		cin >> n;
		if(i==1)
		{
			for(int j=1;j<=n;j++)
			{
				cin >> x;
				a.push_back(x);
				b.push_back(x);
			}
		}
		else
		{
			b=a;
			for(int j=1;j<=n;j++)
			{
				cin >> x >> y;
				a[x-1]=y;
				b[x-1]=y;
			}
		}
		while(b.size()>=2)
		{
			if(b[b.size()-1]-b[0]>=b[1])
			{
				b[b.size()-1]-=b[0];
				b.erase(b.begin());
				sort(b.begin(),b.end());
			}
			else
			{
				break;
			}
		}
		if(b.size()<=2) cout << "1\n";
		else cout << b.size() << "\n";
	}
	return 0;
}

