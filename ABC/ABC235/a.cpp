#include <bits/stdc++.h>
using namespace std;
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc235/tasks/abc235_a
// 文字列として取り込んで ctoi が一番楽そう
void solve(){ 
    string s; cin >> s;
    int ans = 0;
    for(auto c:s){
        ans += ctoi(c) * 111;
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}