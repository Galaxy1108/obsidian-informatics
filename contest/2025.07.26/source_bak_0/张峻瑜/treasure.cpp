#include <bits/stdc++.h>
using namespace std;
struct jian
{
	int lo,shu;
};
jian f[10005][105];
int main()
{
	int n,m,js;
	unsigned long long sum=0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> f[i][j].lo >> f[i][j].shu;
		} 
	}
	cin >> js;
	int qian=0,jsh=0;
	for (int i = 1;i <= n;i++)
	{
		qian = f[i][js].shu;
		sum+=qian;
		jsh=0;
		while (1)
		{
			
			
			if (f[i][js].lo == 1)
			{
				jsh++;
				if (jsh == qian)
				{
					break;
				}
			}
			js++;	
			if (js > m-1)
			{
				js=0;
			}
		}
		
	} 
	cout << sum%20123;
	return 0;
}
