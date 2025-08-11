#include <bits/stdc++.h>
using namespace std;
constexpr int mod=998244353;
int n;
string s;
bool spc;
namespace sub1
{
	void solve()
	{
		int t[3]={0,0,0};
		int AB=0,BC=0,CA=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='A')
			{
				if(BC)
					BC--;
				else if(t[2])
					t[2]--,CA++;
				else
					t[0]++;
			}
			else if(s[i]=='B')
			{
				if(CA)
					CA--;
				else if(t[0])
					t[0]--,AB++;
				else
					t[1]++;
			}
			else
			{
				if(AB)
					AB--;
				else if(t[1])
					t[1]--,BC++;
				else
					t[2]++;
			}
		}
		if(!AB && !BC && !CA && !t[0] && !t[1] && !t[2])
			cout<<"1";
		else
			cout<<"0";
	}
}
namespace bf
{
	void solve()
	{
		cout<<"0";
	}
}
int main()
{
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>s;
	n*=3;
	s=" "+s;
	spc=1;
	for(int i=1;i<=n;i++)
		if(s[i]=='?'){spc=0;break;}
	if(spc)
		sub1::solve();
	else
		bf::solve();
	return 0;
}
