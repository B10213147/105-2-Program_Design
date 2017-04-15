#include <iostream>

using namespace std;

int main()
{
    char alphabat[26] = {};
    cout << "Before:";
    for(int i = 0; i < 26; i++){
        alphabat[i] = 97 + i;
        cout << alphabat[i] << ' ';
    }
    cout << endl << "After:";
    for(int i = 25; i >= 0; i--){
        cout << alphabat[i] << ' ';
    }
    cout << endl;
    return 0;
}
