#include <bits/stdc++.h>
using namespace std;
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc219/tasks/abc219_b
// Sを配列に置いておいて指示順に出力するだけ
void solve(){ 
    string s[4];
    for(int i=1;i<=3;++i){
        cin >> s[i];
    }
    string t; cin >> t;
    for(char c:t){
        cout << s[ctoi(c)];
    }
    cout << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}