/*********************************
 *     A NUMBER GUESSING GAME    *
 *********************************/

#include<iostream>
#include<cstdlib>  // srand() function 
#include<ctime>    // time() function

using namespace std;

int random_number_generator()
{
	int secret_num;
	secret_num = rand()%100+0;  //selects random number 
	return secret_num;
}

bool check_match(int secret_num, int guess)
{
	if(secret_num == guess)
		return true;
	return false;
}

void check_range(int secret_num, int guess)
{
		if(guess > secret_num)
			cout << "too high" << endl;
		else if(guess < secret_num) 
			cout << "too low" << endl;
}

int main(void)
{
	int secret_num, guess;

	srand(time(NULL));  //seeds the random number generator
	
	secret_num = random_number_generator();    //make call to the random_number_generator() function

	do
	{
		cout << "Enter your guess: ";
		cin >> guess;
		
		if(check_match(secret_num, guess))
			cout << "Congratulations you guessed correctly" << endl;
		else
		{
			check_range(secret_num, guess);
			cout << "\n" << "Sorry please try again" << endl; 
		}
			
	}
	while(guess != secret_num);

	return 0;
}
