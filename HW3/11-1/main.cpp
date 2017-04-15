#include <iostream>

using namespace std;

void foo(char* a){
    if(a[0] != NULL){
        foo(a + 1);
        cout << a[0];
    }
}

int main()
{
    char str[99];
    cin.getline(str, 99);
    foo(str);
    cout << endl;
    return 0;
}
