#include <iostream>

using namespace std;

void foo(int n){
    if(n > 0){
        cout << (n % 10);
        foo(n / 10);
    }
}

int main()
{
    int input_num;
    cin >> input_num;
    foo(input_num);
    cout << endl;
    return 0;
}
