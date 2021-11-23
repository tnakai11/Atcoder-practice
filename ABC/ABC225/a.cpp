#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc225/tasks/abc225_a
// map を使って全探索する or 文字の種類数で算数 or if 文列挙
void solve(){ 
    string s; cin >> s;
    sort(ALL(s));
    char a = s[0];
    char b = s[1];
    char c = s[2];
    int ans;
    if(a==b && b==c) ans = 1;
    else if(a==b && b!=c) ans = 3;
    else if(a!=b && b==c) ans = 3;
    else if(a!=b && b!=c) ans = 6;
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}