#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CINA(a,n) for(int i=0, i##_len=(n); i<i##_len; ++i) cin >> a[i];
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc258/tasks/abc258_b
// スタート地点と方向を決めて直進した時最大スコアはいくらか
// 実装に注意
void solve(){ 
    int N; cin >> N;
    string board[N]; CINA(board,N);
    ll ans = 0LL;
    REP(start_x,N){
        REP(start_y,N){
            for(int dx=-1;dx<=1;++dx){
                for(int dy=-1;dy<=1;++dy){
                    if(dx==0 && dy==0) continue;
                    ll cand = 0LL;
                    REP(i,N){
                        cand *= 10;
                        int x = (start_x + dx*i + N)%N;
                        int y = (start_y + dy*i + N)%N;
                        cand += ctoi(board[x][y]);
                    }
                    chmax(ans,cand);
                }
            }
        }
    }
    cout << ans << '\n';

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}