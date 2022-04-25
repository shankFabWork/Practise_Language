#include <iostream>
#include <fstream>

using namespace std;


static int next_account_no=0;

class User
{
    private:
        string f_name;
        string l_name;
        int amount;
        int account_no;
    public:

        User()
        {
            f_name="";
            l_name="";
            amount=0;
        }

        void MakeUser_And_MakeFile(string f_name,string l_name,int amount)
        {
            this->f_name=f_name;
            this->l_name=l_name;
            this->amount=amount;
            this->account_no=next_account_no++;

            ofstream outfile("data.txt",ios::app);
            outfile<<f_name<<endl;
            outfile<<l_name<<endl;
            outfile<<amount<<endl;
            outfile<<account_no<<endl;
            outfile<<endl;
            outfile.close();
        }

        string get_f_name()
        {
            return f_name;
        }

        string get_l_name()
        {
            return l_name;
        }

        int get_amount()
        {
            return amount;
        }

        int get_account_no()
        {
            return account_no;
        }



};

int main()
{
    int n;
    User u;
    string f_name="";
    string l_name="";
    int amount=0;
    do
    {

        cout<<"\n"<<" 1-> Make New Employee "<<"\n";
        cout<<"\n"<<" 2-> Show All Employee "<<"\n";
        cout<<"\n"<<" "<<"\n";
        cout<<"\n"<<" "<<"\n";
        cout<<"\n"<<" "<<"\n";
        cout<<"\n"<<" "<<"\n";
        cout<<"\n"<<" "<<"\n";
        cin>>n;

        switch(n)
        {
            case 1:
                cout<<"\n"<<" Enter First Name :: "<<"\n";
                cin>>f_name;
                cout<<"\n"<<" Enter Last Name :: "<<"\n";
                cin>>l_name;
                cout<<"\n"<<" Enter Amount :: "<<"\n";
                cin>>amount;
                u.MakeUser_And_MakeFile(f_name,l_name,amount);

                break;

            case 2:
                cout<<"\n"<<" AccountNo FName LName Amount :: "<<"\n";
                // ifstream infile;
                // infile.open("data.txt");
                // // if(infile)
                // if(infile)

                break;

            default:
                cout<<"\n"<<" Wrong Choice "<<"\n";
        }


    } while (n != 7);
    

    return 0;
}