#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define rep(Ii,Jj,Kk) for(int Ii=(Jj),Ii##_=(Kk);Ii<=Ii##_;Ii++)
#define per(Ii,Jj,Kk) for(int Ii=(Jj),Ii##_=(Kk);Ii>=Ii##_;Ii--)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double db;
#define fir first
#define sec second
#define siz(Aa) ((int)(Aa).size())
#define all(Aa) (Aa).begin(),(Aa).end()
#define ckmx(Aa,Bb) (Aa=max(Aa,Bb))
#define ckmn(Aa,Bb) (Aa=min(Aa,Bb))
#define int ll
const int N=100010;
int n,q,s[N];
bool bf=true;
void work(){
	cin>>n;
	rep(i,1,n) cin>>s[i];
	cin>>q;
	if(bf && n<=20 && q<=20){
		while(q--){
			int l,r;
			cin>>l>>r;
			rep(c,1,10) rep(a,0,10) rep(b,0,10){
				rep(i,0,r-l){
					if((a*i+b)/c!=s[i+l]) goto hell;
				}
				cout<<a<<" "<<b<<" "<<c<<"\n";
				goto wow;
				hell:;
			}
			wow:;
		}
		return ;
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		if(l==r){
			cout<<"1 0 "<<s[l]<<"\n";
		}else{
			cout<<"1 "<<s[l+1]-s[l]<<" "<<s[l]<<"\n";
		}
	}
}
signed main(){ios::sync_with_stdio(false),cin.tie(nullptr);
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int T;cin>>T;
	if(T>20) bf=false;
	while(T--)work();
return 0;}
/*
*/