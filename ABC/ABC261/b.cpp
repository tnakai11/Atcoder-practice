#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) for(int i=0, i##_len=(n); i<i##_len; ++i) cin >> a[i];
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc261/tasks/abc261_b
// A_{i,j} と A_{j,i} を全パターン突き合わせればOK. O(N^2)
void solve(){ 
    int N; cin >> N;
    string board[N]; CINA(board,N);
    bool ok = true;
    REP(i,N){
        for(int j=i+1;j<N;++j){
            char x = board[i][j];
            char y = board[j][i];
            if(x=='W' && y=='L') continue;
            if(x=='L' && y=='W') continue;
            if(x=='D' && y=='D') continue;
            ok = false;
            break;
        }
        if(!ok) break;
    }
    string okStr = "correct";
    string ngStr = "incorrect";
    cout << (ok?okStr:ngStr) << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}