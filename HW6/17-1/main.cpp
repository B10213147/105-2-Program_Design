#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fp;
    fp.open("abc.txt", fstream::in);
    if(!fp){ return -1; }
    char line[100];
    fp.getline(line, 100, '\t');
    fp.close();
    cout << "Data in abc.txt:" << endl;
    cout << line << endl;
    cout << "After remove numbers:" << endl;
    for(int i = 0; line[i] != 0; i++){
        if(!(line[i] >= '0' && line[i] <= '9')){
            cout << line[i];
        }
    }
    return 0;
}
