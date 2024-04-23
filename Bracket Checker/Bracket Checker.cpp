#include <iostream>
#include <string>
#include <fstream>
#include <stack>


// Function to check brackets in a file
void bracketCheck(const std::string& filePath) {

	// Opening the file
	std::ifstream file(filePath);


	// Checking if file was opened successfully.
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << filePath << std::endl;
		return;
	}

	std::string line;
	int lineNumber = 0;


	// Reading the file by lines
	while (std::getline(file, line)) {
		++lineNumber;
		std::stack<std::pair<char, int>> bracketStack;

		// Iterating through each character in the line
		for (int i = 0; i < line.size(); ++i) {
			char c = line[i];

			// Checking for opening brackets and pushing them to the stack
			if (c == '{' || c == '[' || c == '(') {
				bracketStack.push({c, i + 1});
			}
			else if (c == '}' || c == ']' || c == ')') {
				// If stack = empty, then there is an invalid bracket
				if (bracketStack.empty()) {
					std::cout << "Invalid bracket " << c << "found at " << filePath << ":" << lineNumber << ":" << i + 1 << "." << std::endl;
					return;
				}

				
			}
		}
	}
}
















