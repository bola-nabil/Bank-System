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
