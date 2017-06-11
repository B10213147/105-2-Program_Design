#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class Info{
public:
    string name, phone, mail;
};

class Node{
public:
    Info data;
    Node *next;
};

char func_menu(void);
void Insert(void);
void List(Node *linklist);
void Find(Node *linklist);
void Save(Node *writelist);
void Open(void);
void free_linklist(Node **linklist);

Node *temp_linklist = 0;
Node *file_linklist = 0;
int main()
{
    while(1){
        switch(func_menu()){
        case 'i':
        case 'I':
            Insert();
            break;
        case 'l':
        case 'L':
            List(temp_linklist);
            break;
        case 'f':
        case 'F':
            Find(file_linklist);
            break;
        case 's':
        case 'S':
            Save(temp_linklist);
            break;
        case 'o':
        case 'O':
            Open();
            break;
        case 'q':
        case 'Q':
            free_linklist(&temp_linklist);
            free_linklist(&file_linklist);
            return 0;
            break;
        default:
            break;
        }
    }
}

char func_menu(void){
    system("cls");
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
            case 'l':
            case 'L':
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

void Insert(void){
    system("cls");
    Node *newnode = new Node;
    newnode->next = 0;

    cin.clear();
    cout << "Input name:";
    getline(cin, newnode->data.name);
    cout << "Input phone number:";
    getline(cin, newnode->data.phone);
    cout << "Input Email:";
    getline(cin, newnode->data.mail);

    if(temp_linklist == 0){
        temp_linklist = newnode;
    }
    else{
        Node *current;
        for(current = temp_linklist; \
            current->next != 0; \
            current = current->next);
        current->next = newnode;
    }
}

void List(Node *linklist){
    system("cls");
    if(linklist != 0){
        for(int i = 1; linklist != 0; linklist = linklist->next, i++){
            cout << "Number " << i << ':' << endl;
            cout << linklist->data.name << endl;
            cout << linklist->data.phone << endl;
            cout << linklist->data.mail << endl;
            cout << "====================" << endl;
        }
    }
    cin.get();
}

void Find(Node *linklist){
    system("cls");
    string enteredname;
    cin.clear();
    cout << "Please enter a friend's name:";
    getline(cin, enteredname);

    while(linklist != 0){
        if(linklist->data.name == enteredname){
            cout << linklist->data.name << '\t';
            cout << linklist->data.phone << '\t';
            cout << linklist->data.mail << endl;
            cin.get();
            return;
        }
        linklist = linklist->next;
    }
    cout << "Cannot find this name!" << endl;
    cin.get();
}

void Save(Node *writelist){
    system("cls");
    string filename;
    cin.clear();
    cout << "Please enter a file name:";
    getline(cin, filename);

    fstream fp;
    fp.open(filename.c_str(), fstream::out | fstream::app);
    while(writelist != 0){
        fp << writelist->data.name << '\t';
        fp << writelist->data.phone << '\t';
        fp << writelist->data.mail << endl;
        writelist = writelist->next;
    }
    fp.close();
}

void Open(void){
    system("cls");
    string filename;
    cin.clear();
    cout << "Please enter a file name:";
    getline(cin, filename);

    char line[100];
    fstream fp;
    fp.open(filename.c_str(), fstream::in);
    if(!fp.fail()){
        free_linklist(&file_linklist);
        while(fp.getline(line, sizeof(line), '\t')){
            Node *newnode = new Node;
            newnode->next = 0;
            newnode->data.name = line;
            fp.getline(line, sizeof(line), '\t');
            newnode->data.phone = line;
            fp.getline(line, sizeof(line), '\n');
            newnode->data.mail = line;

            if(file_linklist == 0){
                file_linklist = newnode;
            }
            else{
                Node *current;
                for(current = file_linklist; \
                    current->next != 0; \
                    current = current->next);
                current->next = newnode;
            }
        }
        List(file_linklist);
    }
    else{   // Open file failure
        cout << "Can't find the file." <<endl;
        cin.get();
    }
    fp.close();
}

void free_linklist(Node **linklist){
    while(*linklist != 0){
        Node *current = *linklist;
        *linklist = (*linklist)->next;
        delete current;
    }
}
