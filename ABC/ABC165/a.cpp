#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc165/tasks/abc165_a
// A<= nk <= B を満たす n が存在するかどうか
// A/k <= n <= B/k を満たす n が存在するかどうか
// OK の場合 A//k or A//k + 1 のうち少なくとも一方が n 
void solve(){ 
    int K,A,B; cin >> K >> A >> B;
    int n = A/K;
    if(A<= n*K && n*K<=B){
        cout << "OK\n"; return;
    }
    ++n;
    if(A<= n*K && n*K<=B){
        cout << "OK\n"; return;
    }
    cout << "NG\n";
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}