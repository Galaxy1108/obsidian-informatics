#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct player{
	long long x,y,z,id;
}a[150086];
pair<int,int> a1[150086],a2[150086],a3[150086];
int n,p1=1,p2=1,p3=1,cnt;
bool cmp(pair<int,int> c,pair<int,int> b){return c.first>b.first;}
int main(){
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
		a1[i]={a[i].x,i};
		a2[i]={a[i].y,i};
		a3[i]={a[i].z,i};
	}
	sort(a1+1,a1+1+n,cmp);
	sort(a2+1,a2+1+n,cmp);
	sort(a3+1,a3+1+n,cmp);
	while(cnt<3){
		if(p1==n+1 or p2==n+1 or p3==n+1){
			cout << -1;
			return 0;
		}
		if(a1[p1].second!=a2[p2].second and a2[p2].second!=a3[p3].second and a1[p1].second!=a3[p3].second){
			cout << a1[p1].first+a2[p2].first+a3[p3].first;
			return 0;
		}
		if(a1[p1].second==a2[p1].second)p1++;
		if(a1[p1].second==a3[p1].second)p1++;
		if(a2[p2].second==a1[p2].second)p2++;
		if(a2[p2].second==a3[p2].second)p2++;
		if(a3[p3].second==a2[p3].second)p3++;
		if(a3[p3].second==a1[p3].second)p3++;
	}
	return 0;
}
