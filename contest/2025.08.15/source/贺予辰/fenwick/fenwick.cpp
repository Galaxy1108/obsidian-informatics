#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define R register
int n;
ull s1,s2;
inline ull my_rand()
{
    R ull s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}
inline void get_query(int &op,ull &num1,ull &num2)
{
    op=my_rand()%2+1;
    if(op==1)
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
    }
    else
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
        if(num1>num2)
             swap(num1,num2);
    }
}
int Q;
ull t[10000007];
const __int128 p = (__int128)1 << 64;
inline void add(int pos, ull x) {
	R ull cnt = 0;
    while (pos <= n) {
        t[pos] = (t[pos] + x * (++cnt) % p) % p,
        pos += (pos & -pos);
    }
}
inline ull que(int pos) {
    R ull ans = 0;
    while (pos) {
        ans = (__int128)(ans + t[pos]) % p;
        pos -= (pos & -pos);
    }
    return ans;
}
int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(t, 0, sizeof(t));
    cin >> n >> Q >> s1 >> s2;
    R ull ans = 0;
    for (ull i = 1; i <= Q; ++i) {
        R int op;
        R ull x, y;
        get_query(op, x, y);
        if (op & 1) add(x, y);
        else {
            R ull tmp = (__int128)(que(y) - que(x - 1) + p) % p;
            tmp = (__int128)(tmp * i) % p;
            ans ^= tmp;
        }
    }
    cout << ans << '\n';
    return 0;
}
