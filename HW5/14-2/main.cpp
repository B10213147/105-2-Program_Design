#include <iostream>

struct TV{
    char brand[10];
    int years;
    int sizes;
    int price;
};

using namespace std;

struct TV TV_Info[5] = {
    {"Sony", 1997, 17, 12300},
    {"Pan", 1998, 21, 14500},
    {"JVC", 1999, 19, 10300},
    {"CCMI", 1997, 28, 22000},
    {"PRS", 2001, 5, 5000}
};
int main()
{
    cout << "Sec. hand TV list:" << endl;
    cout << "Brand\tYears\tSizes\tPrice" << endl;
    cout << "------------------------------" << endl;
    for(int i = 0; i < 5; i++){
        cout << TV_Info[i].brand << '\t';
        cout << TV_Info[i].years << '\t';
        cout << TV_Info[i].sizes << '\t';
        cout << TV_Info[i].price << endl;
    }
    return 0;
}
