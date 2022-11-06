#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
// https://atcoder.jp/contests/abc273/tasks/abc273_d
// 1マスずつシミュレーションするのは間に合わない
// 進行方向にある最近の壁を検索すれば O(Q logN)
int H,W;
map<int, vector<int>> mpr, mpc;
map<int, int> rSorted, cSorted;
void solve(){ 
    int rs, cs; 
    cin >> H >> W >> rs >> cs;
    int N; cin >> N;
    REP(count,N){
        int r,c; cin >> r >> c;
        mpr[r].push_back(c);
        mpc[c].push_back(r);
    }
    int Q; cin >> Q;
    int ansR = rs;
    int ansC = cs;
    REP(count,Q){
        char d; cin >> d;
        int l; cin >> l;
        int r = ansR;
        int c = ansC;
        if(d == 'L' || d == 'R'){
            if(rSorted[r] == 0) {
                rSorted[r] = 1;
                sort(ALL(mpr[r]));
            }
        }
        if(d == 'U' || d == 'D'){
            if(cSorted[c] == 0) {
                cSorted[c] = 1;
                sort(ALL(mpc[c]));
            }
        }
        if(d=='L' || d=='R'){
            auto neighbor = lower_bound(ALL(mpr[r]),c);
            if(d=='L'){
                int nC;
                --neighbor;
                if(mpr[r].size()>0 && neighbor >= mpr[r].begin()){
                    nC = *neighbor;
                }else{
                    nC = 0;
                }
                int nextC = max(nC+1,c-l);
                ansC = nextC;
            }else{
                int nC;
                if (neighbor != mpr[r].end()){
                    nC = *neighbor;
                }else{
                    nC = W+1;
                }
                int nextC = min(nC-1,c+l);
                ansC = nextC;
            }
        } else {
            auto neighbor = lower_bound(ALL(mpc[c]),r);
            if(d=='U'){
                int nR;
                --neighbor;
                if(mpc[c].size()> 0 && neighbor >= mpc[c].begin()){
                    nR = *neighbor;
                }else{
                    nR = 0;
                }
                int nextR = max(nR+1,r-l);
                ansR = nextR;
            } else {
                int nR;
                if (neighbor != mpc[c].end()){
                    nR = *neighbor;
                }else{
                    nR = H+1;
                }
                int nextR = min(nR-1,r+l);
                ansR = nextR;
            }
        }
        cout << ansR << ' ' << ansC << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}