#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long intt;

const int MX = 110;

std::vector <int> vec[MX];

namespace solve
{
int n;
std::vector <int>::iterator x[MX];

intt eval(std::vector <int>::iterator bg, std::vector <int>::iterator ed, std::vector <int>::iterator b1, std::vector <int>::iterator e1)
{
    std::vector <int> v(bg, ed);
    v.insert(v.end(), b1, e1);
    std::sort(v.begin(), v.end());
    v.push_back(2e6);
    int lst= 0 ;
    intt ret = 0;
    for (auto x : v)
    {
        ret += (intt)(x - lst) * (x - lst);
        lst = x;
    }
    return ret;
}

intt ans = 9e18;
int cnt = 0;
void DFS(int p = 1, intt sum = 0)
{
    if (p == n + 1)
    {
        sum += eval(x[n], vec[n].end(), vec[1].begin(), x[1]);
        if (sum < ans)
        {
            ans = sum;
        }
        cnt++;
    }
    else
    {
        for (auto it = vec[p].begin(); it != vec[p].end(); it++)
        {
            x[p] = it;
            DFS(p + 1, sum + (p > 1 ? eval(x[p - 1], vec[p - 1].end(), vec[p].begin(), x[p]) : 0));
        }
    }
}

intt solve(int n)
{
    solve::n = n;
    DFS();
    return ans;
}
}

int main()
{
    freopen("ring.in", "r", stdin);
    freopen("ring.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1, m; i <= n; i++)
    {
        scanf("%d", &m);
        vec[i].resize(m);
        for (auto& x : vec[i])
        {
            scanf("%d", &x);
        }
    }
    printf("%lld", solve::solve(n));
}
