#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct todolist
{
    int id;
    string task;
};

int ID = 0;
void banner();
void addTask();
void viewTask();
int searchTask();
void removeTask();
void markTaskComplete();
void initializeID();

int main()
{
    system("cls");
    initializeID();
    while(true)
    {
        banner();
        cout<<"\n\t 1.Add Task";
        cout<<"\n\t 2.View Task";
        cout<<"\n\t 3.Search Task";
        cout<<"\n\t 4.Remove Task";
        cout<<"\n\t 5.Mark Task Complete";

        int Task_Input;
        cout << "\n\t Enter Input Task : ";
        cin >> Task_Input;
        switch(Task_Input)
        {
            case 1:
                addTask();
                break;
            case 2:
                viewTask();
                break;
            case 3:
                searchTask();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                markTaskComplete();
                break;
            default:
                break;
        }
    }
    return 0;
}

void banner()
{
    cout<<"______________________________________________________________________"<<endl;
    cout<<"                       ~My To-Do List Project~                        "<<endl;
    cout<<"______________________________________________________________________"<<endl;
}

void initializeID()
{
    ifstream fin("to do list file.txt");
    todolist todo;
    while(fin >> todo.id)
    {
        fin.ignore();
        getline(fin, todo.task);
        if(todo.id > ID)
        {
            ID = todo.id;
        }
    }
    fin.close();
}

void addTask()
{
    system("cls");
    banner();
    todolist todo;
    cout<<"Enter new task : ";
    cin.get();
    getline(cin, todo.task);
    char save;
    cout << "Save?(Y/N) : ";
    cin >> save;
    if(toupper(save) == 'Y')
    {
        ID++;
        ofstream fout;
        fout.open("to do list file.txt", ios::app);
        fout << ID << "\n" << todo.task << "\n";
        fout.close();

        char more;
        cout<<"Add more task? (Y/N) : ";
        cin>>more;

        if(toupper(more) == 'Y')
        {
            addTask();
        }
        else
        {
            system("cls");
            cout<<"Added Successfully!!!"<<endl;
        }
    }
    system("cls");
}

void viewTask()
{
    system("cls");
    banner();
    todolist todo;
    ifstream fin("to do list file.txt");
    cout<<"Task : "<<endl;

    while(fin >> todo.id)
    {
        fin.ignore();
        getline(fin, todo.task);
        cout<<"\t"<<todo.id<<" : "<<todo.task<<endl;
    }
    fin.close();
    char exit;
    cout<<"Exit?(Y/N) : ";
    cin>>exit;
    if(toupper(exit) != 'Y')
    {
        viewTask();
    }
    system("cls");
}

int searchTask()
{
    system("cls");
    banner();
    int id;
    cout<<"Enter task id : ";
    cin >> id;
    todolist todo;
    ifstream fin("to do list file.txt");
    while(fin >> todo.id)
    {
        fin.ignore();
        getline(fin, todo.task);
        if(todo.id == id)
        {
            system("cls");
            cout<<"\t"<<todo.id<<" : "<<todo.task<<endl;
            return id;
        }
    }
    system("cls");
    cout<<"Not Found!!!"<<endl;
    return 0;
}

void removeTask()
{
    system("cls");
    int id = searchTask();
    if(id != 0)
    {
        char rem;
        cout<<"\n\t Remove?(Y/N) :";
        cin >> rem;
        if(toupper(rem) == 'Y')
        {
            todolist todo;
            ofstream tempFile("temp file.txt");
            ifstream fin("to do list file.txt");
            while(fin >> todo.id)
            {
                fin.ignore();
                getline(fin, todo.task);
                if(todo.id != id)
                {
                    tempFile << todo.id << "\n" << todo.task << "\n";
                }
            }
            fin.close();
            tempFile.close();
            remove("to do list file.txt");
            rename("temp file.txt", "to do list file.txt");
            system("cls");
            cout<<"\n Removed Successfully!"<<endl;
        }
    }
}

void markTaskComplete()
{
    system("cls");
    int id = searchTask();
    if(id != 0)
    {
        char mark;
        cout<<"\n\t Mark as complete?(Y/N) :";
        cin >> mark;
        if(toupper(mark) == 'Y')
        {
            todolist todo;
            ofstream tempFile("temp file.txt");
            ifstream fin("to do list file.txt");
            while(fin >> todo.id)
            {
                fin.ignore();
                getline(fin, todo.task);
                if(todo.id == id)
                {
                    todo.task += " (Completed)";
                }
                tempFile << todo.id << "\n" << todo.task << "\n";
            }
            fin.close();
            tempFile.close();
            remove("to do list file.txt");
            rename("temp file.txt", "to do list file.txt");
            system("cls");
            cout<<"\n Task marked successfully!"<<endl;
        }
    }
}
