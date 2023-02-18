#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
// https://atcoder.jp/contests/abc284/tasks/abc284_a
// 配列に格納して逆順に出力すればOK
// スタックを使うとかでもよさそう
void solve(){ 
    int N; cin >> N;
    string s[N];
    REP(i,N) {
        cin >> s[i];
    }
    for(int i=N-1;i>=0;--i){
        cout << s[i] << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}