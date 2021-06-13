#include <bits/stdc++.h>
using namespace std;
#define REPR(i,n) for(int i=n; i>-1; --i)
// https://atcoder.jp/contests/abc202/tasks/abc202_b
// 逆向きに見ていけばOK
// O(N)

char turn(char c){
    if(c=='6') return '9';
    if(c=='9') return '6';
    return c;
}
void solve(){ 
    string s; cin >> s;
    REPR(i,s.size()-1){
        cout << turn(s[i]);
    }
    cout << '\n';
}
int main(int argc, char *argv[]){
  solve();
  return 0;
}