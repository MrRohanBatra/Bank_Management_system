#include<iostream>
#include<sstream>
#include<string>
#include<windows.h>
#include<fstream>
#include<conio.h>
using namespace std;
void welcome();
void employees();
void customers();
string getpass();
void preloadtest();
bool checkfilepass(string a);
bool loginsystem();
string inttostring(int num);
class employee;
class customer;
void preloadtest() {
    std::string sources[4];
    sources[3] = "sources\\employees\\payroll_slips";
    sources[0] = "sources\\customers";
    sources[1] = "sources\\employees";
    sources[2] = "sources\\password";

    for (int i = 0; i < 4; i++) {
        string command = "mkdir " + sources[i] + " > nul 2>&1";
        system(command.c_str());
    }
}
int main()
{
    //system("mode con cols=100 lines=50");
    preloadtest();
    welcome();
    while(loginsystem())
    {
        // cout<<"CHecked properly"<<endl;
        return 0;
    }
    return 0;
}
bool loginsystem()
{
    int count=0;
    while(count<3)
    {
        cout<<"Enter password: ";
        string temp;
        temp=getpass();
        if(checkfilepass(temp))
        {
            system("color 71");
            cout<<"Welcome "<<temp<<" to JAYPEE BANKS"<<endl;
            return true;
        }
        else if(temp=="exit")
        {
            return false;
        }
        system("color 74");
        cout<<"Incorrect password!\nPlease retry"<<endl;
        count++;
    }
    // cout<<"Enter password: ";
    
    // string temp;
    // temp=getpass();
    // if(checkfilepass(temp))
    // {
    //     return true;
    // }
    // else if(temp=="exit")
    // {
    //     return false;
    // }
    return false;
}
bool checkfilepass(string a)
{
    string temp;
    ifstream file("sources\\password\\password");
    while(getline(file,temp))
    {
        if(a==temp)
        {
            // cout<<"Password matched"<<endl;
            return true;
        }
    }
    return false;
}
void welcome()
{
    system("cls");
    system("color 70");
    cout<<"\t\t\t______________________________________\n";
    cout<<"\t\t\t|           JAYPEE BANKS             |\n";
    cout<<"\t\t\t|____________________________________|\n";
    cout<<"\t\t\t|      Project developed by:         |\n";
    cout<<"\t\t\t|      Rohan Batra           23104056|\n";
    cout<<"\t\t\t|                                    |\n";
    cout<<"\t\t\t|                                    |\n";
    cout<<"\t\t\t|____________________________________|\n\n";
    cout<<"\t\t\t  Press any key to continue...      ";
    getch();
    cout<<endl;
    system("color 71");
}
string getpass()
{
    string temp="";
    char c;
    while(true)
    {
        c=getch();
        if(c!=13)
        {
            cout<<"*";
            temp=temp+c;
        }
        else if(c==13)
        {
            break;
        }
    }
    cout<<endl;
    return temp;
}
void maimenu()
{
    system("cls");
    cout<<"\t\t\t            JAYPEE BANKS              \n";
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t1)Employees Management"<<endl;
    cout<<"\t\t\t2)Customers Management"<<endl;
    cout<<"\t\t\t3)Exit"<<endl;
    cout<<"\t\t\tEnter your choice: ";
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            employees();
            break;
        }
        case 2:
        {
            customers();
            break;
        }
    }
}
string inttostring(int num) 
{
    stringstream ss{};
    ss << num;
    return ss.str();
}
class employee
{
    private:
        string name;
        static int next;
        int age;
        string department;
        float salary;
    public:
        int id=next++;
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
        float tax()
        {
            float tax;  //variable to stoe tax
            if(salary<=500000)  //if salary <50000
            {
                tax=0.1*salary; //tax=10%
            }
            else if(salary>500000 && salary<=1000000) //salary>500000 && salary<=1000000
            {
                tax=50000+(salary-500000)*0.2; //tax=50000 +20% of(salary-500000)
            }
            else if(salary>100000) //salary > 1000000
            {
                tax=150000+(salary-1000000)*0.3;
                //tax=150000 +30% of (salary-1000000)
            }
            return tax;
        }
        employee()
        {

        }
        employee(string n,int a,string dept,float sal)
        {
            this->name=n;
            this->department=dept;
            if(a>=18)
            {
                this->age=a;
            }
            else
            {
                this->age=0;
            }
            this->salary=sal;
            cout<<"Employee ID generated: "<<id<<endl;
        }
        friend ostream &operator<<(ostream &out,employee &obj)
        {
            out<<"Name:        "<<obj.name<<endl
                <<"ID:         "<<obj.id<<endl
                <<"Age:        "<<obj.age<<endl
                <<"Salary:     "<<obj.salary<<endl
                <<"Department: "<<obj.department<<endl;
            return out;
        }
        void savetofile()
        {
            ofstream fobj;
            fobj.open("sources\\employees\\"+inttostring(id));
            if(fobj.is_open())
            {
                fobj<<name<<endl
                    <<id<<endl
                    <<age<<endl
                    <<salary<<endl
                    <<department<<endl;
            }
            else
            {
                cout<< "Failed to open file for writing." << endl;
            }
        }
        void generate_payrollslip()
        {
            ofstream fobj;
            string id1=inttostring(id);
            string filepath="sources\\employees\\payroll_slips\\"+id1+".txt";
            fobj.open(filepath);
            if(fobj.is_open())
            {
                string l="-------------------------";
                fobj<<"\t\t\t______________________________________\n"
                    <<"\t\t\t|           JAYPEE BANKS             |\n"
                    <<"\t\t\t|____________________________________|\n";
                fobj<<l<<endl;
                fobj<<"Payroll Slip"<<endl
                    <<l<<endl
                    <<"Employee Name: "<<name<<endl
                    <<"Employee Age: "<<age<<endl 
                    <<"Employee ID: "<<id<<endl
                    <<"Department: "<<department<<endl
                    <<"Gross Salary: "<<salary<<endl
                    <<l<<endl
                    <<"Net Salary: "<<net_salary()<<endl
                    <<"Tax Payable: "<<tax()<<endl;
                fobj.close();
                cout<<"Payroll Slip saved to sources/employees/payroll_slips/"+inttostring(id)+".txt"<<endl;
                //string execute="notepad.exe sources\\emplyees\\payroll_slips\\"+inttostring(id)+".txt";
                string execute = "notepad.exe " + filepath;
                system(execute.c_str());
            }
            else
            {
                cout<<"Error in generating payroll slip"<<endl;
            }
        }
        employee loaddata()
        {
            ifstream fobj;
            employee temp;
            fobj.open("sources\\employees\\"+inttostring(id));
            if(fobj.is_open())
            {
                getline(fobj, temp.name);
                fobj >> temp.id >> temp.age >> temp.salary;
                fobj >> ws;
                getline(fobj, temp.department);
                fobj.close();
            }
            else 
            {
            cout<< "Failed to open file for reading." << endl;
            }
        return temp;
        }
};
