#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc260/tasks/abc260_a
// map が一番楽
void solve(){ 
    string s; cin >> s;
    map<char,int> mp;
    for(char c:s) ++mp[c];
    char ans = 'A';
    for(char c:s){
        if(mp[c]==1) ans = c;
    }
    if(ans=='A'){
        cout << -1 << '\n';
    }else{
        cout << ans << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}