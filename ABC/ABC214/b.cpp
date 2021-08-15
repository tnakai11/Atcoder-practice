#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc214/tasks/abc214_b
// a+b+c<=100 より高々 10^6 パターン調べれば OK
// 重複を省けばより少ないパターンを調べるので済む
void solve(){ 
    int S,T; cin >> S >> T;
    int ans = 0;
    for(int a=0;a<=S;++a){
        for(int b=0;b<=a;++b){
            for(int c=0;c<=b;++c){
                if(a+b+c>S) break;
                if(a*b*c>T) break;
                if(a==b && b==c) ans += 1;
                else if(a==b || b==c) ans += 3;
                else ans += 6;
            }
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}