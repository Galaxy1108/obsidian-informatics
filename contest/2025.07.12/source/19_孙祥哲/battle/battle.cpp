#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node { int x, id; };

int n;
Node x[150005], y[150005], z[150005];
int tmp[150005];

bool cmp(Node a, Node b) { return a.x > b.x; }

int main()
{
    freopen("battle.in", "r", stdin);
    freopen("battle.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &x[i].x, &y[i].x, &z[i].x);
        x[i].id = y[i].id = z[i].id = i;
    }
    sort(x+1, x+1+n, cmp), sort(y+1, y+1+n, cmp), sort(z+1, z+1+n, cmp);
    int t1 = 1, t2 = 1, t3 = 1;
    while (1)
    {
    	if (t1 > n || t2 > n || t3 > n) break;
        if (x[t1].id == y[t2].id && y[t2].id == z[t3].id) 
            t1++, t2++, t3++;
        else if (x[t1].id == y[t2].id) 
            t1++, t2++;
        else if (x[t1].id == z[t3].id) 
            t1++, t3++;
        else if (y[t2].id == z[t3].id) 
            t2++, t3++;
        else break;
    }
    if (t1 > n || t2 > n || t3 > n) puts("-1");
    else printf("%d\n", x[t1].x + y[t2].x + z[t3].x);
    return 0;
}
