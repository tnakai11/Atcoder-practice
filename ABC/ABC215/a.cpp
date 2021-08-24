#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc215/tasks/abc215_a
// やるだけ
void solve(){
    string s; cin >> s;
    string t = "Hello,World!";
    string ans;
    if(s==t){
        ans = "AC";
    }else{
        ans = "WA";
    }
    cout << ans <<'\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}