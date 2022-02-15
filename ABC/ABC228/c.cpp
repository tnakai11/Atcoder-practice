#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
#define Liny "Yes\n"
#define Linn "No\n"
#define ll long long
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc228/tasks/abc228_c
// 満点を加算したときにK位以内に入れるか
// 毎回調べ直すと O(N^2) となりきつい
// ソートしておけば O(N log N)

void solve(){ 
    int N,K; cin >> N >> K;
    vector<int> q(N);
    vector<int> r(N);
    REP(i,N){
        q[i] = 0;
        REP(j,3){
            int p; cin >> p;
            q[i] += p;
        }
        r[i] = q[i];
    }
    sort(ALL(q),greater<int>());
    for(int e:r){
        if( e + 300 >= q[K-1] ){
            cout << Liny;
        }else{
            cout << Linn;
        }
    }
    
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}