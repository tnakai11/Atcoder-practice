#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc305/tasks/abc305_a
// 給水所が高々21ヶ所なので全探索で全然間に合う
// O(1)解法: N=5a+bに分解して b<=2 なら 5a, 3<=bなら5(a+1)
void solve(){ 
    int N; cin >> N;
    int a = N/5;
    int b = N%5;
    int ans;
    if (b<=2) ans = a*5;
    else ans = (a+1)*5;
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}