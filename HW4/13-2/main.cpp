#include <iostream>

#define SS(X, Y)    (X * X + Y * Y)

using namespace std;

int main()
{
    int a, b;
    cin >> a;
    cin >> b;
    cout << SS(a, b) << endl;
    return 0;
}
