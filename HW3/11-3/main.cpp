#include <iostream>

using namespace std;

int main()
{
    char str[99];
    cin.getline(str, 99);
    int nul_pos;
    for(int i = 0; i < 99; i++){
        if(str[i] == 0){
            nul_pos = i;
            break;
        }
    }
    for(int i = nul_pos; i > 0; i--){
        int inew = 0;
        for(int j = 0; j < i; j++){
            if(str[j] == ' '){
                int tmp = str[j];
                str[j] = str[j+1];
                str[j+1] = tmp;
                inew = j + 1;
            }
        }
        if(inew != 0){
            str[inew] = NULL;
        }
        i = inew;
    }
    cout << str << endl;
    return 0;
}
