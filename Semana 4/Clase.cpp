#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template<int A, int B>
auto suma() {
    return A + B;
}

template<typename T>
T triplicar_num(T x) {
    return x * 3;
}


template<typename T>
T naximo(T a,T b) {
    return a>b?a:b;
}

template<typename T, typename F>
void apply(vector<T>& v, F fun) {
    for (auto& x : v) {x=fun(x);}
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto& x : v) {os<<x<<" ";}
    os<<endl;
    return os;
}

int main() {
    cout<<naximo(3,4)<<endl;
    vector<int> d1 = {10,20,30};
    vector<double> d2 = {10.5,20.5,30.5};
    vector<int> v = {10,20,30};
    apply(v,[](int x){return x * 3;});
    apply(v,triplicar_num<int>);
    cout<<d1;
    cout<<d2;
    return 0;
}