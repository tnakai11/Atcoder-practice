#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc233/tasks/abc233_b
// 愚直に構成すれば O(|S|)
void solve(){ 
    int L,R; cin >> L >> R;
    string s,t; cin >> s;
    t = s;

    --L; --R;
    for(int i=0;i<=R-L;++i){
        int l = L + i;
        int r = R - i;
        t[l] = s[r];
    }
    cout << t << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}