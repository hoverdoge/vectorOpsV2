#include <vector>
#include <iostream>

using namespace std;

vector<int> vec;
char takeInput();
void decideOperation();
void outEnd();
void invalidInput();
bool checkNum(int input);
bool checkEmpty();
void p();
void a();
void m();
void s();
void l();
void q();

int main()
{
	decideOperation();
}

char takeInput()
{
	cout << "P - Print numbers\n" << "A - Add numbers\n" << "M - Find mean\n" << "S - Find smallest element\n" << "L - Find largest element\n" << "Q - Quit program\n";
	char input = ' ';
	cin >> input;
	outEnd();
	return tolower(input);
}

void decideOperation()
{
	switch (takeInput()) 
	{
		case 'p':
			p();
			break;
		case 'a':
			a();
			break;
		case 'm':
			m();
			break;
		case 's':
			s();
			break;
		case 'l':
			l();
			break;
		case 'q':
			q();
			break;
		default:
			invalidInput(); 
			break;
	}
}

void p()
{
	if (vec.size() == 0)
	{
		cout << "Vector is empty." << endl;
	}
	else
	{
		for (unsigned int i = 0; i < vec.size(); i++)
		{
			if (i == vec.size() - 1)
			{
				cout << vec.at(i) << endl;
			}
			else
			{
				cout << vec.at(i) << ", ";
			}
		}

	}
	decideOperation();
}

void a()
{
	int num;
	cout << "What number would you like to push? \n";
	cin >> num;
	outEnd();
	if (checkNum(num) == false)
	{
		vec.push_back(num);

	}
	decideOperation();
}

void m()
{
	if (checkEmpty() == false)
	{
		int sum = 0;
		for (unsigned int i = 0; i < vec.size(); i++)
		{
			sum += vec[i];
		}
		cout << sum / vec.size() << endl;
	}
	decideOperation();
}

void s()
{
	if (checkEmpty() == false)
	{
		int number = vec[1];
		for (unsigned int i = 0; i < vec.size(); i++)
		{
			if (vec[i] <= number)
			{
				number = vec[i];
			}
			
		}
		cout << number << endl;

	}
	decideOperation();
}
void l()
{
	if (checkEmpty() == false)
	{
		int number = 0;
		for (unsigned int i = 0; i < vec.size(); i++)
		{
			if (vec[i] >= number)
			{
				number = vec[i];
			}

		}
		cout << number << endl;

	}
	decideOperation();
}

void q()
{
	exit(0);
}

void invalidInput()
{
	cout << "Invalid input. Try Again.";
	decideOperation();
}

void outEnd()
{
	cout << endl;
}

bool checkNum(int input)
{
	if (input * 0 != 0)
	{
		return true;
		invalidInput();
	}
	else
	{
		return false;
	}
}

bool checkEmpty()
{
	if (vec.size() <= 0)
	{
		cout << "Vector is Empty" << endl;
		decideOperation();
		return true;
	}
	else
	{
		return false;
	}
}
