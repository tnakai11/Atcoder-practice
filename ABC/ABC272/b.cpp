#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
// https://atcoder.jp/contests/abc272/tasks/abc272_b
// 各人について同じ舞踏会に参加した人を記録した後総当たりで検証
// 時間計算量は O(N^2 M)
int together[105][105];
void solve(){ 
    int N,M; cin >> N >> M;
    REP(i,N) REP(j,N) together[i][j] = 0;
    REP(turn,M){
        int k; cin >> k;
        vector<int> v(k);
        REP(i,k){
            cin >> v[i];
            --v[i];
        }
        REP(i,k){
            int x = v[i];
            for(int j=i+1;j<k;++j){
                int y = v[j];
                together[x][y] = 1;
            }
        }
    }
    bool ok = true;
    REP(x,N){
        for(int y=x+1;y<N;++y){
            if(together[x][y]==0){
                ok = false;
                break;
            }
        }
    }
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}