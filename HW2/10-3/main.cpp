#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int nums[10];
    srand(time(NULL));
    cout << "Before:";
    for(int i = 0; i < 10; i++){
        nums[i] = rand() % 99 + 1;
        cout << nums[i] << ' ';
    }
    for(int i = 10 - 1; i >= 0; i--){
        int inew = 0;
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[j+1]){
                int tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
                inew = j + 1;
            }
        }
        i = inew;
    }
    cout << endl << "After:";
    for(int i = 0; i < 10; i++){
        cout << nums[i] << ' ';
    }
    cout << endl;
    return 0;
}
