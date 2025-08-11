#include <bits/stdc++.h>
using namespace std;
struct dong
{
	long long x,y,z;
};
int t,n,h,r;
dong de[1005];
int a[1005];
int pan=0;
void sou(int x,int y,int z)
{
	long double d;
	if (z >= h-r or pan==1)
	{
		pan=1;
		return;
	}
	for (int i = 1;i <= n;i++)
	{
		if (pan == 1)
		{
			return;
		}
		if (a[i] == 0)
		{
			d = sqrt((de[i].x - x)*(de[i].x - x) + (de[i].y - y)*(de[i].y - y) + (de[i].z - z)*(de[i].z - z));
			if (d <= 2*r)
			{
				a[i]=1;
				sou(de[i].x,de[i].y,de[i].z);
				a[i]=0;
			}
		}
	} 
	
}
int main()
{
	cin >> t;
	for (int i = 1;i<= t;i++)
	{
		cin >> n >> h >> r;
		for (int j = 1;j <= n;j++)
		{
			cin >> de[j].x >> de[j].y >> de[j].z;
		}
		for (int i = 1;i <= n;i++)
		{
			if (de[i].z-r <= 0 and pan == 0)
			{
				sou(de[i].x,de[i].y,de[i].z);
			}
			if (pan == 1)
			{
				cout << "Yes" << endl;
				break;
			}
		}
		if (pan == 0)
		{
			cout << "No" << endl;
		}
		pan=0;
	} 
	return 0;
}
