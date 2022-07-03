#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc258/tasks/abc258_c
// 文字列をいちいち操作するとO(NQ) の時間がかかる
// 先頭に来ているインデックスを控えるのみにすればO(Q)で処理可能
void solve(){ 
    int N,Q; cin >> N >> Q;
    string s; cin >> s;
    int top = 0; // 先頭に来ている文字のインデックス
    REP(q,Q){
        int r,x; cin >> r >> x;
        if(r==1){
            top = (top-x+N)%N;
        }else{
            int y = (top+x-1)%N;
            cout << s[y] << '\n';

        }
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}