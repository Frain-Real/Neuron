#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int weights[15]; //Weights

int set[10][15] = { { 1,1,1,1,0,1,1,0,1,1,0,1,1,1,1 }, //Learn Data
	{ 0,0,1,0,0,1,0,0,1,0,0,1,0,0,1 },
	{ 1,1,1,0,0,1,1,1,1,1,0,0,1,1,1 },
	{ 1,1,1,0,0,1,1,1,1,0,0,1,1,1,1 },
	{ 1,0,1,1,0,1,1,1,1,0,0,1,0,0,1 },
	{ 1,1,1,1,0,0,1,1,1,0,0,1,1,1,1 },
	{ 1,1,1,1,0,0,1,1,1,1,0,1,1,1,1 },
	{ 1,1,1,0,0,1,0,0,1,0,1,0,0,1,0 },
	{ 1,1,1,1,0,1,1,1,1,1,0,1,1,1,1 },
	{ 1,1,1,1,0,1,1,1,1,0,0,1,1,1,1 } };

int test_is_five1[] = { 1,1,1,1,0,0,1,0,1,0,0,1,1,1,1 }; //Test Data
int test_is_five2[] = { 1,1,1,0,0,0,1,1,1,0,0,1,1,1,1 };

int bias = 4; //Bias

/*Activate function*/
float sigmoid(int x) {
	return 1 / (1 + exp(-x));
}

/*Neuron function*/
bool is_five(int *arr) {
	int res=0;
	for (int i = 0; i < 15; i++) {
		res += arr[i] * weights[i];
	}
	if (sigmoid(res + bias) > 0.5)
		return true;
	return false;
}

/*Increase weights*/
void increase(int *arr) {
	for (int i = 0; i < 15; i++)
		if (arr[i])
			weights[i]++;
}

/*Decrease weights*/
void decrease(int *arr) {
	for (int i = 0; i < 15; i++)
		if (arr[i])
			weights[i]--;
}

int main()
{
	srand(time(0));
	for (int i = 0; i < 15; i++) {
		weights[i] = rand() % 10; //do weight random
	}
	/*Learning*/
	for (int i = 0; i < 1000; i++) {
		int number = rand() % 10;
		if (is_five(set[number])) {
			if(number != 5)
				decrease(set[number]);
		}
		else {
			if (number == 5)
				increase(set[number]);
		}
	}
	/*Test*/
	cout << "0 is 5? " << is_five(set[0]) << endl;
	cout << "1 is 5? " << is_five(set[1]) << endl;
	cout << "2 is 5? " << is_five(set[2]) << endl;
	cout << "3 is 5? " << is_five(set[3]) << endl;
	cout << "4 is 5? " << is_five(set[4]) << endl;
	cout << "5 is 5? " << is_five(set[5]) << endl;
	cout << "6 is 5? " << is_five(set[6]) << endl;
	cout << "7 is 5? " << is_five(set[7]) << endl;
	cout << "8 is 5? " << is_five(set[8]) << endl;
	cout << "9 is 5? " << is_five(set[9]) << endl;
	cout << "Test1 is 5? " << is_five(test_is_five1) << endl;
	cout << "Test1 is 5? " << is_five(test_is_five1) << endl;
	cout << "Weights: ";
	for (int i = 0; i < 15; i++)
		cout << weights[i] << " ";
	cout << endl;
}
