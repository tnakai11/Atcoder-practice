#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc224/tasks/abc224_d
// 紙で動かしてみたもののよく分からん

// 解説を読む
// 可能な状態の幅優先全探索
vector<int> neighbor[10];
void solve(){ 
    int M; cin >> M;
    REP(count,M){
        int u,v; cin >> u >> v;
        neighbor[u].push_back(v);
        neighbor[v].push_back(u);
    }
    string start = "0" + string(9,'9');
    for(char j='1';j<='8';++j){
        int p; cin >> p;
        start[p] = j;
    }
    dprint(start);

    queue<string> q;
    map<string,int> mp;
    map<string,int> visit;
    mp[start] = 0;
    visit[start] = 1;
    q.push(start);

    string goal = "0123456789";
    while(!q.empty()){
        string state = q.front(); q.pop();
        int vd;
        for(int i=1;i<=9;++i){
            if(state[i]=='9') {
                vd = i; break;
            }
        }
        for(auto x:neighbor[vd]){
            string next = state;
            swap(next[vd], next[x]);
            if( visit[next] ) continue;
            mp[next] = mp[state] + 1;
            visit[next] = 1;
            q.push(next);
            dprint(next);
            dprint(mp[next]);
        }
        if(visit[goal]) break;
    }

    int ans = mp[goal];
    if( visit[goal] == 0 ) ans = -1;
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}