#include <iostream>
#include <stdlib.h>
#include <string>
#include <set>
using namespace std;

void makeGuess(int& g, int& r, int& w, set<char> mset, set <char>& a, string s, char c[]);
void fillSet(set<char>& mset, string line);
void setArray(char a[], string s);
void printTry(char a[], int size);

int main()
{
	string phrase;//Get phrase from user
	set <char> letters;//unique letters in phrase
	set <char> alrdy;//letters already guessed
	int guesses = 0;//total guesses
	int right = 0;//total right guesses
	int wrong = 0;//total wrong guesses
	cout << "Enter a phrase to guess." << endl;
	getline(cin, phrase);

	system("CLS");

	//make array to show guesses
	char* ar2 = new char[phrase.size()];//shows letters

	//fill char array with contents, and second with underscores __
	setArray(ar2, phrase);

	fillSet(letters, phrase);
	printTry(ar2, phrase.size());

	//make guess
	//loop make guess
	while (right != letters.size())
	{
		makeGuess(guesses, right, wrong, letters, alrdy, phrase, ar2);
	}
	cout << "Congrats! It took you " << guesses << " guesses.\nYou guessed right " << right << " times." << "\nYou guessed wrong " << wrong << " times." << endl;

	return 0;
}
//make a guess
void makeGuess(int& g, int& r, int& w, set<char> mset, set <char>& a, string s, char c[])
{
	char guess = ' ';
	cout << "Enter a letter to guess: ";
	cin >> guess;
	if (a.find(guess) != a.end())//already guessed this letter
	{
		cout << "OOPS You already guessed this letter" << endl;
		return;
	}
	if (mset.find(guess) == mset.end())//it isnt in the phrase
	{
		g++;
		w++;
		a.insert(guess);
		cout << "Try again!" << endl;
		printTry(c, s.size());
	}
	else
	{
		g++;
		r++;
		a.insert(guess);
		cout << "You guessed right!" << endl;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == guess)
				c[i] = guess;
		}
		cout << endl;
		printTry(c, s.size());
	}
}
//keeps track of all the unique letters in phrase
void fillSet(set<char>& mset, string line)
{
	for (int i = 0; i < line.size(); i++)
	{
		char let = line[i];
		if (mset.find(let) == mset.end() && let != ' ')
			mset.insert(let);
	}
}
void setArray(char a[], string s)
{
	//fill char array with contents, and second with underscores __
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (c == ' ')
			a[i] = ' ';
		else
			a[i] = '_';
	}
}
void printTry(char a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i];
	}
	cout << endl;
}