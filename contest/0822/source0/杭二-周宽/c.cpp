#include <bits/stdc++.h>
#define PR(x) printf(x ? "YES\n" : "NO\n")
#define pr(x) printf(x ? "Yes\n" : "No\n")
#define mk make_pair
#define pb emplace_back
#define fi first
#define se second
#define pii pair<int, int>
#define fore(i, u, v) for (int i = h[u], v = e[i].v; i; v = e[i = e[i].nxt].v)
#define all(x) x.begin(), x.end()

using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (! isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}

int main() {
	
	return 0;
}

/*
[G < 2 & G* & !ap*] 
- G < 2 ==> ap >= n - i
- G*    ==> 
- !ap*  ==> 

*6 >*5 >*4 >[3]> 2 > 1
*4   1  *5  [2] *6  *3
 2   6   1  [3]  5   4
 2   4   5  [1]  3   6
 4   2   6  [5]  3   1

 f[l][r] <----
*/