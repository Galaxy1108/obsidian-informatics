/*
e(n)=e(n-1)+2f(n-1)
f(n)=e(n-1)+f(n-1)
*/

#include <bits/stdc++.h>
using namespace std;

//struct bigint{
//    int num[1000], tops;
//    void operator=(long long a){
//        bigint anss;
//        anss.tops = 0;
//        while(a){
//            num[++tops] = a % 10;
//            a /= 10;
//        }
//        for (int i = tops + 1; i <= 100;i++){
//            num[i] = 0;
//        }
//    }
//    bigint div_10(){
//        bigint anss;
//        anss = 0;
//        anss.tops = tops - 1;
//        for (int i = 2; i <= tops;i++){
//            anss.num[i - 1] = num[i];
//        }
//        return anss;
//    }
//    bigint tim_10(int anum){
//        bigint anss;
//        anss = 0;
//        anss.tops = tops + anum;
//        for (int i = anum + 1; i <= tops;i++){
//            anss.num[i - anum] = num[i];
//        }
//        return anss;
//    }
//    friend bigint operator+(bigint a,bigint b){
//        bigint ans;
//        ans = 0;
//        int add = 0, topp = max(a.tops, b.tops);
//        for (int i = 1; i <= topp;i++){
//            ans.num[i] = a.num[i] + b.num[i] + add;
//            add = ans.num[i] / 10;
//            ans.num[i] %= 10;
//        }
//        if(add){
//            ans.num[++ans.tops] = add;
//        }
//        return ans;
//    }
//    friend bigint operator-(bigint a,bigint b){
//        bigint ans;
//        ans = 0;
//        int add = 0, topp = max(a.tops, b.tops);
//        for (int i = 1; i <= topp;i++){
//            ans.num[i] = a.num[i] - b.num[i] - add;
//            if(ans.num[i]<0){
//                add = 1;
//                ans.num[i] += 10;
//            }
//        }
//        assert(add >= 0);
//        return ans;
//    }
//    friend bigint operator*(bigint a,int b){
//        bigint ans;
//        ans = 0;
//        int add = 0;
//        for (int i = 1; i <= a.tops;i++){
//            ans.num[i] = a.num[i] * b + add;
//            add = ans.num[i] / 10;
//            ans.num[i] %= 10;
//        }
//        while(add){
//            ans.num[++ans.tops] = add;
//            add = ans.num[++ans.tops] % 10;
//        }
//        return ans;
//    }
//    friend bigint operator*(bigint a,bigint b){
//        bigint ans;
//        ans = 0;
//        for (int i = 1; i <= b.tops;i++){
//            ans = (a + a * b.num[i]);
//            a.tim_10(1);
//        }
//        return ans;
//    }
//    friend bool operator>(bigint a,bigint b){
//        if(a.tops>b.tops){
//            return true;
//        }
//        if(a.tops<b.tops){
//            return false;
//        }
//        for (int i = a.tops; i >= 1;i--){
//            if(a.num[i]>b.num[i]){
//                return true;
//            }
//            if(a.num[i]<b.num[i]){
//                return false;
//            }
//        }
//        return false;
//    }
//    friend bool operator>=(bigint a,bigint b){
//        if(a.tops>b.tops){
//            return true;
//        }
//        if(a.tops<b.tops){
//            return false;
//        }
//        for (int i = a.tops; i >= 1;i--){
//            if(a.num[i]>b.num[i]){
//                return true;
//            }
//            if(a.num[i]<b.num[i]){
//                return false;
//            }
//        }
//        return true;
//    }
//    friend bool operator!=(bigint a,long long s){
//        bigint b;
//        b = s;
//        if(a.tops>b.tops || a.tops<b.tops){
//            return true;
//        }
//        for (int i = a.tops; i >= 1;i--){
//            if(a.num[i]>b.num[i] || a.num[i]<b.num[i]){
//                return true;
//            }
//        }
//        return false;
//    }
//    friend bigint operator/(bigint a,bigint b){
//        bigint anss;
//        anss = 0;
//        bigint divb = b.tim_10(a.tops - b.tops), tmpa = a;
//        int topp = a.tops - b.tops + 1;
//        while(topp){
//            while(tmpa>=divb){
//                tmpa = (tmpa - divb);
//                anss.num[topp]++;
//                anss.tops = max(anss.tops, topp);
//            }
//            topp--;
//        }
//        return anss;
//    }
//    friend bigint operator%(bigint a,bigint b){
//        bigint ans;
//        ans = 0;
//        bigint divb = b.tim_10(a.tops - b.tops), tmpa = a;
//        int topp = a.tops - b.tops + 1;
//        while(topp){
//            while(tmpa>=divb){
//                tmpa = (tmpa - divb);
//            }
//            topp--;
//        }
//        return tmpa;
//    }
//    friend ostream& operator<<(ostream& out,bigint a){
//        for (int i = a.tops; i >= 1;i++){
//            out << a.num[i];
//        }
//        return out;
//    }
//};
//
//// struct douint{
////     long double num;
////     douint(long long a){
////         num = a;
////     }
////     void operator=(long long a){
////         num = a;
////     }
////     douint operator/(douint b){
////         return floor(num / b.num);
////     }
////     douint operator*(douint b){
////         return num * b.num;
////     }
////     douint operator%(long long b){
////         while((num-b)>1e-2){
////             num -= b;
////         }
////         return num;
////     }
////     void puts(){
////         printf("%.0Lf\n", num);
////     }
//// };

using ll = long long;
using i128 = __int128;
#define PUTS_LEN 1000000000

void puti128(i128 num){
    if(num<=PUTS_LEN){
        cout << (ll)num;
        return;
    }
    puti128(num / PUTS_LEN);
    cout << (ll)(num % PUTS_LEN);
}

i128 _lcm(i128 a,i128 b){
    return a / __gcd(a, b) * b;
}

i128 f[100000];

int main(){
    freopen("lcm.in", "r", stdin);
    freopen("lcm.out", "w", stdout);
    ll T;
    cin >> T;
    while(T--){
        ll n, p;
        cin >> n >> p;
        i128 anss;
        anss = 0;
        i128 g;
        i128 s;
        s = 1;
        g = 1;
        f[1] = 1;
        for (int i = 1; i <= n;i++){
            g = _lcm(g, f[i]);
            anss = (anss + (((g % (s * p)) * i) % (s * p))) % (s * p);
            // puti128(g % p);
            // cout << ' ';
            // puti128((i128)i * (g % p));
            // cout << '\n';
            f[i + 1] = (s * 2) * f[i] + f[i - 1];
        }
        puti128(anss);
        cout << '\n';
        // cout << anss << '\n';
    }
}
