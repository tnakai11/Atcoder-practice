#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define MP make_pair
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc222/tasks/abc222_c
// 毎ラウンドソートで O(M N log N)
struct person{
    int index = 0;
    int score = 0;
};
pii janken(char x, char y){
    if(x=='G'){
        if(y=='C'){
            return MP(1,0);
        }
        if(y=='P'){
            return MP(0,1);
        }
        return MP(0,0);
    }
    if(x=='C'){
        if(y=='P'){
            return MP(1,0);
        }
        if(y=='G'){
            return MP(0,1);
        }
        return MP(0,0);
    }
    if(x=='P'){
        if(y=='G'){
            return MP(1,0);
        }
        if(y=='C'){
            return MP(0,1);
        }
        return MP(0,0);
    }
    return MP(-100,-100);
}
bool func(person p, person q){
    if(p.score!=q.score) return p.score > q.score;
    return p.index < q.index;
}

void solve(){ 
    int N,M; cin >> N >> M;
    vector<person> p(N*2);
    vector<string> a(N*2); 
    REP(i,N*2){
        cin >> a[i];
        p[i] = {i,0};
    }
    REP(i,M){
        REP(k,N){
            int x = k*2;
            int y = k*2+1;
            pii r = janken(a[ p[x].index ][i],a[ p[y].index ][i]);
            p[x].score += r.first;
            p[y].score += r.second;
        }
        sort(ALL(p),func);
    }
    for(auto x:p){
        cout << x.index + 1 << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}