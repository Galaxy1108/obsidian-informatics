/*
构造一条链
*/

#include <bits/stdc++.h>
using namespace std;

// int anss[2505];
// struct s{
//     int num, idx;
// };
// s sort_by[2505];

// int lcm(int a,int b){
//     return a * b / __gcd(a, b);
// }

// int fat[2505];
// int get_fat(int a){
//     return (fat[a] == a ? a : fat[a] = get_fat(fat[a]));
// }

// vector<int> a[2505];

int main(){
    freopen("divisors.in", "r", stdin);
    freopen("divisors.out", "w", stdout);
    int n;
    cin >> n;
    cout << 2520 << ' ';
    for (int i = 2; i <= n;i++){
        cout << i << ' ';
    }
    cout << '\n';
    for (int i = 2; i <= n;i++){
        cout << i << ' ' << 1 << '\n';
    }
    // for (int i = 1; i <= n;i++){
    //     anss[i] = 1;
    //     fat[i] = i;
    // }
    // for (int k = 1; k <= n;k++){
    //     for (int i = 1; i <= n;i++){
    //         sort_by[i].num = lcm(anss[i], k);
    //         sort_by[i].idx = i;
    //     }
    //     sort(sort_by + 1, sort_by + 1 + n, [](s a, s b)
    //          { return a.num < b.num; });
    //     bool flag = true;
    //     for (int i = 2; i <= n && flag;i++){
    //         for (int j = 1; j < i;j++){
    //             int u = min(sort_by[i].idx, sort_by[j].idx);
    //             int v = max(sort_by[i].idx, sort_by[j].idx);
    //             int uf = get_fat(u), vf = get_fat(v);
    //             if(uf != vf){
    //                 fat[uf] = vf;
    //                 a[u].emplace_back(v);
    //                 int un = (u == sort_by[i].idx ? sort_by[i].num : sort_by[j].num);
    //                 int vn = (v == sort_by[i].idx ? sort_by[i].num : sort_by[j].num);
    //                 anss[u] = un, anss[v] = vn;
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //     }
    // }
    // for (int i = 1; i <= n;i++){
    //     cout << anss[i] << ' ';
    // }
}