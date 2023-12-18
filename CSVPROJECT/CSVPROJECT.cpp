#include<iostream>
#include<string>
#include<sstream>
#include<Windows.h>
#include<fstream>
#include"head.h"
using namespace std;
int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD attributes = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE; 
    attributes |= FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY; 
    SetConsoleTextAttribute(hConsole, attributes);
    bool flag = true;
    int choice = 0;
    cout << "\t\t\t\t\t|--------------------------------|\n";
    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
    cout << "\t\t\t\t\t|--------------------------------|\n\n";
    while (flag == true)
    {
        system("cls");
        cout << "\t\t\t\t\t|--------------------------------|\n";
        cout << "\t\t\t\t\t\tWelcome to Flex!\n";
        cout << "\t\t\t\t\t|--------------------------------|\n\n";
        cout << "Enter (1) to (4)\n\n";
        cout << "1)Admin\n2)Teacher\n3)Student\n4)Exit\n";
        cin >> choice;
        if (cin.fail())
        {
            cout << "Enter correct input\n";
            cin.clear();
            cin.ignore();
            continue;
        }
        switch (choice)
        {
        case 1:
        {
            // taking a input user id and pass and matching it with the ones exist in file
            string input_id = "", input_pass = "";
            cout << "\nEnter Admin ID:";
            cin >> input_id;
            cout << "\nEnter Password:";
            cin >> input_pass;
            ifstream reader;
            reader.open("Adminidpass.csv");
            string username = "", password = "", line = "";
            getline(reader, line);
            line = "";
            bool res = false;
            while (getline(reader, line))
            {
                username = "", password = "";
                stringstream ss(line);
                getline(ss, username, ',');
                getline(ss, password, ',');
                if (username == input_id && password == input_pass)
                {
                    system("cls");
                    cout << "\t\t\t\t\t|--------------------------------|\n";
                    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
                    cout << "\t\t\t\t\t|--------------------------------|\n\n";
                    cout << "\nUser Autenticated\n";
                    res = true;
                    break;

                }
            }
            while (res == true)
            {

                Admin obj;
                int operation = 0;
                cout << "\nPlease select the operation you want to Perform\n";
                cout << "1)Add New Teacher\n2)Add New Student\n3)Edit Student Details\n4)Edit Teacher Details\n5)View Students\n6)View Teachers\n7)EXIT\n";
                cin >> operation;
                if (cin.fail())
                {
                    cout << "Enter correct input\n";
                    cin.clear();
                    cin.ignore();
                    continue;
                }
                switch (operation)
                {
                case 1:
                {
                    system("cls");
                    cout << "\t\t\t\t\t|--------------------------------|\n";
                    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
                    cout << "\t\t\t\t\t|--------------------------------|\n\n";
                    obj.AddTeacher();
                    break;
                }

                case 2:
                {
                    system("cls");
                    cout << "\t\t\t\t\t|--------------------------------|\n";
                    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
                    cout << "\t\t\t\t\t|--------------------------------|\n\n";
                    obj.AddStudent();
                    break;
                }
                case 3:
                {
                    system("cls");
                    cout << "\t\t\t\t\t|--------------------------------|\n";
                    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
                    cout << "\t\t\t\t\t|--------------------------------|\n\n";
                    obj.Edit_Student();

                    break;
                }
                case 4:
                {
                    system("cls");
                    cout << "\t\t\t\t\t|--------------------------------|\n";
                    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
                    cout << "\t\t\t\t\t|--------------------------------|\n\n";
                    obj.Edit_Teacher();

                    break;
                }
                case 5:
                {
                    system("cls");
                    cout << "\t\t\t\t\t|--------------------------------|\n";
                    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
                    cout << "\t\t\t\t\t|--------------------------------|\n\n";
                    obj.viewstudents();

                    break;
                }
                case 6:
                {
                    system("cls");
                    cout << "\t\t\t\t\t|--------------------------------|\n";
                    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
                    cout << "\t\t\t\t\t|--------------------------------|\n\n";
                    obj.viewteachers();

                    break;
                }
                case 7:
                {
                    res = false;
                    break;
                }
                default:
                {
                    cout << "Please enter correct input!!";
                    break;
                }

                }
            }
            break;
        }
        case 2:
        {
            //Teacher module
            string input_id = "", input_pass = "";
            cout << "\nEnter Teacher ID:";
            cin >> input_id;
            cout << "\nEnter Password:";
            cin >> input_pass;
            ifstream reader;
            reader.open("Teacheridpass.csv");
            string username = "", password = "", line = "";
            getline(reader, line);
            line = "";
            bool res = false;
            while (getline(reader, line))
            {
                username = "", password = "";
                stringstream ss(line);
                getline(ss, username, ',');
                getline(ss, password, ',');
                if (username == input_id && password == input_pass)
                {
                    system("cls");
                    cout << "\t\t\t\t\t|--------------------------------|\n";
                    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
                    cout << "\t\t\t\t\t|--------------------------------|\n\n";
                    cout << "\nUser Autenticated\n";
                    res = true;
                    break;

                }
            }
            while (res == true)
            {
                Admin obj1;
                int operation = 0;
                cout << "\nPlease select the operation you want to Perform\n";
                cout << "1)View Timetable\n2)Assign Marks\n3)Mark Attendence\n4)EXIT\n";
                cin >> operation;
                if (cin.fail())
                {
                    cout << "Enter correct input\n";
                    cin.clear();
                    cin.ignore();
                    continue;
                }
                switch (operation)
                {
                case 1:
                {
                    system("cls");
                    cout << "\t\t\t\t\t|--------------------------------|\n";
                    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
                    cout << "\t\t\t\t\t|--------------------------------|\n\n";
                    obj1.ViewTimeTable(input_id);
                    break;
                }
                case 2:
                {
                    system("cls");
                    cout << "\t\t\t\t\t|--------------------------------|\n";
                    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
                    cout << "\t\t\t\t\t|--------------------------------|\n\n";
                    obj1.AssignScore();
                }
                case 3:
                {
                    system("cls");
                    cout << "\t\t\t\t\t|--------------------------------|\n";
                    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
                    cout << "\t\t\t\t\t|--------------------------------|\n\n";
                    obj1.TakeAttendance();
                }
                case 4:
                {
                    res = false;
                    break;
                }
                }
            }
            break;
        }
        case 3:
        {
            //student module
            string input_id = "", input_pass = "";
            cout << "\nEnter Student ID:";
            cin >> input_id;
            cout << "\nEnter Password:";
            cin >> input_pass;
            ifstream reader;
            reader.open("Studentidpass.csv");
            string username = "", password = "", line = "";
            getline(reader, line);
            line = "";
            bool res = false;
            while (getline(reader, line))
            {
                username = "", password = "";
                stringstream ss(line);
                getline(ss, username, ',');
                getline(ss, password, ',');
                if (username == input_id && password == input_pass)
                {
                    system("cls");
                    cout << "\t\t\t\t\t|--------------------------------|\n";
                    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
                    cout << "\t\t\t\t\t|--------------------------------|\n\n";
                    cout << "\nUser Autenticated\n";
                    res = true;
                    break;

                }
            }
            while (res == true)
            {

                Admin obj;
                int operation = 0;
                cout << "\nPlease select the operation you want to Perform\n";
                cout << "1)View Attendance\n2)View Score\n3)View Courses\n4)View FeeStatus\n5)EXIT\n";
                cin >> operation;
                if (cin.fail())
                {
                    cout << "Enter correct input\n";
                    cin.clear();
                    cin.ignore();
                    continue;
                }
                switch (operation)
                {
                case 1:
                {
                    system("cls");
                    cout << "\t\t\t\t\t|--------------------------------|\n";
                    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
                    cout << "\t\t\t\t\t|--------------------------------|\n\n";
                    obj.ViewAttendance( input_id);
                    break;
                }

                case 2:
                {
                    system("cls");
                    cout << "\t\t\t\t\t|--------------------------------|\n";
                    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
                    cout << "\t\t\t\t\t|--------------------------------|\n\n";
                    obj.ViewScore(input_id);
                    break;
                }
                case 3:
                {
                    system("cls");
                    cout << "\t\t\t\t\t|--------------------------------|\n";
                    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
                    cout << "\t\t\t\t\t|--------------------------------|\n\n";
                    obj.ViewCourses(input_id);

                    break;
                }
                case 4:
                {
                    system("cls");
                    cout << "\t\t\t\t\t|--------------------------------|\n";
                    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
                    cout << "\t\t\t\t\t|--------------------------------|\n\n";
                    obj.ViewFeeStatus(input_id);

                    break;
                }
                
                case 5:
                {
                    res = false;
                    break;
                }
                default:
                {
                    cout << "Please enter correct input!!";
                    break;
                }

                }
            }
            break;

        }
        case 4:
        {
            flag = false;
            break;
        }
        default:
        {
            cout << "Please enter correct input!!";
            break;
        }
        }

    }
    system("pause");
    return 0;
}
