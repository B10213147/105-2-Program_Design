#include <iostream>
#include <cstdlib>

using namespace std;

char func_list(void);

int main()
{
    while(1){
        switch(func_list()){
        case 'i':
        case 'I':
            break;
        case 'f':
        case 'F':
            break;
        case 's':
        case 'S':
            break;
        case 'o':
        case 'O':
            break;
        case 'q':
        case 'Q':
            return 0;
            break;
        default:
            break;
        }
        system("cls");
    }
}

char func_list(void){
    cout << "i: Insert" << endl;
    cout << "l: List" << endl;
    cout << "f: Find" << endl;
    cout << "s: Save" << endl;
    cout << "o: Open" << endl;
    cout << "q: Quit" << endl;
    while(1){
        string a;
        getline(cin, a);
        if(a[1] == 0){
            switch(a[0]){
            case 'i':
            case 'I':
            case 'f':
            case 'F':
            case 's':
            case 'S':
            case 'o':
            case 'O':
            case 'q':
            case 'Q':
                return a[0];
                break;
            default:
                break;
            }
        }
        cout << "Error! Please enter again." << endl;
    }
}
