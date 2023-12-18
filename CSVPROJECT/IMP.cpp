#include"head.h"
using namespace std;
Admin::Admin()
{
    username = password = ""; teacher_count = student_count = 0;
}
//Adds a teacher to respective csv file
void Admin::AddTeacher()
{
    ifstream reader;
    reader.open("teachercount.csv");
    string line = "";
    getline(reader, line);
    stringstream ss(line);
    string temp = "";
    getline(ss, temp);
    teacher_count = stoi(temp);
    reader.close();
    ofstream writer; writer.open("Teachers.csv", std::ios_base::app);
    cout << "Enter Teacher Info:\n";
    cin.ignore();
    cout << "\nEnter name :"; getline(cin, T_name);
    cout << "\nEnter fathername :"; getline(cin, T_Fname);
    cout << "\nEnter Gender :"; getline(cin, T_gender);
    cout << "\nEnter CNIC :"; getline(cin, T_cnic);
    cout << "\nEnter contact no. :"; getline(cin, T_contact);
    cout << "\nEnter Address e.g. (House/Street etc.) :"; getline(cin, T_address);
    T_id = "T" + to_string( teacher_count);
    cout << "\nEnter Password :"; getline(cin, T_password);
    cout << "\nEnter Qualification : "; getline(cin, qualification);
    cout << "\nEnter Salary : "; getline(cin, salary);
    cout << "\nEnter Department :"; getline(cin, T_department);
    cout << "\nEnter TimeTable details (Lec Name/Date): ";
    cin >> timetable.lecture1 >> timetable.day1 >> timetable.time1;
    cin >> timetable.lecture2 >> timetable.day2 >> timetable.time2;
    cin >> timetable.lecture3 >> timetable.day3 >> timetable.time3;
    writer << T_id << ',' << T_password << ',' << T_name << ','
        << T_Fname << ',' << T_gender << ',' << T_cnic << ','
        << T_contact << ',' << T_address << ',' << qualification << ','
        << salary << ',' << T_department << ',' << timetable.lecture1 << ',' << timetable.day1 << ',' << timetable.time1
        << ',' << timetable.lecture2 << ',' << timetable.day2 << ',' << timetable.time2
        << ',' << timetable.lecture3 << ',' << timetable.day3 << ','<<timetable.time3<< '\n';
    writer.close();
    
    teacher_count++;
    ofstream fout;
    fout.open("teachercount.csv");
    fout << teacher_count;
    fout.close();
   
}
//Adds a Student to the Students.csv File
void Admin::AddStudent()
{
    ifstream reader;
    reader.open("studentcount.csv");
    string line = "";
    getline(reader, line);
    stringstream ss(line);
    string temp = "";
    getline(ss, temp);
    student_count = stoi(temp);
    reader.close();
    ofstream writer; writer.open("Students.csv", std::ios_base::app);
    cout << "Enter Student Info:\n";
    cin.ignore();
    cout << "\nEnter name :"; getline(cin, S_name);
    cout << "\nEnter fathername :"; getline(cin, S_Fname);
    cout << "\nEnter Gender :"; getline(cin, S_gender);
    cout << "\nEnter CNIC :"; getline(cin, S_cnic);
    cout << "\nEnter contact no. :"; getline(cin, S_contact);
    cout << "\nEnter Address e.g. (House/Street etc.) :"; getline(cin, S_address);
    S_id = "S" + to_string( student_count);
    cout << "\nEnter Password :"; getline(cin, S_password);
    cout << "\nEnter FeeStatus : "; getline(cin, feestatus);
    cout << "\nEnter Department :"; getline(cin, S_department);
   /* cout << "\nEnter Course (1):"; getline(cin, mark.Course1);
    cout << "\nEnter Marks :"; getline(cin, mark.marks1);
    cout << "\nEnter Grade :"; getline(cin, mark.grade1);
    cout << "\nEnter Course (2):"; getline(cin, mark.Course2);
    cout << "\nEnter Marks :"; getline(cin, mark.marks2);
    cout << "\nEnter Grade :"; getline(cin, mark.grade2);
    cout << "\nEnter Course (1):"; getline(cin, mark.Course3);
    cout << "\nEnter Marks :"; getline(cin, mark.marks3);
    cout << "\nEnter Grade :"; getline(cin, mark.grade3);
    cout << "\nEnter Status(1) :"; getline(cin, attendance.lex);*/
    writer << S_id << ',' << S_password << ',' << S_name << ','
        << S_Fname << ',' << S_gender << ',' << S_cnic << ','
        << S_contact << ',' << S_address << ',' << feestatus << ','
        << S_department << ',' << mark.Course1 << ',' << mark.marks1 << ',' << mark.grade1
        << ',' << mark.Course2 << ',' << mark.marks2 << ',' << mark.grade2 << ',' << mark.Course3
        << ',' << mark.marks3 << ',' << mark.grade3 << ',' << attendance.status1 << ',' << attendance.date1<<
         ','<< attendance.status2 << ','<< attendance.date2 << ',' << attendance.status3 << ',' << attendance.date3 << '\n';
    writer.close();
    student_count++;
    ofstream fout;
    fout.open("studentcount.csv");
    fout << student_count;
    fout.close();

}
//edits student data
void Admin:: Edit_Student()
{
    ifstream reader;
    reader.open("studentcount.csv");
    string line1 = "";
    getline(reader, line1);
    stringstream ss(line1);
    string temp = "";
    getline(ss, temp);
    student_count = stoi(temp);
    reader.close();
    Admin* ptr = new Admin[student_count];
    ifstream fin;
    fin.open("Students.csv");
    string line2 = "";
    getline(fin, line2);
    line2 = "";
    int i = 0;
    while( i < student_count && getline(fin, line2))
    {
        stringstream s2(line2);
        getline(s2, ptr[i].S_id, ','); 
        getline(s2, ptr[i].S_password, ',');
        getline(s2, ptr[i].S_name, ',');
        getline(s2, ptr[i].S_Fname, ',');
        getline(s2, ptr[i].S_gender, ',');
        getline(s2, ptr[i].S_cnic, ',');
        getline(s2, ptr[i].S_contact, ',');
        getline(s2, ptr[i].S_address, ',');
        getline(s2, ptr[i].feestatus, ',');
        getline(s2, ptr[i].S_department, ',');
        getline(s2, ptr[i].mark.Course1, ',');
        getline(s2, ptr[i].mark.marks1, ',');
        getline(s2, ptr[i].mark.grade1, ',');
        getline(s2, ptr[i].mark.Course2, ',');
        getline(s2, ptr[i].mark.marks2, ',');
        getline(s2, ptr[i].mark.grade2, ',');
        getline(s2, ptr[i].mark.Course3, ',');
        getline(s2, ptr[i].mark.marks3, ',');
        getline(s2, ptr[i].mark.grade3, ',');
        getline(s2, ptr[i].attendance.status1, ',');
        getline(s2, ptr[i].attendance.date1, ',');
        getline(s2, ptr[i].attendance.status2, ',');
        getline(s2, ptr[i].attendance.date2, ',');
        getline(s2, ptr[i].attendance.status3, ',');
        getline(s2, ptr[i].attendance.date3, ',');
        i++;
    }
    fin.close();
    string id;
    bool stufound = false;
    cout << "\nEnter Student ID of the student you want to edit: "; cin >> id;
    for (int i = 0; i < student_count; i++)
    {
        if (id == ptr[i].S_id)
        {
            stufound = true;
            int choice=0;
            cout << "\nEnter\n1)FirstName\n2)LastName\n3)FeeStatus\n4)Address\n5)ContactNo\n6)Exit\n";
            cin >> choice;
            if (choice == 1)
            {
                string name;
                cout << "\nEnter New Name: "; cin >> name;
                ptr[i].S_name = name;
                cout << "\nUpdated\n";
                break;
            }
            else if (choice == 2)
            {
                string lastname;
                cout << "\nEnter new Last name :"; cin >> lastname;
                ptr[i].S_Fname = lastname;
                cout << "\nUpdated\n";
                break;
            }
            else if (choice == 3)
            {
                string status;
                cout << "\nUpdate FeeStatus: "; cin >> status;
                ptr[i].feestatus = status;
                cout << "\nUpdated\n";
                break;
            }
            else if (choice == 4)
            {
                string address = "";
                cout << "\nEnter Updated Address: "; cin >> address;
                ptr[i].S_address = address;
                cout << "\nUpdated\n";
                break;
            }
            else if (choice == 5)
            {
                string upcontact;
                cout << "\nEnter Updated contact :"; cin >> upcontact;
                cout << "\nUpdated\n";
                break;
            }
            else if(choice==6)
            {
                break;
            }
            else
            {
                break;
            }

        }
        if (stufound == false)
        {
            break;
        }

    }
    remove("Students.csv");
    ofstream writer;
    writer.open("Students.csv");
    writer << "ID,PASS,NAME,FNAME,GENDER,CNIC,CONTACT,ADDRESS,FEESTATUS,DEPT,C1,M1,G1,C2,M2,G2,C3,M3,G3,Status1,Date1,Status2,Date2,Status3,Date3" << '\n';
    for (int i = 0; i < student_count; i++)
    {
        writer << ptr[i].S_id << ',' << ptr[i].S_password << ',' << ptr[i].S_name << ','
            << ptr[i].S_Fname << ',' << ptr[i].S_gender << ',' << ptr[i].S_cnic << ','
            << ptr[i].S_contact << ',' << ptr[i].S_address << ',' << ptr[i].feestatus << ','
            << ptr[i].S_department << ','<<ptr[i].mark.Course1 << ',' << ptr[i].mark.marks1
            << ',' << ptr[i].mark.grade1 << ',' << ptr[i].mark.Course2 << ',' << ptr[i].mark.marks2 << ',' << ptr[i].mark.grade2
            << ',' <<  ptr[i].mark.Course3 << ',' << ptr[i].mark.marks3 << ',' << ptr[i].mark.grade3 << ','<<ptr[i].attendance.status1
            << ',' << ptr[i].attendance.date1 << ',' << ptr[i].attendance.status2 << ',' << ptr[i].attendance.date2
            << ',' << ptr[i].attendance.status3 << ',' << ptr[i].attendance.date3 <<'\n';
    }
    writer.close();
    delete[]ptr;
    ptr = NULL;
}
// edits teacher details
void Admin::Edit_Teacher()
{
    ifstream reader;
    reader.open("teachercount.csv");
    string line1 = "";
    getline(reader, line1);
    stringstream ss(line1);
    string temp = "";
    getline(ss, temp);
    teacher_count = stoi(temp);
    reader.close();
    Admin* ptr = new Admin[teacher_count];
    ifstream fin;
    fin.open("Teachers.csv");
    string line2 = "";
    getline(fin, line2);
    line2 = "";
    int i = 0;
    while ( i < teacher_count && getline(fin, line2))
    {
        stringstream s2(line2);
        getline(s2, ptr[i].T_id, ',');
        getline(s2, ptr[i].T_password, ',');
        getline(s2, ptr[i].T_name, ',');
        getline(s2, ptr[i].T_Fname, ',');
        getline(s2, ptr[i].T_gender, ',');
        getline(s2, ptr[i].T_cnic, ',');
        getline(s2, ptr[i].T_contact, ',');
        getline(s2, ptr[i].T_address, ',');
        getline(s2, ptr[i].qualification, ',');
        getline(s2, ptr[i].salary, ',');
        getline(s2, ptr[i].T_department, ',');
        getline(s2, ptr[i].timetable.lecture1, ',');
        getline(s2, ptr[i].timetable.day1, ',');
        getline(s2, ptr[i].timetable.time1, ',');
        getline(s2, ptr[i].timetable.lecture2, ',');
        getline(s2, ptr[i].timetable.day2, ',');
        getline(s2, ptr[i].timetable.time2, ',');
        getline(s2, ptr[i].timetable.lecture3, ',');
        getline(s2, ptr[i].timetable.day3, ',');
        getline(s2, ptr[i].timetable.time3, ',');
        i++;
    }
    fin.close();
    string id;
    cout << "\nEnter Teacher ID of the teacher you want to edit: ";
    cin >> id;
    bool teachfound = false;
    for (int i = 0; i < teacher_count; i++)
    {
        
        if (id == ptr[i].T_id)
        {
            teachfound = true;
            int choice = 0;
            cout << "\nEnter\n1)Address\n2)Contact\n3)Qualification\n4)Salary\n5)Exit\n";
            cin >> choice;
            if (choice == 1)
            {
                string upaddress;
                cout << "\nEnter New Address: "; cin >> upaddress;
                ptr[i].T_address = upaddress;
                cout << "\nUpdated\n";
                break;
            }
            else if (choice == 2)
            {
                string upcontact;
                cout << "\nEnter new Contact :"; cin >> upcontact;
                ptr[i].T_contact =upcontact;
                cout << "\nUpdated\n";
                break;
            }
            else if (choice == 3)
            {
                string quali;
                cout << "\nUpdate Qualification: "; cin >> quali;
                ptr[i].qualification = quali;
                cout << "\nUpdated\n";
                break;
            }
            else if (choice == 4)
            {
                string upsalary = "";
                cout << "\nEnter Updated Salary: "; cin >> upsalary;
                ptr[i].salary = upsalary;
                cout << "\nUpdated\n";
                break;
            }
            else if (choice==5)
            {
                break;
            }
            else
            {
                break;
            }
        }
        if (teachfound == false)
        {
            cout << "\nInvalid ID\n";
            break;
        }

    }
    remove("Teachers.csv");
    ofstream writer;
    writer.open("Teachers.csv");
    writer << "ID,PASS,NAME,FNAME,GENDER,CNIC,PHONE,ADDRESS,QUALIFICATION,SALARY,DEPT,LEC1,DAY,LEC2,DAY,LEC3,DAY" << '\n';
    for (int i = 0; i < teacher_count; i++)
    {
        writer << ptr[i].T_id << ',' << ptr[i].T_password << ',' << ptr[i].T_name << ','
            << ptr[i].T_Fname << ',' << ptr[i].T_gender << ',' << ptr[i].T_cnic << ','
            << ptr[i].T_contact << ',' << ptr[i].T_address << ',' << ptr[i].qualification << ','
            << ptr[i].salary << ',' << ptr[i].T_department << ',' << ptr[i].timetable.lecture1 << ','
            << ptr[i].timetable.day1 << ',' << ptr[i].timetable.time1 << ',' << ptr[i].timetable.lecture2 << ',' << ptr[i].timetable.day2 << ','<<ptr[i].timetable.time2
            << ',' << ptr[i].timetable.lecture3 << ',' << ptr[i].timetable.day3 <<','<<ptr[i].timetable.time3<<'\n';
    }
    writer.close();
    system("cls");
    cout << "\t\t\t\t\t|--------------------------------|\n";
    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
    cout << "\t\t\t\t\t|--------------------------------|\n\n";
}
void Admin::viewstudents()
{
    system("cls");
    cout << "\t\t\t\t\t|--------------------------------|\n";
    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
    cout << "\t\t\t\t\t|--------------------------------|\n\n";
    ifstream reader;
    reader.open("studentcount.csv");
    string line1 = "";
    getline(reader, line1);
    stringstream ss(line1);
    string temp = "";
    getline(ss, temp);
    student_count = stoi(temp);
    reader.close();
    Admin* ptr = new Admin[student_count];
    ifstream fin;
    fin.open("Students.csv");
    string line2 = "";
    getline(fin, line2);
    line2 = "";
    int i = 0;
    while (i < student_count && getline(fin, line2))
    {
        stringstream s2(line2);
        getline(s2, ptr[i].S_id, ',');
        getline(s2, ptr[i].S_password, ',');
        getline(s2, ptr[i].S_name, ',');
        getline(s2, ptr[i].S_Fname, ',');
        getline(s2, ptr[i].S_gender, ',');
        getline(s2, ptr[i].S_cnic, ',');
        getline(s2, ptr[i].S_contact, ',');
        getline(s2, ptr[i].S_address, ',');
        getline(s2, ptr[i].feestatus, ',');
        getline(s2, ptr[i].S_department, ',');
        i++;
    }
    fin.close();
    int choice=0;
    bool flag1 = true;
    while (flag1 == true)
    {
        cout << "1)Specific Student\n2)All Students\n3)Exit";
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
            string id;
            cout << "Enter Student ID"; cin >> id;
            for (int i = 0; i < student_count; i++)
            {
                if (ptr[i].S_id == id)
                {
                    cout << "ID :" << ptr[i].S_id << endl;
                    cout << "Name :" << ptr[i].S_name << endl << "Father Name : " << ptr[i].S_Fname << endl;
                    cout << "Dept. :" << ptr[i].S_department << endl << endl;
                    break;
                }
            }
        }
        case 2:
        {
            cout << "Registered Students are:\n";
            for (int i = 0; i < student_count; i++)
            {
                cout << "ID :" << ptr[i].S_id << endl;
                cout << "Name :" << ptr[i].S_name << endl << "Father Name : " << ptr[i].S_Fname << endl;
                cout << "Dept. :" << ptr[i].S_department << endl << endl;

            }
        }
        case 3:
        {
            flag1 = false;
        }
        default:
        {
            cout << "\nInvalid Input!\n";
        }
        }
    }
}
void Admin::viewteachers()
{
    system("cls");
    cout << "\t\t\t\t\t|--------------------------------|\n";
    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
    cout << "\t\t\t\t\t|--------------------------------|\n\n";
    ifstream reader;
    reader.open("teachercount.csv");
    string line1 = "";
    getline(reader, line1);
    stringstream ss(line1);
    string temp = "";
    getline(ss, temp);
    teacher_count = stoi(temp);
    reader.close();
    Admin* ptr = new Admin[teacher_count];
    ifstream fin;
    fin.open("Teachers.csv");
    string line2 = "";
    getline(fin, line2);
    line2 = "";
    int i = 0;
    while (i < teacher_count && getline(fin, line2))
    {
        stringstream s2(line2);
        getline(s2, ptr[i].T_id, ',');
        getline(s2, ptr[i].T_password, ',');
        getline(s2, ptr[i].T_name, ',');
        getline(s2, ptr[i].T_Fname, ',');
        getline(s2, ptr[i].T_gender, ',');
        getline(s2, ptr[i].T_cnic, ',');
        getline(s2, ptr[i].T_contact, ',');
        getline(s2, ptr[i].T_address, ',');
        getline(s2, ptr[i].qualification, ',');
        getline(s2, ptr[i].salary, ',');
        getline(s2, ptr[i].T_department, ',');
        i++;
    }
    fin.close();
    cout << "Registered teachers are:\n";
    for (int i = 0; i < teacher_count; i++)
    {
        cout << "Name :" << ptr[i].T_name <<endl<< "Father Name : " << ptr[i].T_Fname;
        cout << "\nGender :" << ptr[i].T_gender;
        cout << "\nQualification :" << ptr[i].qualification;
        cout << "\nContact :" << ptr[i].T_contact;
        cout << "\nID :" << ptr[i].T_id << endl;
    }


}
void Admin:: ViewTimeTable(string id)
{
    system("cls");
    cout << "\t\t\t\t\t|--------------------------------|\n";
    cout << "\t\t\t\t\t\tWelcome to Flex!\n";
    cout << "\t\t\t\t\t|--------------------------------|\n\n";
    ifstream reader;
    reader.open("teachercount.csv");
    string line1 = "";
    getline(reader, line1);
    stringstream ss(line1);
    string temp = "";
    getline(ss, temp);
    teacher_count = stoi(temp);
    reader.close();
    Admin* ptr = new Admin[teacher_count];
    ifstream fin;
    fin.open("Teachers.csv");
    string line2 = "";
    getline(fin, line2);
    line2 = "";
    int i = 0;
    while (i < teacher_count && getline(fin, line2))
    {
        stringstream s2(line2);
        getline(s2, ptr[i].T_id, ',');
        getline(s2, ptr[i].T_password, ',');
        getline(s2, ptr[i].T_name, ',');
        getline(s2, ptr[i].T_Fname, ',');
        getline(s2, ptr[i].T_gender, ',');
        getline(s2, ptr[i].T_cnic, ',');
        getline(s2, ptr[i].T_contact, ',');
        getline(s2, ptr[i].T_address, ',');
        getline(s2, ptr[i].qualification, ',');
        getline(s2, ptr[i].salary, ',');
        getline(s2, ptr[i].T_department, ',');
        getline(s2, ptr[i].timetable.lecture1, ',');
        getline(s2, ptr[i].timetable.day1, ',');
        getline(s2, ptr[i].timetable.time1, ',');
        getline(s2, ptr[i].timetable.lecture2, ',');
        getline(s2, ptr[i].timetable.day2, ',');
        getline(s2, ptr[i].timetable.time2, ',');
        getline(s2, ptr[i].timetable.lecture3, ',');
        getline(s2, ptr[i].timetable.day3, ',');
        getline(s2, ptr[i].timetable.time3, ',');
        i++;
    }
    fin.close();
    bool teachfound = false;
    for (int i = 0; i < teacher_count; i++)
    {

        if (id == ptr[i].T_id)
        {
            cout << "\n\t\t\t\t\t\tLECTURES" << "\t" << "DAY"<<"\t\t"<<"TIME\n";
                cout << "\t\t\t\t\t|------------------------------------------------|\n";
                cout << "\t\t\t\t\t\t" << "1)"  << ptr[i].timetable.lecture1 << "\t\t" << ptr[i].timetable.day1<<"\t\t"<<ptr[i].timetable.time1 << endl;
                cout << "\t\t\t\t\t\t" << "2)" << ptr[i].timetable.lecture2 << "\t\t" << ptr[i].timetable.day2 <<"\t\t"<<ptr[i].timetable.time2 << endl;
                   cout << "\t\t\t\t\t\t" << "3)"  << ptr[i].timetable.lecture3  <<"\t\t" << ptr[i].timetable.day3<<"\t\t"<<ptr[i].timetable.time3 << endl;



        }


    }
    delete[]ptr;
    ptr = NULL;
}
void Admin::AssignScore()
{

    ifstream reader;
    reader.open("studentcount.csv");
    string line1 = "";
    getline(reader, line1);
    stringstream ss(line1);
    string temp = "";
    getline(ss, temp);
    student_count = stoi(temp);
    reader.close();
    Admin* ptr = new Admin[student_count];
    ifstream fin;
    fin.open("Students.csv");
    string line2 = "";
    getline(fin, line2);
    line2 = "";
    int i = 0;
    while (i < student_count && getline(fin, line2))
    {
        stringstream s2(line2);
        getline(s2, ptr[i].S_id, ',');
        getline(s2, ptr[i].S_password, ',');
        getline(s2, ptr[i].S_name, ',');
        getline(s2, ptr[i].S_Fname, ',');
        getline(s2, ptr[i].S_gender, ',');
        getline(s2, ptr[i].S_cnic, ',');
        getline(s2, ptr[i].S_contact, ',');
        getline(s2, ptr[i].S_address, ',');
        getline(s2, ptr[i].feestatus, ',');
        getline(s2, ptr[i].S_department, ',');
        getline(s2, ptr[i].mark.Course1, ',');
        getline(s2, ptr[i].mark.marks1, ',');
        getline(s2, ptr[i].mark.grade1, ',');
        getline(s2, ptr[i].mark.Course2, ',');
        getline(s2, ptr[i].mark.marks2, ',');
        getline(s2, ptr[i].mark.grade2, ',');
        getline(s2, ptr[i].mark.Course3, ',');
        getline(s2, ptr[i].mark.marks3, ',');
        getline(s2, ptr[i].mark.grade3, ',');
        getline(s2, ptr[i].attendance.status1, ',');
        getline(s2, ptr[i].attendance.date1, ',');
        getline(s2, ptr[i].attendance.status2, ',');
        getline(s2, ptr[i].attendance.date2, ',');
        getline(s2, ptr[i].attendance.status3, ',');
        getline(s2, ptr[i].attendance.date3, ',');
        i++;
    }
    fin.close();
    string id;
    bool stufound = false;
    cout << "\nEnter Student ID of the student you want to assign the grade to: "; cin >> id;
    for (int i = 0; i < student_count; i++)
    {
        if (id == ptr[i].S_id)
        {
            stufound = true;
            cin.ignore();
            cout << "\nEnter Marks of Course " << ptr[i].mark.Course1 << endl;
            getline(cin, ptr[i].mark.marks1);
            if( (stoi(ptr[i].mark.marks1)) >= 80&& (stoi(ptr[i].mark.marks1)) <= 100)
            {
                ptr[i].mark.grade1 = "A";
            }
            else if (stoi(ptr[i].mark.marks1) >= 70 )
            {
                ptr[i].mark.grade1 = "B";
            }
            else if (stoi(ptr[i].mark.marks1) >= 60)
            {
                ptr[i].mark.grade1 = "C";
            }
            else if (stoi(ptr[i].mark.marks1) >= 50)
            {
                ptr[i].mark.grade1 = "D";
            }
            else  
            {
                ptr[i].mark.grade1 = "F";
            }
            cout << "\nEnter Marks of Course " << ptr[i].mark.Course2 << endl;
            getline(cin, ptr[i].mark.marks2);
            if ((stoi(ptr[i].mark.marks2)) >= 80 && (stoi(ptr[i].mark.marks2)) <= 100)
            {
                ptr[i].mark.grade2 = "A";
            }
            else if (stoi(ptr[i].mark.marks2) >= 70)
            {
                ptr[i].mark.grade2 = "B";
            }
            else if (stoi(ptr[i].mark.marks2) >= 60)
            {
                ptr[i].mark.grade2 = "C";
            }
            else if (stoi(ptr[i].mark.marks2) >= 50)
            {
                ptr[i].mark.grade2 = "D";
            }
            else
            {
                ptr[i].mark.grade2 = "F";
            }
            cout << "\nEnter Marks of Course " << ptr[i].mark.Course3 << endl;
            getline(cin, ptr[i].mark.marks3);
            if ((stoi(ptr[i].mark.marks3)) >= 80 && (stoi(ptr[i].mark.marks3)) <= 100)
            {
                ptr[i].mark.grade3 = "A";
            }
            else if (stoi(ptr[i].mark.marks3) >= 70)
            {
                ptr[i].mark.grade3 = "B";
            }
            else if (stoi(ptr[i].mark.marks3) >= 60)
            {
                ptr[i].mark.grade3 = "C";
            }
            else if (stoi(ptr[i].mark.marks3) >= 50)
            {
                ptr[i].mark.grade3 = "D";
            }
            else
            {
                ptr[i].mark.grade3 = "F";
            }
            cout << "\n Marks Updated\n";
        }
        if (stufound == false)
        {
            break;
        }

    }
    remove("Students.csv");
    ofstream writer;
    writer.open("Students.csv");
    writer << "ID,PASS,NAME,FNAME,GENDER,CNIC,CONTACT,ADDRESS,FEESTATUS,DEPT,C1,M1,G1,C2,M2,G2,C3,M3,G3,Status1,Date1,Status2,Date2,Status3,Date3" << '\n';
    for (int i = 0; i < student_count; i++)
    {
        writer << S_id << ',' << S_password << ',' << S_name << ','
            << S_Fname << ',' << S_gender << ',' << S_cnic << ','
            << S_contact << ',' << S_address << ',' << feestatus << ','
            << S_department << ',' << mark.Course1 << ',' << mark.marks1 << ',' << mark.grade1
            << ',' << mark.Course2 << ',' << mark.marks2 << ',' << mark.grade2 << ',' << mark.Course3
            << ',' << mark.marks3 << ',' << mark.grade3 << ',' << attendance.status1 << ',' << attendance.date1 <<
            ',' << attendance.status2 << ',' << attendance.date2 << ',' << attendance.status3 << ',' << attendance.date3 << '\n';
    }
    writer.close();
    delete[]ptr;
    ptr = NULL;

}
// Taking Attendance
void Admin::TakeAttendance()
{

    ifstream reader;
    reader.open("studentcount.csv");
    string line1 = "";
    getline(reader, line1);
    stringstream ss(line1);
    string temp = "";
    getline(ss, temp);
    student_count = stoi(temp);
    reader.close();
    Admin* ptr = new Admin[student_count];
    ifstream fin;
    fin.open("Students.csv");
    string line2 = "";
    getline(fin, line2);
    line2 = "";
    int i = 0;
    while (i < student_count && getline(fin, line2))
    {
        stringstream s2(line2);
        getline(s2, ptr[i].S_id, ',');
        getline(s2, ptr[i].S_password, ',');
        getline(s2, ptr[i].S_name, ',');
        getline(s2, ptr[i].S_Fname, ',');
        getline(s2, ptr[i].S_gender, ',');
        getline(s2, ptr[i].S_cnic, ',');
        getline(s2, ptr[i].S_contact, ',');
        getline(s2, ptr[i].S_address, ',');
        getline(s2, ptr[i].feestatus, ',');
        getline(s2, ptr[i].S_department, ',');
        getline(s2, ptr[i].mark.Course1, ',');
        getline(s2, ptr[i].mark.marks1, ',');
        getline(s2, ptr[i].mark.grade1, ',');
        getline(s2, ptr[i].mark.Course2, ',');
        getline(s2, ptr[i].mark.marks2, ',');
        getline(s2, ptr[i].mark.grade2, ',');
        getline(s2, ptr[i].mark.Course3, ',');
        getline(s2, ptr[i].mark.marks3, ',');
        getline(s2, ptr[i].mark.grade3, ',');
        getline(s2, ptr[i].attendance.status1, ',');
        getline(s2, ptr[i].attendance.date1, ',');
        getline(s2, ptr[i].attendance.status2, ',');
        getline(s2, ptr[i].attendance.date2, ',');
        getline(s2, ptr[i].attendance.status3, ',');
        getline(s2, ptr[i].attendance.date3, ',');
        i++;
    }
    fin.close();
    string id;
    bool stufound = false;
    cout << "\nEnter Student ID of the student you want to take the attendance of: "; cin >> id;
    for (int i = 0; i < student_count; i++)
    {
        if (id == ptr[i].S_id)
        {
            stufound = true;
            cin.ignore();
            cout << "\nEnter attendance of Lecture " << ptr[i].mark.Course1 << endl;
            cout << "\nStauts(P/A) & Date(dd/mm/yy)\n";
            cin >> ptr[i].attendance.status1 >> ptr[i].attendance.date1;
            cout << "\nEnter attendance of Lecture " << ptr[i].mark.Course2 << endl;
            cout << "\nStauts(P/A) & Date(dd/mm/yy)\n";
            cin >> ptr[i].attendance.status2 >> ptr[i].attendance.date2;
            cout << "\nEnter attendance of Lecture " << ptr[i].mark.Course3 << endl;
            cout << "\nStauts(P/A) & Date(dd/mm/yy)\n";
            cin >> ptr[i].attendance.status3 >> ptr[i].attendance.date3;
           
        }
        if (stufound == false)
        {
            break;
        }

    }
    remove("Students.csv");
    ofstream writer;
    writer.open("Students.csv");
    writer << "ID,PASS,NAME,FNAME,GENDER,CNIC,CONTACT,ADDRESS,FEESTATUS,DEPT,C1,M1,G1,C2,M2,G2,C3,M3,G3,Status1,Date1,Status2,Date2,Status3,Date3" << '\n';
    for (int i = 0; i < student_count; i++)
    {
        writer << S_id << ',' << S_password << ',' << S_name << ','
            << S_Fname << ',' << S_gender << ',' << S_cnic << ','
            << S_contact << ',' << S_address << ',' << feestatus << ','
            << S_department << ',' << mark.Course1 << ',' << mark.marks1 << ',' << mark.grade1
            << ',' << mark.Course2 << ',' << mark.marks2 << ',' << mark.grade2 << ',' << mark.Course3
            << ',' << mark.marks3 << ',' << mark.grade3 << ',' << attendance.status1 << ',' << attendance.date1 <<
            ',' << attendance.status2 << ',' << attendance.date2 << ',' << attendance.status3 << ',' << attendance.date3 << '\n';
    }
    writer.close();
    delete[]ptr;
    ptr = NULL;

}
void Admin::ViewAttendance(string id)
{


    system("cls");
    cout << "\t\t******************************************\n";
    cout << "\t\t*\t\t\t\t\t\t *\n";
    cout << "\t\t*\tWelcome to Flex!\t\t\t *\n";
    cout << "\t\t*\t\t\t\t\t\t *\n";
    cout << "\t\t******************************************\n\n";
    ifstream reader;
    reader.open("studentcount.csv");
    string line1 = "";
    getline(reader, line1);
    stringstream ss(line1);
    string temp = "";
    getline(ss, temp);
    student_count = stoi(temp);
    reader.close();
    Admin* ptr = new Admin[student_count];
    ifstream fin;
    fin.open("Students.csv");
    string line2 = "";
    getline(fin, line2);
    line2 = "";
    int i = 0;
    while (i < student_count && getline(fin, line2))
    {
        stringstream s2(line2);
        getline(s2, ptr[i].S_id, ',');
        getline(s2, ptr[i].S_password, ',');
        getline(s2, ptr[i].S_name, ',');
        getline(s2, ptr[i].S_Fname, ',');
        getline(s2, ptr[i].S_gender, ',');
        getline(s2, ptr[i].S_cnic, ',');
        getline(s2, ptr[i].S_contact, ',');
        getline(s2, ptr[i].S_address, ',');
        getline(s2, ptr[i].feestatus, ',');
        getline(s2, ptr[i].S_department, ',');
        getline(s2, ptr[i].mark.Course1, ',');
        getline(s2, ptr[i].mark.marks1, ',');
        getline(s2, ptr[i].mark.grade1, ',');
        getline(s2, ptr[i].mark.Course2, ',');
        getline(s2, ptr[i].mark.marks2, ',');
        getline(s2, ptr[i].mark.grade2, ',');
        getline(s2, ptr[i].mark.Course3, ',');
        getline(s2, ptr[i].mark.marks3, ',');
        getline(s2, ptr[i].mark.grade3, ',');
        getline(s2, ptr[i].attendance.status1, ',');
        getline(s2, ptr[i].attendance.date1, ',');
        getline(s2, ptr[i].attendance.status2, ',');
        getline(s2, ptr[i].attendance.date2, ',');
        getline(s2, ptr[i].attendance.status3, ',');
        getline(s2, ptr[i].attendance.date3, ',');
        i++;
    }
    fin.close();
    bool stufound = false;
    for (int i = 0; i < student_count; i++)
    {
        if (id == ptr[i].S_id)
        {
            stufound = true;
            cout << "LECTURES" << "    " << "STATUS" << "     " << "DATE\n\n";
            cout << " 1 )" <<ptr[i].mark.Course1<< "\t       " << ptr[i].attendance.status1 << "      " << ptr[i].attendance.date1 << endl;
            cout << " 2 )"<<ptr[i].mark.Course2 << "\t       " << ptr[i].attendance.status2 << "      " << ptr[i].attendance.date2 << endl;
            cout << " 3 )" <<ptr[i].mark.Course3<< "\t       " << ptr[i].attendance.status3 << "      " << ptr[i].attendance.date3 << endl;
        }
        if (stufound == false)
        {
            break;
        }

    }

}

void Admin::ViewScore(string id)
{


    ifstream reader;
    reader.open("studentcount.csv");
    string line1 = "";
    getline(reader, line1);
    stringstream ss(line1);
    string temp = "";
    getline(ss, temp);
    student_count = stoi(temp);
    reader.close();
    Admin* ptr = new Admin[student_count];
    ifstream fin;
    fin.open("Students.csv");
    string line2 = "";
    getline(fin, line2);
    line2 = "";
    int i = 0;
    while (i < student_count && getline(fin, line2))
    {
        stringstream s2(line2);
        getline(s2, ptr[i].S_id, ',');
        getline(s2, ptr[i].S_password, ',');
        getline(s2, ptr[i].S_name, ',');
        getline(s2, ptr[i].S_Fname, ',');
        getline(s2, ptr[i].S_gender, ',');
        getline(s2, ptr[i].S_cnic, ',');
        getline(s2, ptr[i].S_contact, ',');
        getline(s2, ptr[i].S_address, ',');
        getline(s2, ptr[i].feestatus, ',');
        getline(s2, ptr[i].S_department, ',');
        getline(s2, ptr[i].mark.Course1, ',');
        getline(s2, ptr[i].mark.marks1,',');
        getline(s2, ptr[i].mark.grade1, ',');
        getline(s2, ptr[i].mark.Course2, ',');
        getline(s2, ptr[i].mark.marks2, ',');
        getline(s2, ptr[i].mark.grade2, ',');
        getline(s2, ptr[i].mark.Course3, ',');
        getline(s2, ptr[i].mark.marks3, ',');
        getline(s2, ptr[i].mark.grade3, ',');
        getline(s2, ptr[i].attendance.status1, ',');
        getline(s2, ptr[i].attendance.date1, ',');
        getline(s2, ptr[i].attendance.status2, ',');
        getline(s2, ptr[i].attendance.date2, ',');
        getline(s2, ptr[i].attendance.status3, ',');
        getline(s2, ptr[i].attendance.date3, ',');
        i++;
    }
    fin.close();
    bool stufound = false;
    for (int i = 0; i < student_count; i++)
    {
        if (id == ptr[i].S_id)
        {
            stufound = true;
            cout << setw(3) << "COURSE" << setw(10) << "MARKS" << setw(11) << "GRADE\n\n";
            cout << "1)" << setw(2) << ptr[i].mark.Course1 << setw(10) << ptr[i].mark.marks1 << setw(9) << ptr[i].mark.grade1 << endl;
            cout << "2)" << setw(2) << ptr[i].mark.Course2 << setw(10) << ptr[i].mark.marks2 << setw(9) << ptr[i].mark.grade2 << endl;
            cout << "3)" << setw(2) << ptr[i].mark.Course3 << setw(10) << ptr[i].mark.marks3 << setw(9) << ptr[i].mark.grade3 << endl;
            int total = stoi(ptr[i].mark.marks1) + stoi(ptr[i].mark.marks2) + stoi(ptr[i].mark.marks3);
            cout << "\n\nTotal Score: " << total;

        }
        if (stufound == false)
        {
            break;
        }



    }
    delete[]ptr;
    ptr = NULL;

}

    void Admin:: ViewCourses(string id)
    {

        ifstream reader;
        reader.open("studentcount.csv");
        string line1 = "";
        getline(reader, line1);
        stringstream ss(line1);
        string temp = "";
        getline(ss, temp);
        student_count = stoi(temp);
        reader.close();
        Admin* ptr = new Admin[student_count];
        ifstream fin;
        fin.open("Students.csv");
        string line2 = "";
        getline(fin, line2);
        line2 = "";
        int i = 0;
        while (i < student_count && getline(fin, line2))
        {
            stringstream s2(line2);
            getline(s2, ptr[i].S_id, ',');
            getline(s2, ptr[i].S_password, ',');
            getline(s2, ptr[i].S_name, ',');
            getline(s2, ptr[i].S_Fname, ',');
            getline(s2, ptr[i].S_gender, ',');
            getline(s2, ptr[i].S_cnic, ',');
            getline(s2, ptr[i].S_contact, ',');
            getline(s2, ptr[i].S_address, ',');
            getline(s2, ptr[i].feestatus, ',');
            getline(s2, ptr[i].S_department, ',');
            getline(s2, ptr[i].mark.Course1, ',');
            getline(s2, ptr[i].mark.marks1, ',');
            getline(s2, ptr[i].mark.grade1, ',');
            getline(s2, ptr[i].mark.Course2, ',');
            getline(s2, ptr[i].mark.marks2, ',');
            getline(s2, ptr[i].mark.grade2, ',');
            getline(s2, ptr[i].mark.Course3, ',');
            getline(s2, ptr[i].mark.marks3, ',');
            getline(s2, ptr[i].mark.grade3, ',');
            getline(s2, ptr[i].attendance.status1, ',');
            getline(s2, ptr[i].attendance.date1, ',');
            getline(s2, ptr[i].attendance.status2, ',');
            getline(s2, ptr[i].attendance.date2, ',');
            getline(s2, ptr[i].attendance.status3, ',');
            getline(s2, ptr[i].attendance.date3, ',');
            i++;
        }
        fin.close();
        bool stufound = false;
        for (int i = 0; i < student_count; i++)
        {
            if (id == ptr[i].S_id)
            {
                stufound = true;
                cout << "\nRegistered Courses\n";
                cout << "----------------------\n";
                cout << "1)" << ptr[i].mark.Course1 << endl;
                cout << "2)" << ptr[i].mark.Course2 << endl;
                cout << "3)" << ptr[i].mark.Course3 << endl;
            }
            if (stufound == false)
            {
                break;
            }



        }
        delete[]ptr;
        ptr = NULL;

    }
    void Admin::ViewFeeStatus(string id)
    {

        ifstream reader;
        reader.open("studentcount.csv");
        string line1 = "";
        getline(reader, line1);
        stringstream ss(line1);
        string temp = "";
        getline(ss, temp);
        student_count = stoi(temp);
        reader.close();
        Admin* ptr = new Admin[student_count];
        ifstream fin;
        fin.open("Students.csv");
        string line2 = "";
        getline(fin, line2);
        line2 = "";
        int i = 0;
        while (i < student_count && getline(fin, line2))
        {
            stringstream s2(line2);
            getline(s2, ptr[i].S_id, ',');
            getline(s2, ptr[i].S_password, ',');
            getline(s2, ptr[i].S_name, ',');
            getline(s2, ptr[i].S_Fname, ',');
            getline(s2, ptr[i].S_gender, ',');
            getline(s2, ptr[i].S_cnic, ',');
            getline(s2, ptr[i].S_contact, ',');
            getline(s2, ptr[i].S_address, ',');
            getline(s2, ptr[i].feestatus, ',');
            getline(s2, ptr[i].S_department, ',');
            getline(s2, ptr[i].mark.Course1, ',');
            getline(s2, ptr[i].mark.marks1, ',');
            getline(s2, ptr[i].mark.grade1, ',');
            getline(s2, ptr[i].mark.Course2, ',');
            getline(s2, ptr[i].mark.marks2, ',');
            getline(s2, ptr[i].mark.grade2, ',');
            getline(s2, ptr[i].mark.Course3, ',');
            getline(s2, ptr[i].mark.marks3, ',');
            getline(s2, ptr[i].mark.grade3, ',');
            getline(s2, ptr[i].attendance.status1, ',');
            getline(s2, ptr[i].attendance.date1, ',');
            getline(s2, ptr[i].attendance.status2, ',');
            getline(s2, ptr[i].attendance.date2, ',');
            getline(s2, ptr[i].attendance.status3, ',');
            getline(s2, ptr[i].attendance.date3, ',');
            i++;
        }
        fin.close();
        bool stufound = false;
        for (int i = 0; i < student_count; i++)
        {
            if (id == ptr[i].S_id)
            {
                cout << "Name: " << ptr[i].S_name << ptr[i].S_Fname << endl;
                cout << "Student ID: " << ptr[i].S_id<<endl;
                cout << "Status: " << ptr[i].feestatus << endl;
            }
            if (stufound == false)
            {
                break;
            }



        }
        delete[]ptr;
        ptr = NULL;


    }



