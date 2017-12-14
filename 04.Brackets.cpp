#include <iostream>
#include <sstream>

//Yea i know that my function its too big and its a crappy maded but still i've put too much time in that task...

bool checkIfBracketsAreCorrect(std::string brackets, int currentBracket, int bracketCounter);
int main()
{
	int test = 0;
	std::string brackets;
	bool result;
	std::getline(std::cin, brackets);
	int currentBracket = 0;
	int bracketCounter = 0;
	result = checkIfBracketsAreCorrect(brackets,currentBracket,bracketCounter);

	if (result == true)
	{
		std::cout << "Valid" << std::endl;
	}
	else
	{
		std::cout << "Invalid" << std::endl;
	}

	std::cin >> test;
}

bool checkIfBracketsAreCorrect(std::string brackets, int currentBracket, int bracketCounter)
{
	char leftParantheses = '(';
	char rightParantheses = ')';
	char leftSquare = '[';
	char rightSquare = ']';
	char leftBraces = '{';
	char rightBraces = '}';

	bool valid = true;
	while (valid == true)
	{


		bracketCounter++;

		if (brackets[currentBracket] == leftParantheses &&
			brackets[bracketCounter] == rightParantheses)
		{

			brackets.erase(bracketCounter, 1);
			brackets.erase(currentBracket, 1);
			currentBracket = 0;
			bracketCounter = 0;
			continue;
		}
		if (brackets[currentBracket] == leftParantheses && brackets[bracketCounter] == leftSquare ||
			brackets[currentBracket] == leftParantheses && brackets[bracketCounter] == rightSquare)
		{
			
			valid = false;
			return valid;
		}
		if (brackets[currentBracket] == leftSquare &&
			brackets[bracketCounter] == rightSquare)
		{
			if (bracketCounter - currentBracket > 1)
			{
				valid = checkIfBracketsAreCorrect(brackets, currentBracket + 1, currentBracket + 1);
				//std::cout << temp << std::endl;
			}
			brackets.erase(bracketCounter, 1);
			brackets.erase(currentBracket, 1);
			currentBracket = 0;
			bracketCounter = 0;
			continue;
		}

		if (brackets[currentBracket] == leftBraces && brackets[bracketCounter] == rightBraces)
		{
			if (bracketCounter - currentBracket > 1)
			{
				valid = checkIfBracketsAreCorrect(brackets, currentBracket + 1, currentBracket + 1);
				//std::cout << temp << std::endl;
			}
			brackets.erase(bracketCounter, 1);
			brackets.erase(currentBracket, 1);
			currentBracket = 0;
			bracketCounter = 0;
			continue;
		}

		if (brackets.empty() || brackets.size() % 2 != 0)
		{
			valid = false;
		}

		//	std::cout << brackets << std::endl;
	}
	if (brackets.empty())
	{
		return true;
	}
	return valid;

}



