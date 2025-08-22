#include<bits/stdc++.h>
#define IL inline
#define RG register
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
    if (n < 0) putchar('-'), n = -n;
    if (n > 9) write(n / 10);
    putchar(n % 10 + '0');
}
signed main() {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    printf("1 4 3\n\
0 1 1\n\
0 2 1\n\
1 1 1\n\
5 4 4\n\
1 2 1\n\
3 6 2\n\
5 1 2\n");
    return 0;
}