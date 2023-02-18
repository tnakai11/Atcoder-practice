#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc285/tasks/abc285_b
// 愚直に判定してもO(N^2)なので十分間に合いそう
void solve(){ 
    int N; cin >> N;
    string s; cin >> s;
    for(int i=1;i<=N-1;++i){
        int l = 0;
        for(int k=0;k+i<N;++k){
            if(s[k]!=s[k+i]){
                ++l;
            }else{
                break;
            }
        }
        cout << l << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}