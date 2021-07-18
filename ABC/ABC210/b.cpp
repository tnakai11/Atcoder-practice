#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc210/tasks/abc210_b
// 頭から見ていって最初に出た 1 の位置の偶奇で判定. O(N)
// 文字であることに注意
void solve(){ 
    int N; cin >> N;
    string s; cin >> s;
    string ans = "Aoki";
    REP(i,N){
        dprint(i);
        if(s[i]=='1'){
            if(i%2==0) ans = "Takahashi";
            break;
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}