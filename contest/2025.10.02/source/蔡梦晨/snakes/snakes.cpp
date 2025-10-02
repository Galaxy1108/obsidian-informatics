#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int s[N];
struct snk{
	int l,x;
}a[N];
int n;
bool cmp(snk q,snk p){
	return q.l>=p.l;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t;
	cin>>t;
	bool o=0;
	cin>>n;
	while(t){
		t--;
		if(o==0){
			for(int i=1;i<=n;i++){
				cin>>s[i];
			}
		}else{
			int k;
			cin>>k;
			for(int i=1;i<=k;i++){
				int q,p;
				cin>>q>>p;
				s[q]=p;
			}
		}
		o=1;
		if(n==3){
			if(s[3]-s[1]>=s[2]){
				cout<<1<<endl;
			}else{
				cout<<3<<endl;
			}
			continue;
		}
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			a[n-i+1].l=s[i];
			a[n-i+1].x=i;
		}
//		sort(a+1,a+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<a[i].l<<" "<<a[i].x<<endl;
//		}
		int ln=n;
		while(a[1].l-a[ln].l>=a[ln-1].l||ln==2){
			a[1].l-=a[ln].l;
			ln--;
			int i=1;
			while(a[i].l<a[i+1].l&&i<=ln){
				snk u=a[i];
				a[i]=a[i+1];
				a[i+1]=a[i];
				i++;
			}
		}
		cout<<ln<<endl;
	}
	return 0;
}
