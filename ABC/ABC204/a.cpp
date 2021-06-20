#include <bits/stdc++.h>
using namespace std;
// https://atcoder.jp/contests/abc204/tasks/abc204_a
// 全員違う手を出すパターン -> 合計が3なので 3 - (x+y) が正解
// 全員同じ手を出すパターン -> xが正解
void solve(){ 
    int x,y; cin >> x >> y;
    cout << (x==y?x:(3-x-y)) << '\n';
}
int main(int argc, char *argv[]){
  solve();
  return 0;
}