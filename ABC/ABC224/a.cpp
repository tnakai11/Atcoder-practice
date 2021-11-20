#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc224/tasks/abc224_a
// 末尾文字の取得と if 
// contain だと erist や ister でバグりそう
void solve(){ 
    string s; cin >> s;
    int N = s.size();
    char c = s[N-1];
    string ans = "er";
    if(c=='t'){
        ans = "ist";
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}