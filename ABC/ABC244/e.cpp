#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc244/tasks/abc244_e
// なぜ桃鉄？
// 貧乏神を回避する経路の探索か...
// 3次元dpでいける?
// dp[a][b][c] ...  a 移動目でマス b にたどり着き X 通過数は c%2 回であるパターンの数
vector<int> connect[2005];
mint dp[2005][2005][2];
map<int,int> mp;
vector<int> v;
void solve(){ 
    int N,M,K,S,T,X;
    cin >> N >> M >> K >> S >> T >> X;
    REP(i,M){
        int u,v; cin >> u >> v;
        connect[u].emplace_back(v);
        connect[v].emplace_back(u);
    }

    dp[0][S][0] = 1;
    v.emplace_back(S);
    ++mp[S];
    for(int a=1;a<=K;++a){
        vector<int> w;
        for(int from:v){
            if(from==X){
                for(int to: connect[from]){
                    dp[a][to][0] += dp[a-1][from][1];
                    dp[a][to][1] += dp[a-1][from][0];
                    if(mp[to]==0){
                        w.emplace_back(to);
                        ++mp[to];
                    }
                }
            }else{
                for(int to: connect[from]){
                    dp[a][to][0] += dp[a-1][from][0];
                    dp[a][to][1] += dp[a-1][from][1];
                    if(mp[to]==0){
                        w.emplace_back(to);
                        ++mp[to];
                    }
                }
            }
        }
        for(auto to:w){
            v.emplace_back(to);
        }
    }
    if(DEBUG){
        REP(i,N+1) cout << mp[i] << ' ';
        cout << endl;
    }
    cout << dp[K][T][0].val() << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}