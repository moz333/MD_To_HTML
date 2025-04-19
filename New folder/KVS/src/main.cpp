#include <bits/stdc++.h>
using namespace std;
void get(string &name, unordered_map<string, long long> &phonebook)
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
void setNum(string &name, long long number, unordered_map<string, long long> &phonebook)
{
    phonebook[name] = number;
    cout << "number saved succesfully" << endl;
}
void del(string &name, unordered_map<string, long long> &phonebook)
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
void save(const string filename, unordered_map<string, long long> &phonebook)
{
    ofstream book(filename,ios::app);
    string content;
    if (book.is_open())
    {
        for (auto it : phonebook)
        {
            book << it.first << ":" << it.second << endl;
        }
    }
    else
        cout << "couldn't open the file" << endl;
    book.close();
}
int main()
{
    cout << "commads: get | set | del | exit" << endl;
    string name;
    long long number;
    string command;
    unordered_map<string, long long> phonebook;
    string input = "y";
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
            cout << "exiting the program,bye...." << endl;
            break;
        }
        else
        {
            cout << "wrong command! do you want to continue?y/n" << endl;
            cin >> input;
            if (input == "n")
                cout << "exiting te program! Bye" << endl;
        }
    }
    cout << "enter s to save the data or l to load the data!" << endl;
    cin >> command;
    while (true)
    {
        if (command == "s")
        {
            cout << "enter the file name where you want to save: " << endl;
            string filename;
            cin >> filename;
            save(filename, phonebook);
        }

        cout << "continue? y/n : " << endl;
        cin >> input;
        if (input == "n")
            break;
    }

    return 0;
}