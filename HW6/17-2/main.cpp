#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

class Grade{
public:
    string name;
    float score;
    int rank;

    float str2float(char *str);
};

bool a_comp(Grade a, Grade b){ return a.score > b.score; }

Grade gradedata[10];
int main()
{
    fstream fp;
    fp.open("gradedata.txt", fstream::in);
    if(!fp){ return -1; }
    char line[100];
    int n_lines;
    for(int i = 0; line[0] != 0; i++){
        Grade A;
        fp.getline(line, 100, ' ');
        if(line[0] == 0){
            n_lines = i;
            break;
        }
        A.name = line;
        fp.getline(line, 100, '\n');
        A.score = A.str2float(line + 1);
        gradedata[i] = A;
    }
    fp.close();
    sort(gradedata, gradedata + n_lines, a_comp);
    cout << "Name\tScore\tRank" << endl;
    for(int i = 0; i < n_lines; i++){
        cout << gradedata[i].name << '\t' <<
        gradedata[i].score << '\t' <<
        i + 1 << endl;
    }
    fp.open("output.txt", fstream::out);
    fp << "Name\tScore\tRank" << endl;
    for(int i = 0; i < n_lines; i++){
        fp << gradedata[i].name << '\t' <<
        gradedata[i].score << '\t' <<
        i + 1 << endl;
    }
    fp.close();
    return 0;
}

float Grade::str2float(char *str){
    int dot_p, null_p;
    for(int i = 0; ; i++){
        if(str[i] == '.'){ dot_p = i; }
        if(str[i] == 0){
            null_p = i;
            break;
        }
    }
    float sum = 0;
    for(int i = 0; i < dot_p; i++){
        sum += (str[i] - '0') * pow(10, dot_p - i - 1);
    }
    for(int i = 1; i + dot_p < null_p; i++){
        sum += (str[i + dot_p] - '0') * pow(10, -i);
    }
    return sum;
}
