#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<sstream>
#include<conio.h>
#include<limits>

using namespace std;

// Function prototypes
int newgetdataint();
long long int newgetdatalint();
void welcome();
void employees();
void customers();
void preloadtest();
bool checkfilepass(string a);
bool loginsystem();
string getpass();
string inttostring(int num);
string newgetdata();
string toLowercase(const string& str);
int reademployees();
float grosssalary(float sal);
void incrementemployees();
void addemployees();
void modifyemployees();
void deleteemployees();
void mainmenu();
void displayemployees();    
void taxpayble();          
float taxpayble(string temp);
void GeneratePayrollReport();
void GeneratePayrollSlip();
float newgetdatafloat();
void branchcodes();
int readcustomers();
void display_customers();
void addcustomer();
void modifycustomer();
void deletecustomer(){}
void changebranch(){}
void generatepassbook(){}
void depositmoney(){}
void withrawmoney(){}
string getdob();
string getbranch(int a);

//class prototypes
class employee;
class customer;


//employees function
void employees() 
{
    int choice;
    system("cls");
    cout << "\t\t\t            JAYPEE BANKS              \n";
    cout<<"1. Add Employee"<<endl;
    cout<<"2. Modify Employee"<<endl;
    cout<<"3. Delete Employee"<<endl;
    cout<<"4. Display Employees"<<endl;
    cout<<"5. Tax Payable"<<endl;
    cout<<"6. Generate Payroll Report" << endl;
    cout<<"7. Generate Payroll Slip"<<endl;
    cout<<"8. Exit to previous menu"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {   cin.ignore();
            addemployees();
            system("pause");
            employees();
            break;
        }
        case 2:
        {
            modifyemployees();
            system("pause");
            employees();
            break;
        }
        case 3:
        {
            deleteemployees();
            system("pause");
            employees();
            break;
        }
        case 4:
        {
            displayemployees();
            system("pause");
            employees();
            break;
        }
         case 5:
        {
            taxpayble();
            system("pause");
            employees();
            break;
        }
        case 6:
        {
            GeneratePayrollReport();
            system("pause");
            employees();
            break;
        }
        case 7:
        {
            GeneratePayrollSlip();
            system("pause");
            employees();
            break;
        }
        case 8:
        {
            mainmenu();
            break;
        }
        default:
        {
            cout<<"Incorrect Choice"<<endl;
            employees();
        }
    }
}

//cusotmers function
void customers() 
{
    int choice;
    system("cls");
    cout << "\t\t\t            JAYPEE BANKS              \n";
    // cout << "Customers management function called." << endl;
    cout<<"1) Add Customer"<<endl
        <<"2) Modify Customer"<<endl
        <<"3) Delete Customer"<<endl
        <<"4) Change Branch"<<endl
        <<"5) Generate Passbook"<<endl
        <<"6) Display Data"<<endl
        <<"7) Deposit Money"<<endl
        <<"8) Withdraw Money"<<endl
        <<"9) Exit to previous menu"<<endl
        <<"Enter you choice: ";
    cin>>choice;
    switch (choice)
    {
        case 1:
        {
            addcustomer();
            customers();
            break;
        }
        case 2:
        {
            modifycustomer();
            customers();
            break;
        }
        case 3:
        {
            deletecustomer();
            customers();
            break;
        }
        case 4:
        {
            changebranch();
            customers();
            break;
        }
        case 5:
        {
            generatepassbook();
            customers();
            break;
        }
        case 6:
        {
            display_customers();
            customers();
            break;
        }
        case 7:
        {
            depositmoney();
            customers();
            break;
        }
        case 8:
        {
            withrawmoney();
            customers();
            break;
        }
        case 9:
        {
            mainmenu();
            break;
        }
        default:
        {
            system("color 74");
            cout<<"Incorrect Choice !"<<endl;
            system("timeout /t 2 /nobreak >null");
            customers();
            break;
        }
    }
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
    ifstream fobj;
    fobj.open(sources[2]+"\\password");
    if(fobj.is_open())
    {
        fobj.close();
    }
    else if(!fobj.is_open())
    {
        fobj.close();
        ofstream fobj1;
        fobj1.open(sources[2]+"\\password");
        if(fobj1.is_open())
        {
            fobj1<<"rohan"<<endl;
            fobj1<<"admin"<<endl;
            fobj1<<"shubham"<<endl;
        }
        fobj1.close();
    }
    fobj.close();
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
void mainmenu() 
{
    system("cls"); // Clear screen
    cout << "\t\t\t            JAYPEE BANKS              \n";
    cout << endl << endl << endl;
    cout << "\t\t\t1)Employees Management" << endl;
    cout << "\t\t\t2)Customers Management" << endl;
    cout << "\t\t\t3)Exit to Desktop" << endl;
    cout << "\t\t\tEnter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
        {
            employees();
        }    break;
        case 2:
        {    
            customers();
        }     break;
        case 3:
        {
            cout<<"thanks for using the project!"<<endl;
            break;
        }
        default:
        {
            cout<<"Incorrect Choice !"<<endl;
            mainmenu();
            break;
        }
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
        float net_salary() 
        {
            float net;
            float deductions;
            float allowances;
            deductions = salary * 0.1;
            allowances = salary * 0.05;
            net = salary - deductions + allowances;
            return net;
        }
        friend void modifyemployees();
        float tax() 
        {
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
        employee() 
        {

        }

        employee(string n, int a, string dept, float sal) 
        {
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
        friend ostream &operator<<(ostream &out, employee &obj) 
        {
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
        employee loaddata() 
        {
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

//CUSTOMERS class defined
class customer
{
    private:
        string name;
        string address;
        string branchCode;
        long long int mobileNumber;
        float balance;
        long long int accountNumber;
        string accountType;
        string dateOfBirth;
        string emailAddress;
        string kycDocuments[2];
    public:
        static int next;
        customer(){}
        customer(customer &obj)
        {
            this->name=obj.name;
            this->address=obj.address;
            this->branchCode=obj.branchCode;
            this->mobileNumber=obj.mobileNumber;
            this->balance=obj.balance;
            this->accountNumber=obj.accountNumber;
            this->accountType=obj.accountType;
            this->dateOfBirth=obj.dateOfBirth;
            this->emailAddress=obj.emailAddress;
            this->kycDocuments[0]=obj.kycDocuments[0];
            this->kycDocuments[1]=obj.kycDocuments[1];   
        }
        customer(string n,string add,string branch,long long int mob,float bal,string acctype,string dob,string email,string kyc[])
        {
            name=n;
            address=add;
            branchCode=branch;
            mobileNumber=mob;
            balance=bal;
            accountNumber=next++;
            accountType=acctype;
            dateOfBirth=dob;
            emailAddress=email;
            for(int i=0;i<2;i++)
            {
                kycDocuments[i]=kyc[i];
            }
            cout<<"Account Number generated: "<<accountNumber<<endl;
        }
        void getcustomer(string n,long long int accno,string add,string branch,long long int mob,float bal,string acctype,string dob,string email,string kyc[])
        {
            name=n;
            accountNumber=accno;
            address=add;
            branchCode=branch;
            mobileNumber=mob;
            balance=bal;
            accountNumber=next++;
            accountType=acctype;
            dateOfBirth=dob;
            emailAddress=email;
            for(int i=0;i<2;i++)
            {
                kycDocuments[i]=kyc[i];
            }
        }
        customer loaddata()
        {
            customer loaded;
            ifstream fobj;
            fobj.open("sources\\customers\\"+inttostring(accountNumber));
            if(fobj.is_open())
            {
                getline(fobj,loaded.name);
                getline(fobj,loaded.address);
                getline(fobj,loaded.branchCode);
                fobj>>loaded.mobileNumber;
                fobj>>loaded.balance;
                fobj>>loaded.accountNumber;
                fobj.ignore();
                getline(fobj,loaded.accountType);
                getline(fobj,loaded.dateOfBirth);
                getline(fobj,loaded.emailAddress);
                getline(fobj,loaded.kycDocuments[0]);
                getline(fobj,loaded.kycDocuments[1]);
            }
            fobj.close();
            return loaded;
        }
        void savedata()
        {
            ofstream fobj;
            fobj.open("sources\\customers\\"+inttostring(accountNumber));
            if(fobj.is_open())
            {
                fobj<<name<<endl
                    <<address<<endl
                    <<branchCode<<endl
                    <<mobileNumber<<endl
                    <<balance<<endl
                    <<accountNumber<<endl
                    <<accountType<<endl
                    <<dateOfBirth<<endl
                    <<emailAddress<<endl
                    <<kycDocuments[0]<<endl
                    <<kycDocuments[1]<<endl;
            }
            fobj.close();
        }
};

void display_customers()
{
    int accno;
    cout<<"Enter Account Number: "<<accno;
    ifstream fobj;
    fobj.open("sources\\customers\\"+inttostring(accno));
    string name;
    string address;
    string branchCode;
    long long int mobileNumber;
    float balance;
    string accountType;
    string dateOfBirth;
    string emailAddress;
    string kycDocuments[2];
    if(fobj.is_open())
    {
        int accountNumber;
        getline(fobj,name);
        getline(fobj,address);
        getline(fobj,branchCode);
        fobj>>mobileNumber;
        fobj>>balance;
        fobj>>accountNumber;
        fobj.ignore();
        getline(fobj,accountType);
        getline(fobj,dateOfBirth);
        getline(fobj,emailAddress);
        getline(fobj,kycDocuments[0]);
        getline(fobj,kycDocuments[1]);
        fobj.close();
        cout<<"Cusotmer details are:-"<<endl
            <<"Name: "<<name<<endl
            <<"Account Number: "<<accno<<endl
            <<"Account Type: "<<accountType<<endl
            <<"Account Balance: "<<balance<<endl
            <<"Address: "<<address<<endl
            <<"Date of Birth: "<<dateOfBirth<<endl
            <<"Mobile Number: "<<mobileNumber<<endl
            <<"Email Address: "<<emailAddress<<endl
            <<"KYC document: "<<kycDocuments[0]<<" authentication number: "<<kycDocuments[1]<<endl;
    }
    else
    {
        fobj.close();
        system("color 74");
        cout<<"Incorrect Employee ID !"<<endl;
        system("timout /t 2 /nobreak >null");
        system("color 71");
    }
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
            f.close();
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


void displayemployees()
{
    system("cls");
    string temp;
    cout<<"Enter Employee ID: ";
    cin>>temp;
    ifstream fobj;
    fobj.open("sources\\employees\\"+temp);
    if(fobj.is_open())
    {   cout<<"Searching!"<<endl;
        system("timeout /t 2 /nobreak >null");
        cout<<"Found!\nEmployee Details are:"<<endl;
        string name,depart;
        int age,temp1;
        float sal;
        getline(fobj,name);
        fobj>>temp1;
        fobj>>age;
        fobj>>sal;
        fobj.ignore();
        getline(fobj,depart);
        string l = "----------------------------------";
        cout<<l<<endl;
        cout<<"Employee Name:        "<<name<<endl
            <<"employee ID:          "<<temp<<endl
            <<"Employee Age:         "<<age<<endl
            <<"Employee Salary:      "<<fixed<<setprecision(3)<<sal<<endl
            <<"Employee Department : "<<depart<<endl
            <<l<<endl;
        
    }
    else if(!fobj.is_open())
    {
        system("cls");
        system("color 74");
        cout<<"Employee ID not found "<<endl;
        system("timeout /t 1 /nobreak >nul");
        //displayemployees();
    }
    fobj.close();
}

void modifyemployees() {
    system("cls");
    int id;
    cout << "Enter Employee ID: ";
    cin >> id;
    ifstream fobj;
    fobj.open("sources\\employees\\" + inttostring(id));
    if (fobj.is_open()) {
        string name, depart;
        int age;
        float sal;
        getline(fobj, name); // Read and discard the newline character left in the stream
        fobj >> id;
        fobj.ignore(); // Ignore the newline character left in the stream after reading id
        fobj >> age;
        fobj.ignore(); // Ignore the newline character left in the stream after reading age
        fobj >> sal;
        fobj.ignore(); // Ignore the newline character left in the stream after reading salary
        getline(fobj, depart); // Read the department using getline
        fobj.close();

        string new_name, new_depart;
        int new_age;
        float new_sal;
        cout << "********************************************************************" << endl;
        cout << "Modify Employee details leave blank for no updation just press enter" << endl;
        cout << "********************************************************************" << endl;
        cout << "Employee ID: " << id << "    it can be modified " << endl;
        cout << "Employee Name: " << name << "    ";
        new_name = newgetdata();
        cout << "Employee Age: " << age << "    ";
        new_age = newgetdataint();
        cout << "Employee Department: " << depart << "    ";
        new_depart = newgetdata();
        cout << "Employee Salary: " << sal << "    ";
        new_sal = newgetdatafloat();
        cout << "********************************************************************" << endl;
        string confirmation;
        cout << "Are you sure you want to modify the original data? (yes/no): ";
        cin >> confirmation;
        if (confirmation == "yes" || confirmation == "YES" || confirmation == "Y") {
            ofstream fobj;
            fobj.open("sources\\employees\\" + inttostring(id));
            if (fobj.is_open()) {
                fobj << (new_name.empty() ? name : new_name) << endl
                     << id << endl
                     << (new_age == 0 ? age : new_age) << endl
                     << (new_sal == 0.0f ? sal : new_sal) << endl
                     << (new_depart.empty() ? depart : new_depart) << endl;
                fobj.close();
                cout << "********************************************************************" << endl;
                cout << "Data Modified!" << endl;
                cout << "********************************************************************" << endl;
            } 
            else 
            {
                cout << "Error: Unable to open file for writing." << endl;
            }
        } 
        else 
        {
            cout << "Modification aborted." << endl;
        }
    } else {
        system("color 74");
        cout << "Employee ID not found! Please retry" << endl;
    }
    system("color 71");
}

void modifycustomer()
{
    system("cls");
    string name;
    string address;
    string branchCode;
    long long int mobileNumber;
    float balance;
    long long int accountNumber;
    string accountType;
    string dateOfBirth;
    string emailAddress;
    string kycDocuments[2];
    cout << "Enter Account Number: ";
    cin>>accountNumber;
    ifstream fobj;
    fobj.open("sources\\customers\\" + inttostring(accountNumber));
    if (fobj.is_open()) 
    {
        getline(fobj,name);//
        getline(fobj,address);//
        getline(fobj,branchCode);//
        fobj>>mobileNumber;//
        fobj>>balance;//
        fobj>>accountNumber;//
        fobj.ignore();
        getline(fobj,accountType);//
        getline(fobj,dateOfBirth);//
        getline(fobj,emailAddress);//
        getline(fobj,kycDocuments[0]);//
        getline(fobj,kycDocuments[1]);//
        fobj.close();
        string new_name;
        string new_address;
        string new_branchCode;
        long long int new_mobileNumber;
        float new_balance;
        long long int new_accountNumber;
        string new_accountType;
        string new_dateOfBirth;
        string new_emailAddress;
        string new_kycDocuments[2];
        cout << "********************************************************************" << endl;
        cout << "Modify Customer details leave blank for no updation just press enter" << endl;
        cout << "********************************************************************" << endl;
        cout << "Account Number: " << accountNumber << "    it can be modified " << endl;
        new_accountNumber=accountNumber;
        cout << "Name: " << name << "    ";
        new_name = newgetdata();
        cout << "Branch: " << branchCode  << "    use CHANGE BRANCH OPTION from mainmenu" << endl;
        new_branchCode=branchCode;
        cout<< "Address: "<<address<<"    ";
        new_address=newgetdata();
        cout << "Mobile Number: " << mobileNumber << "    ";
        cin.ignore();
        new_mobileNumber = newgetdatalint();
        cout << "Balance: " << balance << "    use DEPOSIT and WITHRAW option from the mainmenu"<<endl;
        new_balance=balance;
        cout << "Account Type: " << accountType << "    ";
        new_accountType = newgetdata();
        cout<<"Date Of Birth: "<<dateOfBirth<<"    ";
        new_dateOfBirth=getdob();
        cout<<"Email Address: "<<emailAddress<<"    ";
        new_emailAddress=newgetdata();
        cout<<"Kyc Document: "<<kycDocuments[0]<<"    ";
        new_kycDocuments[0]=newgetdata();
        if(toLowercase(new_kycDocuments[0])!=toLowercase(kycDocuments[0]))
        {
            cout<<kycDocuments[0]<<" number: "<<kycDocuments[1]<<"    "<<new_kycDocuments[0]<<" number: ";
            new_kycDocuments[1]=newgetdata();
        }
        cout << "********************************************************************" << endl;
        string confirmation;
        cout << "Are you sure you want to modify the original data? (yes/no): ";
        cin >> confirmation;
        if(toLowercase(confirmation)=="yes" || toLowercase(confirmation)=="y")
        {
            customer temp;
            temp.getcustomer(new_name,new_accountNumber,new_address,new_branchCode,new_mobileNumber,new_balance,new_accountType,new_dateOfBirth,new_emailAddress,new_kycDocuments);
            temp.savedata();
            cout << "********************************************************************" << endl;
            cout << "Data Modified!" << endl;
            cout << "********************************************************************" << endl;   
        }
        else
        {
            cout << "********************************************************************" << endl;
            cout << "Data NOT Modified!" << endl;
            cout << "********************************************************************" << endl;   
        }
    }
    system("timeout /t 2 /nobreak >null");
}

string newgetdata()
{
    string temp = "";
    char c;
    while (true) {
        c = getch(); // Get character input without echoing to console
        if (c != 13) {
            cout<<c;
            temp = temp + c;
        }
        else if (c == 13) {
            break;
        }
    }
    cout << endl;
    return temp;
}

int newgetdataint()
{
    string number;  
    while (true) 
    {
        char ch = getch(); 
        if (ch == 13) 
            break; // Exit the loop if Enter key is pressed

        number = number+ch;
        cout<<ch;
    }
    cout<<endl;
    // Convert the character to integer and return it
    return stoi(number);
}

long long int newgetdatalint() {
    string number;
    char ch;
    while (true) {
        ch = getchar(); // Read a character from standard input
        if (ch == '\n') // Exit the loop if Enter key is pressed
            break;
        else if (ch == '\b') { // Handle backspace
            if (!number.empty()) {
                cout << "\b \b"; // Move cursor back, erase character, move cursor back again
                number.pop_back(); // Remove last character from string
            }
        }
        else if (isdigit(ch)) {
            number += ch; // Append character to string
        }
    }
    //cout << endl; // Print newline after user presses Enter
    return stoll(number); // Convert the string to long long integer and return it
}

float newgetdatafloat() 
{
    string number;  
    while (true) {
        char ch = getch(); 
        if (ch == 13) 
            break; // Exit the loop if Enter key is pressed

        number += ch;
        cout << ch;
    }
    cout << endl;
    // Convert the string to float and return it
    return stof(number);
}

void deleteemployees()
{  system("color 71");
    string temp;
    cout<<"Enter Employee ID: ";
    cin>>temp;
    ifstream fobj;
    cout<<"Searching"<<endl;
    fobj.open("sources\\employees\\"+temp);
    system("timeout /t 1 /nobreak >nul");

    if(fobj.is_open())
    {
        fobj.close();
        string execute="cmd /c del sources\\employees\\"+temp;
        system(execute.c_str());
        cout<<"Employee Successfully Deleted"<<endl;
    }
    else
    {
        system("color 74");
        cout<<"Employee ID not found"<<endl;
    }
    fobj.close();
}

void taxpayble()
{
    system("cls");
    string temp;
    cout<<"Enter Employee ID: ";
    cin>>temp;
    cout<<"Searching!"<<endl;
    system("timeout /t 1 /nobreak >nul");
    ifstream fobj;
    fobj.open("sources\\employees\\"+temp);
    float salary;
    float tax;
    if(fobj.is_open())
    {
        string name,depart;
        int age,id;
        getline(fobj,name);
        fobj>>id;
        fobj>>age;
        fobj>>salary;
        fobj>>depart;
        if (salary <= 500000) 
        {
            tax = 0.1 * salary;
        }
        else if (salary > 500000 && salary <= 1000000) 
        {
        tax = 50000 + (salary - 500000) * 0.2;
        }
        else if (salary > 100000) 
        {
                tax = 150000 + (salary - 1000000) * 0.3;
        }
        cout<<"Gross Salary : "<<fixed<<setprecision(3)<<grosssalary(salary)<<endl;
        cout<<"Tax Payable : "<<fixed<<setprecision(3)<<tax<<endl;
    }
    else if(!fobj.is_open())
    {
        system("color 74");
        cout<<"Incorrect Employee ID"<<endl;
        system("timeout /t 2 /nobreak >nul");
    }
}

float taxpayble(string temp)
{
    ifstream fobj;
    fobj.open("sources\\employees\\"+temp);
    float salary;
    float tax;
    if(fobj.is_open())
    {
        string name,depart;
        int age,id;
        getline(fobj,name);
        fobj>>id;
        fobj>>age;
        fobj>>salary;
        fobj>>depart;
        if (salary <= 500000) 
        {
            tax = 0.1 * salary;
        }
        else if (salary > 500000 && salary <= 1000000) 
        {
        tax = 50000 + (salary - 500000) * 0.2;
        }
        else if (salary > 100000) 
        {
                tax = 150000 + (salary - 1000000) * 0.3;
        }
        return tax;
    }
    else if(!fobj.is_open())
    {
        system("color 74");
        cout<<"Incorrect Employee ID"<<endl;
        system("timeout /t 2 /nobreak >nul");
    }
}

float grosssalary(float sal)
{            
    float net;
    float deductions;
    float allowances;
    deductions = sal * 0.1;
    allowances = sal * 0.05;
    net = sal - deductions + allowances;
    return net;
}

void GeneratePayrollSlip()
{
    cout<<"Enter Employee ID: ";
    int id;
    cin>>id;
    ifstream fobj1;
    fobj1.open("sources\\employees\\"+inttostring(id));
    string name,depart;
    int age;
    float sal;
    if(fobj1.is_open())
    {
        getline(fobj1,name);
        fobj1>>id;
        fobj1>>age;
        fobj1>>sal;
        fobj1.ignore();
        getline(fobj1,depart);
        fobj1.close();
    }
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
                    << "Department: " << depart << endl
                    << "Gross Salary: " << setprecision(3)<<sal << endl
                    << l << endl
                    << "Net Salary: " << setprecision(3)<<grosssalary(sal) << endl
                    << "Tax Payable: " << setprecision(3)<<taxpayble(inttostring(id)) << endl;
                fobj<<"-------------------------"<<endl;
                fobj.close();
                cout << "Payroll Slip saved to " << filepath << endl;
                string execute = "notepad.exe " + filepath; // Open generated payroll slip in Notepad
                system(execute.c_str());
            }
            else {
                system("color 74");
                cout << "Error in generating payroll slip" << endl;
            }   
}

void GeneratePayrollReport()
{
    system("cls");
    cout<<"Enter Employee ID: ";
    int id;
    cin>>id;
    ifstream fobj;
    fobj.open("sources\\employees\\"+inttostring(id));
    string name,depart;
    int age;
    float sal;
    if(fobj.is_open())
    {   
        getline(fobj,name);
        fobj>>id;
        fobj>>age;
        fobj>>sal;
        getline(fobj,depart);
        system("cls");
        string l = "-------------------------";
        cout << "\t\t\t______________________________________\n"
            << "\t\t\t|           JAYPEE BANKS             |\n"
            << "\t\t\t|____________________________________|\n";
        cout << l << endl;
        cout << "Payroll Slip" << endl
            << l << endl
            << "Employee Name: " << name << endl
            << "Employee Age: " << age << endl
            << "Employee ID: " << id << endl
            << "Department: " << depart << endl
            << "Gross Salary: " << sal << endl
            << l << endl
            << "Net Salary: " << grosssalary(sal) << endl
            << "Tax Payable: " << taxpayble(inttostring(id)) << endl;
        cout<<"-------------------------"<<endl;
        fobj.close();
    }
    else if(!fobj.is_open())
    {
        system("color 74");
        cout<<"Incorrect Employee ID"<<endl;
        system("timeout /t 2 >null");
        system("color 71");
    }
}

void branchcodes()
{
    cout<<"Noida Sector 62, Uttar Pradesh:"<<"JPBN62UP"<<endl;
    cout<<"Noida Sector 128, Uttar Pradesh:"<<"JBPN128UP"<<endl;
    cout<<"Guna, Madhya Pradesh: "<<"JPBGMMP"<<endl;
    cout<<"Solan, Himachal Pradesh:"<<"JPBHSHP"<<endl;
}

int readcustomers()
{
    string fpath="sources\\customers\\!";
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

void addcustomer()
{
    string name;
    string address;
    string branchCode;
    long long int mobileNumber;
    float balance;
    long long int accountNumber;
    string accountType;
    string dateOfBirth;
    string emailAddress;
    string kycDocuments[2];
    cout<<"Enter Cusotmer Details:- "<<endl;
    cout<<"Name: ";
    getline(cin,name);
    cout<<"Address: ";
    getline(cin,address);
    cout<<"Date Of Birth: ";
    dateOfBirth=getdob();
    cout<<"Mobile Number: ";
    cin>>mobileNumber;
    cout<<"Balance: ";
    cin>>balance;
    cout<<"Account Type: ";
    cin>>accountType;
    cout<<"Email Address: ";
    cin>>emailAddress;
    cout<<"Enter KYC Document: ";
    cin>>kycDocuments[0];
    cout<<"Enter "<<kycDocuments[0]<<" number: ";
    cin>>kycDocuments[1];
    branchCode=getbranch(0);
}

string getdob()
{
    int count = 1;
    string dob;
    char c;
    while (count <= 8)
    {
        c = getch();
        if (c != 13)
        {
            if (count == 3 || count == 5)
            {
                dob = dob + ".";
                cout << ".";
            }
            dob = dob + c;
            cout << c;
            count++;
        }
    }
    cout<<endl;
    return dob;
}

string getbranch(int a)
{
    string branch[]={"JPBN62UP","JBPN128UP","JPBGMMP","JPBHSHP"};
    for(int i=0;i<4;i++)
    {
        if(i==a)
        {
            return branch[i];
        }
    }
}

string toLowercase(const string& str) {
    string result = str; // Make a copy of the input string
    
    // Loop through each character and convert to lowercase
    for (int i = 0; i < result.size(); ++i) {
        result[i] = tolower(result[i]); // Convert character to lowercase
    }
    
    return result;
}

//Employee class static int variable next defined
int employee::next = 23104001+reademployees();
//Customer class static int variable next defined
int customer::next=1+readcustomers();
int main() 
{
    preloadtest();
    welcome();
    if(loginsystem())
    {
        modifycustomer();
    }
    return 0;
}

