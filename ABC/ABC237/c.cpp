#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc237/tasks/abc237_c
// a---a ... ---を調べる
// ---a ... --- を調べる
// a--- ... a--- を調べる
void solve(){ 
    string s; cin >> s;
    int l = 0;
    int r = s.size()-1;
    bool ok = true;
    while(s[l]=='a' && l<=r){
        if(s[r]!='a'){
            break;
        }
        ++l; --r;
    }
    while(s[r]=='a' && l<=r){
        --r;
    }
    while(l<=r){
        if(s[l]!=s[r]){
            ok = false;
        }
        ++l; --r;
    }
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}