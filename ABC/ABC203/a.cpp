#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) REP(i,(n)){ cin >> (a)[i]; }
// https://atcoder.jp/contests/abc203/tasks/abc203_a
// やるだけ
// ソートすると判定が楽
void solve(){ 
    int a[3];
    CINA(a,3);
    sort(a,a+3);
    int ans = 0;
    if(a[0]==a[1]){
        ans = a[2];
    }else if(a[1]==a[2]){
        ans = a[0];
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  solve();
  return 0;
}