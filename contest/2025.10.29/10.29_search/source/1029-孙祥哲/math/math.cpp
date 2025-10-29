#include <bits/stdc++.h>
#define ll long long
//#define db
using namespace std;

void write(ll x)
{
	if (x > 9) write(x/10);
	cout << '0'+int(x%10);
}
//ostream& operator << (ostream& os, const ll& x) { write(x); return os; }
template<typename T> T mgcd(T a, T b) { return b ? mgcd(b, a%b) : a; }
struct frac
{
    ll x, y;
    frac() { x = 0, y = 1; }
    frac(ll xx, ll yy) { ll g = mgcd(xx,yy);x = xx/g, y = yy/g; }
    bool operator < (const frac& o) { return (ll)x*o.y < (ll)y*o.x; }
    frac operator + (const frac& o)
    {
        ll tx = (ll)x * o.y + (ll)y * o.x;
        ll ty = (ll)y * o.y;
        ll g = mgcd(tx, ty);
        frac r; r.x = tx/g, r.y = ty/g;
        if (r.y < 0) r.y = -r.y, r.x = -r.x;
        return r;
    }
    frac operator - () const {  frac r;r.x=-x,r.y=y; return r; }
    frac operator - (const frac& o) { return *this + (-o); }
    void gx() { ll g = mgcd(x, y); x /= g, y /= g; }
};
//ostream& operator << (ostream& os, const frac& x) { os<<x.x<<'/'<<x.y; return os; }

int A, B, _, P;
vector<int> res;

void dfs(frac a, int xz)
{
    if (!xz || _) return;
    if (a.x == 1)
    {
        cout << res.size()+1 << '\n';
        #ifdef db
            for (auto i : res) cout << "1/" << i << '+';
            cout << "1/" << a.y << '\n';
        #else
            for (auto i : res) cout << i << ' ';
            cout << a.y << '\n';
        #endif
        _ = 1;
        exit(0);
    }
    frac lim = a;
    lim.y *= xz, lim.gx();
    ll tmp = a.y / a.x;
    for (frac i = {1, tmp}; !_; i.y++)
    {
        if (a < i) continue;
        if (i < lim) break;
        res.push_back(i.y);
//        if (P == 6) cout << i << '\n';
        dfs(a-i, xz-1);
        res.pop_back();
    }
}

int main()
{
   freopen("math.in", "r", stdin);
   freopen("math.out", "w", stdout);
    cin >> A >> B;
//    A = 511, B = 997;
	// A = 991, B = 997;
    for (int i = 1; ; i++) P = i, dfs({A, B}, i);
    return 0;
}
//
