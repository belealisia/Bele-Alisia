#include <iostream>

#include <cstdlib>

#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int randomNumber=rand()%101,attempt=10,attemptUsed=0,guess;



    cout<<"Instruction!!!"<<endl;
    cout<<"Your calculator will generate a random number, and you will have to guess it."<<endl;
    cout<<"You have 10 tries, for each guess the game will tell you if the number is higher, lower or if you guessed it."<<endl;
    cout<<"Also if you don't enter the number, the game will show you on the screen ...You lost! The number was..."<<endl;
    cout<<"Very lucky! Start!"<<endl;



    while(attempt!=0&&guess!=randomNumber)
    {
        cout<<"Enter a number ";
        cin>>guess;
        attempt--;
        attemptUsed++;
        if(guess==randomNumber)
            {
                cout<<"Congratulations! The number is "<<guess<<"."<<endl;
                cout<<"You uesd "<<attemptUsed<<" attempt."<<endl;
            }
        else 
            if(guess>randomNumber)
                {
                    cout<<"Your number is smaller"<<endl;
                    cout<<"You have "<<attempt<<" more attempt"<<endl;
                }
            else
                {
                    cout<<"Your number is bigger"<<endl;
                    cout<<"You have "<<attempt<<" more attempt"<<endl;
                }
    }
    if(attempt==0)
            cout<<"You lost! The number was "<<randomNumber<<endl;
    return 0;
}