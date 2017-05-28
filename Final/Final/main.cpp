#include <iostream>
#include <cstdlib>

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

char func_list(void);
void Insert(void);
void List(Node *linklist);
void Find(void);
void Save(void);
void Open(void);
void free_linklist(Node *linklist);

Node *temp_linklist = 0;
Node *file_linklist = 0;
int main()
{
    while(1){
        switch(func_list()){
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
            Find();
            break;
        case 's':
        case 'S':
            Save();
            break;
        case 'o':
        case 'O':
            Open();
            break;
        case 'q':
        case 'Q':
            free_linklist(temp_linklist);
            free_linklist(file_linklist);
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
    //Node *newnode = (Node *)malloc(sizeof(Node));
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

void Find(void){

}

void Save(void){

}

void Open(void){

}

void free_linklist(Node *linklist){
    while(linklist != 0){
        Node *current = linklist;
        linklist = linklist->next;
        delete current;
    }
}
