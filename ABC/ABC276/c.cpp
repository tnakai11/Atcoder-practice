#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
template<class T> void printVec(vector<T> v){ int v_size = v.size(); int i = 0; for(const auto & e:v){ cout << e << (i<v_size-1?' ':'\n'); ++i; } }
// https://atcoder.jp/contests/abc276/tasks/abc276_c
// 愚直に比較しようとすると最大100! パターン生成することになるので厳しい
// 元の順列より1小さい順列を見つける問題なら解けそう
// 4,3,2,1
// 4,3,1,2
// 4,2,3,1
// 4,2,1,3
// 4,1,3,2
// 4,1,2,3
// 3,2,4,1
// 3,2,1,4
// 一番下をひっくり返す
// 無理なら一つ上の値を最低限下げて余りで降順
// 無理ならさらに一つ上の値を最低限下げて余りで降順
int N;
void solve(){ 
    // setup
    cin >> N;
    vector<int> p(N);
    REP(i,N){
        cin >> p[i];
    }
    vector<int> ans(N);
    for(int i=N-2;i>=0;--i){
        vector<int> used(101,0);
        REP(j,i){
            used[ p[j] ] = 1;
        }
        int ansIValue = p[i]-1;
        while(ansIValue>0 && used[ansIValue]==1){
            --ansIValue;
        }
        if(ansIValue==0) continue;

        // make answer
        REP(j,i){
            ans[j] = p[j];
        }
        ans[i] = ansIValue;
        used[ansIValue] = 1;
        int nextV = N;
        for(int j=i+1;j<N;++j){
            while(used[nextV]==1) --nextV;
            ans[j] = nextV;
            used[nextV] = 1;
        }
        break;
    }
    printVec(ans);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}