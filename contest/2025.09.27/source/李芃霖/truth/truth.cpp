#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e4+50;
template<class T>
inline T read(){
	T x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
} 

ll s[N],t[N],n,m,k,head,mina,cnt,op,x,y;

int main(){
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	n=read<ll>();
	k=read<ll>();
	m=read<ll>();
	for(ll i=1;i<=n;i++) s[i]=read<ll>();
	for(ll i=1;i<=m;i++){
		op=read<ll>();
		if(op==1){
			x=read<ll>();
			y=read<ll>();
			s[x]=y;
		}
		else if(op==2){
			cnt=0;
			head=1;
			mina=LONG_LONG_MAX;
			memset(t,0,sizeof(t));
			for(ll j=1;j<=n;j++){
				if(t[s[j]]==0) cnt++;
				t[s[j]]++;
				if(cnt==k){
					while(t[s[head]]>1&&head<=j){
						t[s[head]]--;
						head++;
					}
					mina=min(mina,j-head+1);
					cnt--;
					t[s[head]]--;
					head++;
				}
			}
			if(mina==LONG_LONG_MAX) cout<<-1<<endl;
			else cout<<mina<<endl;
		}
	} 
	return 0;
}
