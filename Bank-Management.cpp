#include<iostream>
#include<string>
#include<string.h>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<time.h>
#include<windows.h>
#include<cmath>
#include<conio.h>

using namespace std;
class Admin;
class Date
{
	public:
		int year;
		int Month;
		int Day;
		int hr;
		int min;
		int sec; 	
		int get_year()
		{
		time_t now = time(0);
		tm *ltm = localtime(&now);
	   	
		year=int(1900 + ltm->tm_year); 
		return year;
	    }
	    
		int get_month()
		{
			time_t now = time(0);
		tm *ltm = localtime(&now);
	   	
		Month=int(1 + ltm->tm_mon); 
		return Month;
		}

		int get_day()
		{
			time_t now = time(0);
		tm *ltm = localtime(&now);
		Day=int(ltm->tm_mday); 
		return Day;
		}
	    int get_hrs()
	    {
	    //	work();
	    time_t now = time(0);
		tm *ltm = localtime(&now);
	    	hr=int(1 + ltm->tm_hour);
	    	return hr-1;
		}
		
		int get_mins()
		{
			//work();
			
			time_t now = time(0);
		tm *ltm = localtime(&now);
			min=int(1 + ltm->tm_min);
			return min;
		}
		
		int get_sec()
		{
		//	work();
		time_t now = time(0);
		tm *ltm = localtime(&now);
			sec=int(1 + ltm->tm_sec );
			return sec;
		}
		
};
class Account
{
   friend Admin;
   protected:
   int AccNo;
   char name[20];
   char gender;
   char type;
   double deposit;
   static double interest;
   Date d;

   public:

	
   int getacc_no();
    char* getname();
    char getacc_type();
    double getammount();
    double get_interest();
    int menu();
    virtual int Get_Data_Account(bool);
    void Create_Account();
    bool check(int);
    void show_data();
    void View_Detail(int);
    void View_Balance(int);
    void Delete_Account(int);
    void Modify_Account(int);
    char Check_AccountType(int);
    virtual int Deposit(int)=0;
    virtual int WithDraw(int)=0;
	int Donate_Fund(int);
    
    
};
double Account::interest=0.00;

/*bool Account::check(int a)
{
	int temp;
	ifstream fin("ID.txt",ios::in);
	fin.seekg(0,ios::beg);
	fin>>temp;
	while(!fin.eof())
	{
		if(temp==a)
		{
		//cout<<"Same";
		fin.close();
		return false;
	    }
		fin.ignore();
		fin>>temp;
	}
	//cout<<"notSame"<<endl;
	fin.close();
	return true;
}*/

	int Account:: getacc_no()
		{
			return AccNo;
		}
	   	char* Account:: getname()
		{
			return name;
		}
		char Account::getacc_type()
		{
			return type;
		}
		double Account::getammount()
		{
			return deposit;
		}
		double Account::get_interest()
		{
			return interest;
		}
     int Account::menu()
     {
      system("cls");
      int ch;
      cout<<endl<<endl<<endl<<endl<<setw(82)<<"Welcome To AYS-At Your Service Bank"<<endl;
      cout<<setw(91)<<"_____________________________________________________"<<endl<<endl;
      cout<<setw(92)<<"|     Press 1 to Create Account                     |\n"      ;
      cout<<setw(98)<<"|     Press 2 to View Details                       |\n      ";
      cout<<setw(86)<<"|     Press 3 to Enquire About Balance              |\n";
      cout<<setw(92)<<"|     Press 4 to Delete Your Account                |\n";//faisal seekg  //Apply Restrictions/interest for fixed saving rsectively ;inheritnce
      cout<<setw(91)<<"|     Press 5 to Deposit Money                      |"<<endl;
	  cout<<setw(91)<<"|     Press 6 to WithDraw Money                     |"<<endl;
	  cout<<setw(92)<<"|     Press 7 to Modify Account                     |\n";  //Fixed cannot be changed
      cout<<setw(91)<<"|     Press 8 to Donate Money For Relief Fund       |"<<endl;
	  cout<<setw(92)<<"|     Press 9 to Return to profile log              |\n";
	  cout<<setw(91)<<"_____________________________________________________"<<endl<<endl;
      cin>>ch;
	  system("pause");
      return ch;
      }
   int Account::Get_Data_Account(bool choice)
   {
     double dep;
	 char gen;
	 int i=0;
     //int ID=1210;
     while(1)
	{
	cout<<"Enter Name"<<endl;
	fflush(stdin);
	try
	{
		cin.getline(name,20);
		while(name[i]!='\0')
		{
		if(name[i]>='a'&&name[i]<='z'||name[i]>='A'&&name[i]<='Z'||name[i]==32)
		{
			i++;
		}
		else 
		{
			cout<<"Invalid Name Input"<<endl;
			throw -1;
		}
		
	}
	if(name[i]=='\0')
	break;
    }
	catch(int e)
	{
		if(e==-1)
		continue;
	}
   }
     while(1)
     {
     cout<<"Enter Your Gender"<<endl;
     cin>>gen;
     if(toupper(gen)=='F'||toupper(gen)=='M')
     {
     gender=toupper(gen);
     break;
     }
     else
     {
         cout<<"Invalid Input"<<endl;
         continue;
     }
     }
     if(choice==true)
     {
     	while(1)
     	{
		 cout<<"Enter the initial amount you want to deposit"<<endl;
		 try
		 {
		 	cin>>dep;
		 	if(dep>=500.00)
		 	{
               deposit=dep;
               break;
            }
            else
            throw -1;
		  }
		  catch( int e)
		  {
		  	cout<<"Amount not enough to create an account"<<endl;
		  	continue;
		  }
        } 
     d.year=d.get_year();
	 d.Month=d.get_month();
	 d.Day=d.get_day();
     cout<<"Your Account is Created on "<<d.Day<<"/"<<d.Month<<"/"<<d.year<<endl;
     cout<<"Account Created Sucessfully\n"<<endl;
     cout<<"Your Account Number is "<<++AccNo<<endl;
    }
    else
    {
    	cout<<"Account Modified........"<<endl; 
	}
	system("pause");
   }
   
   void Account::Create_Account()
   {
       ofstream out;
       out.open("Account.dat",ios::binary|ios::app);
       if(!out)
       {
       cout<<"File Not Loaded"<<endl;
       system("pause");
       }
       else
       {
           Get_Data_Account(true);
           out.write((char*)this,sizeof(*this));
           out.close();
       }       
   }
   void Account::show_data()
{
	system("cls");
	cout<<"************************************************************************"<<endl;
    cout<<setw(30)<<"Time "<<d.get_hrs()<<":"<<d.get_mins()<<":"<<d.get_sec()<<endl;
	cout<<"Account Number is "<<getacc_no()<<endl;
	cout<<"Name is "<<getname()<<endl;
	cout<<"Gender is [F for Female M for Male] "<<gender<<endl;
	cout<<"Account Type is "<<getacc_type()<<endl;
	cout<<"Deposit "<<getammount()<<endl;
	cout<<"Interest Rate is "<<interest<<endl;
	cout<<"Account Created On "<<d.Day<<"/"<<d.Month<<"/"<<d.year<<endl<<endl;
	cout<<"**************************************************************************"<<endl;
	system("pause");	
} 
    void Account::View_Balance(int acc)
  
    {
		bool flag=true;
    	fstream fin("Account.dat",ios::binary|ios::in);
		if(!fin)
		{
			cout<<"File Not Opened"<<endl;
		}
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(this->AccNo==acc)
			{
			system("cls");
			cout<<endl<<endl<<endl<<endl;
			cout<<setw(68)<<"Balance Enquiry"<<endl<<endl;
    	    cout<<setw(70)<<"Your Current Balance is "<<getammount()<<endl;
			getch();
			flag=false;
			}
    	    fin.read((char*)this,sizeof(*this));
		}
		if(flag)
		{
		cout<<"Account ID Not Found"<<endl;
		system("pause");
	    }
		fin.close();
	}
	
	void Account::View_Detail(int acc)
	{
        bool flag=true;
		ifstream fin("Account.dat",ios::binary|ios::in);
		if(!fin)
		{
			cout<<"File Not Opened"<<endl;
			getch();
		}
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(this->AccNo==acc)
			{
			flag=false;
			show_data();
		    }
			fin.read((char*)this,sizeof(*this));
		}
		fin.close();
		if(flag)
		{
		cout<<"Record Not Found"<<endl;
		system("pause");
	    }
		getch();
	}
	void Account::Delete_Account(int acc)
		{
			ifstream i;
			ofstream o;
			i.open("Account.dat",ios::in|ios::binary);
			if(!i)
			{
				cout<<"FILE NOT FOUND.."<<endl;
				system("pause");
			}
			else
			{
				o.open("temp.dat",ios::out);
				i.read((char*)this,sizeof(*this));
				while(!i.eof())
				{
					if(AccNo!=acc)
					{	
						o.write((char*)this,sizeof(*this));	
					}
					i.read((char*)this,sizeof(*this));
				}
				i.close();
				o.close();
				remove("Account.dat");
				rename("temp.dat","Account.dat");
				cout<<" Account ID "<<acc<<" Has Been Removed "<<endl;
				getch();
			}
		}
		void Account::Modify_Account(int acc)
		{
			ifstream fin("Account.dat",ios::in|ios::binary);
			ofstream fout("Temp.dat",ios::out|ios::binary);
			bool flag=true;
			if(!fin)
			{
				cout<<"FILE IS NOT OPENED...."<<endl;
				getch();
			}
			else
			{
			fin.read((char*)this,sizeof(*this));
			while(!fin.eof())
			{
				if(acc==AccNo)
				{
					flag=false;
					system("cls");
					cout<<setw(78)<<"Enter Updated Data"<<endl;
					Account::Get_Data_Account(false);
				}
				fout.write((char*)this,sizeof(*this));
				fin.read((char*)this,sizeof(*this));
			}
			if(flag)
			{
				cout<<"Record Not Found"<<endl;
				getch();
			}
         }
		    fout.close();
			fin.close();
			remove("Account.dat");
			rename("Temp.dat","Account.dat");
		
	    }
				
	/*void Account::amountupdate()
		{
			int choice;
			
			cout<<"1: DEPOSIT AMMOUNT: "<<endl<<"2: WITHDRAW AMMOUNT: "<<endl;
			cout<<"ENTER YOUR CHOICE TO UPDATE: ";
			cin>>choice;
			if(choice==1)
			{
				double dep;
				cout<<"ENTER AMMOUNT TO BE DEPOSITED IN YOUR ACCOUNT: ";
				cin>>dep;
				if(dep>=0.00)
				deposit=deposit+dep;	
				else
				cout<<"Not a Valid Value"<<endl;		
			}
			else if(choice==2)
			{
				double with;
				cout<<"ENTER AMMOUNT TO BE WITHDRAWN: ";
				cin>>with;
				if(with>=0.00)
				deposit= deposit-with;	
				else
				cout<<"Not a Valid Value"<<endl;	
			}
		}*/
	/*	void Account::Update_Amount(int acc)
		{
			fstream f;
			cout<<"Inside"<<endl;
			f.open("Account.txt",ios::in|ios::out|ios::ate);
			if(!f)
			{
				cout<<"FILE IS NOT OPENED...."<<endl;
			}
			else
			{
			f.seekg(0);
			f.read((char*)this,sizeof(*this));
			while(!f.eof())
			{
				if(AccNo==acc)
				{
					
				    amountupdate(this->d.year);
					f.seekp(f.tellp()-sizeof(*this));
					f.write((char*)this,sizeof(*this));
				}
				f.read((char*)this,sizeof(*this));
			}
		    }
     	}*/
     	
     	char Account::Check_AccountType(int Acc)
     	{
     		ifstream fin("Account.dat",ios::in|ios::binary);
     		if(!fin)
     		{
     			cout<<"File Not Loaded"<<endl;
			}
			fin.read((char*)this,sizeof(*this));
			while(!fin.eof())
			{
				if(this->AccNo==Acc)
				return this->type;
				fin.read((char*)this,sizeof(*this));
			}
		}
		
	 int Account::Donate_Fund(int Acc)
	 {
		 double don;
		 bool flag=true;
         fstream fin("Account.dat",ios::in|ios::binary);
		 fstream fout("Temp.dat",ios::out|ios::binary);
		 if(!fin)
		 {
			 cout<<"File Not Loaded"<<endl;
			 return 1;
		 }
		 fin.read((char*)this,sizeof(*this));
		 while(!fin.eof())
		 {
			 if(this->AccNo==Acc)
			 {
			 flag=false;
			 system("cls");
			 cout<<endl<<endl<<endl<<endl;
			 cout<<setw(70)<<"Every Bit Counts"<<endl;
			 cout<<setw(78)<<"How Much Would You Like To Donate?"<<endl;
			 cin>>don;
			 if(don>0.00)
			 this->deposit=this->deposit-don;
			 cout<<setw(72)<<"Thank You Helping Us"<<endl;
			 getch();
			 }
			fout.write((char*)this,sizeof(*this));
			fin.read((char*)this,sizeof(*this));
		 }
		 if(flag)
		 cout<<"Record Not Found"<<endl;
		 getch();
		 fin.close();
		 fout.close();
		 remove("Account.dat");
		 rename("Temp.dat","Account.dat");
	 }
		
   class Saving:public Account
 {
	friend Admin;
    static double limit_amount;
	public:
		Saving()
    	{
   	      fstream fin("Rate-S.txt",ios::in);
	    if(!fin)
	    {
	  	cout<<"File Not Found"<<endl;
	  	getch();
	    }
		fin.seekg(0, ios::end);  
          if (fin.tellg() == 0)
          {
          	interest=0.00;
          	limit_amount=0.00;
		  }	
		   else
		     {
		    fin.seekg(0,ios::beg);
		  	   fin>>interest;
		  	   fin>>limit_amount;
		     }
	   
	   fin.close();
	   fin.open("Saving.txt",ios::in);
	   fin.seekg(0, ios::end);  
          if (fin.tellg() == 0)
          {
          	AccNo=2310;
		  }
		  else
		  {
		   fin.seekg(0,ios::beg);
	       fin>>AccNo;
	      }
	   fin.close();
       }
	   ~Saving()
	   {
	   	ofstream fout("Saving.txt",ios::out);
     	if(!fout)
     	{ 		
	     cout<<"not found"<<endl;
        }
        else
      	{
  		fout<<AccNo;
  		fout.close();
  	    }
  	   fout.open("Rate-S.txt",ios::out);
     	if(!fout)
     	{ 		
	     cout<<"not found"<<endl;
        }
       else
      	{
      	fout<<interest<<endl;
  		fout<<limit_amount<<endl;
  		fout.close();
	    }
  	    }
		int get_limit_amount()
		{
			return limit_amount;
		}
		
		int Get_Data_Account(bool x)
		{
			system("cls");
			cout<<setw(75)<<endl<<endl<<endl<<endl<<" Welcome To Your Saving Account"<<endl;
			type='S';
			Account::Get_Data_Account(x);
			//system("pause");
		}


		int Deposit(int AccNo)
		{
			bool flag=true;
			double dep;
			ofstream fout("Transaction.txt",ios::app);
			ofstream output("Temp.dat",ios::out|ios::binary);
			fstream fin("Account.dat",ios::in|ios::binary);
			if(!fin||!fout)
			{
				cout<<"File Not Loaded"<<endl;
				getch();
				return 1;
			}
			fin.seekg(0);
			fin.read((char*)this,sizeof(*this));
			while(!fin.eof())
			{
				if(this->AccNo==AccNo)
				{
					flag=false;
					cout<<"How Much Do You Want To Deposit"<<endl;
					cin>>dep;
					if(dep>=0.00)
					{
					deposit=deposit+dep;
					if(deposit>=limit_amount)
					deposit=deposit+dep*interest;	
					cout<<dep<<"Deposited"<<endl;
					system("pause");	
					}	
					fout<<this->AccNo<<" "<<this->name<<" "<<this->type<<" "<<"Deposit "<<dep<<" "<<d.get_hrs()<<":"<<d.get_mins()<<":"<<d.get_sec()<<" ";
					fout<<endl;
					//cout<<"In"<<endl;
					//d.get_WeekDay();
					//cout<<"Out";
				  }
				  output.write((char*)this,sizeof(*this));
				  fin.read((char*)this,sizeof(*this));
			}
			if(flag)
			{
            cout<<"Account ID Not Found"<<endl;
            system("pause");
            }
			fout.close();
			fin.close();
			output.close();
			remove("Account.dat");
			rename("Temp.dat","Account.dat");
		}
		int WithDraw(int AccNo)
		{
			double with;
			bool flag=true;
			fstream fin("Account.dat",ios::in|ios::binary);
			ofstream output("Temp.dat",ios::out|ios::binary);
			ofstream fout("Transaction.txt",ios::app);
			if(!fin)
			{
				cout<<"File Not Loaded"<<endl;
				return 1;
			}
			fin.read((char*)this,sizeof(*this));
			while(!fin.eof())
			{
				if(this->AccNo==AccNo)
				{
					flag=false;
					system("cls");
					cout<<"How Much Do You Want To WithDraw?"<<endl;
					cin>>with;
					if(with>=0.00&&with<=deposit)
					deposit=deposit-with;
					cout<<"WithDraw Complete"<<endl;
					fout<<this->AccNo<<" "<<this->name<<" "<<this->type<<" "<<"WithDraw "<<with<<" "<<d.get_hrs()<<":"<<d.get_mins()<<":"<<d.get_sec()<<" ";
					fout<<endl;
					system("pause");
					//d.get_WeekDay();
				}
				output.write((char*)this,sizeof(*this));
				fin.read((char*)this,sizeof(*this));
			}
			if(flag)
			cout<<"Account ID Not Found"<<endl;
			fout.close();
			fin.close();
			output.close();
			remove("Account.dat");
			rename("Temp.dat","Account.dat");
		}
		
};
double Saving::limit_amount=0.00;

class Fixed:public Account
{
   friend Admin;
   private:
   static float penalty;
   static int years;
   public:
   	
	   Fixed()
   	{
   		ifstream fin;
   		fin.open("Fixed.txt",ios::in);
	    fin.seekg(0, ios::end);  
          if (fin.tellg() == 0)
          {
          	AccNo=9152;
		  }
		  else
		  {
		  	fin.seekg(0,ios::beg);
		  	fin>>AccNo;
		  }
		fin.close();
        fin.open("Rate-F.txt",ios::in);
		fin.seekg(0, ios::end);  
          if (fin.tellg() == 0)
          {
          	penalty=0.00;
          	years=0;
		  }	
		   else
		     {
		     	fin.seekg(0, ios::beg);  
		     	fin>>interest;
		  	   fin>>penalty;
		  	   fin>>years;
		     }
	  fin.close();
    }
	   ~Fixed()
	   {
	   	ofstream fout("Fixed.txt",ios::out);
     	if(!fout)
     	{ 		
	     cout<<"not found"<<endl;
        }
        else
      	{
  		fout<<AccNo;
  		fout.close();
  	    }
  		fout.open("Rate-F.txt",ios::out);
     	if(!fout)
     	{ 		
	     cout<<"not found"<<endl;
        }
       else
      	{
      	fout<<interest<<endl;
      	fout<<penalty<<endl;
  		fout<<years<<endl;
  		fout.close();
	    }
  	    }
  	       	
static int get_years()
   	{
   		return years;
	}
   	int Get_Data_Account(bool x)
		{
			system("cls");
			cout<<" Welcome To Your Fixed Account"<<endl;
			type='F';
			Account::Get_Data_Account(x);
		}
		
		int Deposit(int AccNo)
		{
			double dep;
			fstream fout("Transaction.txt",ios::app);
			ofstream output("Temp.dat",ios::out|ios::binary);
			fstream fin("Account.dat",ios::in|ios::binary);
			if(!fin)
			{
				cout<<"Deposit Function of Fixed Not Loaded"<<endl;
				getch();
				return 1;
			}
			//fin.seekg(0);
			fin.read((char*)this,sizeof(*this));
			while(!fin.eof())
			{
				if(this->AccNo==AccNo)
				{
                    system("cls");
					cout<<"How Much Do You Want To Deposit?"<<endl;
					cin>>dep;
					if(dep>=0)
					deposit=deposit+dep+dep*interest;
					cout<<dep<<" Rs has been deposited"<<endl;
					//fin.seekp(fin.tellp()-sizeof(*this));
					//cout<<dep<<" Rs has been Deposited"<<endl;
					fout<<this->AccNo<<" "<<this->name<<" "<<"F"<<" "<<"Deposit "<<dep<<" "<<d.get_hrs()<<":"<<d.get_mins()<<":"<<d.get_sec()<<" ";
				   // d.get_WeekDay();	
				   fout<<endl;
				   system("pause");
				}
				output.write((char*)this,sizeof(*this));
				fin.read((char*)this,sizeof(*this));
			}
			fout.close();
			fin.close();
			output.close();
			remove("Account.dat");
			rename("Temp.dat","Account.dat");
		}
		
		int WithDraw(int AccNo)
		{
			double with;
			bool flag=true;
			int op;
			fstream fout("Transaction.txt",ios::app);
			fstream output("Temp.dat",ios::out|ios::binary);
			fstream fin("Account.dat",ios::in|ios::binary);
			if(!fin)
			{
				cout<<"Withdraw of fixed"<<endl;
				return 1;
			}
			fin.read((char*)this,sizeof(*this));
			while(!fin.eof())
			{
				if(this->AccNo==AccNo)
				{
					system("cls");
					cout<<"How Much Do You Want To WithDraw?"<<endl;
					cin>>with;
					if(with>=0.00&&with<=deposit)
					{
					if(d.get_year()-this->d.year!=years)
					//if(d.get_year()-2018!=years)  //For Testing
					{
						cout<<"Are You Sure You Want To WithDraw Before Due Year[Penalty Will BE Charged]\a"<<endl;//Pop Up box with Beep
						cout<<"Press 1 to proceed"<<endl;
						cin>>op;
						if(op==1)
						{
							flag=false;
							deposit=deposit-with-penalty;
							cout<<"Your Current Balance is "<<deposit<<endl;
							if(deposit<0.00)
							{
							double a=abs(deposit);
							cout<<"You Are Obliged To Pay "<<a<<" To Bank, Your CNIC Is Being Recorded"<<endl;
						    }
						}	
					}
					else
					{
						flag=false;
						deposit=deposit-with;
						cout<<"WithDraw Complete"<<endl;
					}
					system("pause");
					if(!flag)
					{
					fout<<this->AccNo<<" "<<this->name<<" "<<"F"<<" "<<"WithDraw "<<with<<" "<<d.get_hrs()<<":"<<d.get_mins()<<":"<<d.get_sec()<<" ";
					//d.get_WeekDay();
					fout<<endl;
				    }
				}
				
			}
			output.write((char*)this,sizeof(*this));
			fin.read((char*)this,sizeof(*this));
			
		}
		fin.close();
		fout.close();
		output.close();
		remove("Account.dat");
		rename("Temp.dat","Account.dat");
	}
		
		double get_penalty()
		{
			return penalty;
		}
};
float Fixed::penalty=0.00;
int Fixed::years=0.00;
 	

class Admin
{
    private:
    char password[10];                    
    int options();
    void set_password(char * s);
    public:
    Admin()   //Prompt user to ask for password at time of creation
    {
        //password='\0';
    }
     
     bool check_password(char* s,bool );
     int Display_Menu();
     int View_Rec();
     void display_data(Saving&);
     int View_Rec(int);
     int View_Total();
     void set_rates();
     void View_Transactions();
     int View_Balance();
    
};

void Admin::set_password(char* s)
    {
        ofstream out;
		strcpy(password,s);	
        //password=s;
        out.open("Password.txt",ios::out);
        out<<password;
        out.close();
    }

bool Admin::check_password(char* s,bool flag)             
    {
        char s1[10];
        int newpass,ch;
       ifstream output;
        output.open("Password.txt",ios::in);
       if(!output)
      {
          cout<<"File Cannot Be opened"<<endl;
          system("pause");
          return false;		  
      }
       output>>s1;
      if(!strcmp(s,s1))
      {
          cout<<setw(71)<<"Correct Password"<<endl;
		  getch();
          if(flag)
          {
		  system("cls");
		  cout<<"\a"<<endl;
		  cout<<setw(68)<<"PENDING WORK"<<endl;
          if(Account::interest==0.00)
          cout<<endl<<endl<<setw(90)<<"You Haven't Set The Interest Rate Yet"<<endl;
          if(Saving::limit_amount==0.00)
          cout<<endl<<endl<<setw(90)<<"You Haven't Set The Limiting Amount For Saving Account Yet"<<endl;
          if(Fixed::years==0)
          cout<<endl<<endl<<setw(89)<<"You Haven't Set The Duration(Years) for Fixed Account Yet"<<endl;
          if(Fixed::penalty==0.00)
          cout<<endl<<endl<<setw(89)<<"You Haven't Set The Penalty Amount for Fixed Account Yet"<<endl;
		  getch();          
          set_password(s);
          system("cls");
          }
          cout<<setw(73)<<endl<<endl<<endl<<"Do you want to change password[Press 1]"<<endl;
          cin>>ch;
          if(ch==1)
          {
              cout<<"Enter New Password"<<endl;
              cin>>s1;
              set_password(s1);
              cout<<endl<<"New Password Set"<<endl;
              getch();
          }
          output.close();
          return true;
        }
       else
         {
          cout<<"Password is incorrect"<<endl;
          getch();
          return false;
          }
     }
int Admin:: Display_Menu()
     {
		system("cls");
        int ch;
        cout<<endl<<endl<<endl<<endl;
        cout<<setw(80)<<" ______________________________________________"<<endl<<endl;
        cout<<setw(80)<<"|  Press 1 To View All Account Holders Details |"<<endl;
        cout<<setw(80)<<"|  Press 2 To Search A Particular Account      |"<<endl;
        cout<<setw(80)<<"|  Press 3 To Find Total Accounts in Bank      |"<<endl;
        cout<<setw(80)<<"|  Press 4 To Set Rates/Penalties              |"<<endl;
        cout<<setw(80)<<"|  Press 5 To Change Password                  |"<<endl;
        cout<<setw(80)<<"|  Press 6 To View Transaction History         |"<<endl; //Account or Day wise
        cout<<setw(80)<<"|  Press 7 To View Total Balance In Bank       |"<<endl;
        cout<<setw(80)<<"|  Press 8 To Return Profile Log               |"<<endl;
		cout<<setw(80)<<" ______________________________________________"<<endl;
		cin>>ch; 
		system("pause");
		return ch;     
     }
	  
int Admin::View_Rec() 
{
	Saving A;
	ifstream fin("Account.dat",ios::binary|ios::in);
	if(!fin)
	{
		cout<<"File Not Opened"<<endl;
		return 1;
	}
	fin.read((char*)&A,sizeof(A));
	while(!fin.eof())
	{
		display_data(A);
		fin.read((char*)&A,sizeof(A));
	}
	fin.close();
} 

int Admin::View_Rec(int x)  
{
	Saving A;
	ifstream fin("Account.dat",ios::binary|ios::in);
	if(!fin)
	{
		cout<<"File Not Opened"<<endl;
		return 1;
	}
	fin.read((char*)&A,sizeof(A));
	while(!fin.eof())
	{
	    if(A.getacc_no()==x)
		display_data(A);
		fin.read((char*)&A,sizeof(A));
	}
	fin.close();
}

void Admin::display_data(Saving &A)
{	
	system("cls");
	cout<<"***************************"<<endl;
    cout<<"Account ID "<<A.getacc_no()<<endl;
	cout<<"Name is "<<A.getname()<<endl;
	cout<<"Gender is "<<A.gender<<endl;
	cout<<"Account Type is "<<A.getacc_type()<<endl;
	cout<<"Deposit "<<A.getammount()<<endl;
	cout<<"Account Created On "<<A.d.Day<<"/"<<A.d.Month<<"/"<<A.d.year<<endl;
	cout<<"*****************************"<<endl;
	system("pause");
} 

int Admin::View_Total()
{
	int save,fixed,count;
	save=fixed=count=0;
	Saving A;
	ifstream fin("Account.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"File Not Opened"<<endl;
		return 1;
	}
	fin.read((char*)&A,sizeof(A));
	while(!fin.eof())
	{
	    count++;
	    if(A.getacc_type()=='S')
	    save++;
	    else
	    fixed++;
		fin.read((char*)&A,sizeof(A));
	}
	system("cls");
	cout<<endl;
	cout<<"\t\tAccount Count"<<endl;
	cout<<"______________________________________________________"<<endl<<endl;
	cout<<"Total Accounts in Bank                        |"<<count<<endl;
	cout<<"Total Saving Accounts                         |"<<save<<endl;
	cout<<"Total Fixed Accounts                          |"<<fixed<<endl;
	cout<<"______________________________________________________"<<endl;
	fin.close();
	getch();
}
int Admin::options()
{
	int op;
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<setw(70)<<"Working Status"<<endl<<endl;
	cout<<setw(95)<<"|Press 1 to Set Interest Rate For Saving Account [0.0-1.0]"<<endl;
	cout<<setw(88)<<"|Press 2 to Set Amount For Saving Account's Deposit"<<endl;
	cout<<setw(97)<<"|Press 3 to Set Penalty Rate For FD Withdraw Before Due Year"<<endl;
	cout<<setw(80)<<"|Press 4 to Set Duration For Fixed Accounts"<<endl;
	cin>>op;
	system("pause");
	return op;
}
	
void Admin::set_rates()
{
	double rate;
	int y;
	//Saving obj1;
	//Fixed obj2;
	switch(options())
	{
		case 1:
			cout<<endl<<endl<<"Current Interest Rate is "<<Saving::interest<<endl;
			cout<<"Enter New Interest Rate "<<endl;
			cin>>rate;
			if(rate>=0.00&&rate<=1.00)
			{
			Saving::interest=rate;
			cout<<"Interest Rate is "<<Saving::interest<<endl;
		    }
			else
			cout<<"Not A Valid Value"<<endl;
			system("pause");
			break;
		case 2:
			cout<<endl<<endl<<"Current Amount Set For Saving Account's Deposit "<<Saving::limit_amount<<endl;
			cout<<"Enter New Amount"<<endl;
			cin>>rate;
			if(rate>0.00)
			{
				Saving::limit_amount=rate;
			}
			cout<<"Amount is "<<Saving::limit_amount<<endl;
			system("pause");
			break;
		case 3:
		   cout<<endl<<endl<<"Current Penalty For Fixed Accounts are "<<Fixed::penalty;
		   cout<<"Enter Penalty For Fixed Account"<<endl;
			cin>>rate;
			if(rate>0.00)
			{
				Fixed::penalty=rate;
			}
			cout<<"Penalty for Fixed Account "<<Fixed::penalty<<endl;
			system("pause");
			break;
		case 4:
			cout<<endl<<endl<<"Current Duration is "<<Fixed::years<<endl;
			cout<<"Enter Duration for Fixed Account "<<endl;
			cin>>y;
			if(y>=0)
			{
				Fixed::years=y;
				cout<<"Duration is "<<endl;
			}
				else
			cout<<"Not A Valid Value"<<endl;
			system("pause");
			break;		
	        }
} 

void Admin::View_Transactions()
{
			string wday;
			string status;
			double amount;
			int Acc;
			Date d;
			char name[10];
			char type;	
			ifstream fin("Transaction.txt",ios::in);
		
			while(!fin.eof())
			{
			fin>>Acc;
			fin>>name;
			fin>>type;
			fin>>status;
			fin>>amount;
			fin>>d.hr;
			fin.ignore();
			fin>>d.min;
			fin.ignore();
			fin>>d.sec;
			system("cls");
			//fin>>wday;		
			//cout<<"ID\tName\tType\tStatus\tAmount(Deposit/WithDraw)\tTime\tDay"<<endl; 
			//cout<<Account::AccNo<<"\t"<<Account::name<<"\t"<<Account::type<<"\t"<<status<<"\t"<<amount<<"\t\t"<<d.hr<<":"<<d.min<<":"<<d.sec<<"\t"<<wday<<endl;
		    cout<<"********************************************************"<<endl;
			cout<<setw(40)<<"Account Number: "<<Acc<<endl;
			cout<<"********************************************************"<<endl;
			cout<<"Account Holder: "<<name<<endl;
			cout<<"Account Type[F/S]: "<<type<<endl;
			cout<<"Status: "<<status<<endl;
			cout<<"Amount[In PKR]: "<<amount<<endl;
			cout<<"Transaction Time: "<<d.hr<<":"<<d.min<<":"<<d.sec<<endl<<endl;
			//cout<<"Day: "<<wday<<endl;
			cout<<"*********************************************************"<<endl;
			system("pause");
			}
		    fin.close();
		}	

int Admin::View_Balance()
{
	Saving S;
	double total=0;
	system("cls");
	ifstream fin("Account.dat",ios::in);
	if(!fin)
	{
		cout<<"Cannot Open File"<<endl;
		getch();
		return 1;
	}
	fin.read((char*)&S,sizeof(S));
	while(!fin.eof())
	{
		total=total+S.deposit;
		fin.read((char*)&S,sizeof(S));
	}
	cout<<endl<<endl<<endl;
	cout<<setw(60)<<"Total Balance in Bank is "<<total<<" PKR"<<endl;
	getch();
	fin.close();
}

void loading()
{
   //system("color 0a");
    cout<<"\n\n\n\t\t\t\t\t\t      Please wait while loading\n\n";
    char a=177, b=219;
    cout<<"\t\t\t\t\t\t\t";
    for (int i=0;i<=15;i++)
    cout<<a;
    cout<<"\r";
    cout<<"\t\t\t\t\t\t\t";
     for (int i=0;i<=15;i++)
    {
    cout<<b;
    for (int j=0;j<=1e8;j++); //You can also use sleep function instead of for loop
    }
    cout<<endl;
 //clrscr()
}



int log()
{
    int ch;
	system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<setw(73)<<"Bank Management System"<<endl<<endl<<endl;
    cout<<setw(70)<<"|Press 1 for Admin"<<endl;
    cout<<setw(69)<<"|Press 2 for User"<<endl;
    cout<<setw(80)<<"|Press 3 to Exit the Profile"<<endl;
    cin>>ch;
    loading();
    return ch;
}

int Account_Choice()
{
	int op;
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<setw(68)<<"Account Type "<<endl<<endl;
	cout<<setw(76)<<"|Press 1 for Saving Account"<<endl;
	cout<<setw(75)<<"|Press 2 for Fixed Account"<<endl;
	cin>>op;
	getch();
	return op;
}


int log_out()
{
	system("cls");
	cout<<endl<<endl<<endl<<endl;
	cout<<setw(70)<<"Thank You For Visiting "<<endl;
	cout<<setw(67)<<"Come Again Soon"<<endl;
}
int main()
{
	
 int choice;
    int ID,i=0;
    double dep;
    char pass[6];
    char ch;
    Account *ptr;
    Saving S;
    Fixed F;
    ptr=&S;
    Admin A;
    bool flag;
    system("color 0A");
    while(1)
    {
      int op=log();
        if(op==1)
        {
          system("cls");
          cout<<endl<<endl<<setw(75)<<"Welcome To Admin Profile "<<endl<<endl;
          cout<<setw(69)<<"Enter Password"<<endl;
          //ch=fgetc(stdin);
         /* ch=_getch();
          while(ch!=13&&ch!=32)
          {
       		cout<<"*";
       		pass[i]=ch;
       		i++;
			ch=_getch();
		 }*/
		  cin>>pass;
          if(A.check_password(pass,true))
          {	
            flag=true;
		    while(flag)
			{ 
             switch(A.Display_Menu())
             {    
              case 1:
              	A.View_Rec();
                break;
              case 2:
              	cout<<"Enter account ID"<<endl;
              	cin>>ID;
              	A.View_Rec(ID);
              	break;
              case 3:
              	A.View_Total();
              	break;
              case 4:
              	A.set_rates();
              	break;
			  case 5:
			  	cout<<"Enter Current Password"<<endl;   
                cin>>pass;
			    A.check_password(pass,false);
			    break;
			  case 6:
			  	A.View_Transactions();
			  	break;
			 case 7:
			 	A.View_Balance();
			 	break;
			  case 8:
			  	flag=false;
			  	break;
			  	
			  }	  				  	
           }
       }
   }
   
        else if(op==2)
        {
        	flag=true;
          while(flag)
		  {
        	switch(ptr->menu())
        	{
        		case 1:
        			{
        			int option=Account_Choice();
        			if(option==1)
        			{
        			  //Saving S;
		              ptr=&S;
        			  ptr->Create_Account();
        		    }
        		    else if(option==2)
        		    {
        		    	//Fixed F;
        		    	ptr=&F;
        		    	ptr->Create_Account();
					}
					else
					{
						cout<<"Not Possibele"<<endl;
					}
        			  break;
        		}
        		 case 2:
        		 	cout<<"Enter Account ID"<<endl;
        			cin>>ID;
        		 	ptr->View_Detail(ID);
        		 	break;
        		case 3:
        			cout<<"Enter Account ID"<<endl;
        			cin>>ID;
        			ptr->View_Balance(ID);
        			break;
        		case 4:
        			cout<<"Enter Account ID"<<endl;
        			cin>>ID;
        			ptr->Delete_Account(ID);
        			break;	
        		case 5:
        			cout<<"Enter Account ID"<<endl;
        			cin>>ID;
        			if(char(ptr->Check_AccountType(ID))=='S')
        			{
        				ptr=&S;
					}
					else if(char(ptr->Check_AccountType(ID))=='F')
					{
						ptr=&F;
					} 
        			ptr->Deposit(ID);
        			break;
        		case 6:
        			cout<<"Enter Account ID"<<endl;
        			cin>>ID;
        			if(char(ptr->Check_AccountType(ID))=='S')
        			{
        				ptr=&S;
					}
					else if(char(ptr->Check_AccountType(ID))=='F')
					{
						ptr=&F;
					}  
					ptr->WithDraw(ID);
					break;        				
        		case 7:
        			cout<<"Enter Account ID"<<endl;
        			cin>>ID;
        			ptr->Modify_Account(ID);
        			break;
        		case 8:
        			cout<<"Enter Your Account ID"<<endl;
					cin>>ID;
					ptr->Donate_Fund(ID);
					break;
				case 9:
				    flag=false;
					break;	
        	}
        }
        }
		else if(op==3)
		{
			log_out();
			return 0;
		}
        else
        {
            continue;
        }    
    }
}
