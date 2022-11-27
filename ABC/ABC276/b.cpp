#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
// https://atcoder.jp/contests/abc276/tasks/abc276_b
// 各都市について連結リストを作る。O(NlogM +M)
vector<int> connect[100005];
void solve(){ 
    int N,M; cin >> N >> M;
    REP(count,M){
        int a,b; cin >> a >> b;
        connect[a].emplace_back(b);
        connect[b].emplace_back(a);
    }
    for(int i=1;i<=N;++i){
        sort(ALL(connect[i]));
        int d = connect[i].size();
        cout << d << ' ';
        REP(j,d){
            cout << connect[i][j];
            if(j<d-1) cout << ' ';
        }
        cout << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}