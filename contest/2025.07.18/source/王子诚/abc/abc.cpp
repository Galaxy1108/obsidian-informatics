#include <bits/stdc++.h>
using namespace std;

int n;
string str;

int solve_1(char A,char B,char C){
    bool a = (A == 'A' && B == 'B' && C == 'C');
    bool b = (A == 'B' && B == 'C' && C == 'A');
    bool c = (A == 'C' && B == 'A' && C == 'B');
    return a + b + c;
}

int nums[100];
char s[100][4];
int top[100];

int solve_2(){
    for (int i = 0; i < 3 * n;i++){
        nums[i] = i;
    }
    do{
        for (int i = 0; i < n;i++){
            top[i] = 0;
        }
        for (int i = 0; i < 3 * n;i++){
            s[nums[i]/3][++top[nums[i]/3]] = str[i];
        }
        bool is_can = true;
        for (int i = 0; i < n;i++){
            // cout << s[i][1] << ' ' << s[i][2] << ' ' << s[i][3] << endl;
            if(!solve_1(s[i][1],s[i][2],s[i][3])){
                is_can = false;
                break;
            }
        }
        if(is_can){
            return true;
        }
    } while (next_permutation(nums, nums + 3 * n));
    // cout << str << endl;
    // cout << "____\n";
    return false;
}

int do_something(int i){
    if(str[i]!='?'){
        return (i == 3 * n - 1 ? solve_2() : do_something(i + 1));
    }
    int anss = 0;
    str[i] = 'A';
    anss += (i == 3 * n - 1 ? solve_2() : do_something(i + 1));
    // cout << "=>" << anss << endl;
    str[i] = 'B';
    anss += (i == 3 * n - 1 ? solve_2() : do_something(i + 1));
    // cout << "=>" << anss << endl;
    str[i] = 'C';
    anss += (i == 3 * n - 1 ? solve_2() : do_something(i + 1));
    // cout << "=>" << anss << endl;
    str[i] = '?';
    // cout << str << ' ' << anss << ' ' << (i == 3 * n - 1) << endl;
    return anss;
}

int main(){
    freopen("abc.in", "r", stdin);
    freopen("abc.out", "w", stdout);
    cin >> n >> str;
    cout << do_something(0);
}