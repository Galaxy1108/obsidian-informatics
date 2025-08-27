#include <cstdio>

using namespace std;
typedef long long ll;

int prime[2505], c = 0, p;
ll qp1[2005], qp2[2005];
ll qw1[2005], qw2[2005];
ll sum[20005];
ll ans[20005];
bool ntp[20005];
void sieve(int x)
{
	int i, j;
	ntp[1] = 1;
	for(i = 2; i <= x; i++)
	{
		if(!ntp[i])
			prime[++c] = i;
		for(j = 1; j <= c && i * prime[j] <= x; j++)
		{
			ntp[i * prime[j]] = 1;
			if(!(i % prime[j]))
				break;
		}
	}
}
void work(int x)
{
	int i;
	qp1[0] = 1;
	qp2[0] = 1;
	qw1[0] = 1;
	qw2[0] = 1;
	sum[0] = 0;
	for(i = 1; i <= 20000; i++)
		sum[i] = sum[i / x] + (i % x);
	for(i = 1; i <= 20000; i++)
		sum[i] += sum[i - 1];
	for(i = 1; i <= 1000; i++)
		qw1[i] = qw1[i - 1] * x % p;
	for(i = 1; i <= 1000; i++)
		qw2[i] = qw2[i - 1] * qw1[1000] % p;
	for(i = 1; i <= 1000; i++)
		qp1[i] = (qp1[i - 1] + qw1[i]) % p;
	for(i = 1; i <= 1000; i++)
		qp2[i] = (qp2[i - 1] + (qp1[1000] - 1) * qw2[i - 1] % p) % p;
}
int qrys(int y)
{
	return (qp2[y / 1000] + (qp1[y % 1000] - 1) * qw2[y / 1000] % p) % p;
}

int main()
{
	freopen("gonna.in", "r", stdin);
	freopen("gonna.out", "w", stdout);
	int n, i, j, t;
	scanf("%d%d", &n, &p);
	sieve(n);
	for(i = 1; i <= n; i++)
		ans[i] = 1;
	for(i = 1; i <= c; i++)
	{
		work(prime[i]);
		for(j = prime[i]; j <= n; j++)
		{
			t = (2 * sum[j] - (j + 1) * (sum[j] - sum[j - 1])) / (prime[i] - 1);
			ans[j] = ans[j] * qrys(t) % p;
		}
	}
	t = 0;
	for(i = 1; i <= n; i++)
		t = (t + ans[i]) % p;
	printf("%d\n", t);
	return 0;
}