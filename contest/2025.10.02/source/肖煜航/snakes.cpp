#include<cstdio>
#include<algorithm>
#include<deque>
#define pa pair<int,int>
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=1e6+5;
int T,n,a[N];
deque<pa> q1,q2,q3;
pa get_max(){
	pa mx={-1e9,-1e9};
	if(!q1.empty()){
		mx=max(mx,q1.back());
	}
	if(!q2.empty()){
		mx=max(mx,q2.back());
	}
	if(!q3.empty()){
		mx=max(mx,q3.back());
	}
	return mx;
}
pa get_min(){
	pa mi={1e9,1e9};
	if(!q1.empty()){
		mi=min(mi,q1.front());
	}
	if(!q2.empty()){
		mi=min(mi,q2.front());
	}
	if(!q3.empty()){
		mi=min(mi,q3.front());
	}
	return mi;
}
int lst=0;
void delet(pa x,int op){
	if(op==0){
		if(!q1.empty()){
			if(x==q1.back()){
				q1.pop_back();
				return;
			}
		}
		if(!q2.empty()){
			if(x==q2.back()){
				q2.pop_back();
				return;
			}
		}
		if(!q3.empty()){
			if(x==q3.back()){
				q3.pop_back();
				return;
			}
		}
	}
	else{
		if(!q1.empty()){
			if(x==q1.front()){
				q1.pop_front();
				lst=1;
				return;
			}
			
		}
		if(!q2.empty()){
			if(x==q2.front()){
				q2.pop_front();
				lst=2;
				return;
			}
		}
		if(!q3.empty()){
			if(x==q3.front()){
				q3.pop_front();
				lst=3;
				return;
			}
		}
	}
}
void init(){
	q1.clear();
	q2.clear();
	q3.clear();
	for(int i=1;i<=n;i++) q1.push_back({a[i],i});
}
bool check(int now){
	if(now==2) return 1;
	pa mx=get_max();	
	pa mi=get_min();
	delet(mi,1);
	pa op=mx;
	op.first-=mi.first;
	pa ni=get_min();
	if(op>ni) return 1;
	else{
		delet(mx,0);
		q3.push_front(op);
		return !check(now-1);
	}
}
void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void solve(){
	init();
	int ans=n;
	while(1){
		if(ans==1||ans==2){
			printf("1\n");
			return;
		}
		pa mx=get_max();	
		pa mi=get_min();
		delet(mi,1);
		pa op=mx;
		op.first-=mi.first;
		pa ni=get_min();
		if(op>ni){
			delet(mx,0);
			q2.push_front(op);
			ans--;
		}
		else{
			if(lst==1){
				q1.push_front(mi);
			}
			else if(lst==2){
				q2.push_front(mi);
			}
			else{
				q3.push_front(mi);
			}
			if(check(ans)){
				ans--;
			}
			break;
		}
	}
	write(ans);
	putchar('\n');
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	T=read();
	for(int t=1;t<=T;t++){
		if(t==1){
			n=read();
			for(int i=1;i<=n;i++) a[i]=read();
		}
		else{
			int o=read();
			while(o--){
				int x=read(),y=read();
				a[x]=y;
			}
		}
		solve();
	}
	return 0;
}
