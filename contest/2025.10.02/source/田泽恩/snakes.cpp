#include <bits/stdc++.h>
using namespace std;
int n,t,k,x,y,a[1919810],ans;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;++i){
		deque<pair<int,int> >q1,q2;
		ans=0;
		if(i==1){
			cin>>n;
			for(int j=1;j<=n;++j) cin>>a[j];
		}
		else{
			cin>>k;
			while(k--){
				cin>>x>>y;
				a[x]=y;
			}
		}
		for(int j=1;j<=n;++j) q1.push_back({a[j],j});
		while(1){
			if(q1.size()+q2.size()==2){
				ans=1;
				break;
			}
			int x,y,id;
			y=q1.front().first;
			q1.pop_front();
			if(q2.empty()||!q1.empty()&&q1.back()>q2.back()){
				x=q1.back().first;
				id=q1.back().second;
				q1.pop_back();
			}
			else{
				x=q2.back().first;
				id=q2.back().second;
				q2.pop_back();
			}
			pair<int,int> now={x-y,id};
			if(q1.empty()||q1.front()>now){
				ans=q1.size()+q2.size()+2;
				int cnt=0;
				while(1){
					++cnt;
					if(q1.size()+q2.size()==1){
						if(cnt%2==0) --ans;
						break;
					}
					int z,ID;
					if(q2.empty()||!q1.empty()&&q1.back()>q2.back()){
						z=q1.back().first;
						ID=q1.back().second;
						q1.pop_back();
					}
					else{
						z=q2.back().first;
						ID=q2.back().second;
						q2.pop_back();
					}
					now={z-now.first,ID};
					if(!(q1.empty()||now<q1.front())||!(q2.empty()||now<q2.front())){
						if(cnt%2==0) ans--;
						break;
					}
				}
				break;
			}
			else{
				q2.push_front(now);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
