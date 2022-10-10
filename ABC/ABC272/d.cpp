#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int,int>
#define MP make_pair
bool DEBUG = 0;
// https://atcoder.jp/contests/abc272/tasks/abc272_d
// dfs かな
// 移動可能なマスは高々O(N^2)

// 距離がちょうど sqrt(M) のマスをどう探すか
// 軸を固定して計算で調べれば O(N)

// 全体の計算量は O(N^3) となり多分いける

int step[405][405];
int N,M;
bool canGo(pii p){
    if(p.second < 1 || N < p.second) return false;
    if(step[p.first][p.second]!=-1) return false;
    return true;
}
void solve(){ 
    cin >> N >> M;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j) step[i][j] = -1;
    }
    queue<pii> q;
    q.push(MP(1,1));
    step[1][1] = 0;
    while(!q.empty()){
        pii p = q.front(); 
        q.pop();
        if(DEBUG) cout << p.first << ' ' << p.second;
        if(DEBUG) cout << ' ' << step[p.first][p.second] << '\n';

        for(int x=1;x<=N;++x){
            int X = (x-p.first)*(x-p.first);
            if(X > M) continue;
            // M = X + Y
            // Y = M - Y
            int Y = M - X;
            int candDif = sqrt(Y);
            if(candDif * candDif != Y) continue;
            pii next[2];
            next[0] = {x,p.second-candDif};
            next[1] = {x,p.second+candDif};
            for(pii np:next){
                if(!canGo(np)) continue;
                q.push(np);
                step[np.first][np.second] = step[p.first][p.second] + 1;
            }
        }
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cout << step[i][j] << (j<N?' ':'\n');
        }
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}