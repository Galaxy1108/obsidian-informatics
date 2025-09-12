#include <bits/stdc++.h>
using namespace std;

void read(int &n)
{
	int x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x=x*10+ch-'0', ch=getchar();
	n = x;
}
void read(long long &n)
{
	int x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x=x*10+ch-'0', ch=getchar();
	n = x;
}
void write(int x) {if(x>9)write(x/10);putchar(x%10+'0');}
void write(long long x) {if(x>9)write(x/10);putchar(x%10+'0');}

int T, n;
vector<int> v[200005];

int main()
{
	freopen("labyrinth.in", "r", stdin);
	freopen("labyrinth.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	read(T);
	while (T--)
	{
		for (int i = 1; i <= n; i++) v[i].clear();
		read(n);
		for (int i = 1, x, y; i < n; i++)
		{
			read(x), read(y);
			v[x].push_back(y), v[y].push_back(x);
		}
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; i++) cnt1 += (v[i].size()==1), cnt2 += (v[i].size()==2);
//		cout << logn << '\n';
		if (cnt1 == 2 && cnt2 == n-2) write((int)log2(n)+1), putchar('\n');
		else write((int)log2(n)+1-4), putchar('\n');
//		else puts("YES");
	}
	return 0;
} 
