#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e5+5;
int n,m;
ll a[N],d[N],Dx2,Dx1;

ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}

void prt(ll a,ll b,ll c){
  cout<<a<<' '<<b<<' '<<c<<'\n';
}

bool chk(int l,int r,ll a,ll &b,ll c){
//   cerr<<"chk: "<<l<<' '<<r<<' '<<a<<' '<<b<<' '<<c<<endl;
  if(gcd(a,c)!=1) return false;
  if(a>=c||a<0) return false;
  for(b=0;b<c;b++){
    ll lst=0,A=b;
	bool fl=true;
    for(int i=l+1;i<=r;i++){
	  A+=a;
	  if((A/c)!=lst){
	    if(d[i]!=Dx2){fl=false;break;}
	  }else if(d[i]==Dx2){fl=false;break;}
	  lst=A/c;
    }
	if(fl) return true;
  }
  return false;
}

void qry(int l,int r){
  if(l==r) return prt(0,a[l],1);
  Dx1=-1,Dx2=-1;
  for(int i=l+1;i<=r;i++){
    if(Dx1==-1) Dx1=d[i];
	else if(d[i]!=Dx1) Dx2=d[i];
  }
  if(Dx2==-1) return prt(Dx1,a[l],1);
  if(Dx1>Dx2) swap(Dx1,Dx2);

//   cerr<<"Dx = "<<Dx1<<' '<<Dx2<<endl;

  ll ka=Dx1,kb=a[l],a=0,b=0,c=0,i;

  for(c=1,i=l;c<=r-l+1;c++,i++){
    a+=(d[i+1]==Dx2);
    if(gcd(a,c)==1&&chk(l,r,a,b,c)) break;
  }
  prt(ka*c+a,kb*c+b,c);
}

void SOLVE(){
  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i],d[i]=a[i]-a[i-1];//,cerr<<d[i]<<' ';
//   cerr<<endl;
  cin>>m;
  while(m--){
	int l,r;
	cin>>l>>r;
	qry(l,r);
  }
}

int main(){
  freopen("d.in","r",stdin);
  freopen("d.out","w",stdout);

  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int _;cin>>_;
  while(_--) SOLVE();
  return 0;
}