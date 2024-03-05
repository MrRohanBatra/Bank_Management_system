#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void welcome();
bool logincheck();
bool logincheckfile();
void generatenew(string t);
string cstring(int a);
// int test()
// {
//     generatenew("customer");
//     return 0;
// }
class employee;
class customer
{
    private:
        static int next;
        string name;
        string address;
        bool checkbook;
        bool debitcard;
        bool creditcard;
        float balance;
        string branch="JYBP0000062";
    public:
        string acc_no=cstring(next++);
        customer(string n,string add,float bal,bool check,bool debit,bool credit)
        {
            name=n;
            address=add;
            checkbook=check;
            balance=bal;
            debitcard=debit;
            creditcard=credit;
        }
        customer(){}
        void generatenew()
        {
            ofstream file("sources\\customer\\"+acc_no+".txt");
            file.close();
        }
};
int customer::next=230001;
string customerfolder="sources\\customer\\";
int main()
{
    welcome();
    while(logincheck())
    {
        system("color 7");
        // cout<<"Condition true";
        // test();
        customer c;
        c.generatenew();
        return 0;
    }
    system("color 7");
    return 0;
}
bool logincheck()
{
    // welcome();
    // system("pause");
    
    string name;
    string pass="";
    string password="admin";
    char c;
    cout<<"Enter paswword: ";
    while(true)
    {
        c=getch();
        if(c!=13)
        {
            cout<<"*";
            pass+=c;
        }
        else
        {
            break;
        }
    }
    cout<<endl;
    system("color E");
    cout<<"Please wait checking password....."<<endl;
    system("timeout /t 2 >nul");
    if(pass=="rohan"||pass=="suyash"||pass==password||pass=="shubham"||pass=="exit")
    {
        system("color a");
        if(pass=="rohan")
        {
            name="Rohan Batra";
        }
        else if(pass=="shubham"){name="Shubham Rawat";}
        else if(pass=="suyash"){name="Suyash Bajpai";}
        else if(pass==password){name="Admin";}
        else if(pass=="exit"){return false;}
    cout << "Hello, " << name << "! We're happy to see you at Jaypee Bank." << endl << endl;
    return true;
    }
    else
    {
        system("color C");
        cout<<"Incorrect Password\tRetry\n\n";
        logincheck();
    }
}

void welcome()
{
    system("cls");
    system("color a");
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
    system("color 7");
}

bool logincheckfile()
{
    fstream file;
    file.open("sources\\password\\password.dat",ios::in);
    file<<"rohan\nsuyash\nadmin\nshubham\nadmin\exit";
    file.close();
}

void generatenew(string t)
{
    if(t=="customer")
    {
        system("customer.bat");
        // ofstream file("sources\\customer\\"+acc_no+".txt");
        // file.close();
    }
    else if(t=="employee")
    {
        system("employee.bat");
    }
    else {
        if(t=="password")
    {
        system("password.bat");
    }
    }
}
string cstring(int a)
{
    stringstream o;
    o<<a;
    return o.str();
}
