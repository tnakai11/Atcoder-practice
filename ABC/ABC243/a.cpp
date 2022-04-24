#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc243/tasks/abc243_a
// 人数をKとして O(VK)で愚直に調査できる
// 先にA+B+Cの塊を省いておけばO(K)
void solve(){ 
    int a[3];
    char name[3] = {'F','M','T'};

    int V; cin >> V;
    int block = 0;
    REP(i,3) {
        cin >> a[i];
        block += a[i];
    }

    V -= block * (V/block);

    REP(i,3){
        V -= a[i];
        if(V<0){
            cout << name[i] << '\n';
            break;
        }
    }

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}