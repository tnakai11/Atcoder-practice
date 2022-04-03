#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc237/tasks/abc237_d
// RRRR -> 01234
// LLLL -> 43210
// RRLL -> 01432
// RLRL -> 02431
// データ構造で何とかする問題の気はする
// 後ろから初めて deque で構成
void solve(){ 
    int N; cin >> N;
    string s; cin >> s;
    deque<int> dq{N};
    for(int i=N-1;i>=0;--i){
        if(s[i]=='L'){
            dq.emplace_back(i);
        }else{
            dq.emplace_front(i);
        }
    }
    REP(i,N+1){
        cout << dq[i];
        cout << (i<N?' ':'\n');
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}