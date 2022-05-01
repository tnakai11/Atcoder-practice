#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc244/tasks/abc244_c
// 未宣言の数をストックしておいて相手が宣言した数の表と付き合わせれば O(N log N) 程度でOK
void solve(){ 
    int N; cin >> N;
    int M = N*2 + 1;
    vector<int> v(M);
    for(int i=1;i<=M;++i){
        v[i-1] = i;
    }
    mt19937 get_rand_mt(501);
    shuffle(ALL(v),get_rand_mt);

    int index = 0;
    map<int,int> mp;
    while(index<M){
        int x = v[index];
        ++index;
        if( mp[x] ) continue;
        ++mp[x];
        cout << x << endl;
        int y; cin >> y;
        if(y==0) break;
        ++mp[y];
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}