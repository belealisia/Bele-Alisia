#include <iostream>

#include <cstdlib>

#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int randomNumber=rand()%101,attempt=10,attemptUsed=0,guess;
    
    while(attempt!=0)
    {
        cin>>guess;
        attempt--;
        attemptUsed++;
        if(guess==randomNumber)
            {
                cout<<"Congratulations! The number is "<<guess<<endl;
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