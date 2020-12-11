#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

class Admin
{   private:
        string username,password;
    public:
        int deleteAllStudents();
        int registerStudent();
};
class teacher
{
    string username,password;
    int total=50;
    public:
        int marks();
        int Attendance();
        int Attendance(string);
        int ListOfStudents();
        int assignment(string username);
};

class student : public teacher
{
    string username,password;
    public:
        int studentView();
        int checkStudentCredentials(string username,string password);

};
class user: public teacher,public Admin
{

    public:
        int adminLogin();
        int teacherlogin();
        int studentView();
        int studentLogin();

};
int Admin::registerStudent()
{
int m = 0;
int k =0;
    cout<<"\n ----- Form to Register Student ---- \n";

    string name, username, password,subcampus,department,rollno;
     int total;

    cout<<"\n Enter Name : ";     cin>>name;

    cout<<"\n Enter Username : ";     cin>>username;


    cout<<"\n Enter password : ";     cin>>password;
    cout<<"\n Enter subcampus : ";     cin>>subcampus;
    cout<<"\n Enter department : ";     cin>>department;
    cout<<"\n Enter rollno : ";     cin>>rollno;
    getchar();
	cout<<"\n Enter initial number of presents :"; cin>>m;


    //check if record already exist..
    ifstream read;
    read.open("db.dat");

    if(read)
    {      int recordFound =0;
	   string line;
    	    while(getline(read, line)) {
        	if(line == username+".dat" )
        	{
        		recordFound = 1 ;
        	    break;
			}
        }
        if(recordFound == 1)
        {
        	cout<<"\n Username already Registered. Please choose another username ";
        	getchar(); getchar();
        	read.close();
        	return 0;
		}
	}
    read.close();

    ofstream out;
	out.open("db.dat", ios::app);
	out<<username+".dat"<<"\n";
	out.close();

	ofstream out1;
	string temp = username+".dat";
	out1.open(temp.c_str());
	out1<<name<<"\n"; 	out1<<username<<"\n"; 	out1<<password<<"\n";
	out1<<subcampus<<"\n"; out1<<department<<"\n"; out1<<rollno<<"\n";
	out1<<m<<"\n";
    out1.close();

	cout<<"\n Student Registered Successfully !!";

        cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;
}
int Admin::deleteAllStudents()
{
	remove("db.dat");
	cout<<"\n Please any key to continue..";

	getchar(); getchar();
	return 0;
}
int teacher:: Attendance()
{
    ifstream read;
    read.open("db.dat");

    if(read)
    {       int recordFound =0;
	    string line;
    	    while(getline(read, line)) {

    	    	char name[100];
    	    	strcpy(name, line.c_str());
    	    	string filename = name;

    int total_lines = 0;
            ifstream read1;
	read1.open(filename.c_str(), ios::app);
	string line;
	while(getline(read1,line)){
			++ total_lines;
		}
    read1.close();


	ifstream read;
	read.open(filename.c_str(), ios::app);
	// ifstream read;
	// read.open("db.dat");
    cout<<"name:"<<filename<<endl;
    int c;
    cout<<"1: present:"<<"\t"<<"O : absent:"<<endl;
    cout<<"enter choice:"<<endl;
    cin>>c;
    switch(c)
    {
        case 1:
                { string line;
                if(read)
                {
                    int line_no = 0;
                while (line_no != total_lines && getline(read, line)) {
                ++line_no;
                }
                if (line_no == total_lines) {
                    int i;
                    istringstream(line)>>i;
                    i++;

                    ofstream out1;
                    string temp = name;

                    out1.open(temp.c_str(), ios::app);
                    out1<<i<<"\n";

                }
                }
                break;
                }
        case 0:
                break;

    }

    read.close();
    }

    }
    read.close();

cout<<"\n Please any key to continue..";

getchar();getchar();

return 0;
}
int teacher::Attendance(string username)							// Function overloading
{		int total_lines = 0;
	string filename = username+".dat";


	ifstream read;
	read.open(filename.c_str(), ios::app);
	string line;
	while(getline(read,line)){
			++ total_lines;
		}

	read.close();


	ifstream read1;
	 read1.open(filename.c_str(), ios::app);
	if(read1)
	{
		int line_no = 0;

	while (line_no != total_lines && getline(read1, line)) {
    ++line_no;
	}
	if (line_no == total_lines) {

		cout<<"\nTotal present: "<<line;
		int i;
		istringstream(line) >> i;
		cout<<"\nPercentage of attendance :\t"<< (i*100/total)<<"%";
	}
	}
	cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;
}

int teacher::marks()
{   ifstream read;
    read.open("db.dat");

     if(read)
    {       int recordFound =0;
	    string line;
    	    while(getline(read, line)) {

    	    	char name[100];
    	    	strcpy(name, line.c_str());
    	    	string filename = name;

    int mark1,mark2,mark3,totalmarks;
	ifstream read;
	read.open(filename.c_str(), ios::app);
    cout<<"name:"<<filename<<endl;
    cout<<"\n"<<"ASSESMENT1:";
    cin>>mark1;
     cout<<"\n"<<"ASSESMENT2:";
                  cin>>mark2;
    cout<<"\n"<<"ASSIGNMENT:";
    cin>>mark3;
   totalmarks=(mark1+mark2+mark3)/3;
   cout<<"Total marks"<<totalmarks;
                char add[100];
	getchar();
	cin.getline(add, 100);

	ofstream out;
	out.open("marks.dat", ios::app);
	out<<add<<filename<<"\n"<<"ASSESMENT1: "<<mark1<<"\n"<<"ASSESMENT2:"<<mark2<<"\n"<<"ASSIGNMENT:"<<mark3<<"\n"<<"Total marks:"<<totalmarks<<"\n";
	out.close();


    read.close();
    	    }
    }
 return 0;
    }

int teacher::ListOfStudents(){
    cout<<"\n ---------- Check List of Student Registered by Username----------- ";

	    //check if record already exist..
    ifstream read;
    read.open("db.dat");

    if(read)
    {       int recordFound =0;
	    string line;
    	    while(getline(read, line)) {

				char name[100];
    	    	strcpy(name, line.c_str());
    	    	string filename = name;


				int total_lines = 0;
            ifstream read1;
			read1.open(filename.c_str(), ios::app);
			string line;
			while(getline(read1,line)){
				++ total_lines;
			}
    		read1.close();
			ifstream read;
			read.open(filename.c_str(), ios::app);
			string l;
			cout<<"\n"<<"Name   "<<"Username    "<<"Password  "<<"Subcampus"<<"Department"<<"Roll number    "<<"Attendance    "<<"\n";
                if(read)
                {
                    int line_no = 0;
                while (line_no != total_lines && getline(read, l)) {
                cout<<l<<"\t";
                line_no++;
                }

				read.close();
    	    	 char name[100];
    	    	 strcpy(name, line.c_str());
    	    	char onlyname[100];
    	    	 strcpy(onlyname, name);
    	    	 cout<<" \n " << onlyname;

            }
    read.close();
    }
	}
    else
    {
    	cout<<"\n No Record found :(";
    }


    cout<<"\n Please any key to continue..";
    getchar(); getchar();
    return 0;
}
int teacher::assignment(string username)
{
	char add[100];
	cout<<"\n Write your assignment here: ";
	getchar();
	cin.getline(add, 100);

	time_t now = time(0);
	tm *ltm = localtime(&now);

	ofstream out;
	out.open("application.dat", ios::app);
	out<<add<<" -> "<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<" -> "<<username<<"\n";
	out.close();
	cout<<"\n Application successfully sent !!";

	cout<<"\n Please any key to continue..";
	getchar();getchar();
	return 0;
}

int student::checkStudentCredentials(string username, string password)
{

	ifstream read;
	read.open("db.dat");
	int recordFound = 0;
	if (read) {
  		string line;
        string temp = username +".dat";
        while(getline(read, line)) {
        	if(line == temp)
        	{
        		recordFound = 1;
		}
        }
	}
    read.close();
        if(recordFound == 1)
            {
				ifstream read;
				string filename = username+".dat";
				read.open(filename.c_str(), ios::app);
				int line_number = 0;
				string line;
				while (line_number != 3 && getline(read, line)) {
                ++line_number;
                }
				if(password == line)
					return 1;
				else
					return 0;
			}
		else
			return 0;

}

int user::studentLogin()
{   student s;      // creating object of class studnet
    system("cls");
    cout<<"\n -------------------- Student Login ----------------------";
    s.studentView();
    return 0;
}

int student::studentView()
{
cout<<"\n Enter username : ";
cin>>username;

cout<<"\n Enter password : ";
cin>>password;

int res = checkStudentCredentials(username, password);

if(res  == 0)
{
   cout<<"\n Invalid Credentials !!";
   cout<<"\n Press any key for Main Menu..";
   getchar(); getchar();
   return 0;
}

    int goBack = 0;
	while(1)
    {

		system("cls");
		cout<<"\n 1 Count my Attendance";
		cout<<"\n 2 Send my assignment";
		cout<<"\n 0. Go Back <- \n";
		int choice;

		cout<<"\n Enter you choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1: Attendance(username); break;
			case 2: assignment(username);break;
			case 0: goBack = 1;break;
	                default: cout<<"\n Invalid choice. Enter again ";
	                getchar();
	   }

	   if(goBack == 1)
	   {
	   	break;
           }

   }

}


int user::teacherlogin()
{

    system("cls");
	cout<<"\n -------------------- Teacher Login ----------------------";

        string username;
	string password;

	cout<<"\n Enter username : ";
	cin>>username;
	cout<<"\n Enter password : ";
	cin>>password;

	if(username=="teacher" && password=="teacher")
	{   int goBack = 0;
    while(1)
    {
		system("cls");
		cout<<"\n 1 Mark Attendance";
		cout<<"\n 2 Enter Marks";
		cout<<"\n 3 Assignment";
		cout<<"\n 0. Go Back <- \n";
		int choice;

		cout<<"\n Enter you choice: ";
		cin>>choice;

		switch(choice)
		{			case 1: Attendance();break;
                    case 2: marks();break;
                    case 3: assignment(username);break;
			case 0: goBack = 1;break;
	                default: cout<<"\n Invalid choice. Enter again ";
	                 getchar();
	   }

	   if(goBack == 1)
	   {
	   	break;
           }
           }

	    getchar();
       }
    else
       {
        cout<<"\n Error ! Invalid Credentials..";
        cout<<"\n Press any key for main menu ";
        getchar();
      }
}


int user::adminLogin()
{
	system("cls");
	cout<<"\n -------------------- Admin Login --------------------";

    string username;
	string password;

	cout<<"\n Enter username : ";
	cin>>username;
	cout<<"\n Enter password : ";
	cin>>password;

	if(username=="admin" && password=="admin")
	{
	     int goBack = 0;
    while(1)
    {
		system("cls");
		cout<<"\n 1 Register a Student";
		cout<<"\n 2 Delete All students name registered";
		cout<<"\n 3 Check List of Student registered by username";
		cout<<"\n 0. Go Back <- \n";
		int choice;

		cout<<"\n Enter you choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1: registerStudent();break;
			case 2: deleteAllStudents(); break;
			case 3: ListOfStudents(); break;
			case 0: goBack = 1;break;
	                default: cout<<"\n Invalid choice. Enter again ";
	                 getchar();
	   }

	   if(goBack == 1)
	   {
	   	break;
           }

	    getchar();
       }}
       else
       {
        cout<<"\n Error ! Invalid Credintials..";
        cout<<"\n Press any key for main menu ";
        getchar();getchar();
      }

   return 0;

}



int main(int argc, char** argv) {
   user t;
	while(1)
	{
		system("cls");

		cout<<"\t\t\t\t\t E-Class Management System \n";
		cout<<"------------------------------------------------------------------------------------------------------------------------\n\n";

		cout<<"1. Student Login\n";
		cout<<"2. Admin Login\n";
		cout<<"3. Teacher Login\n";
		cout<<"0. Exit\n";
		int choice;

		cout<<"\n Enter you choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1: t.studentLogin(); break;
			case 2: t.adminLogin(); break;
			case 3: t.teacherlogin();break;
			case 0:
			        while(1)
			        {
					    system("cls");
			        	cout<<"\n Are you sure, you want to exit? y | n \n";
			        	char ex;
			        	cin>>ex;
			        	if(ex == 'y' || ex == 'Y')
			        		exit(0);
			        	else if(ex == 'n' || ex == 'N')
	                     {
	                     	 break;
	                     }
	                     else{

	                     	cout<<"\n Invalid choice !!!";
	                     	getchar();
	                     }


                 	 }	break;

            default: cout<<"\n Invalid choice. Enter again ";
                     getchar();

		}

	}

	return 0;
}

