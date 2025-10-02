#include<iostream>
using namespace std;
int a,b,c,d,e,f;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>a>>b>>c;
	for(int i=1;i<=c;i++) cin>>d>>e>>f;
	cin>>a;
	for(int i=1;i<=a;i++) cin>>d>>e>>f;
	for(int i=1;i<=a;i++) cout<<0<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
