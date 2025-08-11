#include<iostream>
#include<algorithm>
using namespace std;
long long a[200086],t,q,n,cnt,ans[200086],last[200086],res[200086],vis;
struct qu{
	long long t,i,id;
}que[1000086];
bool cmp(qu a,qu b){
	return a.t<b.t;
}
int main(){
	freopen("magic.in","r",stdin);
//	freopen("magic.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++)cin >> a[i],last[i]=ans[i]=a[i];
	for(int i=1;i<=q;i++)cin >> que[i].t >> que[i].i,que[i].id=i;
	sort(que+1,que+1+q,cmp);
	for(int i=1;i<=q;i++){
		while(cnt<que[i].t){
			if(vis)break;
			int r=n/2+1,l=1;
			for(int i=1;i<=n;i++){
				if(r==n+1)ans[i]=last[l++];
				else if(l==n/2+1)ans[i]=last[r++];
				else if(last[l]<last[r])ans[i]=last[l++];
				else ans[i]=last[r++];
			}
			int flag=0;
			for(int i=1;i<=n;i++){
				if(last[i]!=ans[i] or cnt==0)flag=1;
				last[i]=ans[i];
//				cout << last[i] << ' ';
			}
//			cout << endl;
			if(!flag){
				vis=1;	
			}
			cnt++;
		}
		res[que[i].id]=ans[que[i].i];
	}
	for(int i=1;i<=q;i++){
		cout << res[i] << endl;
	}
	return 0;
}
