#include <bits/stdc++.h>
using namespace std;
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc248/tasks/abc248_a
// ctoi で char -> int 変換
// Sum_i=0^i=9 i = 45 から出てきた数を引いたものが答えになる 
void solve(){ 
    string s; cin >> s;
    int ans = 45;
    for(char c:s){
        ans -= ctoi(c);
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}