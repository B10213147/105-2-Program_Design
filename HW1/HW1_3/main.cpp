#include <iostream>

using namespace std;

char password[4] = {'6', '2', '5', '1'};
int main()
{
    int failure_n = 1;
    while(failure_n < 4){
        if(failure_n == 1){
            cout << "Enter 1 time." << endl;
        }
        else{
            cout << "Enter " << failure_n << " times." << endl;
        }
        cout << "Please enter a 4 digits number. ";
        cout << "Press Enter after u finish." << endl;
        char str[256];
        cin.getline(str, 256);
        // If input's digit is bigger than
        // password's digit, means wrong.
        if(str[4] != 0){
            cout << "Wrong!" << endl;
            failure_n++;
        }
        else{ // Enter 4, or less, digits number.
            if(str[0] == password[0] &&
               str[1] == password[1] &&
               str[2] == password[2] &&
               str[3] == password[3]){
                cout << "Welcome~" << endl;
                break;
            }
            else{
                cout << "Wrong!" << endl;
                failure_n++;
            }
        }
    }

    if(failure_n > 3){
        cout << "Triple errors, please contact Service Staff." << endl;
    }

    return 0;
}
