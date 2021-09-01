class account {
	int acno; char name[50];
	int deposit; char type;
public:
	void create_account();  // function to get data from user
	void show_account() const;  // function to show data from user
	void modify();  // function to add new data
	void dep(int x); // function to accpet amount and add to balance amount
	void draw(int x);  // function to accept amount and subtract from balance amount
	void report() const; // function to show data in tabular format
	int retacno() const; // function to return account number
	int retdeposit() const; // function to return balance amount
	int rettype() const; // function to return type of account
};
void account::create_account() {
	cout << "\nEnter The Account No.: "; cin >> acno;
	cout << "\n\nEnter The Name Of Account Holder: ";
	cin.ignore(); cin.getline(name, 50);
	cout << "\nEnter Type of The Account (C/S): "; cin >> type;
	type = toupper(type);
	cout << "\nEnter The Initial amount: "; cin >> deposit;
	cout << "\n\nAccount Created..";
}
void account::show_account() const {
	cout << "\nAccount No.: " << acno;
	cout << "\nAccount Holder Name: " << name;
	cout << "\nType of Account: " << type;
	cout << "\nBalance amount: " << deposit;
}
void account::modify() {
	cout << "\nAccount No.: " << acno;
	cout << "\nModify Holder Name: ";
	cin.ignore(); cin.getline(name, 50);
	cout << "\nModify Type of Account: "; cin >> type;
	type = toupper(type);
	cout << "\nModify Balance amount: "; cin >> deposit;
}
void account::dep(int x) {
	deposit += x;
}
void account::draw(int x) {
	deposit -= x;
}
void account::report() const {
	cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
}
int account::retacno()const {
	return acno;
}
int account::retdeposit() const {
	return deposit;
}
int account::rettype() const {
	return type;
}
