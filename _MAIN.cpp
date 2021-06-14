/* 
   OOP LAb Bank Project
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cls system("cls");
#define ps  system("pause");
// CLass & Func
class Bank{
	public:
	Bank(){}
	// Setter
	void set_account_num (ll it)  { this->account_num =it;}
	void set_accounttype (bool it){ this->saving_acc=it;}
	void set_Balance     (ll it)  {this->balance =it;}
	void set_cardid      (ll it)  {this->card_id =it;}
	// get
	ll   get_account_num(void){ return this->account_num;}
	bool get_acc_type(void) { return this->saving_acc;}
	ll   get_balance(void)    {return this->balance;}
	ll   get_cardid(void) {return this->card_id;}
	// Display
	void to_console(void){
		cout<<"\tAccount Number : "<<account_num<<endl;
		cout<<"\tCard Number    : "<<card_id<<endl;
		cout<<"\t Balance       : "<<balance<<endl;
	}
	// Balance
	void operator +(ll amount){
		abs(amount);
		balance += amount;
	}
	void operator -(ll amount){
		#define _max 50000
		#define min 5000
		abs(amount);
		double Tax;// Tax
		if(amount  > min || amount <=_max){
			Tax = 0.2/balance*100;// Formula
			balance =balance-(amount-Tax);
		}
		else{
			Tax = 2.5/balance*100;// Formula
			balance =balance-(amount - Tax);
		}
	}
	protected:
		ll account_num,balance,card_id;// AccNum, Balance , card num
		bool saving_acc;
};
class UserData:public Bank{
public:
	UserData(){}
	UserData(string name,string last_name,string address){
		name,last_name,address,Time;
		this->name =name;
		this->last_name=last_name;
		this->address=address;
	    #define Size 24// Size we wana to copy
	    time_t timenow;
	    time(&timenow);
	    string temp = ctime(&timenow); 
	    for(int i=0;i<Size;i++)
	       this->Time.push_back(temp[i]);
	}
	// Setter
	void set_name(string it){this->name = it;}
	void set_last_name(string it){ this->last_name=it;}
	void set_address(string it){this->address=it;}
	void set_cell_num(ll it){this->cell_num =it;}
	void set_cnic_num(ll it){ this->cnic_num=it;}
	void set_Time(string it){this->Time =it;}
	void set_DOB(short d,short m,short y){
		this->day=d;
		this->month=m;
		this->year=y;
	}
	// Get
	string get_name(void){return this->name;}
	string get_address(void){ return this->address;}
    string get_last_name(void){return this->last_name;}
	string get_Time(void) {return this->Time;}
    ll     get_cell_num(void){return this->cell_num;}
    ll     get_cnic_num(void){ return this->cnic_num;}
	// Display
	void to_console(void){
		cout<<"-----------------------------------------------"<<endl;
		Bank::to_console();
		cout<<"\tName         : "<<this->name<<endl;
		cout<<"\tLast Name    : "<<this->last_name<<endl;
		cout<<"\tCell Number  : "<<this->cell_num<<endl;
		cout<<"\tCnic  Number : "<<this->cnic_num<<endl;
		cout<<"\tDate of Bith : "<<this->month<<"/"<<day<<"/"<<year<<endl;
		cout<<"\tSince        :  "<<this->Time<<endl;
		cout<<"\tAccount Type : "<<((saving_acc)?"Saving":"Checking")<<endl;
		cout<<"-----------------------------------------------"<<endl;
	}
	// to Data Base
	string to_DataBase(void){
		stringstream ss;
		ss<<name<<"$"<<last_name<<"$"<<address<<"$"<<Time<<"$"<<day<<"$"<<month<<"$"<<year<<"$";
		return ss.str();
	}
protected:
	// User Data
	string name,last_name,address,Time;
	ll cell_num , cnic_num;
	short day,month,year;
};
class BankHistory:public UserData{
	public:
		BankHistory(ll in_Amount,ll out_Amount):in_Amount(in_Amount),out_Amount(out_Amount){
		       #define Size 24// Size we wana to copy
	           time_t timenow;
	           time(&timenow);
	          string temp = ctime(&timenow); 
	          for(int i=0;i<Size;i++)
	             this->Time.push_back(temp[i]);
		}
		void Show_History(void){
			cout<<"-------------------------------"<<endl;
			cout<<"\tAccount Number : "<<acc<<endl;
			cout<<"\tAmount Enter   : " <<in_Amount<<endl;
			cout<<"\tout_Amount     : "   <<out_Amount<<endl;
			cout<<"\tTime           : "   <<Time<<endl;
			cout<<"-------------------------------"<<endl;
		}
		void Set_Data(UserData &obj){
			this->acc = obj.get_account_num();
		}
		// Set
		void set_AccountNumber_(ll it){this->acc = it;}
		// TO Data Base
		string to_database(void){
			stringstream ss;
			ss<<acc<<"$"<<in_Amount<<"$"<<out_Amount<<"$"<<Time;
			return ss.str();
		}
		// return 
		ll return_HAcc_Num(void){return this->acc;}
	protected:
		ll in_Amount,out_Amount,acc;
};
// Find Duplicate Account
template<class T,typename t>
bool Find_DuplicateAccountNum(T first,T last,t str){
	if(first ==  last) return false;
	while(first != last){
		if(first->get_account_num() == str)
		   return true;
		first++;
	}
	return false;
}
// Find Duplicate Cnic num
template<class T,typename t>
bool Find_DuplicateCnicNum(T first,T last,t str){
	if(first ==  last) return false;
	while(first != last){
		if(first->get_cnic_num() == str){
		   cout<<"\t Cnic Number already Exist _ ";
		   return true;
		}
		first++;
	}
	return false;
}
// Find Duplicate Card Num
template<class T,typename t>
bool Find_DuplicateCardNum(T first,T last,t num){
	if(first ==  last) return false;
	while(first != last){
		if(first->get_cardid() == num)
		   return true;
		first++;
	}
	return false;
}
// Find Account
template<class T,typename t>
T FindAccount(T F,T L,t Var){
	if(F == L) return L;
	while(F!=L){
		if(F->get_account_num() == Var)
		  return F;
		F++;
	}
	return L;
}
// Find Cnic
template<class T,typename t>
T FindCnic(T F,T L,t &Var){
	if(F == L) return L;
	while(F!=L){
		if(F->get_cnic_num() == Var)
		  return F;
		F++;
	}
	return L;
}
// FInd Card
template <class T,typename t>
T FindCard(T F,T L, t &it){
	if(F ==  L) return L;
	while(F !=  L){
		if(F->get_cardid() ==  it)
		  return F;
		F++;
	}
	return L;
}
// Create Account Number
template<class T>
ll Create_AccountNumber(T &vec){// Not Call in Main
	#define AccountNumber 1634161807654321
    int Count =1000;
    ll Accnum;
    do{
    	Accnum  = AccountNumber + (rand() %Count);
    	Count +=Count;
	  } while(Find_DuplicateAccountNum(vec.begin(),vec.end(),Accnum));
	  return Accnum;
}
// Credit Card
template<class T>
ll Create_CardNumber(T &vec){// Not Call in Main
	#define AccountNumber 1634161807654321
    int Count =1;
    ll cardnum=0;
    do{
    	cardnum  = AccountNumber + (rand()%Count);
    	Count +=Count;
	  } while(Find_DuplicateCardNum(vec.begin(),vec.end(),cardnum));
	return cardnum;
}
/*        Display Func        */
template<class T>
void Balance_inquiry(T &vec){  cls
	ll acc_num,cnic_num;
	cout<<"\t Enter Account Number : ";
	cin>>acc_num;
	cout<<"\t Enter Cnice Number : ";
	cin>>cnic_num;
	auto itr = FindAccount(vec.begin(),vec.end(),acc_num);
	if(itr != vec.end()){
		itr = FindCnic(vec.begin(),vec.end(),cnic_num);
		if(itr != vec.end()){
		    cout<<"\t Total Balance  : "<<itr->get_balance()<<endl;
		} else cout<<"\t !! Cnic Number is inCorrect"<<endl;
	} else cout<<"\t !! Account Not Found "<<endl;
}
// Create Account 
template<class T>
void Create_Account(T &vec){ // Create user Account
    #define len 16
    #define intailamount 1000
	string name,last_name,address,phoneno,cnic_num;
	ll amount;
	short d,m,y;
	char choice;
	cout<<"\t Enter Name _ ";
	cin.sync();
	getline(cin,name);
	cout<<"\t Last Name _ ";
	cin.sync();
	getline(cin,last_name);
	cout<<"\t Enter Adress _ ";
	cin.sync();
	getline(cin,address);
	cout<<"\t Enter Phone Number _ ";
	cin>>phoneno;
	cout<<"\t Enter Cnic Number _ ";
	do{
	   cin>>cnic_num;
	}while(cnic_num.length()!=len && Find_DuplicateCnicNum(vec.begin(),vec.end(),stoll(cnic_num)));
	ll acc_num =Create_AccountNumber(vec);// Account Number
	ll card_num = Create_CardNumber(vec);// Card Number
	cout<<"\t Enter Date of Birth"<<endl;
	cout<<"\t Enter Day : "; cin>>d;
	cout<<"\t Enter Month : "; cin>>m;
	cout<<"\t Enter Year : "; cin>>y;
	cout<<"\t Enter Account Type Checking or Saving <C/S> _ ";
	cin>>choice; 
	bool type = (choice == 'S' || choice =='s') ? true :false;
	cout<<"\tEnter Amount (Amount Must be Greater then 1000) _ ";
	cin>>amount;
	if(amount >= intailamount ){
		UserData obj(name,last_name,address);
		obj.set_account_num(acc_num);// Set Account Number
	    obj.set_cell_num(stoll(phoneno));// Cell Number
	    obj.set_cnic_num(stoll(cnic_num));// Cnic Number
	    obj.set_DOB(d,m,y);// Set DOB
	    obj.set_Balance(amount);// set intail Amount
	    obj.set_accounttype(type);// set Account Type
	    obj.set_cardid(card_num);// Set Credit Card Num
	    vec.push_back(obj);
	    cout<<"\t\t--Account Created SucessFully--"<<endl;
	    cout<<"\t Account Number : "<<acc_num<<endl;
	    cout<<"\t Credit Card Has been Issued : "<<card_num<<endl;
	} else cout<<"\t !!Amount is Too low "<<endl;
	
}

// Deposit_Money via check book
template <class T,class t>
void Deposit_Money(T &vec,t &_vec){// Deposit_Money via check book
	ll cnic_num,acc_num,amount;
	cout<<"\t Enter Account Number : ";
	cin>>acc_num;
	cout<<"\t ENter Cnic Number : ";
	cin>>cnic_num;
	auto itr = FindAccount(vec.begin(),vec.end(),acc_num);
	if(itr != vec.end()){
		itr = FindCnic(vec.begin(),vec.end(),cnic_num);
		if(itr != vec.end()){
			cout<<"\t Enter Amount You Want To Add : ";
			cin>>amount;
			*itr + amount;// Addd amount to Account
			BankHistory obj(amount,0);
			obj.Set_Data(*itr);
			_vec.push_back(obj);// add to History
			cout<<"\tAmount Has Been Added!! : "<<amount<<endl;
		} else cout<<"\t Incorrect Cnic Number "<<endl;
	} else cout<<"\t Incorrect Account Number !!"<<endl;
}
// With Draw Money via Check Book
template<class T,class t>
void With_drawMoney(T &vec,t &_vec){
	ll cnic_num,acc_num,amount;
	cout<<"\t Enter Account Number : ";
	cin>>acc_num;
	cout<<"\t ENter Cnic Number : ";
	cin>>cnic_num;
	auto itr = FindAccount(vec.begin(),vec.end(),acc_num);
	if(itr != vec.end()){
		itr = FindCnic(vec.begin(),vec.end(),cnic_num);
		if(itr != vec.end()){
			cout<<"\t Total Balance in Account : "<<itr->get_balance()<<endl;
			cout<<"\t Enter Amount You Want To Add : ";
			cin>>amount;
			if(amount < itr->get_balance()){
				*itr -amount;// With draw Cash
				 BankHistory obj(0,amount);
				 obj.Set_Data(*itr);
				 _vec.push_back(obj);
			} else cout<<"\t!!!insufficient Balance"<<endl;
		} else cout<<"\t Incorrect Cnic Number "<<endl;
	} else cout<<"\t Incorrect Account Number !!"<<endl;
}
// With Draw via Card
template<class T,class t>
void WithDrawViaCard(T &vec, t &_vec){
	ll num,amount;
	cout<<"\t Enter Card Number _ ";
	cin>>num;
	auto itr =  FindCard(vec.begin(),vec.end(),num);
	if(itr != vec.end()){
		cout<<"\t Total Balance : "<<itr->get_balance()<<endl;
		cout<<"\t Enter Amount You Want to WithDraw _ ";
		cin>>amount;
		if(amount < itr->get_balance()){
			*itr-amount;
			BankHistory obj(0,amount);
			obj.Set_Data(*itr);
			_vec.push_back(obj);// Keep Record
			cout<<"\t All Set"<<endl;
		} else cout<<"\t!!!insufficient Balance"<<endl;
	} else cout<<"\t Card Number Not Found"<<endl;
}
// Account History
template<class T,typename t>
void Show_Transactionhistory(T &vec,t check){
	#define max 9
	bool Found=false;
	ll acc_num; short i= 0;
	cout<<"\t Enter Account Number : ";
	cin>>acc_num;
	for(auto it :  vec){
		if(it.return_HAcc_Num() == acc_num){
			Found=true;
			it.Show_History();
			if(check){i++;}
		}
		if(i==max) {break;}
	}
	if(!Found){cout<<"\t No Record Found for this Account "<<endl;}
	cout<<"\t************************************************"<<endl;
}
/*   Admin              */
template<class T>// Find Account or  Display Account Detail's
void Display_Account(T &vec){ cls
	ll acc_num,cnic_num;
	cout<<"\t Enter Account Number _ ";
	cin>>acc_num;
	cout<<"\t Enter Cnic Number _ ";
	cin>>cnic_num;
	auto itr = FindAccount(vec.begin(),vec.end(),acc_num);
	if(itr != vec.end()){
		itr =  FindCnic(vec.begin(),vec.end(),cnic_num);
		if(itr != vec.end()){
			itr->to_console();
		} else cout<<"\t Cnic Number Not Found !!!"<<endl;
	} else cout<<"\t Account Number Not FOund !!"<<endl;
}
template<class T,class t>// Delete Account
void Delete_Account(T &vec,t &_vec){
	ll acc_num,cnic_num;
	cout<<"\t Enter Data to Delete Account "<<endl;
	cout<<"\t Enter Account Number _ ";
	cin>>acc_num;
	cout<<"\t Enter Cnic Number _ ";
	cin>>cnic_num;
	auto itr = FindAccount(vec.begin(),vec.end(),acc_num);
	if(itr != vec.end()){
		itr =  FindCnic(vec.begin(),vec.end(),cnic_num);
		if(itr != vec.end()){
			itr->to_console();
			cout<<"\t This Account Has been Deleted"<<endl;
			for(auto it = _vec.begin();_vec.begin()!=_vec.end();it++){
				if(it->get_account_num() == acc_num){
					_vec.erase(it);
				}
			}
			vec.erase(itr);
		} else cout<<"\t Cnic Number Not Found !!!"<<endl;
	} else cout<<"\t Account Number Not FOund !!"<<endl;
}
template<class T>
void Add_withDrawMoney(T &vec){// Deposit or With Draw Money
	ll acc_num , am; char Choice;
	cout<<"\t Enter Account Number  _ ";
	cin>>acc_num;
	auto itr =  FindAccount(vec.begin(),vec.end(),acc_num);
	if(itr != vec.end()){
		itr->to_console();
		cout<<"\t Deposit Money-1   WithDraw Money-2  _ ";
		cin>>Choice;
		if(Choice  ==  '1'){
			cout<<"\t Enter Money You Want to Add ";
			cin>>am;
			*itr+am;
			cout<<"\t Amount Has been Added"<<endl;
		} 
		else if(Choice == '2'){
			cout<<"\t Enter Money You Want to WithDraw  _ ";
			cin>>am;
			if(am > itr->get_balance()){
				itr->set_Balance(am);
				cout<<"\t Balance Set to  0 "<<endl;
			} else {
				*itr - am;
				cout<<"\t Amount With Draw SucessFully"<<endl;
			}
		}
	} else cout<<"\t Account Number is not Correct"<<endl;
}
// FInd Account By Cedit Card
template<class T>
void Find_AccBYidnum(T &vec){
	ll num;
	cout<<"\t Enter Card Number : ";
	cin>>num;
	bool Found=false;
	if(vec.empty()){
		for(auto it:vec){
		    if(it.get_cardid() == num){
		    	it.to_console();
		    	Found!=Found;
		    	break;
			}
	    }
	}
	if(!Found){cout<<"\t No Record Found "<<endl;}
}
// files
template<class T>
void Get_History(T&);

template<class T>
void Get_BankData(T&);
// Check File Content
bool is_Empty(std::ifstream& pFile){
return pFile.peek() == ifstream::traits_type::eof();
}
// Driver Code
int main(){
	// Custom Data Type's
	vector<UserData> BD;
	vector<BankHistory> BH;
	// Fetch Data from File
	Get_History(BH);// Get User Data
    Get_BankData(BD);// Get USer data
    // Main Progarm
	char Choice;
    cout<<"\t Login as Employee     ---1"<<endl;
    cout<<"\t Login a bank customer ---2"<<endl;
    cout<<"\t Make Choice _ ";
    cin>>Choice;
    if(Choice == '2'){
    	do{// Do Start
    	   ps cls
    	cout<<"\t See Mini-statement             --1"<<endl;
    	cout<<"\t WithDraw Money via Credit Card --2"<<endl;
    	cout<<"\t Withdraw money Via Check book  --3"<<endl;
    	cout<<"\t Deposit  money Via Check Book  --4"<<endl;
    	cout<<"\t Balance inquiry                --5"<<endl;
    	cout<<"\t Transaction history            --6"<<endl;
    	cout<<"\t Make Choice _ ";
    	cin>>Choice;
    	switch(Choice){
    		case '1':// Show Detail's
    			Show_Transactionhistory(BH,true);
    		break;
    		case '2':// With Draw via Card
    			WithDrawViaCard(BD,BH);
    		break;
    		case '3':// With Draw via check book
    			With_drawMoney(BD,BH);
    		break;
    		case '4':// Deposit via check book
    			Deposit_Money(BD,BH);
    		break;
    		case '5':// Check Balance
    			Balance_inquiry(BD);
    		break;
    		case '6':// Show All History
    			Show_Transactionhistory(BH,false);
    		break;
    		default:
    			Choice = '0';
		}
	 }while(Choice!='0');
	}// if
	else if(Choice =='1'){
		do{
			ps cls
		cout<<"\tCreate Account                             --1"<<endl;
    	cout<<"\tDelete  Account                            --2"<<endl;
    	cout<<"\tFind All Account Type (Saving or Checking) --3"<<endl;
    	cout<<"\tFind Account By Cnic or Account Number     --4"<<endl;
    	cout<<"\tFind By Card Number                        --5"<<endl;
    	cout<<"\tDeposit or With Draw amount to Account     --6"<<endl;
    	cout<<"\t Make Choice : ";
    	cin>>Choice;
    	switch(Choice){
    		case '1':// Create Account 
    			Create_Account(BD);
    		break;
    		case '2':// Delete Account
    		    Delete_Account(BD,BH);
    		break;
    		case '3':// Find All Acount 
    	    [](auto &vec){
    	    	short choice;
    	    	bool Bool;
    	    	bool found = false;
    	    	cout<<"\t Make Choice Saving-1 <-> Checking-2 _ ";
    	    	cin>>choice;
    	    	Bool = (choice == 1)?true :false;
    	    	for(auto it:vec){
    	    		if(it.get_acc_type() == Bool){
    	    			found =true;
    	    			it.to_console();
					}
				}
				if(!found) {cout<<"\t No Thing Found "<<endl;}
			}(BD);
    		break;
    		case '4':// Find Account by cnic & num
    		Display_Account(BD);
    		break;
    		case '5':// find Acc by Credit Card Num
    		Find_AccBYidnum(BD);
    		break;
    		case '6':// Deposit or With draw
    		Add_withDrawMoney(BD);
    		break;
    		default:
    			Choice = '0';
		}
      }while(Choice !='0');
	} else cout<<"\t Thanks "<<endl;
	// Put Data to Files
	ofstream out;
	out.open("DataBase/UserHistory.text",ios_base::out);
	if(!out.is_open()){cout<<"\t!!Data Base Error"<<endl; exit(0);}
	if(!BH.empty()){
		for_each(BH.begin(),BH.end(),[&out](auto &obj){
		out<<obj.to_database();
	   });
	}
	out.close();
	
	ofstream ot;
	ot.open("DataBase/UserData.text",ios_base::out);
	// Data Base check
	if(!BD.empty()){
		for_each(BD.begin(),BD.end(),[&ot](auto obj){
		ot<<obj.to_DataBase()<<obj.get_cnic_num()<<"$"<<obj.get_cell_num();
		ot<<"$"<<obj.get_account_num()<<"$"<<obj.get_cardid()<<"$"<<obj.get_acc_type();
		ot<<"$"<<obj.get_balance()<<endl;
	    });
    }
	ot.close();
}//Main
template<class T>
void Get_History(T &vec){
	string str[4];
	ifstream in;
	in.open("DataBase/UserHistory.text",ios_base::in);
	if(!in.is_open()){cout<<"\t Data Base Error _ User Record"<<endl;exit(0);}
	while(getline(in,str[0],'$')){
	//	cout<<str[0]<<endl<<"it"<<endl; // Check
		for(int i=1;i<3;i++)
		   getline(in,str[i],'$');
		getline(in,str[3],'\n');
		[&str](auto &VEC){
			BankHistory obj(stoll(str[1]),stoll(str[2]));
			obj.set_Time(str[3]);
			obj.set_AccountNumber_(stoll(str[0]));
			VEC.push_back(obj);
		}(vec);
	}
	in.close();
}
template<class T>
void Get_BankData(T &vec){
	ifstream in;
	string str[13];
	in.open("DataBase/UserData.text",ios_base::in);
	if(!in.is_open()){cout<<"\t Data Base Error"<<endl; exit(0);}
	if(!is_Empty(in)){
	while(getline(in,str[0],'$')){
		for(int i=1;i<12;i++)
		   getline(in,str[i],'$');
		getline(in,str[12],'\n');
		[&str](auto &it){
		     	UserData obj(str[0],str[1],str[2]);
		     	obj.set_Time(str[3]);// Set Time
		     	obj.set_DOB(stoi(str[4]),stoi(str[5]),stoi(str[6]));// Set DOB
		     	obj.set_cnic_num(stoll(str[7]));// Set Cnic Num
		     	obj.set_cell_num(stoll(str[8]));// Set Cell Num
		     	obj.set_account_num(stoll(str[9]));// Set Account Num
		     	obj.set_cardid(stoll(str[10]));// Set Card num
		     	bool Bool = (str[11]=="1")?true :false;// Acount Type
		     	obj.set_Balance(stoll(str[12]));// set Balance
		     	obj.set_accounttype(Bool);// Set Type
		     	it.push_back(obj);
		} (vec);
	}// While
	 in.close();
   }// if
	else{
		in.close();
		cout<<"\t Add Account to Continue !! No Data Found"<<endl;
		Create_Account(vec);
	}
}