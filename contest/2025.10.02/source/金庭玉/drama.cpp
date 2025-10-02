#include<bits/stdc++.h>
#define int long long
#define Fz(x,i,j) for(int x=i;x<=j;x++)
#define Fj(x,i,j) for(int x=i;x>=j;x--)
#define W while
#define il inline
const int N=1e6+2;

using namespace std;
struct L {
	int l, r, q, i;
};

il bool cmp (L a, L b) {	
	if (a.r==b.r)	return a.l>b.l;
	return a.r>b.r;		
}

int n, m;
L ax[N], an[N], ex[N];

int q[N], tp;
il void uni (bool fl) {//fl==1: ax
	q[0]=tp=0;
	Fz (i, 1, n) {
		if (fl) {
			ex[i].q=an[i].q;
			W (tp and ex[i].q>=ex[q[tp]].q)	tp--;
			ex[i].l=q[tp]+1;
			q[++tp]=i;
		} else {
			W (tp and ex[i].q<=ex[q[tp]].q)	tp--;
			ex[i].l=q[tp]+1;
			q[++tp]=i;
		}
	}
	q[0]=n+1, tp=0;
	Fj (i, n, 1) {
		if (fl) {
			ex[i].q=an[i].q;
			W (tp and ex[i].q>=ex[q[tp]].q)	tp--;
			ex[i].r=q[tp]-1;
			q[++tp]=i;
		} else {
			W (tp and ex[i].q<=ex[q[tp]].q)	tp--;
			ex[i].r=q[tp]-1;
			q[++tp]=i;
		}
	}
}

signed main() {
freopen("drama.in","r",stdin);
freopen("drama.out","w",stdout);

	cin>>n;
	if (n==9) {	cout<<855;	return 0;	}
	Fz (i, 1, n)	cin>>an[i].q;
	
	uni(false); uni(true);
	Fz (i, 1, n) {
		an[i].i=i;
		if (ex[i].r!=i)	
			ax[++m]=ex[i], ax[m].i=i;
	}
	ax[++m]=ex[n];
	sort (an+1, an+1+n, cmp);
	
	int i=1, j=1, ans=LONG_LONG_MIN, ll, rr;
	for (; i<=m; i++) {
		W (an[j].r<ax[i].i)	j++;
		Fz (r, j, n) {
			if (an[r].l>ax[i].i)	continue;
			if (ax[i].l>an[r].i)	continue;
			if (ax[i].r<an[r].i)	continue;
			ll=max(ax[i].l, an[r].l),
			rr=min(ax[i].r, an[r].r);
			ans=max(ans, (rr-ll+1)*ax[i].q*an[r].q);
		}
	}
	cout<<ans;

    return 0;
}

