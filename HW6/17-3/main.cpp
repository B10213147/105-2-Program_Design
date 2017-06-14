#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fp;
    fp.open("graph.txt", fstream::in);
    if(!fp){ return -1; }
    char line[100];
    fp.getline(line, 100, '\n');
    cout << "The martix in file graph.txt:" << endl;
    for(int i = line[0] - '0'; i > 0; i--){
        fp.getline(line, 100, '\n');
        cout << line << endl;
    }
    fp.close();
    return 0;
}
