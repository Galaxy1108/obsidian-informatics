#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const int N=1e7+5;
int n,m,H,inv2;
vector<int> s,g,ss,pres,suf;

int adc(int a,int b){return a+b>=H?a+b-H:a+b;}
int dec(int a,int b){return a<b?a-b+H:a-b;}
int mul(int a,int b){return 1ll*a*b%H;}
void add(int &a,int b){a=adc(a,b);}
void del(int &a,int b){a=dec(a,b);}

int qpow(int a,int b=H-2){
  int res=1;
  while(b){if(b&1) res=mul(res,a);a=mul(a,a),b>>=1;}
  return res;
}

int main(){
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);

  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>n>>m>>H;inv2=qpow(2);
  s.resize(m+1),g.resize(m+1);
  ss.resize(m+1),pres.resize(m+1);
  suf.resize(m+2);

  for(int i=1;i<=m;i++) s[i]=mul(mul(i,i+1),inv2),g[i]=mul(m-i+1,i);

  for(int i=2;i<=n;i++){
	// cerr<<"i = "<<i<<endl;
	for(int j=1;j<=m;j++){
	  pres[j]=adc(pres[j-1],s[j-1]);
      ss[j]=adc(ss[j-1],mul(j,adc(mul(2,s[j-1]),g[j])));
	}

	for(int j=m;j>=1;j--) suf[j]=adc(suf[j+1],adc(s[j-1],g[j]));

	for(int j=1;j<=m;j++){
	  s[j]=dec(ss[j],mul(j+1,pres[j]));
	  g[j]=dec(mul(j,suf[j]),mul(m-j+1,pres[j]));
	}
  }

  cout<<s[m];
  return 0;
}