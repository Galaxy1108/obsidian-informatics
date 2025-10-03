#include <bits/stdc++.h>

using namespace std;

namespace IO {
FILE *Fin = freopen("are.in", "r", stdin), *Fout = freopen("are.out", "w", stdout);
class qistream {
    static const size_t SIZE = 1 << 18, BLOCK = 150;
    FILE *fp;
    char buf[SIZE];
    int p;

   public:
    qistream(FILE *_fp = stdin) : fp(_fp), p(0) {
        fread(buf + p, 1, SIZE - p, fp);
    }

    void flush() {
        memmove(buf, buf + p, SIZE - p), fread(buf + SIZE - p, 1, p, fp), p = 0;
    }

    qistream &operator>>(char &str) {
        str = getch();
        while (isspace(str)) str = getch();
        return *this;
    }

    template <class T>
    qistream &operator>>(T &x) {
        x = 0;
        p + BLOCK >= SIZE ? flush() : void();
        bool flag = false;
        for (; !isdigit(buf[p]); ++p) flag = buf[p] == '-';
        for (; isdigit(buf[p]); ++p) x = x * 10 + buf[p] - '0';
        x = flag ? -x : x;
        return *this;
    }

    char getch() {
        p + BLOCK >= SIZE ? flush() : void();
        return buf[p++];
    }

    qistream &operator>>(char *str) {
        char ch = getch();
        while (ch <= ' ') ch = getch();
        int i;
        for (i = 0; ch > ' '; ++i, ch = getch()) str[i] = ch;
        str[i] = 0;
        return *this;
    }

    qistream &operator>>(string &str) {
        str = "";
        char ch = getch();
        while (ch <= ' ') ch = getch();
        for (; ch > ' '; ch = getch()) str += ch;
        return *this;
    }
} qcin(Fin);

class qostream {
// #define fsendl (qcout.flush(), '\n');
#define endl '\n'
    static const size_t SIZE = 1 << 18, BLOCK = 150;
    FILE *fp;
    char buf[SIZE];
    int p;

   public:
    qostream(FILE *_fp = stdout) : fp(_fp), p(0) {}

    ~qostream() { fwrite(buf, 1, p, fp); }

    void flush() { fwrite(buf, 1, p, fp), p = 0; }

    template <class T>
    qostream &operator<<(T x) {
        int len = 0;
        p + BLOCK >= SIZE ? flush() : void();
        x < 0 ? (x = -x, buf[p++] = '-') : 0;
        do buf[p + len] = x % 10 + '0', x /= 10, ++len;
        while (x);
        for (int i = 0, j = len - 1; i < j; ++i, --j)
            swap(buf[p + i], buf[p + j]);
        p += len;
        return *this;
    }

    qostream &operator<<(char x) {
        putch(x);
        return *this;
    }

    void putch(char ch) {
        p + BLOCK >= SIZE ? flush() : void();
        buf[p++] = ch;
    }

    qostream &operator<<(const char *str) {
        for (int i = 0; str[i]; ++i) putch(str[i]);
        return *this;
    }

    qostream &operator<<(char *str) {
        for (int i = 0; str[i]; ++i) putch(str[i]);
        return *this;
    }

    qostream &operator<<(const string str) {
        for (int i = 0; i < (int)str.length(); i++) putch(str[i]);
        return *this;
    }
} qcout(Fout);
}  // namespace IO
using namespace IO;

constexpr int N = 500010, M = N * 2;
int n, m, i, j, k, x, y;
int d[N], out[N], v[N], g[N], nxt[N], vis[N], on[N], f[N], ans;
int q[N], cnt, s[M], ok[M], go[M], now, ret, have;

template <typename _Tp>
inline void read(_Tp &x) {
    x = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
}

void dfs(int x) {
    vis[x] = 1;
    if (!d[x]) {
        f[x] = x == 1 ? 0 : 1;
        if (x > 1) ans++;
        return;
    }
    f[x] = N;
    for (int i = g[x]; i; i = nxt[i]) {
        int y = v[i];
        if (on[y]) continue;
        dfs(y);
        if (f[x] > f[y]) f[x] = f[y];
    }
    f[x]++;
    if (x == 1) f[x] = 0;
    if (!on[x] && f[x] > m) f[x] = 1, ans++;
}

int main() {
    int Case;
    qcin >> Case;
    int T;
    qcin >> T;
    while (T--) {
        ans = now = ret = have = cnt = 0;
        memset(d, 0, sizeof(d));
        memset(out, 0, sizeof(out));
        memset(v, 0, sizeof(v));
        memset(g, 0, sizeof(g));
        memset(nxt, 0, sizeof(nxt));
        memset(vis, 0, sizeof(vis));
        memset(on, 0, sizeof(on));
        memset(f, 0, sizeof(f));
        memset(q, 0, sizeof(q));
        memset(s, 0, sizeof(s));
        memset(ok, 0, sizeof(ok));
        memset(go, 0, sizeof(go));
        qcin >> n >> m;
        for (int i = 1; i <= n; i++) {
            int x, y;
            qcin >> x >> y;
            out[x] = y, v[i] = x, nxt[i] = g[y], g[y] = i, d[y]++;
        }
        for (i = 1; i <= n; i++)
            if (!vis[i]) {
                for (j = i; !vis[j]; j = out[j]) vis[j] = 1;
                on[q[cnt = 1] = j] = 1;
                for (k = out[j]; k != j; k = out[k]) on[k] = 1, q[++cnt] = k;
                for (j = 1; j <= cnt; j++) dfs(q[j]), s[j] = s[j + cnt] = 0;
                for (j = 1; j <= cnt; j++)
                    if (f[q[j]] <= m) {
                        s[j]++;
                        if (j + m - f[q[j]] < cnt + cnt)
                            s[j + m - f[q[j]] + 1]--;
                    }
                for (j = 1; j <= cnt + cnt; j++) s[j] += s[j - 1];
                for (j = 1; j <= cnt; j++)
                    if (s[j] || s[j + cnt])
                        ok[j] = ok[j + cnt] = 1;
                    else
                        ok[j] = ok[j + cnt] = 0;
                go[cnt + cnt + 1] = cnt + cnt + 1;
                for (j = cnt + cnt; j; j--)
                    if (ok[j])
                        go[j] = go[j + 1];
                    else
                        go[j] = j;
                have = 0, now = N;
                for (j = 1; j <= cnt; j++)
                    if (!ok[j]) {
                        for (ret = 0, k = j; k < j + cnt;) {
                            ret++, k += m;
                            if (k < j + cnt) k = go[k];
                        }
                        if (ret < now) now = ret;
                        if ((++have) == m) break;
                    }
                if (now < N) ans += now;
            }
        qcout << ans << endl;
    }
}