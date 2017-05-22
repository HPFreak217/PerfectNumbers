//
//  main.cpp
//  Perfect Numbers
//
//  Created by Carlos Hurtado on 5/21/17.
//  Copyright © 2017 Carlos Hurtado. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
void firstFour();
void perfectNumber(int num);
int main(int argc, const char * argv[])
{
    bool running = true;
    while (running)
    {
        int choice = 0;
        cout<<"1) Display first four perfect numbers"<<endl;
        cout<<"2) Perfect number checker"<<endl;
        cout<<"3) Quit"<<endl;
        cin>>choice;
        if(choice == 1)
        {
            firstFour();
        }
        else if(choice == 2)
        {
            bool valid = false;
            while(!valid)
            {
                int num = 0;
                cout<<"Enter a positive integer or 1 to exit: ";
                cin>>num;
                if(num>1)
                {
                    perfectNumber(num);
                    valid = true;
                }
                else if(num <1)
                {
                    cout<<"-Invalid Number-"<<endl;
                }
                else
                {
                    valid = true;
                }
            }
        }
        else if(choice == 3)
        {
            cout<<"Exitting...done"<<endl;
            running = false;
        }
    }
    return 0;
}

void firstFour()
{
    vector<int> perfect;
    vector<int> divisors;
    bool notPerfect = true;
    int test = 2;
    for(int i = 0; i < 4; i++)
    {
        int divisible = 1;
        while(notPerfect)
        {
            if(divisible < test)
            {
                if(test%divisible == 0)
                {
                    divisors.push_back(divisible);
                }
                divisible++;
            }
            else
            {
                int sum = 0;
                for(int n: divisors)
                {
                    sum+=n;
                }
                if(sum == test)
                {
                    perfect.push_back(test);
                    divisors.clear();
                    notPerfect = false;
                }
                else
                {
                    test++;
                    divisible = 1;
                    divisors.clear();
                }
            }
            
        }
        test++;
        notPerfect =  true;
    }
    for(int i: perfect)
    {
        cout<<i<<endl;
    }
}

void perfectNumber(int num)
{
    if(num == 6 || num == 28 || num == 496 || num == 8128 || num == 33550336)
    {
        cout<<num<<" is a perfect number"<<endl;
    }
    else
    {
        cout<<num<<" is not a perfect number"<<endl;
    }
}
