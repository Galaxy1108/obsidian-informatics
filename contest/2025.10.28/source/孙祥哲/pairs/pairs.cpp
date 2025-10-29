#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll p[123], N;
vector<ll> nx;
unordered_map<ll, ll> t;

void add(ll x, ll y) { while (x<=N+10) t[x] += y, x += x&-x; }
ll sum(ll x) {ll r=0;while(x)r+=t[x],x-=x&-x;return r;}

void init(int n)
{
    t.clear(), nx.clear();
    for (int i = 1; i <= n; i++) p[i] = i;
    do
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i+1; j <= n; j++)
                cnt += (p[i] > p[j]);
        // for (int i = 1; i <= n; i++) cout << p[i] << '|';
        // cout << "      " << cnt << '\n';
        nx.push_back(cnt);
    } while(next_permutation(p+1, p+1+n));
    N = nx.size();
    ll res = 0;
    for (ll i = nx.size()-1; i >= 0; i--)
    {
        res += sum(nx[i]+1);
        add(nx[i]+2, 1);
    }
    cout << res << ',';
}

ll res[1235] = {0,0,0,0,17,904,45926,2725016,196884712,17350671831,1847029162807};

int main()
{
	freopen("pairs.in", "r", stdin);
	freopen("pairs.out", "w", stdout); 
//    for (int i = 1; i <= 10; i++) init(i);
	int n, M; cin >> n >> M; cout << res[n]%M;
    return 0;
}
