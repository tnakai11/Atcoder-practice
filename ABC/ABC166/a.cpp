#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc166/tasks/abc166_a
// if 文でOK
char turn(char c){
    if(c=='B') return 'R';
    return 'B';
}
void solve(){ 
    string s; cin >> s;
    s[1] = turn(s[1]);
    cout << s << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}