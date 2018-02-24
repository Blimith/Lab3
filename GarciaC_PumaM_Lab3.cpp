//Author: Carlos Garcia, Michael Puma
//CPSC 121 Lab 3
//2/12/2018
#include <iostream>
#include <string> 
#include <fstream> //Requied for outputting files
#include <stdlib.h> //Required for clearing screen if the user wishes to not quit the program
using namespace std;

void rectangleLength(int, int, bool); //Function for when you ask for the length of a rectangle.
void rectangleWord(string, int, bool); //Function for when you ask for the word for the rectangle.
void triangleLength(int, bool); //Function for when you ask for the length of a triangle.
void triangleLengthUpsideDown(int, bool); //Function for when you ask for the length of a upside down triangle.
void triangleWord(string, bool); //Function for when you ask for the word for the triangle.
void triangleWordUpsideDown(string, bool); // Function for when you ask for the word of the upsidedown triangle.

int main()
{
	int loop = 0;;
	while(loop = 0)
	{
	char loop; //Used to loop back to the start if the user does not wish to close the program.
	char choice; //Dummy char used for basic user input.
	char choice2; //Dummy char used for basic user input.
	string word; //Used when the user selects a word option.
	int height; //Used to recieve the height of a rectangle.
	int width; //Used when the user selects a width option.
	bool output = false; //Used to decide whether or not to output to a file.
	bool upside = false; //Used to decide whether or not the triangle is upside down.
	
	cout << "Hello! Would you like to print a rectangle or a triangle? (R/T)?\n";
	cin >> choice;
	cout << "Would you like to output to a file name myshape.txt (Y/N)? \n";
	cin >> choice2;
	if (choice2 == 'Y' || choice2 == 'y')
	{
		output = true;
	
	}
	else if (choice2 == 'N' || choice2 == 'n')
	{
		output = false;
	
	}
			
	if (choice == 'R' || choice == 'r')
	{
		cout << "Would you like to give a word or a width? (1/2)\n";
		cin >> choice;
		if (choice == '1')
		{
			cout << "Please input the word\n";
			cin >> word;
			cout << "Please input the height\n";
			cin >> height;
			rectangleWord(word, height, output);
		}
		else
		{
			cout << "Please input the width. \n";
			cin >> width;
			cout << "Please input the height. \n";
			cin >> height;
			rectangleLength(width, height, output);
		}
	}
	else if (choice == 'T' || choice == 't')
	{
		cout << "Would you like to give a word or a width (1/2)? \n";
		cin >> choice;
		cout << "Would you like the triangle to be upside down(Y/N) ? \n";
		cin >> choice2;
		if (choice2 == 'Y' || choice2 == 'y')
			upside = true;
		else if (choice2 == 'N' || choice2 == 'n')
			upside = false;
		if (choice == '1')
		{
			cout << "What would you like your word to be? \n";
			cin >> word;
			if (upside == true)
				triangleWordUpsideDown(word, output);
			else
				triangleWord(word, output);

		}
		if (choice == '2')
		{
			cout << "What would you like your width to be? \n";
			cin >> width;
			if (upside == true)
				triangleLengthUpsideDown(width, output);
			else
				triangleLength(width, output);
		}
	}
		cout << "Would you like to exit the program? (Y/N)\n";
		cin >> loop;
		if (loop == 'N' || loop == 'n')
		{
			system("CLS");
			loop = 1; //Calls back to main function in order to restart the program, if the user desires. 
		}
	}
}
			return 0;
}

void rectangleLength(int w, int l, bool output) //Creates a length rectangle
{
	string box;
	for (int i = 0; i < w; i++)
	{
		box += "x";
	}
	if (output)
	{
		ofstream outfile;
		outfile.open("myshape.txt");
		for (int i = 0; i < l; i++)
		{
			outfile << box << endl;
		}
		outfile.close();
	}
	else
	{
		for (int i = 0; i < l; i++)
		{
			cout << box << endl;
		}
	}
}

	void rectangleWord(string word, int width, bool output) //Creates a word rectangle
	{
		if (output)
		{
			ofstream outfile;
			outfile.open("myshape.txt");
			for (int i = 0; i < width; i++)
			{
				outfile << word << endl;
			}
			outfile.close();
		}
		else
		{
			for (int i = 0; i < width; i++)
			{
				cout << word << endl;
				
			}
		}
	}

	void triangleLength(int length, bool output) //Creates a rightside up length triangle
	{
		string triangle;
		if(output)
		{
			ofstream outfile;
			outfile.open("myshape.txt");
			for (int i = 0; i < length; i++)
			{
				triangle += "x";
				outfile << triangle << endl;
			}
			outfile.close();
		}
		else
		{
			for (int i = 0; i < length; i++)
			{
				triangle += "x";
				cout << triangle << endl;
			}
		}
	}

	void triangleLengthUpsideDown(int length, bool output) //Creates a upside down width triangle
	{
		string triangle;
		for (int i = 0; i < length; i++)
		{
			triangle += "x";
		}
		if (output)
		{
			ofstream outfile;
			outfile.open("myshape.txt");
			for (int i = 0; i < length; i++)
			{
				outfile << triangle.substr(0, triangle.length() - i) << endl;
			}
			outfile.close();
		}
		else
		{
			for (int i = 0; i < length; i++)
			{
				cout << triangle.substr(0, triangle.length() - i) << endl;
			}
		}
	}

	void triangleWord(string word, bool output) // Creates a rightside up word triangle
	{
		if (output)
		{
			ofstream outfile;
			outfile.open("myshape.txt");
			for (int i = 0; i < word.length(); i++)
			{
				outfile << word.substr(0, i + 1) << endl;
			}
			outfile.close();
		}
		else
		{
			for (int i = 0; i < word.length(); i++)
			{
				cout << word.substr(0, i + 1) << endl;
			}
		}
	}
	void triangleWordUpsideDown(string word, bool output) //Creates a upsidedown word triangle
	{
		if (output)
		{
			ofstream outfile;
			outfile.open("myshape.txt");
			for (int i = 0; i < word.length(); i++)
			{
				outfile << word.substr(0, word.length() - i) << endl;
			}
			outfile.close();
		}
		else
		{
			for (int i = 0; i < word.length(); i++)
			{
				cout << word.substr(0, word.length() - i) << endl;
			}
		}
	



