#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int main()
{
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout); 
	long long n,m,p;
	cin>>n>>m>>p;
	cout<<binpow(2,min(n,m)+m,p);
	return 0;
}
