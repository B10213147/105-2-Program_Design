#include <iostream>

#define G(n) ({ \
    int sum = 0; \
    for(int i = 1; i <= n; i++) \
        sum += i + i + 1; \
    sum; })

using namespace std;

int main()
{
    int a;
    cin >> a;
    cout << G(a) << endl;
    return 0;
}
