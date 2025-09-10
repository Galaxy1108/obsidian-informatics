#include <bits/stdc++.h>
#define ll long long
#define mod 9999973
using namespace std;

int n, m;
int a[1005][1005];
vector<int> v;

int func(int x)
{
	int mul = 1;
	while (x)
	{
		mul *= x%10;
		x /= 10;
	}
	return mul <= n ? mul : 0;
}
bool cmp(int a, int y) { return a > y; }

int main()
{
	freopen("elevator.in", "r", stdin);
	freopen("elevator.out", "w", stdout);
	
	return 0;
}
