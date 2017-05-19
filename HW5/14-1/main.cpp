#include <iostream>

using namespace std;

int add(int a, int b){
    if(a > b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    return (a + b) * (b - a + 1) / 2;
}
int main()
{
    cout << add(1, 9) << endl;
    return 0;
}
