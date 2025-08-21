

#include <bits/stdc++.h>
using namespace std;

struct s{
    int num, idx;
};
int sn[55];
s ssn[55];

int main(){
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    // freopen("CON", "r", stdin);
    // freopen("CON", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> sn[i];
        ssn[i].num = sn[i];
        ssn[i].idx = i;
    }
    sort(ssn + 1, ssn + 1 + n, [](s a, s b){
        return (a.num == b.num ? a.idx < b.idx : a.num < b.num); 
    });
    int ans = 0;
    for (int i = 1; i <= n;i++){
        ans += abs(i - ssn[i].idx);
    }
    cout << ans;
}