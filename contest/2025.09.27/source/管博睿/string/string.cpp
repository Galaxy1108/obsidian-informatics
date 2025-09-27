#include <iostream>
#include <string>
using namespace std;
string s;
int cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			cnt++;
		}
	}
	if(cnt>s.size()/2)
	{
		cout << "-1";
	}
	else
	{
		cout << "0";
	}
	return 0;
}
