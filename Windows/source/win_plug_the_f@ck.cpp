/* Plug the fuck

   An HID exploitation framework based on arduino. Created by Christos Tsiakoulas (github.com/littlepwnie).
   The code included in the .ino files requires HID Compatible Atmega microcontrolles.
   The tests were carried out on an Arduino Micro with Atmega32U4. */

#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <regex>
#include <sstream>

// command line colors
#define RED   "\x1B[31m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

using namespace std;

/* do_replace function gets the string variable with the file contents and replaces the information in
   <> with what the user has set. */
string do_replace(string const & in, string const & from, string const & to) {
	string tmp = "<" + from + ">";
	return regex_replace(in, regex(tmp), to);
}

// read_pass function loads the contents of the default .ino files to a string variable for processing.
string read_pass(ifstream &is) {
	string str;
	string file_contents;
	while (getline(is, str))
	{
		file_contents += str;
		file_contents.push_back('\n');
	}
	return file_contents;
}

// GetNthWord splits strings in words and returns the one chosen, defined by "size_t n".
string GetNthWord(string s, size_t n) {
	istringstream iss(s);
	while (n-- > 0 && (iss >> s));
	return s;
}

int main()
{
	// ASCII art :)
    printf(RED "\n                  ______/``'``'-.\n                 (_   6  \\    .^\n               __ `'.__,  |    `'-.\n" RESET);
	printf(RED "              / _ \\  /    /      :`^'\n            / `/_` \\/    /       .'\n            \"/  `'-     |.-'`^. `.\n" RESET);
	printf(RED "            / .`-._     \   `'^^^\n          / `/'    \\      \\ \n          \"\"       \\      `.\n" RESET);
	printf(RED "         .----.    `\      `.\n         | == | =]===`\/     \-'-.-\n         |----|        /     /`.  `-.\n" RESET);
	printf(RED "         | == |       (    /'   )  .^\n         |----|        \\  \\  .'^. `.\n         |::::|         \\ > >  `` `. )\n" RESET);
	printf(RED "         |___.|         // /       .`\n         \"    \"       /`/ /\n                      \"\" \"\n" RESET);

	printf(RED "   ____             ____   _______       ___      ___        ___\n" RESET);
	printf(RED "  /   / /    /   / /   /      /   /   / /        /    /   / /    /   /\n" RESET);
	printf(RED " /___/ /    /   / /  _       /   /---/ /---     /--  /   / /    /---/\n" RESET);
	printf(RED "/     /___ /___/ /___/ ___  /   /   / /___ ___ /    /___/ /___ /    \\ \n\n" RESET);
	printf(RED "         An Arduino-based HID exploitation framework\nBrought to you by Littlepwnie (https://github.com/littlepwnie)\n\n\n" RESET);

	printf(YEL "	6 Windows payloads\n" RESET);
	printf(YEL "	1 Linux Payloads\n\nType \'help\' to see available options.\nType \'exit\' to close the program.\n\n\n" RESET);

	string var, line, payload, value, option, file;
	string stuff;
	ifstream inFile;

	printf(YEL "> " RESET);
	getline(cin, option);

	while (option != "exit") {
		if (option == "help") {
			printf(" +		help: displays help content about the available commands.\n\n +		exit: closes the program.\n\n");
			printf(" +		show windows: gives a list of all available MS Windows payloads and their description.\n\n +		show linux: gives a list of all available Linux payloads and their description.\n\n +		use <path>: use the module specified in the path. The syntax is without the <>.\n\n");
			printf(" +		show options : show available options for the module specified.\n\n +		set <option> <value> : set the value of an available option. The syntax is without the <>.\n\n +		generate : in /generated, make the payload in .ino file, ready for upload through Arduino IDE.\n\n");
		}

		// Lists windows payloads by opening the file.
		else if (option == "show windows") {
			ifstream inFile("payloads\\windows\\windowsindex.txt");
			while (getline(inFile, line).good()) {
				cout << line << endl;
			}
			inFile.close();
		}
		// Lists linux payloads by opening the file.
		else if (option == "show linux") {
			ifstream inFile("payloads\\linux\\linuxindex.txt");
			while (getline(inFile, line).good()) {
				cout << line << endl;
			}
			inFile.close();
		}

		/* Get the second word from use statement, set the payload variable for the options file later,
		   and load in "string stuff" the contents of the .ino file. */
		else if (GetNthWord(option, 1) == "use") {
			file = GetNthWord(option, 2);
			if (file == "linux\\ubuntu_gui_info_gathering") {
				payload = "payloads\\linux\\ubuntu_gui_info_gathering";
				ifstream input("payloads/linux\\ubuntu_gui_info_gathering\\ubuntu_gui_info_gathering.ino");
				stuff = read_pass(input);
			}
			else if (file == "linux\\ubuntu_gui_wget_n_run") {
				payload = "payloads\\linux\\ubuntu_gui_wget_n_run";
				ifstream input("payloads\\linux\\ubuntu_gui_wget_n_run\\ubuntu_gui_wget_n_run.ino");
				stuff = read_pass(input);
			}
			else if (file == "windows\\add_to_hosts_file") {
				payload = "payloads\\windows\\add_to_hosts_file";
				ifstream input("payloads\\windows\\add_to_hosts_file\\add_to_hosts_file.ino");
				stuff = read_pass(input);
			}
			else if (file == "windows\\erase_flash_drives") {
				payload = "payloads\\windows\\erase_flash_drives";
				ifstream input("payloads\\windows\\erase_flash_drives\\erase_flash_drives.ino");
				stuff = read_pass(input);
			}
			else if (file == "windows\\powercat_admin_reverse_shell") {
				payload = "payloads\\windows\\powercat_admin_reverse_shell";
				ifstream input("payloads\\windows\\powercat_admin_reverse_shell\\powercat_admin_reverse_shell.ino");
				stuff = read_pass(input);
			}
			else if (file == "windows\\powercat_reverse_shell") {
				payload = "payloads\\windows\\powercat_reverse_shell";
				ifstream input("payloads\\windows\\powercat_reverse_shell\\powercat_reverse_shell.ino");
				stuff = read_pass(input);
			}
			else if (file == "windows\\wifi_pass_stealer") {
				payload = "windows\\wifi_pass_stealer";
				ifstream input("windows\\wifi_pass_stealer\\wifi_pass_stealer.ino");
				stuff = read_pass(input);
			}
			else {
				payload = "payloads\\windows\\win_add_admin";
				ifstream input("payloads\\windows\\win_add_admin\\win_add_admin.ino");
				stuff = read_pass(input);
			}
		}

		// Read options file for the payload chosen.
		else if (option == "show options") {
			file = payload + "\\options.txt";
			ifstream inFile(file);
			while (getline(inFile, line).good()) {
				cout << line << endl;
			}
			inFile.close();
		}

		/* If "set" is used, get the second (variable to be set) and the third word (its desired value) and replace
		   them in "stuff". Then return the edited payload back to "stuff". */
		else if (GetNthWord(option, 1) == "set") {
			var = GetNthWord(option, 2);
			value = GetNthWord(option, 3);
			stuff = do_replace(stuff, var, value);
		}

		// Write the contents of "stuff" variable back to a new .ino file under the directory \generated of the project folder.
		else if (option == "generate") {
			ofstream outFile("generated\\payload.ino");
			for (const auto &e : stuff) outFile << e;
			printf(YEL "\n +		The payload has been generated! Go to \\generated and open the file with Aruino IDE for upload.\n\n" RESET);
		}

		// If a command is not recognised, print message.
		else {
			printf(YEL "Command is not recognised...\n" RESET);
		}
		printf(YEL "> " RESET);
		getline(cin, option);
	}
}