#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc230/tasks/abc230_b
// oxx を十分量つなげてパターンマッチ
// 開始文字は o, x1, x2 の3パターンあり得る
// |S| <= 10 より t の長さが 12 以上であれば取りこぼしがなくなる
void solve(){ 
    string s; cin >> s;
    string t = "";
    REP(i,4) t += "oxx";
    bool ok = regex_search(t,regex(s));
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}