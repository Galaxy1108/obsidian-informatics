#include <iostream>
#include <iomanip>
using namespace std;
const int MAXN = 1000 + 12;
int w,b;
long double f[MAXN][MAXN][2];
int main()
{
    freopen("mouse.in","r",stdin);
    freopen("mouse.out","w",stdout);
    cin >> w >> b;
    for (int i=1;i<=w;i++)
    {
        f[i][0][0] = 1;
        f[i][0][1] = 0;
        for (int j=1;j<=b;j++)
        {
            f[i][j][0] = 1.0*i/(i+j) + 1.0*j/(i+j)*f[i][j-1][1];
            f[i][j][1] = 1.0*j/(i+j)*(1.0*i/(i+j-1)*f[i-1][j-1][0] + 1.0*(j-1)/(i+j-1)*f[i][j-2][0]);
            //cout << fixed << setprecision(9) << f[i][j][0] << endl;
        }
    }
    cout << fixed << setprecision(9) << f[w][b][0];
    return 0;
}