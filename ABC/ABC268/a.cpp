#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
// https://atcoder.jp/contests/abc268/tasks/abc268_a
// if 文を使う場合フラグ管理などが必要でだるい
// set に入れてサイズを求めればOK
// 制約的には 0~100 の配列を用意して存在フラグを立てるのでもOK
void solve(){ 
    set<int> s;
    REP(i,5){
        int x; cin >> x;
        s.insert(x);
    }
    cout << s.size() << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}