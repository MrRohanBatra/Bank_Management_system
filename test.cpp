#include<bits\stdc++.h>
using namespace std;
string inttostring(int num) 
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

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
        void updatepass(long long int accno)
        {
            ofstream fobj;
            fobj.open("sources\\customers\\passbooks\\"+inttostring(accno)+".txt");
            if(fobj.is_open())
            {
                string l = "-------------------------";
        fobj <<"\t\t\t______________________________________\n"
            << "\t\t\t|           JAYPEE BANKS             |\n"
            << "\t\t\t|____________________________________|\n";
        fobj << l << endl;
        fobj << "Passbook " << endl<<l<<endl;
        fobj<<"Cusotmer details are:-"<<endl
            <<"Name: "<<name<<endl
            <<"Account Number: "<<accountNumber<<endl
            <<"Account Type: "<<accountType<<endl
            <<"Account Balance: "<<balance<<endl
            <<"Address: "<<address<<endl
            <<"Date of Birth: "<<dateOfBirth<<endl
            <<"Mobile Number: "<<mobileNumber<<endl
            <<"Email Address: "<<emailAddress<<endl
            <<"KYC document: "<<kycDocuments[0]<<endl<<"authentication number: "<<kycDocuments[1]<<endl;
            }
            fobj.close();
            savedata();
        }
};
