//		skeleton .cpp
//********************************************
#define _GLIBCXX_USE_C99 1
#include "simple.h"
#include <vector>
#include <fstream>

//declaring functions in the main. may be moved.
void HandleInputLine(std::string inputLine, std::vector<std::string>& command_sep);


int main() {
	std::vector<std::string> command_sep = std::vector<std::string>();
	std::vector<account> account_vec = std::vector<account>();
	std::string input;
	//we'll change 'cin' to other source, obviously.
	std::ifstream inputFile("orders_1");

	if (!inputFile)
	{
		std::cout << "File opening failed.\n";
		return 1;
	}
	char buffer[60];
	while (inputFile)
	{
		
		inputFile.getline(buffer, 60);
		input = buffer;
		HandleInputLine(input, command_sep);
		int flag = 0;
		int flag2 = 0;
		//a critical place. when a thread searches for an account in this 
		account* the_account;
		int ID1 = std::stoi(command_sep[1]);
		std::string basic = command_sep[1];
		for (account index : account_vec) {
			if (flag2 == 0) {
				flag2++;
			}

			if (index.ID == ID1) {
				flag = 1;
				the_account = &index;
				break;
			}
		}
		const char* command = command_sep[0].c_str();
		if (flag != 1) {
			if (*command == 'O') {
				//add here the call to the function.
				//then, return SUCCESS
			}
			std::cout << "Error " << "ATM ID TO HERE PLEASE" << ": Your transaction failed � account id ";
			std::cout << command_sep[1] << "does not exist" << std::endl;
			return 1;
		}
		flag = 0;
		//here we know that the account exists, and we search for its command
		if (*command=='O') {
			std::cout << "Error " << "ATM ID TO HERE PLEASE" << ": Your transaction failed - account with same id exists";
			std::cout << std::endl;
			return 1;
		}
		if (*command == 'D') {
			int password = std::stoi(command_sep[2]);
			int amount = std::stoi(command_sep[3]);
			if (!Deposit(*the_account, password, amount)) {
			}
			else { return 1; }
		}
		if (*command == 'B') {
			int password = std::stoi(command_sep[2]);
			if (!Balance(*the_account, password)) {
			}
			else {
				return 1;
			}
		}
		if (*command == 'T') {
			account* other_account;
			int ID2 = std::stoi(command_sep[3]);
			for (account index : account_vec) {
				if (index.ID == ID2) {
					flag = 1;
					other_account = &index;
					break;
				}
			}
			if (flag != 1) {
				std::cout << "Error " << "ATM ID TO HERE PLEASE" << ": Your transaction failed � account id ";
				std::cout << command_sep[1] << "does not exist" << std::endl;
			}
			else { return 1; }
			int password = std::stoi(command_sep[2]);
			int amount = std::stoi(command_sep[4]);
			if (!Transfer(*the_account, password, *other_account, amount)) {
			}
			else { return 1; }
		}
	}

	inputFile.close();
	
	delete(&command_sep);
	delete(&account_vec);
	return 0;
	
}


void HandleInputLine(std::string inputLine, std::vector<std::string>& command_sep)
{
	const char* delimiters = " \t\n";
	char* Command = (char*)inputLine.c_str();
	const char* cmd = std::strtok(Command, delimiters);
	char* account = std::strtok(NULL, delimiters);
	char* arg;
	command_sep.push_back(cmd);
	command_sep.push_back(account);
	do
	{
		arg = std::strtok(NULL, delimiters);
		if (arg != '\0')
		{
			command_sep.push_back(arg);
		}
	} while (arg != '\0');

}
