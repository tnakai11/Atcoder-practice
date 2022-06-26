#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define MP make_pair
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc256/tasks/abc256_d
// 愚直に調べるとO(N^2)であり厳しい
// Lの値でソートして左から繋いでいくのが良さそう
// ソートがボトルネックになって O(N log N)
// 謎のRE
// N=100 でセグメントフォールド
// struct から pair<int,int> に置き換え
// AC
void solve(){ 
    // input
    int N; cin >> N;
    vector<pii> v; 
    REP(i,N){
        int L,R; cin >> L >> R;
        v.emplace_back(MP(L,R));
    }
    // setup
    sort(ALL(v));
    vector<pii> u;
    
    // unite
    for(pii k:v){
        if(u.size()==0 || u.back().second < k.first){
            u.push_back(k);
        }else{
            chmax(u.back().second,k.second);
        }
    }

    // answer
    for(pii k:u){
        printf("%d %d\n",k.first,k.second);
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}