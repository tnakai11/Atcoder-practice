#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
// https://atcoder.jp/contests/abc205/tasks/abc205_a
// 100/A = B/x より
// x = A*B/100
// 小数に注意
void solve(){ 
    ld A,B; cin >> A >> B;
    ld temp = A*B;
    cout << temp/100. << '\n';
}
int main(int argc, char *argv[]){
  solve();
  return 0;
}