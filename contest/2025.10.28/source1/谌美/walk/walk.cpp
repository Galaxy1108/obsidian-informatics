#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int s=0,w=1; char ch=getchar();
	while (ch<'0' || ch>'9') w=(ch=='-')?-1:1, ch=getchar();
	while (ch>='0' && ch<='9') s=(s<<1)+(s<<3)+(ch^48), ch=getchar();
	return s*w;
}
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout); 
	return 0;
}
