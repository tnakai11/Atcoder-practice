#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc247/tasks/abc247_a
// 各人に対応するインデックスを一つ後にずらして出力すればOK
void solve(){ 
    string s; cin >> s;
    cout << "0";
    for(int i=0;i<3;++i){
        cout << s[i];
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
