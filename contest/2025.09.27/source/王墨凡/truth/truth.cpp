#include<iostream>

using namespace std;
int n,k,m,a[50086],opt,p,v,cnt1[50],flag=1,ans;
bool check(int x){
	int cnt=0;
	for(int i=1;i<=k;i++)cnt1[i]=0;
	for(int i=1;i<=x;i++){
		if(!cnt1[a[i]])cnt++;
		cnt1[a[i]]++;
	}
	if(cnt==k)return 1;
	for(int i=x+1;i<=n;i++){
		if(cnt1[a[i-x]]==1)cnt--;
		cnt1[a[i-x]]--;
		if(!cnt1[a[i]])cnt++;
		cnt1[a[i]]++;
		if(cnt==k)return 1;
	}
	return 0;
}
int main(){
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> k >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=m;i++){
		cin >> opt;
		if(opt==1){
			cin >> p >> v;
			a[p]=v;
			flag=1;
		}
		else{
			if(!flag){
				cout << ans << endl;
				continue;
			}
			else{
				int l=k,r=n+1;
				while(l<r){
					int mid=l+((r-l)>>1);
					if(check(mid))r=mid;
					else l=mid+1;
				}
				flag=0;
				if(l!=n+1)ans=l;
				else ans=-1;
				cout << ans << endl;
			}
		}
	}
	return 0;
}
