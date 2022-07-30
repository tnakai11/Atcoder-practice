#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int,int>
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc260/tasks/abc260_b
// 構造体のソート O(N log N)
struct score {
    int id;
    int english;
    int math;
    int sum(){
        return english + math;
    } 
};
bool compareEnglish(score s,score t){
    if(s.english==t.english) return s.id < t.id;
    return s.english > t.english;
}
bool compareMath(score s,score t){
    if(s.math==t.math) return s.id < t.id;
    return s.math > t.math;
}
bool compareSum(score s,score t){
    if(s.sum()==t.sum()) return s.id < t.id;
    return s.sum() > t.sum();
}
vector<int> pass(1005,0);

void decide(vector<score> v, int limit){
    int x = 0;
    for(auto e:v){
        if(x==limit) return;
        int i = e.id;
        if(pass[i]==1) continue;
        pass[i] = 1;
        ++x;
    }
}

void solve(){ 
    int N,X,Y,Z; 
    cin >> N >> X >> Y >> Z;
    vector<score> v(N);
    REP(i,N){
        v[i].id = i;
        cin >> v[i].math;
    }
    REP(i,N){
        cin >> v[i].english;
    }
    sort(ALL(v),compareMath);
    decide(v,X);

    sort(ALL(v),compareEnglish);
    decide(v,Y);

    sort(ALL(v),compareSum);
    decide(v,Z);

    REP(i,N){
        if(pass[i]) cout << i+1 << '\n';
    }

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}