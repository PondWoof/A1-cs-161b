// ------------- FILE HEADER -------------
// Author ✅: AspenBouma
// Assignment ✅: Assignment 1: Food Truck (CS 161A Review)
// Date ✅: 10/2/2025 
// Citations: AN   


// ------------- ZYBOOKS SCORES -------------
// Chapter ✅: chapter 9 done!
// Participation ✅: 100%
// Challenge ✅: 100%
// Labs ✅: 100%


// ------------- DISCORD POSTS -------------
// https://discord.com/invite/URYKKf8YHm
// Count ✅: ones!
// Links (Optional): https://discord.com/channels/826344686548811809/826344687019360258/1421040692796330067 


// ------------- DESIGN DOCUMENT -------------
// A. INPUT ✅: int yesOrNo, double cost, double tip, string name 
// B. OUTPUT ✅: string text, double cost, double tip, double& discount, double totel.
// C. CALCULATIONS ✅: tDis = (tDis - (tDis / 100) * discount) and (((tip + cost) / 100) * discount)
// D. LOGIC and ALGORITHMS: (pseudocode)
//  I did not do pseudocode :< 
// 
// 
// 
//    (Optional) flow chart link or file name: 


// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS ✅: yep it pases the tests 
// (Optional) Additional tests count: 



// ------------- CODE -------------


#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std; 

//function list 


void welcome();

void badInputText();

void displayMenu();
																
void readOption(int& option);

void readInt(string prompt, int& num);

void readDouble(string prompt, double& num);

void placeOrder(double& cost);

double tipDiscount(double& tip, double& discount, double cost);

// MAIN!!!!!!!!!!!!!!!!
int main() {

	int option = 3;
	double cost = 0.0;
	double totalPreas = 0;
	double discount = 0.0;
	double tip = 0.0;
	double totel = 0;

	cout << fixed << setprecision(2);

	welcome();
	displayMenu();
	readOption(option);
		while((option == 1)) {
		
			// gets cost of 
			placeOrder(cost);

			// 
			cout << endl << "Your order is: $" << cost << endl;
			totel = tipDiscount(tip, discount, cost);
			
			cout << "Your order with tip is: " << (tip + cost) << endl;
			if (discount == 0) {
				cout << (discount) << "% discount  ";
			}
			else {
				
				cout << setprecision(0) << (discount) << "% discount: $";
				cout << setprecision(2) << (((tip + cost) / 100) * discount);
				
			}
			cout << endl << "total: $" << totel << endl << endl;
			// reseting past "total"
			cost  = 0;
			// loop y or n 
			displayMenu();
			readOption(option);
		
		}
		//
		cout << endl << "ended ty :3" << endl;
	
	return 0;

}


// 
//
//


// basic text functions
void welcome() {
	cout << "Welcome to my Food Cart Program!" << endl << endl;
}

void badInputText() {
	cout << "Bad input, please try again." << endl;
}

void displayMenu() {
	cout << "pick an option:" << endl << "1. place an order" << endl;
	cout << "2. quit" << endl;
	cout << ">> ";
}

// validates and "gets" a 1 or 2 from the user
void readOption(int& option) {

	// option is assigned a number thats not 1 or 2. so it's 3 :>    
	option = 3;

	while (!(option == 2 || option == 1)) {

		cin >> option;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(9999999, '\n');
			cout << "Bad input, please try again." << endl << endl;
			displayMenu();
			cin >> option;
		}

		if ((option != 2) && (option != 1)) {
			cout << "Bad input, please try again. :< " << endl << endl;
			displayMenu();
		}
	}
}

// read and validates int 
void readInt(string prompt, int& num) {

	cout << prompt;
	cin >> num;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(9999999, '\n');

		badInputText();
		cout << prompt;
		cin >> num;
	}
	while (num <= 0) {

		badInputText();
		cout << prompt;
		cin >> num;
	}
	while (isalpha(num)) {

		badInputText();
		cout << prompt;
		cin >> num;
	}
}

//read and validates Double
void readDouble(string prompt, double& num) {

	cout << prompt;
	cin >> num;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(9999999, '\n');
		
		badInputText();
		cout << prompt;
		cin >> num;
	}
	while (num <= 0) {
		
		badInputText();
		cout << prompt;
		cin >> num;
	}
	while (isalpha(num)) {
		
		badInputText();
		cout << prompt;
		cin >> num;
	}
}


void placeOrder(double& cost) {
	
	string name = "a";
	double temNum = 0.0;
	char yesOrNo = 'a';

	while (!(yesOrNo == 'n')) {

		cout << endl << "Enter the name of your item: ";
		//name does not do anythingy :)
		cin >> name;
		readDouble("Enter the cost of your item  $ ", temNum);

		cost = cost + temNum;

		do {
			cout << "Do you want another item? (y/n): ";
			cin >> yesOrNo;

			if (isupper(yesOrNo)) {
				yesOrNo = tolower(yesOrNo);
			}

			if ((yesOrNo == 'y')) {

			}
			else if ((yesOrNo == 'n')) {

			}
			else {
				cout << "Invalid Option!" << endl;
				cin.clear();
				cin.ignore(9999999, '\n');
			}

		} while (!(yesOrNo == 'y' || yesOrNo == 'n'));
	}
}

double tipDiscount(double& tip, double& discount, double cost) {

	readDouble("Enter tip $: ", tip);

	discount = 0;
	double tDis = 1;

	tDis = cost + tip;
	//"they get a 10% discount";
	if (tDis > 50) {
		discount = 10;

	}
	//"they get a 5% discount";
	else if (tDis > 35) {
		discount = 5;

	}
	/*	math: if tDis is 50;
		50 / 100 = 0.5  --> 0.5 * 5 = 2.5
		--> 50 - 2.5 = 47.5
		total with discount is now 47.5
	*/
	if (!(discount == 0)) {
		tDis = (tDis - (tDis / 100) * discount);
	}

	return tDis;
}

