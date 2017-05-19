#include <iostream>

using namespace std;

int main()
{
    char a[99];
    cin.getline(a, 99);
    for(int i = 0; a[i] != 0; i++){
        if((a[i] >= 'a') && (a[i] <= 'z')){
            a[i] -= 32;
        }
        else if((a[i] >= 'A') && (a[i] <= 'Z')){
            a[i] += 32;
        }
    }
    cout << a << endl;
    return 0;
}
