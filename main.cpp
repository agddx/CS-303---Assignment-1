#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int check(int array[], int size, int value) //function to check if a certain integer exists
{
	for(int i = 0; i < size; i++)
	{
		if(array[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void modify(int array[], int index, int newvalue, int size) //function that modifys the value of an integer
{
	if (index < size)
	{
		throw out_of_range("Index is not in the array.");
	}
	cout << "Old value is: " << array[index];
	array[index] = newvalue;
	cout << "New value is: " << newvalue;
}

void newinteger(int array[], int size, int value) //function that adds a new integer to the end of the array
{
	size = size+1;
	array[size] = value;
}

void removeinteger(int array[], int index) //function that replaces the integer with 0
{
	array[index] = 0;
}


int main()
{
	int size = 100; //declaration of variables
	int array[size];
	int value = 0;
	string filename;
	
	cout << "Enter file name: "; //input of file
	cin >> filename;
	
	ifstream file;
	file.open(filename.c_str());

	if (file.is_open())
	{
		for (int i = 0; i < size; i++) //conversion of file to array
        	{
            		file >> array[i];
        	}
        	file.close();


		int function = 0;
		while (function != 5) //loop that keeps the program running for the user
		{
			cout << "Enter which function you would like to perform:" << endl;
			cout << "(1) Check if a certain integer exists and return the index where it is present." << endl;
			cout << "(2) Modify the value of an integer with the index." << endl;
			cout << "(3) Add a new integer to the end of the array." << endl;
			cout << "(4) Remove an integer from the array with an index." << endl;
			cout << "(5) End the program." << endl;
			cin >> function;
			
			if (function == 1) //excecution of all the functions when needed
			{
				int integertocheck = 0;
				cout << "Enter the integer you want to check";
				cin >> integertocheck;
				if(check(array, size, integertocheck) != -1)
				{
					cout << "Yes, the index for that integer is: " << check(array, size, integertocheck) << endl;
				}
				else
				{
					cout << "No, that integer does not exist in the array." << endl;
				{
			}

			if (function == 2)
			{
				int indextomodify = 0;
				cout << "Enter the index of the integer you wish to modify: ";
				cin >> indextomodify;

				int newinteger = 0;
				cout << "Enter the value of the new integer: ";
				cin >> newinteger;

				try //try and catch block for exception handling
				{
					modify(array, indextomodify, newinteger, size);
				}
				catch (const exception& e)
				{
					cout << "Error! " << e.what() << endl;
				}

			}

			if (function == 3)
			{
				int newestvalue = 0;
				cout << "Enter the new integer: ";
				cin >> newestvalue;
				newinteger(array, size, newestvalue);
			}

			if (function == 4)
			{
				int indextoremove = 0;
				cout << "What is the index of the value you want to remove: ";
				cin >> indextoremove;
				removeinteger(array, indextoremove);
			}
		}
    	}
    	else
	{
        	cout << "Can't find the input file.";
    	}
	return 0;
}
}
}
