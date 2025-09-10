#include <bits/stdc++.h>
using namespace std;

using ld = long double;
ld anss[1005][1005][2];

ld calc(int x, int y, bool is_w) {
    if (anss[x][y][is_w]) {
        return anss[x][y][is_w];
    }
    if (x == 0) {
        return 0;
    }
    if (y == 0) {
        return anss[x][y][is_w] = (is_w ? 1 : 0);
    }
    ld win_e = ((x * (1.0l)) / (x + y));
    if (is_w) {
        win_e += calc(x, y - 1, is_w ^ 1) * (1 - win_e);
        return anss[x][y][is_w] = win_e;
    }
    win_e = 1 - win_e;
    y--;
    ld runx_e = (((x * (1.0l)) / (x + y)) * win_e);
    if (y == 0) {
        return anss[x][y][is_w] = calc(x - 1, y, is_w ^ 1) * runx_e;
    }
    ld runy_e = (((y * (1.0l)) / (x + y)) * win_e);
    return anss[x][y][is_w] = calc(x - 1, y, is_w ^ 1) * runx_e + calc(x, y - 1, is_w ^ 1) * runy_e;
}

int main() {
    freopen("mouse.in", "r", stdin);
    freopen("mouse.out", "w", stdout);
    int w, b;
    cin >> w >> b;
    printf("%.9Lf", calc(w, b, true));
}