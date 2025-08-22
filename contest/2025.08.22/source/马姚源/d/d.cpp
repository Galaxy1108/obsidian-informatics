#include <bits/stdc++.h>
using namespace std;
int x[1000],y[10005];
void Main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)cin >> x[i];
    int q;
    cin >> q;
    for(int i=1;i<=n;i++){
        int l, r;
        cin >> l >> r;
        for(int j=l;j<=r;j++){
            y[i]=x[i+l];
        }
        for(int c=1;c<=50;c++){
            for(int a=0;a<=50;a++){
                for(int b=0;b<=50;b++){
                    int fl=0;
                    for(int j=l;j<r;j++){
                        if((a*j+b)/c==y[j])fl++;
                        else break;
                    }
                    if(fl==r-l){
                        cout << c << " " << a << " " << b << endl;
                        return;
                    }
                }
            }
        }
    }
}
int main(){
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    int T;
    cin >> T;
    while(T--)Main();
    return 0;
}