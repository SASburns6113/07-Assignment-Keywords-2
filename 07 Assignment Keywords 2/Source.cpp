// Code Breaker 
// Assignment 7

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
	// Ask the recruit to login using their name
	string name;
	cout << "Please enter your name\n" << name;
	cin >> name;
	// Display an overview of what Keywords II is to the recruit 
	// Display an directions to the recruit on how to use Keywords
	cout << "Welcome Agent " << name << ", Good Luck With Your Mission!\n\n";
	cout << "Your mission Agent " << name << " is to use our code system the break in to\n";
	cout << "the terrorist's network so that we can find out their plans.\n";
	cout << "Agent " << name << ", you will have 8 tries to get the code, Good Luck!";


	
	
	//setup
	const int MAX_WRONG = 8; //maximum number of incorrect guesses allowed

	// Create a collection of 10 words you had wrote down manually
	vector<string> words;  //collection of possible words to guess
	words.push_back("GUN");
	words.push_back("PLANE");
	words.push_back("DROPOFF");
	words.push_back("BOMB");
	words.push_back("DOCUMENT");
	words.push_back("BATTLE");
	words.push_back("TIME");
	words.push_back("CITIES");
	words.push_back("STEAL");
	words.push_back("FLASHDRIVE");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());

	const string THE_WORD = words[0];		//word to guess
	int wrong = 0;							//number of incorrect guesses
	string soFar(THE_WORD.size(), '-');	//word guessed so far
	string used = "";						//letters already guessed

	

	//main loop
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		cout << "\n\nAgent " << name << ", You have " << (MAX_WRONG - wrong);
		cout << " attempts left to break the code.\n";
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout << "\nDecoded so far, the code is:\n" << soFar << endl;

		//these four lines set up the the users input into a guess
		char guess;
		cout << "\n\nEnter your guess: ";
		cin >> guess;
		guess = toupper(guess); //make uppercase since secret word in uppercase
		
		//this while loop set up the code to tell the user if they already guessed,
		//got the right letter, or got it wrong
		while (used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}

		used += guess;

		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "That's right! " << guess << " is in the code.\n";
			//update soFar to include newly guessed letter
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << "Incorrect, " << guess << " isn't in the code.\n";
			++wrong;
		}
	}

	//shut down
	if (wrong == MAX_WRONG)
	{
		cout << "\nNetwork is now shutdown, Mission failed, we'll get them next time!";
	}
	else
	{
		cout << "\nYou guessed it!";
	}

	cout << "\nThe word was " << THE_WORD << endl;

	system("pause");

	return 0;

}