#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc216/tasks/abc216_b
// 姓,名でソートしてから調べれば O(N) で判定可能
// ソートが必要なので全体では O(N log N)
// 今回の設定なら全探索でもたぶん間に合う
// 文字列連結対策で aab ccd さんと aa bccd さんがいるテストケースとかありそう
#define pss pair<string,string>
void solve(){ 
    int N; cin >> N;
    vector<pss> v(N);
    REP(i,N){
        cin >> v[i].first >> v[i].second;
    }
    sort(ALL(v));
    bool ans = false;
    REP(i,N-1){
        if(v[i].first==v[i+1].first && v[i].second==v[i+1].second){
            ans = true;
            break;
        }
    }
    cout << (ans?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}