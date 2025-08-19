#include <bits/stdc++.h>
#define mod 1000000007LL
using namespace std;
typedef long long LL;
typedef pair <LL, LL> pr;
LL n;
map <LL, LL> m;
map <LL, LL> :: iterator it;
LL F(LL i){
    LL res1, res2, res;
    if(i < 3) return 1LL; 
    it = m.find(i);
    if(it == m.end()){
        if(i & 1)
        {
            res1 = F(i >> 1);
            res2 = F(i + 1 >> 1);
            res = (res1 * res1 + res2 * res2) % mod;
        }else
        {
            res1 = F(i - 2 >> 1);
            res2 = F(i >> 1);
            res = ((res1 << 1) + res2) * res2 % mod;
        }
        m.insert(pr(i, res));
        return res;
    }else
        return it -> second;
}

int main()
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m;
		cin>>n>>m;
		cout<<__gcd(F(n),F(m))<<endl;
	}
    return 0;
}