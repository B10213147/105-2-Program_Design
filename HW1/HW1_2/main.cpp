#include <iostream>

using namespace std;

int main()
{
    int input_num, digit, sum;

    while(1){
        cin >> input_num;
        if(input_num < 1){
            cout << "The number is smaller than 1, ";
            cout << "please input again!!!" << endl;
        }
        else break;
    }

    for(digit = 0, sum = 0; input_num > 0; digit++){
        sum += input_num % 10;
        input_num /= 10;
    }

    cout << "Digit = " << digit << endl;
    cout << "Sum = " << sum << endl;

    return 0;
}
