#include <iostream>

using namespace std;

int main()
{
    bool flag;
    int a, b;

    // Enter two integer.
    cin >> a;
    cin >> b;

    // Make sure a is smaller than b.
    if(a > b){
        int tmp = a;
        a = b;
        b = tmp;
    }

    // Find prime numbers out.
    for(int i = a; i < b; i++){
        flag = true;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                flag = false;
                break;
            }
        }
        if(flag != false){
            cout << i << " ";
        }
    }

    return 0;
}
