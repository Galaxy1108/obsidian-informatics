#include <bits/stdc++.h>
using namespace std;
long long Qread()
{
	long long x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
long long r,P,remP,phiP;
long long mul(long long A,long long B)
{
	long long C=(A*B-(long long)((long double)A/P*B)*P+P)%P;
	while(C<0) C+=P;
	return C;
}
long long qpow(long long A,long long p)
{
	long long ret=1;
	for(;p;p>>=1,A=mul(A,A))
		if(p&1) ret=mul(ret,A);
	return ret;
}
int T;long long b;
vector<long long>yz;
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	
	T=Qread(),P=Qread();
	phiP=remP=P;
	for(int i=2;1ll*i*i<=remP;i++) if(remP%i==0)
	{
		phiP=phiP/i*(i-1);
		while(remP%i==0) remP/=i;
	}
	if(remP!=1) phiP=phiP/remP*(remP-1);

	remP=phiP;
	for(int i=2;1ll*i*i<=remP;i++) if(remP%i==0)
	{
		yz.push_back(i);
		while(remP%i==0) remP/=i;
	}
	if(remP!=1) yz.push_back(remP);
	while(T--)
	{
		b=Qread();

		if(__gcd(b,P)!=1)
		{
			printf("-1\n");
			continue;
		}

		if(P==2)
		{
			printf("1\n");
			continue;
		}

		r=phiP;
		for(long long p:yz) while(r%p==0&&qpow(b,r/p)==1) r/=p;

		if(r%2==0&&qpow(b,r/2)==P-1)
		{
			if(r==2) printf("2\n");
			else printf("%lld\n",r/2-1);
		}
		else printf("-1\n");
	}
	return 0;
}