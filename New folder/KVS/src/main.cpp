#include <bits/stdc++.h>
using namespace std;
void get(string &name, unordered_map<string, long> &phonebook)
{
    if (phonebook.find(name) != phonebook.end())
    {
        cout << phonebook[name] << endl;
    }
    else
    {
        cout << "not found!" << endl;
    }
}
void setNum(string &name, long number, unordered_map<string, long> &phonebook)
{
    phonebook[name] = number;
    cout<<"number saved succesfully"<<endl;
}
void del(string &name, unordered_map<string, long> &phonebook)
{
    if (phonebook.find(name) != phonebook.end())
    {
        phonebook.erase(name);
        cout << "deleted" << endl;
    }
    else
    {
        cout << "not found!" << endl;
    }
}
int main()
{
    cout << "commads: get | set | del | exit" << endl;
    string name;
    long number;
    string command;
    unordered_map<string, long> phonebook;
    string input;
    cout << "do you want to add number?y/n" << endl;
    if(input=="n")cout<<"exiting..."<<endl;
    cin >> input;
    while (input == "y")
    {
        cout << "enter your command : " << endl;
        cin >> command;
        if (command == "get")
        {
            cout << "enter namer:" << endl;
            cin >> name;
            get(name, phonebook);
        }
        else if (command == "set")
        {
            cout << "enter name and number" << endl;
            cin >> name >> number;
            cin.ignore();
            setNum(name, number, phonebook);
        }
        else if (command == "del" || command == "Del")
        {
            cout << "enter name" << endl;
            cin >> name;
            del(name, phonebook);
        }
        else if (command == "exit" || command == "Exit")
        {
            cout<<"exiting the program,bye...."<<endl;
            break;
        }
        cout << "do you want to continue?y/n" << endl;
        cin >> input;
        
    }
    return 0;
}