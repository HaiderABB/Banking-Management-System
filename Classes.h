int PINset()
{
	cout << "Successfully Logged Out of Manager Account" << endl;
	cout << "---------------------------" << endl;
	cout << "\nAccount Created, Complete Steps" << endl;
	cout << "Enter 4-Digit PIN for your Debit Card" << endl;
	cin >> PIN;
	while (PIN < 1000 || PIN>9999)
	{
		cout << "Enter correct PIN " << endl;
		cin >> PIN;
	}
	return PIN;
}


void setDetailRegex()
{
	cout << "Enter your Name : " << endl;
	cin.ignore();
	getline(cin, name);
	regex Fname_regex("^[A-Za-z]+(?:[\\s-][A-Za-z]+)*$");
	if (regex_match(name, Fname_regex)) {
		check = false;
	}
	else {
		cout << "Name format is incorrect, Retry" << endl;
		check = true;
	}
	while (check)
	{
		// Full Name Check
		cout << "Enter Name : " << endl;
		cin.clear();
		getline(cin, name);
		if (regex_match(name, Fname_regex)) {
			check = false;
		}
		else {
			cout << " Name format is incorrect, Retry" << endl;
			check = true;
		}
	}
	cout << "---------------------------" << endl;
	//           Address Check
	cout << "Enter your address: ";
	cin.clear();
	getline(cin, address);
	regex address_regex("^[A-Za-z0-9\\s,-]+$");
	if (regex_match(address, address_regex)) {
		check = false;
	}
	else {
		cout << "Address format is incorrect, Retry" << endl;
		check = true;
	}
	while (check)
	{
		cout << "Enter your address: ";
		cin.ignore();
		getline(cin, address);
		if (regex_match(address, address_regex)) {
			check = false;
		}
		else {
			cout << "Address format is incorrect, Retry" << endl;
			check = true;
		}
	}
	cout << "---------------------------" << endl;
	// Login-ID check
	cout << "---------------------------" << endl;

	cout << "Enter your login ID: ";
	getline(cin, id);
	regex login_id_regex("^[a-zA-Z0-9_-]{4,16}$");
	if (regex_match(id, login_id_regex)) {

		check = false;
	}
	else {
		cout << "Login ID format is incorrect. Retry" << std::endl;
		check = true;
	}
	while (check)
	{
		cout << "Enter your login ID: ";
		getline(cin, id);
		if (regex_match(id, login_id_regex))
		{

			check = false;
		}
		else {
			cout << "Login ID format is incorrect. Retry" << std::endl;
			check = true;
		}
	}

	// Password Check
	cout << "---------------------------" << endl;

	cout << "Enter your password, Atleast 1 capital letter, minimum 8 characters and maximum 16 characters : ";
	cin.clear();
	getline(cin, pass);
	regex password_regex("^(?=.*[A-Z])(?=.*[0-9]).{8,}$");
	if (regex_match(pass, password_regex)) {
		check = false;
	}
	else {
		cout << "Password format is incorrect, Retry" << endl;
		check = true;
	}
	while (check)
	{
		cout << "Enter your password, Atleast 1 capital letter, 1 digit and minimum 8 characters ";
		cin.clear();
		cin.ignore();
		getline(cin, pass);
		if (regex_match(pass, password_regex)) {
			check = false;
		}
		else {
			cout << "Password format is incorrect, Retry" << endl;
			check = true;
		}
	}
}


bool checkPhoneNumber(long long phoneNumber) {
	return phoneNumber >= 10000000000LL && phoneNumber <= 99999999999LL;
}

void MarksFraudulent(int ID)
{
	write.open("Fraudulent.txt", ofstream::app);
	write << ID << " " << endl;
	write.close();
}


class BankManager {
private:
	string pass;
	string username;
public:
	void setPass(string pass) { this->pass = pass; }
	void setUsername(string username) { this->username = username; }
	string getPass() { return pass; }
	string getUsername() { return username; }
};

BankManager manager[2];


class Transaction {
	string Date;
	int amount;
	string Type;
	int id;
public:
	Transaction(){}
	void setDate(string Date) { this->Date = Date; }
	string getDate() { return Date; }
	void setAmount(int amount) { this->amount = amount; }
	int getAmount() { return amount; }
	void setType(string type) { Type = type; }
	string getType() { return Type; }
	void setId(int id) { this->id = id; }
	int getId() { return id; }
	~Transaction(){}
};


int generateID()
{
	srand(std::time(nullptr));
	int random_number = std::rand() % 69001 + 1000;
	return random_number;
}


class User {
protected:
	int id;
	string name;
	string address;
	string userID;
	string password;
	bool fraud;
public:
	User() { fraud = false; }
	User(string name,string address,string userID,string password) {
		this->name = name; this->address = address; this->userID = userID; this->password = password; id = generateID(); fraud = false;
	}
	void setId(int id) { this->id = id; }
	void setName(string name) { this->name = name; }
	void setAddress(string address) { this->address = address; }
	void setUserId(string userID) { this->userID = userID; }
	void setPassword(string password) { this->password = password; }
	void setFraud(int f) { this->fraud = f; }
	bool getFraud() { return fraud; }
	int getId() { return id; }
	string getName() {return name; }
	string getAddress() { return address; }
    string getUserId() { return userID; }
	string getPassword() { return password; }
	~User(){}
};


class Card {
private:
    long long int cardNum;
	int PIN;
public:
	Card(){}
	void generateCardNum() {
		random_device rd;
		mt19937_64 generator(rd());
		uniform_int_distribution<long long> distribution(1000000000000000LL, 9999999999999999LL);
		cardNum = distribution(generator);
	}
	long long int getCardNum() { return cardNum; }
	int getPIN() { return PIN; }
	void setPin(int pin) { PIN = pin; }
	void setCardNum(long long int num) { cardNum = num; }
	~Card() {}
};


class AccountType {
protected:
	int Balance;
	int limit;
	string Type;
	int totalTransaction;
public:
	AccountType() { Balance = 0; totalTransaction = 0; }
	AccountType(int limit, string type) { this->limit = limit; Balance = 0; Type = type; }
	int getTotalTransaction() { return totalTransaction; }
	void setTotalTransaction(int amount) { totalTransaction = totalTransaction + amount; }
	void setBalance(int bal) { Balance = Balance + bal; }
	int getBalance() { return Balance; }
	void setLimit(int limit) { this->limit = limit; }
	int getLimit() { return limit; }
	bool withDraw(int amount)
	{
		if (amount > Balance)
		{
			check = true;
			return check;
		}
		else
		{
			Balance = Balance - amount;
			check = false;
			cout << "Transaction Complete " << endl;
			setTotalTransaction(amount);
			return check;
		}
	}
	void setType(string Type)
	{
		this->Type = Type;
	}
	string getType() { return Type; }
	~AccountType() {}
};


class UserClient:public User 
{	
protected:
	long long int phoneNum;
	string CNIC;
	int totalCards=1;
public:
	AccountType Acc;
	Card card;
	UserClient() {}
	UserClient(const AccountType Acc, string name, string address, string userID, string password, string CNIC, long long int phoneNum) :User(name, address, userID, password) {this->Acc = Acc; this->CNIC = CNIC; this->phoneNum = phoneNum;  }
	void setPhoneNum(long long int num) { phoneNum = num; }
	void setCNIC(string CNIC) { this->CNIC = CNIC; }
	int getPhoneNum() { return phoneNum; }
	string getCNIC() { return CNIC; }
	void setCard(int num) { card.generateCardNum(); card.setPin(num); }
	int getTotalCard() { return totalCards; }
	
	~UserClient() {}
};


class CompanyClient :public User {
protected:
	int taxNumber;
	int loanC;
public:
	AccountType Acc;
	Card card;
	CompanyClient() { loanC = 0; }
	CompanyClient(const AccountType Acc, string name, string address, string userID, string password, int taxNumber) :User(name, address, userID, password) { this->Acc = Acc; this->taxNumber = taxNumber; loanC = 0; }
	void setTax(int tax) { taxNumber = tax; }
	int getTax() { return taxNumber;}
	void setCard(int num) { card.generateCardNum(); card.setPin(num); }
	void setLoan() { ++loanC; }
	int getLoan() { return loanC; }
	~CompanyClient() {}
};


{
	readRecords();
	setDetailRegex();
	cout << "Enter Company Tax Number : " << endl;
	cin >> tax;
	while (tax < 0)
	{
		cout << "Give Correct Input" << endl;
		cin >> tax;
	}
	// Daily Withdraw Limit
	cout << "---------------------------" << endl;
	cout << "Enter your daily withdraw limit : " << endl;
	cin >> withDrawL;
	while (withDrawL < 0 || withDrawL>20000000)
	{
		cout << "Wrong limit Entered, Retry" << endl;
		cin >> withDrawL;
	}
	// Creating Objects
	AccountType Acc;
	if (withDrawL <= 100000)
	{
		Acc.setLimit(100000);
		Acc.setType("Bronze");
	}
	else if(withDrawL<=500000)
	{
		Acc.setLimit(500000);
		Acc.setType("Gold");
	}
	else
	{
		Acc.setLimit(2000000);
		Acc.setType("Business");
	}
	CompanyClient Company(Acc,name,address,id,pass,tax);
	check=Approval(Company);
	if (check)
	{
		cout << "Logged out of Manager Account, complete steps\n\n";
		Company.setCard(PINset());
		++totalC;
		writeRecords();
		writeSignUp(Company);
	}
	else
		cout << "Account Not Approved " << endl;

}
