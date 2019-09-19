#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Student
{
	string first;//first name
	string last;//last name
	int age;
	double gpa;
	//default
	Student()
	{
		first = "First name not set";
		last = "Last name not set";
		age = 0;
		gpa = 0.0;

	}
	// explict constructor
	Student(string fname, string lname, int ag, double gp)
	{
		first = fname;
		last = lname;
		age = ag;
		if (gp <= 4.0)
		{
			gpa = gp;
		}
		else
		{
			cout << gp << " value of GPA is invalid. It is set to 0.0" << endl;
			gpa = 0.0;
		}
	}

	void print()
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "Name: " << first << ' ' << last << endl;
		cout << "Age: " << age << " years." << endl;
		cout << "GPA: " << gpa << endl;
	}

	void print(ofstream & out)
	{
		out << fixed << showpoint << setprecision(2);
		out << "Name: " << first << ' ' << last << endl;
		out << "Age: " << age << " years." << endl;
		out << "GPA: " << gpa << endl;
	}
	//getters or read access functions or acessors

	string getFirstName()
	{
		return first;
	}
	string getLastName()
	{
		return last;
	}

	int getAge()
	{
		return age;
	}

	double getGPA()
	{
		return gpa;
	}

	string getFullName()
	{
		return first + ' ' + last;
	}
	//setters or mutators
	void setLastName(string newLastName)
	{
		last = newLastName;
	}

	void setFirsttName(string newFirstName)
	{
		first = newFirstName;
	}

	void setAge(int newAge)
	{
		age = newAge;
	}

	void setGPA(double newGPA)
	{
		if (newGPA <= 4.0)
		{
			gpa = newGPA;
			return;
		}
		cout << newGPA << " is an invalid value. No changes made." << endl;
	}
};


int main()
{
	//use of student struct - one scenario
	//menu driven loop

	bool done = false;
	Student std;// default student object got created here

	while (!done)
	{
		cout << "*****Main Menu******" << endl
			<< "1. Create student object from keyboard data entry:" << endl
			<< "2. Print student data to console." << endl
			<< "3. Print student data to output file." << endl
			<< "4. Change student's last name:" << endl
			<< "5. Change student's age:" << endl
			<< "6. Change student's gpa:" << endl
			<< "7. print student's full name only to console:" << endl
			<< "8. Print student's GPA to console only:" << endl
			<< "9. Exit" << endl;
		int choice;
		cin >> choice;
		if (choice == 9)
		{
			done = true;
		}
		else if (choice == 1)
		{
			string frst, lst;
			int ag;
			double gp;
			cout << "Enter student's first name:";
			cin >> frst;
			cout << "Enter student's last name:";
			cin >> lst;
			cout << "Enter student's age on last birthday:";
			cin >> ag;
			cout << "Enter student's gpa:";
			cin >> gp;
			std = Student(frst, lst, ag, gp);
		}
		else if (choice == 2)
		{
			std.print();
		}
		else if (choice == 3)//output to file
		{
			//ask for file name
			string outFileName;
			cout << "Enter full path to output file: ";
			cin.sync();// Clean the buffer for getline. Use ignore on mac
			getline(cin, outFileName);
			ofstream out(outFileName);

			if (!out.is_open())
			{
				cout << "Failed to open output file. " << endl;
				out.clear();
				continue;
			}

			std.print(out);
			out.close();
		}
		else if (choice == 4)//change last name
		{
			cout << "Enter new last name: ";
			string newLastName;
			cin >> newLastName;
			std.setLastName(newLastName);
		}
		else if (choice == 5)//change age
		{
			cout << "Enter new age for student: ";
			int ag;
			cin >> ag;
			std.setAge(ag);
		}
		else if (choice == 6)//change GPA
		{
			cout << "Enter new GPA: ";
			double gp;
			cin >> gp;
			std.setGPA(gp);
		}
		else if (choice == 7)
		{
			cout << "To be completed " << endl;
		}
		else if (choice == 8)
		{
			cout << "To be completed " << endl;
		}
		else
		{
			cout << "This menu choice is not yetr implemented." << endl;
		}
	}//loop
}//main function
