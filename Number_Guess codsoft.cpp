#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand((unsigned int) time(NULL));
    int random_number = rand() % 100 + 1;  // range 1 - 100
    int guess = 0;
    int count = 0;
    do{
        cout<<"Enter Number Guess in range (1 to 100) : ";
        cin>>guess;
        if(guess < random_number){
            cout<<"Your number is lower. Please try again!"<<endl;
            count++;
        }
        else if(guess > random_number){
            cout<<"Your number is greater. Please try again!"<<endl;
            count++;
        }
        else if(guess == random_number){
            cout<<"Congratulation...! You guess the right number. The number is "<<guess<< ". You Won!!!"<<endl;
            count++;
        }
    }while(guess != random_number);
    cout<<"You guess the right number in "<<count<<" attempts."<<endl;
    return 0;
}
