#include <bits/stdc++.h>
using namespace std;
int v[100005],a[100005];
int main()
{
	int n,d;
	long long sum=0,money=0;
	long double you=0,cun;
	cin >> n >> d;
	for (int i = 1;i < n;i++)
	{
		cin >> v[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i < n;i++)
	{
		long long fz=0;
		for (int j = i+1;j <= n;j++)//666
		{
			if (a[j] >= a[i] and j < n)
			{
				fz+=v[j-1];
			}
			else if (a[j] < a[i])
			{
				fz+=v[j-1];
				sum+=fz;
				cun=you;
				money+=ceil((fz-cun*d)*1.0/d)*a[i];
				//cout << cun<< " " << i << " "<< ceil((fz-cun*d)*1.0/d) << endl;
				you=0;
				you += ceil((fz-cun*d)*1.0/d)-(fz-cun*d)*1.0/d;
				fz=0;
				i=j-1;
				break;
			}
			else if(j == n)
			{
				fz+=v[j-1];
				sum+=fz;
				cun=you;
				money+=ceil((fz-cun*d)*1.0/d)*a[i];
				//cout << cun<< " " << i << " "<< ceil((fz-cun*d)*1.0/d) << endl;
				you=0;
				you += ceil((fz-cun*d)*1.0/d)-(fz-cun*d)*1.0/d;
				fz=0;
				i=j-1;
				break;
			}
		} 
	}
	cout << money;
	return 0;
 } 
