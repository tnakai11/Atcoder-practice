#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
// https://atcoder.jp/contests/abc205/tasks/abc205_b
// ソートして(1,2,...,N)になるか判定すれば O(N log N) で解答可能
// 鳩の巣原理より(1,2,...,N) にならない場合はダブる数字が存在
// -> ダブりの有無をチェックすれば O(N) で解答可能
vector<int> v(2000,0);
void solve(){ 
    int N; cin >> N;
    bool ok = true;
    REP(i,N){
        int a; cin >> a;
        if(v[a]>0) ok = false;
        ++v[a];
    }
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  solve();
  return 0;
}