#include<iostream>
#include<cmath>

using namespace std;

bool CheckBinaryOrNot(string BinaryNumber)
{
	short PointCounter = 0;
	for (int i = 0; i < BinaryNumber.length(); i++)
	{
		if (BinaryNumber[i] == '.')
		{
			PointCounter++;
		}

		if (BinaryNumber[i] != '1' && BinaryNumber[i] != '0' && BinaryNumber[i] != '.')
		{
			return 0;
		}
	}

	if (PointCounter == 1 || PointCounter == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

string GetFloatingBinaryPart(string BinaryNumber)
{
	string FloatingBinaryPart = "";
	bool PointIsFound = false;

	for (int i = 0; i < BinaryNumber.length(); i++)
	{
		if (PointIsFound == true)
		{
			FloatingBinaryPart += BinaryNumber[i];
		}

		if (BinaryNumber[i] == '.')
		{
			PointIsFound = true;
		}
	}

	return FloatingBinaryPart;
}

string GetIntegerBinaryPart(string BinaryNumber)
{
	string IntegerBinaryPart = "";
	for (int i = 0; i < BinaryNumber.length(); i++)
	{
		if (BinaryNumber[i] == '.')
		{
			return IntegerBinaryPart;
		}
		else
		{
			IntegerBinaryPart += BinaryNumber[i];
		}
	}

	return IntegerBinaryPart;
}

string ReadBinaryNumber()
{
	string BinaryNumber;
	do
	{
		cout << "ENTER BINARY NUMBER\n";
		cin >> BinaryNumber;

	} while (!CheckBinaryOrNot(BinaryNumber));

		return BinaryNumber;
}

double BinaryToDecimal(string BinaryNumber)
{
	double DecimalNumber = 0;
	string IntegerBinaryPart = GetIntegerBinaryPart(BinaryNumber);
	string FloatingBinaryPart = GetFloatingBinaryPart(BinaryNumber);

	for (int i = 0; i < IntegerBinaryPart.length(); i++)
	{
		DecimalNumber += (IntegerBinaryPart[i] - '0') * pow(2, IntegerBinaryPart.length()-1-i);
	}

	for (int i = 0; i < FloatingBinaryPart.length(); i++)
	{
		DecimalNumber += (FloatingBinaryPart[i] - '0') * pow(2, -i - 1);
	}

	return DecimalNumber;
}

bool DoYouWantToContinue()
{
	string Choice;
	do
	{
		cout << "DO YOU WANT TO CONTINUE[Y/N]\n";
		cin >> Choice;
	} while (Choice != "Y" && Choice != "y" && Choice != "N" && Choice != "n");

	if (Choice == "Y" || Choice == "y")
	{
		system("cls");
		return 1;
	}

	else
	{
		cout << "GOOD BYE :)\n";
		return 0;
	}
}

void PrintBinaryToDecimal(string BinaryNumber)
{
	cout << "DECIMAL NUMBER = " << BinaryToDecimal(BinaryNumber) << "\n";
}

void BinaryToDecimalConverter()
{
	cout << "WELCOME TO BINARY TO DECIMAL CONVERTER\n";
	do
	{

		cout << "-----------------------------------------\n";
		string BinaryNumber = ReadBinaryNumber();
		PrintBinaryToDecimal(BinaryNumber);
		cout << "-----------------------------------------\n";

	} while (DoYouWantToContinue());

}

int main()
{
	
	BinaryToDecimalConverter();

	return 0;
}