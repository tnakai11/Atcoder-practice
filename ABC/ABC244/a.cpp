#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc244/tasks/abc244_a
// index で最後の文字を指せば終わり
// index 間違いを避けるなら
// c++ ... s.back()
// python ... s[-1]
void solve(){ 
    int N; cin >> N;
    string s; cin >> s;
    cout << s.back() << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}