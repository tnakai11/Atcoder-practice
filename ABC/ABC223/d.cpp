#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int,int>
#define MP make_pair
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc223/tasks/abc223_d
// 左側に制限がなく小さい数から順に埋めていく
// O(N+M)？
// TLE
// vector をいちいち変更するのがマズそう
void solve(){ 
    int N,M; cin >> N >> M;

    vector<int> from[N+1];
    vector<int> d(N+1,0);
    map<pii,int> mp;
    REP(count,M){
        int a,b; cin >> a >> b;
        pii checker = MP(a,b);
        if(mp[checker]>0) continue;
        ++mp[checker];
        from[a].push_back(b);
        ++d[b];
    }
    
    priority_queue<int, vector<int>, greater<int> > q;
    for(int a=1;a<=N;++a){
        if(d[a]==0) q.push(a);
    }

    vector<int> ans;
    while( !q.empty() ){
        int a = q.top(); 
        q.pop();
        ans.push_back(a);
        for(auto b:from[a]){
            --d[b];
            if(d[b]==0) q.push(b);
        }
    }
    bool ok = ans.size()==N;
    if(ok){
        REP(i,N){
            cout << ans[i] << (i<N-1?' ':'\n');
        }
    }else{
        cout << -1 << '\n';
    }
}

int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}