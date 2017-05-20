#include <iostream>
#include <cstdlib>

using namespace std;

struct employee{
    int ID;
    char name[20];
    int salary;
    int worked_hour;
    int paied;
};
int main()
{
    int a;
    cout << "Enter number of employees:";
    cin >> a;
    cout << endl;

    struct employee *info = (struct employee*)malloc(sizeof(struct employee) * a);
    for(int i = 0; i < a; i++){
        cout << "Enter employee no." << i + 1 << "'s name:";
        cin >> info[i].name;
        cout << "Enter employee no." << i + 1 << "'s ID:";
        cin >> info[i].ID;
        cout << "Enter employee no." << i + 1 << "'s salary:";
        cin >> info[i].salary;
        cout << "Enter employee no." << i + 1 << "'s worked hour:";
        cin >> info[i].worked_hour;
        info[i].paied = info[i].salary * info[i].worked_hour;
    }
    cout << endl << "ID\tPaied" << endl;
    for(int i = 0; i < a; i++){
        cout << info[i].ID << '\t' << info[i].paied <<endl;
    }

    free(info);
    return 0;
}
