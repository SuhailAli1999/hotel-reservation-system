#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct client{
	string name = "Empty";
	string age = "00";
	string address = "Empty";
	string id = "#00000"; 
	string status = "Empty";
	string roomService = "Empty";
	string checkIn = "0/0/0000";
	string checkOut = "0/0/0000";
};

class hotel {
private:
	string roomType[81];
	string availability[81];
	int roomNumberArray[81];
	int servationsRoom[81];
	client c[81];

public:
	hotel(){
		for (int i = 1; i < 81; i++) {
			servationsRoom[i] = 0;
		};
		for (int i = 0; i <= 20; i++) {
			roomType[i] = "Single";
		};
		for (int i = 21; i <= 40; i++) {
			roomType[i] = "Double";
		};
		for (int i = 41; i <= 60; i++) {
			roomType[i] = "Triple";
		};
		for (int i = 61; i <= 80; i++) {
			roomType[i] = "Sweet";
		};
		 
		
	}
	void mainMenu() {
		int choice = 0;
		cout << "\t\t\t\t\t\x1B[34m#################################\033[0m" << endl;
		cout << "\t\t\t\t\t       Welcome to the hotel" << endl;
		cout << "\t\t\t\t\t\x1B[34m#################################\033[0m" << endl;
		cout << "\t\t\t\t\t   1- Book " << endl;
		cout << "\t\t\t\t\t   2- Display All Room Info" << endl;
		cout << "\t\t\t\t\t   3- Display All Reservations Room" << endl;
		cout << "\t\t\t\t\t   4- Display All Available Room" << endl;
		cout << "\t\t\t\t\t   5- Exit" << endl;
	
		cin >> choice;
		while (choice != 5) {
			switch (choice)
			{
			case 1:	book();
				break;
			case 2: displayAllRoomInfo();
				break;
			case 3: displayAllReservationsRoom();
				break;
			case 4: displayAllAvailableRoom();
				break;
			case 5: return;
			default:
			{
				cout << "\x1B[31m\n\n\t\t\t\t\t          Wrong choice.\033[0m "<< endl << endl;
				mainMenu();
			}
			}

		}
	


	};
	void book() {


		cout << "\t\t\t\t      \x1B[35m We have 80 rooms with different type\033[0m  " << endl << endl;
		cout << "\t\t\t\t\t#################################" << endl;
		cout << "\t\t\t\t\t           1-20 Single" << endl;
		cout << "\t\t\t\t\t#################################" << endl;
		cout << "\t\t\t\t\t           21-40 Double" << endl;
		cout << "\t\t\t\t\t#################################" << endl;
		cout << "\t\t\t\t\t           41-60 Triple" << endl;
		cout << "\t\t\t\t\t#################################" << endl;
		cout << "\t\t\t\t\t           61-80 Sweet" << endl;
		cout << "\t\t\t\t\t#################################" << endl << endl;

		int roomNumber;
		cout << "\t\t\t\t      \x1B[35m Enter the room number you want to book\033[0m  " << endl << endl;

		cin >> roomNumber;
		
		if (servationsRoom[roomNumber] == 0) {
			cout << "Name" << endl;
			cin >> c[roomNumber].name; 
			cout << "Age" << endl;
			cin >> c[roomNumber].age;
			cout << "Address" << endl;
			cin >> c[roomNumber].address;
			cout << "ID" << endl;
			cin >> c[roomNumber].id;
			cout << "Status" << endl;
			cin >> c[roomNumber].status;
			cout << "Room Service" << endl;
			cin >> c[roomNumber].roomService;
			cout << "checkIn" << endl;
			cin >> c[roomNumber].checkIn;
			cout << "checkOut" << endl;
			cin >> c[roomNumber].checkOut;

			cout << "Room has been booked." << endl;
			servationsRoom[roomNumber] = 1;

			system("PAUSE");
			mainMenu();

		}
		else {
			cout << "Sorry, Room is already booked." << endl;
			system("PAUSE");
			mainMenu();
		}

	}
	void displayAllReservationsRoom() {
	
		for (int i = 1; i <= 80; i++) {
			if (servationsRoom[i] == 1) {
				cout << "\x1B[33mRoom Number\033[0m  " << i << "  \x1B[33mRoom Type\033[0m  " << roomType[i] <<"  \x1B[33mClient Name\033[0m  " << c[i].name << "  \x1B[33mRoom Service\033[0m  " <<c[i].roomService<<"  \x1B[33mCheck In\033[0m  " << c[i].checkIn << "  \x1B[33mCheck Out\033[0m  " << c[i].checkOut << endl;
			}
		}
		
		system("PAUSE");
		mainMenu();
	};
	void displayAllAvailableRoom() {
		for (int i = 1; i <= 80; i++) {
			if (servationsRoom[i] == 0) {
				cout << "\x1B[33mRoom Number\033[0m  " << i << "  \x1B[33mRoom Type\033[0m  " << roomType[i] << "  \x1B[33mRoom Service\033[0m  " << c[i].roomService << "  \x1B[33mCheck In\033[0m  " << c[i].checkIn << "  \x1B[33mCheck Out\033[0m  " << c[i].checkOut << endl;
			}
		}

		system("PAUSE");
		mainMenu();

	};
	void displayAllRoomInfo() {
		for (int i = 1; i <= 80; i++) {
			if (servationsRoom[i] == 0) {
			
				availability[i] = "Free";
				
			}
			else {
				availability[i] = "Reserved";

			}
				cout << "\x1B[33mRoom Number\033[0m  " << i << "  \x1B[33mRoom Type\033[0m  " << roomType[i] << "  \x1B[33mAvailability\033[0m  " << availability[i] << "  \x1B[33mRoom Service\033[0m  " << c[i].roomService << "  \x1B[33mCheck In\033[0m  " << c[i].checkIn << "  \x1B[33mCheck Out\033[0m  " << c[i].checkOut << endl;
		

		}
		system("PAUSE");
		mainMenu();
	}
};

int main()
 {
	hotel *p = new hotel;
	p->mainMenu();
	delete p;
	return 0;
}
