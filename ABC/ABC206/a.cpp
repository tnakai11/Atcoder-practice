#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc206/tasks/abc206_a
// 小数点以下切り捨て
// intの形で計算してから必要な部分だけ取り出すと安心
void solve(){ 
    int N; cin >> N;
    int x = 108*N/100;
    string ans = ":(";
    if(x<206){
        ans = "Yay!";
    }else if(x==206){
        ans = "so-so";
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}