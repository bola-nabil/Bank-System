#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;
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
//---------------------------------------------//
void write_account();
void display_sp(int n);
void modify_account(int n);
void delete_account(int n);
void deposit_withdraw(int n1, int n2);
void intro();
//---------------------------------------------//
int main() {
	char ch; int num;
	intro();
	do {
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\tEnter (1). NEW ACCOUNT";
		cout << "\n\n\tEnter (2). DEPOSIT AMOUNT";
		cout << "\n\n\tEnter (3). WITHDRAW AMOUNT";
		cout << "\n\n\tEnter (4). BALANCE ENQUIRY";
		cout << "\n\n\tEnter (5). CLOSE AN ACCOUNT";
		cout << "\n\n\tEnter (6). MODIFY AN ACCOUNT";
		cout << "\n\n\tEnter (7). EXIT";
		cout << "\n\n\tSelect Your Option (1-7) ";
		cin >> ch;
		system("cls");
		switch (ch) {
		case '1': {
			write_account(); break;
		}
		case '2': {
			cout << "\n\nEnter Your Account No.: "; cin >> num;
			deposit_withdraw(num, 1); break;
		}
		case '3': {
			cout << "\n\nEnter Your Account No.: "; cin >> num;
			deposit_withdraw(num, 2); break;
		}
		case '4': {
			cout << "\n\nEnter Your Account No.: "; cin >> num;
			display_sp(num); break;
		}
		case '5': {
			cout << "\n\nEnter Your Account No.: "; cin >> num;
			delete_account(num); break;
		}
		case '6': {
			cout << "\n\nEnter Your Account No.: "; cin >> num;
			modify_account(num); break;
		}
		case '7': {
			cout << "******************************************************\n";
			cout << "                Thanks For Using Bank System             \n";
			cout << "******************************************************\n";
			break;
		}
		default: cout << "\a";
		}
		cin.ignore();
		cin.get();
	} while (ch != 7);
	return 0;
}
void write_account() {
	account ac;
	ofstream outFile;
	outFile.open("account.dat", ios::binary | ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
	outFile.close();
}
void display_sp(int n) {
	account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\nBALANCE DETAILS\n";
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account))) {
		if (ac.retacno() == n) {
			ac.show_account();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false) cout << "\n\nAccount Number deos not Exit";
}
void modify_account(int n)
{
	bool found = false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char*> (&ac), sizeof(account));
		if (ac.retacno() == n)
		{
			ac.show_account();
			cout << "\n\nEnter The New Details of account" << endl;
			ac.modify();
			int pos = (-1) * static_cast<int>(sizeof(account));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&ac), sizeof(account));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Record Not Found ";
}
void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat", ios::binary);
	inFile.seekg(0, ios::beg);
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
	{
		if (ac.retacno() != n)
		{
			outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat", "account.dat");
	cout << "\n\n\tRecord Deleted ..";
}
void deposit_withdraw(int n, int option)
{
	int amt;
	bool found = false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char*> (&ac), sizeof(account));
		if (ac.retacno() == n)
		{
			ac.show_account();
			if (option == 1)
			{
				cout << "\n\n\tTO DEPOSITE AMOUNT ";
				cout << "\n\nEnter The amount to be deposited";
				cin >> amt;
				ac.dep(amt);
			}
			if (option == 2)
			{
				cout << "\n\n\tTO WITHDRAW AMOUNT ";
				cout << "\n\nEnter The amount to be withdraw";
				cin >> amt;
				int bal = ac.retdeposit() - amt;
				if ((bal < 500 && ac.rettype() == 'S') || (bal < 1000 && ac.rettype() == 'C'))
					cout << "Insufficience balance";
				else
					ac.draw(amt);
			}
			int pos = (-1) * static_cast<int>(sizeof(ac));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&ac), sizeof(account));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Record Not Found ";
}
void intro() {
	cout << "******************************************************\n";
	cout << "                Hello In Bank System              \n";
	cout << "******************************************************\n";
	cin.get();
}

