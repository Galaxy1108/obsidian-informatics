#include <bits/stdc++.h>
#define N 100005
using namespace std;
int a[N],b[N];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=1e3){
		for(int i=1;i<=q;i++){
			int t,id;
			cin >> t >> id;
			deque<int> q1,q2,q3,q4;
			for(int j=1;j<=n;j++)q1.push_back(a[j]);
//			for(int j=1;j<=n;j++){
//				q1.push_back(q4.front());
//	//			cout << q4.front() << " ";
//				q4.pop_front();
//			}
			for(int ij=1;ij<=t;ij++){
				for(int j=1;j<=n/2;j++){
					q2.push_front(q1.back());
					q1.pop_back();
				}
				for(int j=1;j<=n/2;j++){
					q3.push_back(q1.front());
					q1.pop_front();
				}
				while(q2.size()&&q3.size()){
					if(q2.front()>q3.front()){
						q1.push_back(q3.front());
						q3.pop_front();
					}
					else{
						q1.push_back(q2.front());
						q2.pop_front();
					}
	//				cout << 114514;
				}
				while(q2.size()){
					q1.push_back(q2.front());
					q2.pop_front();
				}
				while(q3.size()){
					q1.push_back(q3.front());
					q3.pop_front();
				}
			}
			for(int j=1;j<=n;j++){
//				cout << q1.front() << " ";
				if(j==id)cout << q1.front() << "\n";
				q1.pop_front();
			}
//			cout << endl;
			
		}
	}
	else{	
		for(int i=1;i<=q;i++){
			int t,id;
			cin >> t >> id;
			deque<int> q1,q2,q3;
			if(i>1){
				cout << b[id] << endl;
				continue;
			}
			for(int j=1;j<=n;j++)q1.push_back(a[j]);
//			for(int j=1;j<=n;j++){
//				q1.push_back(q4.front());
//	//			cout << q4.front() << " ";
//				q4.pop_front();
//			}
			for(int ij=1;ij<=t;ij++){
				for(int j=1;j<=n/2;j++){
					q2.push_front(q1.back());
					q1.pop_back();
				}
				for(int j=1;j<=n/2;j++){
					q3.push_back(q1.front());
					q1.pop_front();
				}
				while(q2.size()&&q3.size()){
					if(q2.front()>q3.front()){
						q1.push_back(q3.front());
						q3.pop_front();
					}
					else{
						q1.push_back(q2.front());
						q2.pop_front();
					}
	//				cout << 114514;
				}
				while(q2.size()){
					q1.push_back(q2.front());
					q2.pop_front();
				}
				while(q3.size()){
					q1.push_back(q3.front());
					q3.pop_front();
				}
			}
			for(int j=1;j<=n;j++){
				b[j]=q1.front();
//				cout << q1.front() << " ";
				if(j==id)cout << q1.front() << "\n";
				q1.pop_front();
			}
//			cout << endl;
			
		}
	}
	return 0;
}
