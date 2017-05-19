#include <iostream>

#define F(n) ({ \
    float sum = 0; \
    for(int i = 1; i <= n; i++) \
        sum += 1.0 / i; \
    sum; })

using namespace std;

int main()
{
    int a;
    cin >> a;
    cout << F(a) << endl;
    return 0;
}
