#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0; i<n; i++)
#define repl(i,n) for(i=1; i<=n; i++)

#define sz(x) (int) x.size()
#define pb push_back
#define all(x) x.begin(),x.end()
#define uu first
#define vv second
#define mem(x, y) memset(x, y, sizeof(x))
#define un(x) x.erase(unique(all(x)), x.end())

#define sdi(x) scanf("%d", &x)
#define sdii(x, y) scanf("%d %d", &x, &y)
#define sdiii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sdl(x) scanf("%lld", &x)
#define sdll(x, y) scanf("%lld %lld", &x, &y)
#define sdlll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sds(x) scanf("%s", x)
#define pfi(x) printf("%d\n", x)
#define pfii(x, y) printf("%d %d\n", x, y)
#define pfiii(x, y, z) printf("%d %d %d\n", x, y, z)
#define pfl(x) printf("%lld\n", x)
#define pfll(x, y) printf("%lld %lld\n", x, y)
#define pflll(x, y, z) printf("%lld %lld %lld\n", x, y, z)

#define eps 1e-9
#define OK cerr << "ok\n"
#define DB(x) cerr << #x << " = " << x << endl

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int, int> pii;

inline int setBit(int N, int pos) { return N=N | (1<<pos); }
inline int resetBit(int N, int pos) { return N= N & ~(1<<pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1<<pos)); }

//int kx[] = {+2, +1, -1, -2, -2, -1, +1, +2};
//int ky[] = {+1, +2, +2, +1, -1, -2, -2, -1}; //Knight Direction
//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction


const int MAX = 400005;
string arr[MAX];
unordered_map <LL, int> mapp[MAX];
unordered_map <int, int> lenList;
int n, last_yes;
char str[MAX];

struct simplehash{
    int len;
    long long base, mod;
    vector <int> P, H;

    simplehash(){}
    inline simplehash(const char* str, long long b, long long m){
        base = b, mod = m, len = strlen(str);
        P.resize(len + 3, 1), H.resize(len + 3, 0);

        for (int i = 1; i <= len; i++) P[i] = (P[i - 1] * base) % mod;
        for (int i = 1; i <= len; i++) H[i] = (H[i - 1] * base + str[i - 1] + 1007) % mod;
    }

    inline void update(char c) {
        len++;
        P.pb(0);
        H.pb(0);
        P[len] = (P[len - 1] * base) % mod;
        H[len] = (H[len - 1] * base + c + 1007) % mod;
    }

    inline int range_hash(int l, int r){
        int hashval = H[r + 1] - ((long long)P[r - l + 1] * H[l] % mod);
        return (hashval < 0 ? hashval + mod : hashval);
    }
};

struct stringhash{
    simplehash sh1, sh2;
    stringhash(){}
    inline stringhash(const char* str){
        sh1 = simplehash(str, 1949313259, 2091573227);
        sh2 = simplehash(str, 1997293877, 2117566807);
    }

    inline void update(char c) {
        sh1.update(c);
        sh2.update(c);
    }

    inline long long range_hash(int l, int r){
        return ((long long)sh1.range_hash(l, r) << 32) ^ sh2.range_hash(l, r);
    }
} hashList[MAX], sh;

void init() {
    int i;
    rep(i, n) {
        int len = sz(arr[i]);
        hashList[i] = stringhash(arr[i].c_str());
        LL h = hashList[i].range_hash(0, len-1);
        mapp[len][h]++;
        lenList[len]++;
    }
}

inline bool query(int idx) {
    int i, len = strlen(str);
    rep(i, len) {
        int now = str[i]-'a';
        now += last_yes;
        now %= 26;
        str[i] = now+'a';
    }
    sh = stringhash(str);
    for(auto x:lenList) {
        rep(i, len) {
            if(i+x.uu-1 >= len) break;
            LL h = sh.range_hash(i, i+x.uu-1);
            if(mapp[x.uu].find(h) == mapp[x.uu].end()) continue;
            if(mapp[x.uu][h] > 0) {
                last_yes = idx;
                return true;
            }
        }
    }
    return false;
}

inline void update(int idx, int alpha) {
    idx += last_yes;
    idx %= n;
    int len = sz(arr[idx]);
    LL h = hashList[idx].range_hash(0, len-1);
    int cnt = --mapp[len][h];
    if(cnt == 0) mapp[len].erase(h);
    cnt = --lenList[len];
    if(cnt == 0) lenList.erase(len);
    alpha += last_yes;
    alpha %= 26;
    char c = alpha + 'a';
    arr[idx] += c;
    len++;
    hashList[idx].update(c);
    h = hashList[idx].range_hash(0, len-1);
    mapp[len][h]++;
    lenList[len]++;
}

int main() {
//    assert(freopen("in.txt","r",stdin));
//    assert(freopen("out.txt","w",stdout));

    int i, q, com, idx, alpha;

    sdii(n, q);
    rep(i, n) {
        sds(str);
        arr[i] = str;
    }
    init();
    rep(i, q) {
        sdi(com);
        if(com == 1) {
            sds(str);
            puts(query(i)? "YES" : "NO");
        }
        else {
            sdii(idx, alpha);
            update(idx, alpha);
        }
    }

    return 0;
}
