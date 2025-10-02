#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int n,t,a[1000005],k;
void work(){
	deque<pair<int,int> > q1,q2;
	for(int i=0;i<n;i++)
		q1.push_back({a[n-i-1],n-i});
	while(1){
		if(q1.size()+q2.size()==1)
			break;
		if(q2.empty()||(!q2.empty()&&q2.front().fi<q1.front().fi||(q2.front().fi==q1.front().fi&&q2.front().se<q1.front().se))){
			pair<int,int> s=q1.front(),m;
			q1.pop_front();
			if(q2.empty()||(!q2.empty()&&q2.back().fi>q1.back().fi||(q2.back().fi==q1.back().fi&&q2.back().se>q1.back().se))){
				m=q1.back();
				q1.pop_back();
				if((q1.empty()&&!q2.empty())||(!q1.empty()&&s.fi-m.fi<q1.back().fi||(s.fi-m.fi==q1.back().fi&&s.se<q1.back().se))){
					q1.push_front(s);
					q1.push_back(m);
					break;	
				}
				q2.push_back({s.fi-m.fi,s.se});
			}
			else if(q1.empty()||(!q1.empty()&&q1.back().fi>q2.back().fi||(q1.back().fi==q2.back().fi&&q1.back().se>q2.back().se))){
				m=q2.back();
				q2.pop_back();
				if((q1.empty()&&!q2.empty())||(!q1.empty()&&s.fi-m.fi<q1.back().fi||(s.fi-m.fi==q1.back().fi&&s.se<q1.back().se))){
					q1.push_front(s);
					q2.push_back(m);
					break;
				}
				q2.push_back({s.fi-m.fi,s.se});
			}
		}
		else if(q1.empty()||(!q1.empty()&&q1.front().fi<q2.front().fi||(q1.front().fi==q2.front().fi&&q1.front().se<q2.front().se))){
			pair<int,int> s=q2.front(),m;
			q2.pop_front();
			if(q2.empty()||(!q2.empty()&&q2.back().fi>q1.back().fi||(q2.back().fi==q1.back().fi&&q2.back().se>q1.back().se))){
				m=q1.back();
				q1.pop_back();
				if((q1.empty()&&!q2.empty())||(!q1.empty()&&s.fi-m.fi<q1.back().fi||(s.fi-m.fi==q1.back().fi&&s.se<q1.back().se))){
					q2.push_front(s);
					q1.push_back(m);
					break;	
				}
				q2.push_back({s.fi-m.fi,s.se});
			}
			else if(q1.empty()||(!q1.empty()&&q1.back().fi>q2.back().fi||(q1.back().fi==q2.back().fi&&q1.back().se>q2.back().se))){
				m=q2.back();
				q2.pop_back();
				if((q1.empty()&&!q2.empty())||(!q1.empty()&&s.fi-m.fi<q1.back().fi||(s.fi-m.fi==q1.back().fi&&s.se<q1.back().se))){
					q2.push_front(s);
					q2.push_back(m);
					break;
				}
				q2.push_back({s.fi-m.fi,s.se});
			}
		}	
	}
	int ttt=q1.size()+q2.size();
	bool fl=((q1.size()+q2.size())%2==0);
	while(fl){
		if(q1.size()+q2.size()==1)
			break;
		if(q2.empty()||(!q2.empty()&&q2.front().fi<q1.front().fi||(q2.front().fi==q1.front().fi&&q2.front().se<q1.front().se))){
			pair<int,int> s=q1.front(),m;
			q1.pop_front();
			if(q2.empty()||(!q2.empty()&&q2.back().fi>q1.back().fi||(q2.back().fi==q1.back().fi&&q2.back().se>q1.back().se))){
				m=q1.back();
				q1.pop_back();
				if((!q1.empty()&&s.fi-m.fi>q1.back().fi||(s.fi-m.fi==q1.back().fi&&s.se>q1.back().se))){
					fl=false;
					break;	
				}
				q2.push_back({s.fi-m.fi,s.se});
			}
			else if(q1.empty()||(!q1.empty()&&q1.back().fi>q2.back().fi||(q1.back().fi==q2.back().fi&&q1.back().se>q2.back().se))){
				m=q2.back();
				q2.pop_back();
				if((!q1.empty()&&s.fi-m.fi>q1.back().fi||(s.fi-m.fi==q1.back().fi&&s.se>q1.back().se))){
					fl=false;
					break;	
				}
				q2.push_back({s.fi-m.fi,s.se});
			}
		}
		else if(q1.empty()||(!q1.empty()&&q1.front().fi<q2.front().fi||(q1.front().fi==q2.front().fi&&q1.front().se<q2.front().se))){
			pair<int,int> s=q2.front(),m;
			q2.pop_front();
			if(q2.empty()||(!q2.empty()&&q2.back().fi>q1.back().fi||(q2.back().fi==q1.back().fi&&q2.back().se>q1.back().se))){
				m=q1.back();
				q1.pop_back();
				if((!q1.empty()&&s.fi-m.fi>q1.back().fi||(s.fi-m.fi==q1.back().fi&&s.se>q1.back().se))){
					fl=false;
					break;	
				}
				q2.push_back({s.fi-m.fi,s.se});
			}
			else if(q1.empty()||(!q1.empty()&&q1.back().fi>q2.back().fi||(q1.back().fi==q2.back().fi&&q1.back().se>q2.back().se))){
				m=q2.back();
				q2.pop_back();
				if((!q1.empty()&&s.fi-m.fi>q1.back().fi||(s.fi-m.fi==q1.back().fi&&s.se>q1.back().se))){
					fl=false;
					break;	
				}
				q2.push_back({s.fi-m.fi,s.se});
			}
		}
	} 
	cout<<ttt-fl<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t;
	cin>>n;
	for(int i=0;i<n;i++)	
		cin>>a[i];
	work();
	for(int i=1;i<t;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			int x,y;
			cin>>x>>y;
			a[x-1]=y;
		}
		work();
	}
	return 0;
}
