#include <iostream>

using namespace std;

int a_array[3][5]={{2,3,4,5,6},{7,8,9,10,11},{12,13,14,15,16}};
int main()
{
    for(int i = 0; i < 3; i++){
        int *ptr0 = a_array[i];
        for(int j = 0; j < 5; j++){
            cout << *(ptr0 + j) << ", ";
        }
        cout << endl;
    }
    return 0;
}
