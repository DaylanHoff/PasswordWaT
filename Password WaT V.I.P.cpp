/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
////										  Made By:								  	     ////
////										 Daylan Hoff								     ////
////-----------------------------------------------------------------------------------------////
////	                DO NOT DELETE CRDTS, OR REDISTRIBUTE THIS SOFTWARE!!!                ////
////										   5-13-17              					     ////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <limits>
//Precents errors all you need to know
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ios;
//End of error prevention
//Password Login & Registering system.
class User {

public:
    string username;
    string password;
    string inputUsername;
    string inputPassword;

    void userRegisterDo() {

        ofstream usersFile ("user1.txt");
        if (	!usersFile.is_open()) {
            usersFile.open("user1.txt");
        }
            usersFile << username << " " << password << endl;
            usersFile.close();
    }
    void userRegister(){
    		string Display = "";
		ifstream openfile ("logoVIP.txt");
		if(openfile.is_open()) {
			while(! openfile.eof()) {
				getline(openfile, Display);
				cout << Display << endl;
			}
		}
        cout << "Welcome!\n-------------------------\n\nPlease register.\nEnter a new username:\n";
        cin >> username;
        cout << "\nPlease enter a new password:\n";
        cin >> password;
        userRegisterDo();
    }
    void login() {
	string Display = "";
		ifstream openfile ("logoVIP.txt");
		if(openfile.is_open()) {
			while(! openfile.eof()) {
				getline(openfile, Display);
				cout << Display << endl;
			}
		}
        cout << "Please enter your username:\n";
        cin >> inputUsername;
        cout << "\nPlease enter your password:\n";
        cin >> inputPassword;
        string userAndPass = inputUsername + " " + inputPassword;
        int offset;
        string line;
        ifstream usersFile;
        usersFile.open ("info.txt");
bool found = false;
      if(usersFile.is_open()) {
          while(getline(usersFile,line) && !found) {
              if (line.compare(userAndPass) == 0) {
                  found = true;
              }
          }
	usersFile.close();
	if(found) {
		cout << "Welcome! "<< inputUsername << '\n';
	}
	else {
		cout << "\nUsername and/or password incorrect!\n\n\n\n";
		login();
	}
      }
			usersFile.close();
    }
};
//End Login & Regestration.
//Intagers and menu system.
int main0() { //MAIN CALL TO DO NOT TOUCH
int addInfo();
int displayInfo();
int PasswordScram();
int PasswordGen();
int Color();
int ClearData();
int logout();
int menuChoice = 0;
int displayMenu();
//End intagers.
//Menu selection system
menuChoice = displayMenu();

while (menuChoice != -1) {
	if (menuChoice == 1)
		addInfo();
		else if (menuChoice == 2)
			displayInfo();
		else if (menuChoice == 3)
			PasswordScram();
		else if (menuChoice == 4)
			PasswordGen();
		else if (menuChoice == 5)
			Color();
		else if (menuChoice == 6)
			ClearData();
		else if (menuChoice == 0)
			logout();
	else
		cout << "You did not imput a known option. Please Try again!" << endl;
		main0();
	}
logout();//Logs you out of the program if user put -1
}
//End selection system
//Display for menu.
int displayMenu() {
int menu = 0;
cout << "1 Press (1) to add information." << endl;
cout << "2 Press (2) to Display all info." << endl;
cout << "3 Press (3) to scramble your password." << endl;
cout << "4 Press (4) to generate a random password." << endl;
cout << "5 Press (5) to change colors." << endl;
cout << "6 Press (6) to clear all data." << endl;
cout << "7 Press (0) to logout." << endl;
cout << "Enter menu option (1-6) and (0) to logout: " << endl;
cin >> menu;
cin.ignore(1);
return menu;
}
//End menu
//Adding information system
int addInfo() {
string Account  = "";
string Username = "";
string password = "";
string info     = "";
ofstream outFile;
outFile.open("YourPasswords.txt", ios::app);
if (outFile.is_open()) {
	cout << "Enter the name of the software/site your wanting to save. (-1 to stop): ";
	getline(cin, Account);
	while (Account != "-1") {
		cout << "Username (-1 to stop): ";
		getline(cin, Username);
		if (Username == "-1") {
			main0();
		}
		cout << "Password (-1 to stop): ";
		getline(cin, password);
		if (password == "-1") {
			main0();
		}
		if (password.length() < 7) {
			cout << endl << "WARNING: THIS PASSWORD IS NOT VERRY STRONG. YOU SHOULD USE A PASSWORD 8 OR MORE CHARACTERS LONG!" << endl << endl;
		}
		cout << "Input any extra information you would like to save with your login (-1 to stop): ";
		getline(cin, info);
		if (info == "-1") {
			main0();
		}
		outFile << "Program/Website: " << Account<< '\t' << " Username: " << Username << " Password: " << password << " Extra Information: " << info << endl;
		cout << "Your account information was stored. Press ''ENTER'' to continue adding accounts. (-1 to stop): ";
		getline(cin, Account);
	}
	}
	else
		cout << "The file could not be opened. Try Again!" << endl;
		main0(); //brings you back to the menu
	}
//End of adding information system
//Display all stored information system
int displayInfo() {
	string answer = "";
	string Display = "";
		ifstream openfile ("YourPasswords.txt");
		if(openfile.is_open()) {
			while(! openfile.eof()) {
				getline(openfile, Display);
				cout << Display << endl;
				cout << endl;
			}
		}
//Confirmation to send you back to the menu when your done.
cout << "To go back to the menu type (-1): " << endl;
getline(cin, answer);
if (answer == "-1") {
    main0();;
}
	else
		cout << "Unknown imput try again. Type to return to the menu (-1): " << endl;
		displayInfo();
	}
//End confirmation and display
//Password Scrambling system
int PasswordScram() {
	string passwordGen = "";
		cout << "Enter Any Password (-1 to quit): " << endl;
		cout << "To be safe we recomend passwords 8 or more characters long!" << endl;
		getline(cin, passwordGen);
			string waffle = "";//Waffle is your password
//Go back to the menu
		if (passwordGen == "-1") {
		    main0();
		}
//End back to the menu
//Scrambler not verry scrambly but it works
			for (int x = passwordGen.length()-1; x >= 0; x--) {
				waffle += passwordGen.at(x);
			}
			while (waffle.find_first_of("AEIOU") < waffle.length()) {
				waffle.replace(waffle.find_first_of("AEIOU"), 1, "x");
			}
			while (waffle.find_first_of("aeiou") < waffle.length()) {
				waffle.replace(waffle.find_first_of("aeiou"), 1, "X");
			}
			while (waffle.find_first_of("02468") < waffle.length()) {
				waffle.replace(waffle.find_first_of("2468"), 1, "Z");
			}
			while (waffle.find_first_of("13579") < waffle.length()) {
				waffle.replace(waffle.find_first_of("13579"), 1, "z");
			}
			cout << waffle << endl <<endl;
			cout << "Enter another Pssword or press (-1 to quit): " << endl;
			getline(cin, passwordGen);
		}
//End Scrambler
//Password Genorator
int PasswordGen() {
	string imput = "";
	string stop = "";
	cout << "Does the password you are wanting to generate allow symbols in the program ?(-1 to stop)" << endl << "(Y for yes N for no): " << endl;
    getline(cin, imput);
if (imput == "-1") {
    main0();
}
   while (imput == "y") {
      srand(static_cast<unsigned int>(time(0)));
//All characters that is will be used to genorate a password.
      char lower   [26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'y', 'x', 'z' };
      char upper   [26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'Y', 'X', 'Z' };
      char numbers [26] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '1', '2', '3', '4', '5', '6', '7' };
      char symbols [26] = { '!', '@', '#', '$', '%', '^', '&', '*', '!', '@', '#', '$', '%', '^', '&', '*' ,'!', '@', '#', '$', '%', '^', '&', '*', '!', '@' };
      string pass = "";
      for (int n = 0; n <= 6; n++){
      	 //Percent of all different characters being in the generation
         pass = pass + lower[rand() % 25] + upper[rand() % 25] + numbers[rand() % 25] + symbols[rand() % 25];
         //End percentage
      }
	  string stop = "";
      cout << "Your generated password:" << endl;
      cout <<pass<< endl;
      cout << "Press enter to generate another. (-1 to stop):" << endl;
	  getline(cin, stop);
//Return to the menu
      	if (stop == "-1") {
    		main0();
//End to the return
		}
	}
   while (imput == "Y") {
      srand(static_cast<unsigned int>(time(0)));
//All characters that is will be used to genorate a password.
      char lower   [26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'y', 'x', 'z' };
      char upper   [26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'Y', 'X', 'Z' };
      char numbers [26] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '1', '2', '3', '4', '5', '6', '7' };
      char symbols [26] = { '!', '@', '#', '$', '%', '^', '&', '*', '!', '@', '#', '$', '%', '^', '&', '*' ,'!', '@', '#', '$', '%', '^', '&', '*', '!', '@' };
      string pass = "";
      for (int n = 0; n <= 6; n++){
      	 //Percent of all different characters being in the generation
         pass = pass + lower[rand() % 25] + upper[rand() % 25] + numbers[rand() % 25] + symbols[rand() % 25];
         //End percentage
      }
	  string stop = "";
      cout << "Your generated password:" << endl;
      cout <<pass<< endl;
      cout << "Press enter to generate another. (-1 to stop):" << endl;
	  getline(cin, stop);
//Return to the menu
      	if (stop == "-1") {
    		main0();
//End to the return
		}
	}
//Same thing as above, but wont genrorate symbols
   while (imput == "n") {
      srand(static_cast<unsigned int>(time(0)));
//All characters that is will be used to genorate a password.
      char lower   [26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'y', 'x', 'z' };
      char upper   [26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'Y', 'X', 'Z' };
      char numbers [26] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '1', '2', '3', '4', '5', '6', '7' };
      string pass = "";
      for (int n = 0; n <= 6; n++){
      	 //Percent of all different characters being in the generation
         pass = pass + lower[rand() % 25] + upper[rand() % 25] + numbers[rand() % 25];
         //End percentage
      }
	  string stop = "";
      cout << "Your generated password:" << endl;
      cout <<pass<< endl;
      cout << "Press enter to generate another. (-1 to stop):" << endl;
	  getline(cin, stop);
//Return to the menu
      	if (stop == "-1") {
    		main0();
//End to the return
		}
	}
   while (imput == "N") {
      srand(static_cast<unsigned int>(time(0)));
//All characters that is will be used to genorate a password.
      char lower   [26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'y', 'x', 'z' };
      char upper   [26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'Y', 'X', 'Z' };
      char numbers [26] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '1', '2', '3', '4', '5', '6', '7' };
      string pass = "";
      for (int n = 0; n <= 6; n++){
      	 //Percent of all different characters being in the generation
         pass = pass + lower[rand() % 25] + upper[rand() % 25] + numbers[rand() % 25];
         //End percentage
      }
	  string stop = "";
      cout << "Your generated password:" << endl;
      cout <<pass<< endl;
      cout << "Press enter to generate another. (-1 to stop):" << endl;
	  getline(cin, stop);
//Return to the menu
      	if (stop == "-1") {
    		main0();
//End to the return
		}
	}
}
//End Genorator
//Change color of gui (verry important)
int Color() {
//All colors and what you need to type to change it.
	string color = "";
	cout << "Choose one of the following colors (-1 to stop)" << endl<< endl;
	getline(cin, color);
	cout << endl << endl << "0 = Black" << endl;
	cout << " 1 = Blue" << endl;
	cout << " 2 = Green" << endl;
	cout << " 3 = Aqua" << endl;
	cout << " 4 = Red" << endl;
	cout << " 5 = Purple" << endl;
	cout << " 6 = Yellow" << endl;
	cout << " 7 = White(DEFAULT)" << endl;
	cout << " 8 = Gray" << endl;
	cout << " 9 = Light Blue" << endl;
	cout << "10 = Light Green" << endl;
	cout << "11 = Light Aqua" << endl;
	cout << "12 = Light Red" << endl;
	cout << "13 = Light Purple" << endl;
	cout << "14= Light Yellow" << endl;
	cout << "15 = Bright White" << endl;
	cout << "Choose one of the following colors (-1 to stop)" << endl<< endl;
	getline(cin, color);
//End of color list
//What reads the imput and changes the color.
		while(color != "-1") {

		if (color == "0")  {
		system("color 0");
		std::cout << "\t\t\t    Color Changed!" << std::endl;
		Color();
		}
		if (color == "1")  {
		system("color 1");
		std::cout << "\t\t\t    Color Changed!" << std::endl;
		Color();
		}
		if (color == "2")  {
		system("color 2");
		std::cout << "\t\t\t    Color Changed!" << std::endl;
		Color();
		}
		if (color == "3")  {
		system("color 3");
		std::cout << "\t\t\t    Color Changed!" << std::endl;
		Color();
		}
		if (color == "4")  {
		system("color 4");
		std::cout << "\t\t\t    Color Changed!" << std::endl;
		Color();
		}
		if (color == "5")  {
		system("color 5");
		std::cout << "\t\t\t    Color Changed!" << std::endl;
		Color();
		}
		if (color == "6")  {
		system("color 6");
		std::cout << "\t\t\t    Color Changed!" << std::endl;
		Color();
		}
		if (color == "7")  {
		system("color 7");
		std::cout << "\t\t\t    Color Changed!" << std::endl;
		Color();
		}
		if (color == "8")  {
		system("color 8");
		std::cout << "\t\t\t    Color Changed!" << std::endl;
		Color();
		}
		if (color == "9")  {
		system("color 9");
		std::cout << "\t\t\t    Color Changed!" << std::endl;
		Color();
		}
		if (color == "10")  {
		system("color A");
		std::cout << "\t\t\t    Color Changed!" << std::endl;
		Color();
		}
		if (color == "11")  {
		system("color B");
		std::cout << "\t\t\t    Color Changed!" << std::endl;
		Color();
		}
		if (color == "12")  {
		system("color C");
		std::cout << "\t\t\t    Color Changed!" << std::endl;
		Color();
	    }
		if (color == "13")  {
		system("color D");
		std::cout << "\t\t\t    Color Changed!" << std::endl;
		Color();
		}
		if (color == "14")  {
		system("color E");
		std::cout << "\t\t\t    Color Changed!" << std::endl;
		Color();
		}
		if (color == "15")  {
		system("color F");
		std::cout << "\t\t\t    Color Changed!" << std::endl;
		Color();
		}
		//Returns you to menu if -1
		if (color == "-1") {
		main0();
		}
		//End return
	}
}
//End imput and color changer
//End color changer
//Clear stored data (not your account)
int ClearData(){
//Desision of wiether or not to clear all of the data
string answer = "";
cout << "Are you sure you want to remove all stored information? ( Y or N ):" << endl;
getline(cin, answer);
if (answer == "Y") {
			cout << "Your Data has been cleared have a nice day!" << endl;
		std::ofstream ofs;
		ofs.open("YourPasswords.txt", std::ofstream::out | std::ofstream::trunc);
		ofs.close();
}
if (answer == "y") {
			cout << "Your Data has been cleared have a nice day!" << endl;
		std::ofstream ofs;
		ofs.open("YourPasswords.txt", std::ofstream::out | std::ofstream::trunc);
		ofs.close();
	}
	if (answer == "N"){
    main0();
	}
	if (answer == "n"){
    main0();
	}
	else
		cout << "Please enter (Y) for yes or (N) for no." << endl;
		ClearData();//If it didnt understand this will re-prompt you
//End of Desision
}
//End of clearing data
//The main (realy just used for calling to the menu and logging you in)

int main() {
    User user1;
    ifstream usersFile("user1.txt");
    long begin, end;
//If else to figure out if you are registered or not
    if (usersFile.good()) {
        cout << "Users account aquired!\n\n";
    }
    else
        user1.userRegister();
    if(usersFile.is_open()) {
        begin = usersFile.tellg();
        usersFile.seekg (0, ios::end);

        end = usersFile.tellg();
        usersFile.close();

        if(begin == end)
        {
            user1.userRegister();
        }

        else
                user1.login();
    }
//End if else
    main0();//Sends you to the menu after login
    //Made by: Daylan Hoff
}
//End main
//Logout
int logout() {
	main();
}
//End logout
