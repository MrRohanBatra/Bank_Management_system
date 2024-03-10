#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<windows.h>
#include<fstream>
#include<conio.h>
using namespace std;

// Function prototypes
void welcome();
void employees();
void customers();
string getpass();
void preloadtest();
bool checkfilepass(string a);
bool loginsystem();
string inttostring(int num);
int reademployees();
void incrementemployees();
void addemployees();

//class prototypes
class employee;
class customer;


//employees function
void employees() 
{
    int choice;
    cout << "\t\t\t            JAYPEE BANKS              \n";
    cout<<"1. Add Employee"<<endl;
    cout<<"2. Modify Employee"<<endl;
    cout<<"3. Delete Employee"<<endl;
    cout<<"4. Display Employees"<<endl;
    cout<<"5. Tax Payable"<<endl;
    cout<<"6. Generate Payroll Report"<<endl;
    cout<<"7. Generate Payroll Slip"<<endl;
    cout<<"8. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {   
            addemployees();
        }
    }
}

//cusotmers function
void customers() 
{
    cout << "Customers management function called." << endl;
}

// Function to create necessary directories
void preloadtest() 
{
    std::string sources[4];
    // Define directory paths
    sources[3] = "sources\\employees\\payroll_slips";
    sources[0] = "sources\\customers";
    sources[1] = "sources\\employees";
    sources[2] = "sources\\password";

    // Create directories
    for (int i = 0; i < 4; i++) {
        string command = "mkdir " + sources[i] + " > nul 2>&1"; // Redirect output to null device
        system(command.c_str());
    }
}

// Function to handle login system
bool loginsystem() {
    int count = 0;
    while (count < 3) {
        cout << "Enter password: ";
        string temp;
        temp = getpass();
        if (checkfilepass(temp)) {
            system("color 71"); // Change console color
            cout << "Welcome " << temp << " to JAYPEE BANKS" << endl;
            return true;
        }
        else if (temp == "exit") {
            return false;
        }
        system("color 74"); // Change console color
        cout << "Incorrect password!\nPlease retry" << endl;
        count++;
    }
    return false;
}

// Function to check password from file
bool checkfilepass(string a) 
{
    string temp;
    ifstream file("sources\\password\\password");
    while (getline(file, temp)) {
        if (a == temp) {
            return true;
        }
    }
    return false;
}

// Function to display welcome message
void welcome() 
{
    system("cls"); // Clear screen
    system("color 70"); // Change console color
    cout << "\t\t\t______________________________________\n";
    cout << "\t\t\t|           JAYPEE BANKS             |\n";
    cout << "\t\t\t|____________________________________|\n";
    cout << "\t\t\t|      Project developed by:         |\n";
    cout << "\t\t\t|      Rohan Batra           23104056|\n";
    cout << "\t\t\t|                                    |\n";
    cout << "\t\t\t|                                    |\n";
    cout << "\t\t\t|____________________________________|\n\n";
    cout << "\t\t\t  Press any key to continue...      ";
    getch(); // Wait for user input
    cout << endl;
    system("color 71"); // Change console color
}

// Function to get password from user
string getpass() 
{
    string temp = "";
    char c;
    while (true) {
        c = getch(); // Get character input without echoing to console
        if (c != 13) {
            cout << "*"; // Print '*' to mask password
            temp = temp + c;
        }
        else if (c == 13) {
            break;
        }
    }
    cout << endl;
    return temp;
}

// Function to display main menu
void maimenu() 
{
    system("cls"); // Clear screen
    cout << "\t\t\t            JAYPEE BANKS              \n";
    cout << endl << endl << endl;
    cout << "\t\t\t1)Employees Management" << endl;
    cout << "\t\t\t2)Customers Management" << endl;
    cout << "\t\t\t3)Exit" << endl;
    cout << "\t\t\tEnter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            employees();
            break;
        case 2:
            customers();
            break;
    }
}

// Function to convert integer to string
string inttostring(int num) 
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

// Employee class definition
class employee 
{
    private:
        string name;
        static int next;
        int age;
        string department;
        float salary;
    public:
        int id = next++;
        float net_salary() {
            float net;
            float deductions;
            float allowances;
            deductions = salary * 0.1;
            allowances = salary * 0.05;
            net = salary - deductions + allowances;
            return net;
        }
        float tax() {
            float tax;
            if (salary <= 500000) {
                tax = 0.1 * salary;
            }
            else if (salary > 500000 && salary <= 1000000) {
                tax = 50000 + (salary - 500000) * 0.2;
            }
            else if (salary > 100000) {
                tax = 150000 + (salary - 1000000) * 0.3;
            }
            return tax;
        }
        // Constructor
        employee() \
        {

        }
        employee(string n, int a, string dept, float sal) {
            this->name = n;
            this->department = dept;
            if (a >= 18) {
                this->age = a;
            }
            else {
                this->age = 0;
            }
            this->salary = sal;
            cout << "Employee ID generated: " << id << endl;
        }
        // Overloaded stream insertion operator
        friend ostream &operator<<(ostream &out, employee &obj) {
            out << "Name:        " << obj.name << endl
                << "ID:         " << obj.id << endl
                << "Age:        " << obj.age << endl
                << "Salary:     " << obj.salary << endl
                << "Department: " << obj.department << endl;
            return out;
        }
        // Method to save employee data to file
        void savetofile() {
            ofstream fobj;
            fobj.open("sources\\employees\\" + inttostring(id));
            if (fobj.is_open()) {
                fobj << name << endl
                    << id << endl
                    << age << endl
                    << salary << endl
                    << department << endl;
            }
            else {
                cout << "Failed to open file for writing." << endl;
            }
        }
        // Method to generate payroll slip
        void generate_payrollslip() {
            ofstream fobj;
            string id1 = inttostring(id);
            string filepath = "sources\\employees\\payroll_slips\\" + id1 + ".txt";
            fobj.open(filepath);
            if (fobj.is_open()) {
                string l = "-------------------------";
                fobj << "\t\t\t______________________________________\n"
                    << "\t\t\t|           JAYPEE BANKS             |\n"
                    << "\t\t\t|____________________________________|\n";
                fobj << l << endl;
                fobj << "Payroll Slip" << endl
                    << l << endl
                    << "Employee Name: " << name << endl
                    << "Employee Age: " << age << endl
                    << "Employee ID: " << id << endl
                    << "Department: " << department << endl
                    << "Gross Salary: " << salary << endl
                    << l << endl
                    << "Net Salary: " << net_salary() << endl
                    << "Tax Payable: " << tax() << endl;
                fobj.close();
                cout << "Payroll Slip saved to " << filepath << endl;
                string execute = "notepad.exe " + filepath; // Open generated payroll slip in Notepad
                system(execute.c_str());
            }
            else {
                cout << "Error in generating payroll slip" << endl;
            }
        }
        // Method to load employee data from file
        employee loaddata() {
            ifstream fobj;
            employee temp;
            fobj.open("sources\\employees\\" + inttostring(id));
            if (fobj.is_open()) {
                getline(fobj, temp.name);
                fobj >> temp.id >> temp.age >> temp.salary;
                fobj >> ws;
                getline(fobj, temp.department);
                fobj.close();
            }
            else {
                cout << "Failed to open file for reading." << endl;
            }
            return temp;
        }
};

//Employee class static int variable next defined
int employee::next = 23104001+reademployees();
int main() {
    addemployees();
    return 0;
}


//incrementemployees function
void incrementemployees()
{
    ifstream file;
    int count;
    file.open("sources\\employees\\!");
    if(file.is_open())
    {
        file>>count;
        count++;
        file.close();
        ofstream f;
        f.open("sources\\employees\\!");
        if(f.is_open())
        {
            f<<count;
        }
    }
}

//addemployees function
void addemployees()
{
    string n, depart;
    int a;
    float sal;
    cout << "Employee Name: ";
    // cin.ignore();
    getline(cin, n);
    cout << "Employee Age: ";
    cin >> a;
    cout << "Employee Department: ";
    cin.ignore();
    getline(cin, depart);
    cout << "Employee Salary: ";
    cin >> sal;
    employee newEmployee(n, a, depart, sal);
    newEmployee.savetofile();
    incrementemployees();
}


//reademployees function 
int reademployees()
{
    string fpath="sources\\employees\\!";
    ifstream file;
    int read;
    file.open(fpath);
    if(file.is_open())
    {
        file>>read;
        file.close();
    }
    else
    {
        ofstream file;
        file.open(fpath);
        if(file.is_open())
        {
            read=0;
            file<<read;
        }
        file.close();
    }
    return read;
}
