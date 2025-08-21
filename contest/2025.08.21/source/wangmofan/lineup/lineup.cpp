#include<iostream>
#include<algorithm>
using namespace std;
struct student{
	int height,id;
}a[1086];
bool cmp(student a,student b){
	return a.height<b.height;
}
int n,ans,maxn;
int main(){
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i].height,a[i].id=i;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)ans+=abs(a[i].id-i);
	cout << ans;
	return 0;
} 
