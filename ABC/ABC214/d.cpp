#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc214/tasks/abc214_d
// 頂点同士を調べるには時間が足りない
// 重み最大の辺で木を分割していけば高々枝数回の計算で求まりそう
// TLE 分割の度にサイズを見るのがやや重い
// 解説を見る
// 重み最小の辺から順に構成すれば UnionFind で解ける

struct edge
{
    int u,v,w;
};

const int MAX = 100005;
edge e[MAX];

// vector<int> neigh[MAX];
// map<int,int> cut[MAX];

// bool func(edge a,edge b){
//     return a.w > b.w;
// }
// ll bfs(int root){
//     ll res = 0;
//     queue<int> q;
//     map<int,int> mp;
//     q.push(root);
//     while( !q.empty() ){
//         int cur = q.front();
//         mp[cur] = 1;
//         res += 1;
//         q.pop();
//         for(auto next:neigh[cur]){
//             if(mp[next]) continue;
//             if(cur<next){
//                 if(cut[cur][next]) continue;
//             }else{
//                 if(cut[next][cur]) continue;
//             }
//             q.push(next);
//         }
//     }
//     return res;
// }

// void solveTLE(){ 
//     int N; cin >> N;
//     REP(i,N-1){
//         int u,v,w; cin >> u >> v >> w;
//         e[i].u = u;
//         e[i].v = v;
//         e[i].w = w;
//         neigh[u].emplace_back(v);
//         neigh[v].emplace_back(u);
//     }
//     sort(e,e+N,func);
//     ll ans = 0LL;
//     REP(i,N-1){
//         edge x = e[i];
//         int u = x.u;
//         int v = x.v;
//         int w = x.w;
//         if(u>v) swap(u,v);
//         cut[u][v] = 1;
//         ans += w * bfs(u) * bfs(v);
//         dprint(ans);
//     }
//     cout << ans << '\n';
// }

struct UnionFind{
    vector<int> par,s;
    UnionFind(int N) : par(N),s(N){
        REP(i,N){
            par[i] = i;
            s[i] = 1;
        }
    }
    int root(int x){
        if(par[x]==x){ return x; }
        else{ 
          par[x]= root(par[x]);
          return par[x];
        }
    }
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if( rx!=ry ){
            par[rx] = ry;
            s[ry] += s[rx];
        }
    }
    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return (rx==ry);
    }
    int size(int x){
        int rx = root(x);
        return s[rx];
    }
};

bool func2(edge a, edge b){
    return a.w < b.w;
}

void solve(){
    int N; cin >> N;
    int M = N-1;
    REP(i,M){
        cin >> e[i].u;
        cin >> e[i].v;
        cin >> e[i].w;
        --e[i].u;
        --e[i].v;
    }
    sort(e,e+M,func2);

    ll ans = 0LL;
    UnionFind uft = UnionFind(N);
    REP(i,M){
        int u = e[i].u;
        int v = e[i].v;
        int w = e[i].w;
        ans += w * (ll)uft.size(u) * (ll)uft.size(v);
        uft.unite(u,v);
    }
    cout << ans << '\n';
}

int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}