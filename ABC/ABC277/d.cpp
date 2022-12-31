#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
bool DEBUG = 0;
// https://atcoder.jp/contests/abc277/tasks/abc277_d
// 連結成分ごとに和を出して全体の和から引く
// 連結操作で計算量O(NlogN)
void solve(){ 
    ll N,M; cin >> N >> M;
    ll a[N];
    REP(i,N){
        cin >> a[i];
    }
    sort(a,a+N);
    // unite
    vector<int> neighbor[N];
    REP(i,N){
        int j = (i+1)%N;
        if(a[j]==a[i]){
            neighbor[i].emplace_back(j);
            neighbor[j].emplace_back(i);
            continue;
        }
        if(a[j]==(a[i]+1)%M){
            neighbor[i].emplace_back(j);
            neighbor[j].emplace_back(i);
            continue;
        }
    }
    // calculate
    ll allSum = 0;
    REP(i,N){ allSum += a[i]; }

    ll ans = allSum;
    vector<int> used(N,0);
    REP(start,N){
        if(used[start]) continue;
        ll subSum = 0;
        queue<int> q;
        q.push(start);
        used[start] = 1;
        while(!q.empty()){
            int index = q.front();
            q.pop();
            subSum += a[index];
            for(int next:neighbor[index]){
                if(used[next]) continue;
                q.push(next);
                used[next] = 1;
            }
        }
        chmin(ans, allSum - subSum);
    }
    // ans
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}