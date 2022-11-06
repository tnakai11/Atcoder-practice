#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
#define pii pair<int,int>
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
// https://atcoder.jp/contests/abc275/tasks/abc275_a
// for文を2回回せばOK O(N^2)
// 計算量的に厳しい場合はindexをつけてソート O(NlogN)
int N;
pii p[105];
bool func(pii x, pii y){
    return x.second>y.second;
}
void solve(){ 
    cin >> N;
    for(int i=0;i<N;++i){
        int h; cin >> h;
        p[i] = MP(i+1,h);
    }
    sort(p,p+N,func);
    int ans = p[0].first;
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}