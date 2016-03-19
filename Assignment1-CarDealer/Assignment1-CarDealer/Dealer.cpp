#include <iostream>
#include <math.h>
using namespace std;

int menu()
{
	int choice;
	bool valopt = false;
	
	cout << endl;
	cout << "Welcome to the Virtual Car dealer" << endl;
	cout << "Let me show you through our virtual showroom" << endl;
	cout << "Here are our options:" << endl;
	cout << "1. Nissan" << endl;
	cout << "2. Ford" << endl;
	cout << "3. BMW" << endl;


	while (!valopt)
	{
		cout << "Which car would you like? ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Splendid choice! You are quite intelligent (and good looking I may add)."
				<< endl;
			cout << "This will only set you back $15,000!" << endl;
			valopt = true;
			return 15000;
		case 2:
			cout << "Splendid choice! You are quite intelligent (and good looking I may add)."
				<< endl;
			cout << "Fords are super reliable and for $25,000 you won't regret it!" << endl;
			valopt = true;
			return 25000;
		case 3:
			cout << "Splendid choice! You are quite intelligent (and good looking I may add)."
				<< endl;
			cout << "Are you sitting down? Good. It will be $35,000 but it does come with cup warmers."
				<< endl;
			valopt = true;
			return 35000;
		default:
			cout << "Not a valid option" << endl;
		}
	}
	
	return choice;
}

float credscore()
{
	float score;

	cout << "Now we need to collect some information to see what your payments will be."
		<< endl;
	while (true)
	{
		cout << endl;
		cout << "Please enter your credit score: ";
		cin >> score;
		if (score > 0 && score <= 500)
		{
			return .05;
		}
		else if (score > 500 && score <= 700)
		{
			return .02;
		}
		else if (score > 700 && score <= 850)
		{
			return .01;
		}
		else
		{
			cout << "Invalid credit score... Try again bud.";
		}
	}
}


int main()
{
	int price = menu();
	float interest = credscore();
	int dwnpayment;
	char hasDwnpymnt;

	while (true)
	{
		cout << "Are you going to have a downpayment? [y/n]: ";
		cin >> hasDwnpymnt;
		if (hasDwnpymnt == 'y' || hasDwnpymnt == 'Y')
		{
			cout << "Please enter the ammount you will put down: ";
			cin >> dwnpayment;
			break;
		}
		else if (hasDwnpymnt == 'n' || hasDwnpymnt == 'N')
		{
			dwnpayment = 0;
			break;
		}
		else
		{
			cout << "Invalid input" << endl;
			continue;
		}
	}

	for (int i = 1; i < 5; i++)
	{
		float payment = ((price - dwnpayment)*pow((1 + interest), i)) / (12 * i);
		cout << "This is your monthly payment over " << i << " year(s): " << payment << endl;
	}
	return 0;
}