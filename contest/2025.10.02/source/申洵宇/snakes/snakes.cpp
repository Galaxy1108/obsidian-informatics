#include <bits/stdc++.h>
using namespace std;
namespace FastI{
#define SIZE (1<<24)
char buf1[SIZE];
int tail1;
char mygetchar(){
	if(tail1>=SIZE){
		fread(buf1,1,SIZE,stdin);
		tail1=0;
	}
	return buf1[tail1++];
}
void read(int& res){
	res=0;
	static char c;c=mygetchar();
	static bool f;f=false;
	for(;!isdigit(c);c=mygetchar()){
		if(c=='-')f=true;
	}
	for(;isdigit(c);c=mygetchar()){
		res=res*10+(c^48);
	}
	res=f?-res:res;
}
}using FastI::read;
#define N 1000005
int n,a[N];
int gest[N],lest[N];
set<pair<int,int>>st;
bitset<N>book;
void solve(){
	st.clear();
	for(int i=1;i<=n;i++){
		st.emplace(a[i],i);
	}
	gest[0]=st.rbegin()->second;
	lest[0]=st.begin()->second;
	pair<int,int>l;
	set<pair<int,int>>::iterator il,is;
	for(int i=1;i<n;i++){
		il=st.find(*st.rbegin());
		is=st.begin();
		l=*il;
		l.first-=is->first;
		st.erase(is);
		st.erase(il);
		st.emplace(l);
		gest[i]=st.rbegin()->second;
		lest[i]=st.begin()->second;
	}
	book.reset();
	int ne=n;
	for(int i=n-1;i>=0;i--){
		if(book[gest[i]]==0){
			for(int j=ne-1;j>=i;j--){
				book[lest[j]]=1;
			}
			ne=i;
		}
	}
	printf("%lld\n",(long long)book.count());
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T;
	read(T);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	solve();
	T--;
	int k,x,y;
	while(T--){
		read(k);
		while(k--){
			read(x),read(y);
			a[x]=y;
		}
		solve();
	}
	return 0;
} 