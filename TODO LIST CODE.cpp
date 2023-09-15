#include <iostream>
#include <fstream>
#include<string>
#include <cstdlib>

using namespace std;
int ID;
//custom type todo which has two fields id and task
struct todo {
    int id;
    string task;
};

//this method is used to add a new task to the list of tasks
void addtask() {
    system("cls");
    cout<<"\t\t\t________________________________________________________________________"<<endl;
	cout<<"\t\t\t                       WELCOME TO Your ToDo List                       "<<endl;
    cout<<"\t\t\t________________________________________________________________________"<<endl<<endl<<endl;
    todo todo;
    cout << "\n\tEnter new task: ";
    cin.get();
    getline(cin, todo.task); //get user input
    ID++; //increment id for the current task

    //now write this task to the todo.txt file
    ofstream write;
    write.open("todo.txt", ios::app);//
    write << "\n" << ID;
    write << "\n" << todo.task ;
    write.close();
    //write the id to a new file so that we can use this id later to add new task
    write.open("id.txt");
    write << ID;
    write.close();

    char ch;
    cout<<"Do you want to add more task? y/n"<<endl;
    cin>> ch;
    //if user wants to add a new task again then call the same function else return
    if(ch == 'y'){
        addtask();
    }
    else{
        cout << "\n\tTask has been added successfully";
        return;
    }
}

// this method is used to print the task on the screen
void print(todo s) {
    cout << "\n\tID is : " << s.id;
    cout << "\n\tTask is : " << s.task;
}

//This method is used to read data from the todo.txt file and print it on screen
void readtask() {
    system("cls");
     cout<<"\t\t\t_______________________________________________________________________"<<endl;
	cout<<"\t\t\t                       WELCOME TO Your ToDo List                       "<<endl;
    cout<<"\t\t\t________________________________________________________________________"<<endl<<endl<<endl;
    todo todo;
    ifstream read;
    read.open("todo.txt");
    cout << "\n\t_________________Your current Tasks in the list______________________";
    // while we dont reach the end of file keep on printing the data on screen
    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        print(todo);
    }
    read.close();
}

//this method is used to search for a specific task from the todo.txt file
int searchtask() {
    system("cls");
    cout<<"\t\t\t________________________________________________________________________"<<endl;
	cout<<"\t\t\t                       WELCOME TO Your ToDo List                       "<<endl;
    cout<<"\t\t\t________________________________________________________________________"<<endl<<endl<<endl;
    int id;
    cout << "\n\tEnter task id: ";
    cin >> id;
    todo todo;
    ifstream read;
    read.open("todo.txt");
    //while we dont reach end of file keep or searching for the id to match to the user input id
    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        if (todo.id == id) {
            print(todo);
            return id;
        }
    }
}

// this method is used to delete the task from the todo.txt file
void deletetask() {
    system("cls");
    cout<<"\t\t\t________________________________________________________________________"<<endl;
	cout<<"\t\t\t                       WELCOME TO Your ToDo List                       "<<endl;
    cout<<"\t\t\t________________________________________________________________________"<<endl<<endl<<endl;
    int id = searchtask();
    cout << "\n\tDo you want to delete this task (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");
        //while we dont reach the end of file keep on searching for the id to delete the task
        while (!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask deleted successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}

//this method is used to update the task
//here we create a new temp.txt file and add all the updated data to this file
//once updated we then delete the original todo.txt and then rename this file to todo.txt
void updatetask() {
    system("cls");
     cout<<"\t\t\t________________________________________________________________________"<<endl;
	cout<<"\t\t\t                       WELCOME TO Your ToDo List                       "<<endl;
    cout<<"\t\t\t________________________________________________________________________"<<endl<<endl<<endl;
    int id = searchtask();
    cout << "\n\tYou want to update this task (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo newData;
        cout << "\n\tEnter todo task : ";
        cin.get();
        getline(cin, newData.task);
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");
        //while we dont reach end of file keep on searching for the id and once found update with new data
        while (!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
            else {
                tempFile << "\n"<< todo.id;
                tempFile << "\n"<< newData.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}
int main()
{
    system("cls");
	system("Color 87"); // "Color XY", X - backgroung color, Y - text color
    system("title todoapp ");
    cout<<"\t\t\t_______________________________________________________________________"<<endl;
    cout<<"\t\t\t                                                                     "<<endl;
	cout<<"\t\t\t                       ToDo List                      "<<endl;
	cout<<"\t\t\t                                                                     "<<endl;
    cout<<"\t\t\t_______________________________________________________________________"<<endl<<endl<<endl<<endl;
    ifstream read;
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID = 0;
    }
    read.close();

    while (true) {
        cout<<endl<<endl;
        cout << "\n\t1.Add Task";
        cout << "\n\t2.See Task";
        cout << "\n\t3.Search Task";
        cout << "\n\t4.Delete Task";
        cout << "\n\t5.Update Task";

        int choice;
        cout << "\n\tEnter your choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addtask();
            break;
        case 2:
            readtask();
            break;
        case 3:
            searchtask();
            break;
        case 4:
            deletetask();
            break;
        case 5:
            updatetask();
            break;
        }
    }

}
