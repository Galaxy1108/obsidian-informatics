#include <bits/stdc++.h>
using namespace std;
string s[11];
int main()
{
    freopen("divisors.in","r",stdin);
    freopen("divisors.out","w",stdout);
    int n;
    cin >> n;
    s[3] = "2 6 3";
    s[4] = "3 6 8 12";
    s[5] = "10 15 6 8 4";
    s[6] = "5 15 18 12 8 8";
    s[7] = "7 35 15 9 18 12 8 ";
    s[8] = "7 35 15 9 18 12 8 8";
    s[9] = "7 35 15 9 18 12 8 8 4";
    s[10]= "7 35 70 10 9 18 12 8 8 4";
    cout << s[n] << endl;
    for(int i=1;i<n;i++)
    {
        cout << i << ' ' << i+1 << endl;
    }
    return 0;
}