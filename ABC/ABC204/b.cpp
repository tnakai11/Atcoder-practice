#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
// https://atcoder.jp/contests/abc204/tasks/abc204_b
// やるだけ 計算量は O(N)
void solve(){ 
    int N; cin >> N;
    int ans = 0;
    int a;
    REP(i,N){
        cin >> a;
        ans += max(a-10,0);
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  solve();
  return 0;
}