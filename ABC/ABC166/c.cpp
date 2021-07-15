#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) REP(i,(n)){ cin >> (a)[i]; }
// https://atcoder.jp/contests/abc166/tasks/abc166_c
// 展望台それぞれについて状況を探索
// 道を2回ずつ見るだけなので計算量は O(N + M)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}

int h[100005];
vector<int> neighbor[100005];

void solve(){ 
    int N,M; cin >> N >> M;
    CINA(h,N);
    REP(count,M){
        int a,b; cin >> a>> b;
        --a; --b;
        neighbor[a].emplace_back(b);
        neighbor[b].emplace_back(a);
    }
    int ans = 0;
    REP(i,N){
        bool ok = true;
        for(int x:neighbor[i]){
            if(h[x]>=h[i]) ok = false;
        }
        if(ok) ++ans;
    }
    cout << ans << '\n';
    

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}