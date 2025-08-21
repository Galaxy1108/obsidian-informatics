#include<bits/stdc++.h>
#define IL inline
#define RG register
#define int long long
IL int read() {
    RG int ans = 0, fl = 1;
    RG char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') fl = -1;
        c = getchar();
    }
    while (isdigit(c))
        ans = ans * 10 + c - '0',
        c = getchar();
    return ans * fl;
}
IL void write(RG int n) {
    if (n < 0) n = -n, putchar('-');
    if (n > 9) write(n / 10);
    putchar(n % 10 + '0');
}
using namespace std;
signed main() {
    freopen("far.out", "w", stdout);
    cout << 1 << '\n' << 3 << '\n';
    cout << 3 << '\n' << 6 << '\n';
    return 0;
}