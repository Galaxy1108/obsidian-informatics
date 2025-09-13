#include<bits/stdc++.h>
using namespace std;
int n,l,r,q,s[2000005],rs[2000005],f[2000005],p[2000005],idx;
string ss;
int getf(int x){
	return (f[x]==x)?x:f[x]=getf(f[x]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	cin>>n>>l>>r>>ss;
	for(int i=0;i<n;i++){
		s[i+1]=s[i]+(ss[i]=='a');
		if(ss[i]=='a')
			p[++idx]=i+1; 
	}
	int kkk=s[n]+1;
	for(int i=n;i>=1;i--){
		if(kkk-s[i-1]>1)
			kkk--;
		rs[i]=kkk;
	}
	for(int i=1;i<=n;i++)
		f[i]=i;
	int ll=0,rr=0,a=0,b=0;
	for(int i=1;i<=n;i++){
		if(rs[i]+l-1>idx)
			break;
		else
			ll=p[rs[i]+l-1];
		if(rs[i]+r-1<idx)
			rr=p[rs[i]+r]-1;
		else
			rr=n;
		if(ll<=b)
			if(getf(i)!=getf(i-1))
				f[getf(i)]=getf(i-1);
		for(int j=max(b+1,ll);j<=rr;j++)
			if(getf(i)!=getf(j))
				f[getf(i)]=getf(j);
		a=ll;
		b=rr;
	} 
	cin>>q;
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(getf(x)==getf(y))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	} 
	return 0;
}
