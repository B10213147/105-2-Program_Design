#include <iostream>

using namespace std;

int main()
{
    int min_num = 0x7fffffff, input_num;
    for(int i = 0; i < 10; i++){
        cin >> input_num;
        if(input_num < min_num){
            min_num = input_num;
        }
    }
    cout << min_num << endl;
    return 0;
}
