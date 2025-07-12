#include<iostream>
#include<windows.h>
#include<ctime>
#include<cstdlib>
using namespace std;

void shots_count(int abc[])
{
    int loaded=0, emptyy=0;
    for(int i=0;i<10;i++)
    {
        if(abc[i]==1)
        {
            loaded++;
        }
        else
        {
            emptyy++;
        }
    }
    cout<<"There are "<<loaded<<" loaded rounds and "<<emptyy<<" empty rounds in the gun"<<endl;
}

int main()
{
    srand(time(0));
    int flag=0,dealer_choice;
    char decision;
    int dealer_hp=2,our_hp=2;
    int shots[10];
    for(int i=0;i<10;i++)
    {
        shots[i]=rand()%2;
    }
    cout<<"This is a famous mafia game..."<<endl;
    Sleep(3000);
    cout<<"You're playing against a dealer who arranged this..."<<endl;
    Sleep(3000);
    cout<<"Whoever holds the gun can shoot either themself or the person in front"<<endl;
    Sleep(4000);
    cout<<"If someone shoots themself and the round is empty, they will get a second chance to shoot"<<endl;
    Sleep(5000);
    cout<<"but if loaded, the next turn will be in opponents hands"<<endl;
    Sleep(4000);
    cout<<"Both have 2 hp"<<endl;
    Sleep(1000);
    shots_count(shots);
    Sleep(2000);
    cout<<"The dealer is putting the rounds in an random sequence..."<<endl;
    Sleep(7000);
    for(int i=0;i<10;i++)
    {
        if(dealer_hp==0)
        {
            Sleep(3000);
            cout<<"The dealer is dead"<<endl;
            cout<<"You won!";
            break;
        }
        else if(our_hp==0)
        {
            Sleep(3000);
            cout<<"You are dead"<<endl;
            cout<<"You lost";
            break;
        }
        if(flag==0)
        {
            cout<<"You have the gun, chose whom to shoot(yourself/dealer): ";
            cin>>decision;
            if(decision=='d'||decision=='D')
            {
                cout<<"You chose to shoot the dealer..."<<endl;
                Sleep(3000);
                if(shots[i]==1)
                {
                    cout<<"The round was loaded"<<endl;
                    dealer_hp--;
                    Sleep(3000);
                    cout<<"Your hp: "<<our_hp<<endl;
                    cout<<"Dealer's hp: "<<dealer_hp<<endl;
                    flag=1;
                }
                else
                {
                    cout<<"The round was empty"<<endl;
                    Sleep(3000);
                    cout<<"Your hp: "<<our_hp<<endl;
                    cout<<"Dealer's hp: "<<dealer_hp<<endl;
                    flag=1;
                }
            }
            else if(decision=='y'||decision=='Y')
            {
                cout<<"You chose to shoot yourself..."<<endl;
                Sleep(3000);
                if(shots[i]==1)
                {
                    cout<<"The round was loaded"<<endl;
                    our_hp--;
                    Sleep(3000);
                    cout<<"Your hp: "<<our_hp<<endl;
                    cout<<"Dealer's hp: "<<dealer_hp<<endl;
                    flag=1;
                }
                else
                {
                    cout<<"The round was empty"<<endl;
                    Sleep(3000);
                    cout<<"Your hp: "<<our_hp<<endl;
                    cout<<"Dealer's hp: "<<dealer_hp<<endl;
                    flag=0;
                }
            }
        }
        else if(flag==1)
        {
            cout<<"Now, the dealer is choosing his shot..."<<endl;
            dealer_choice=rand()%2;
            Sleep(5000);
            if(dealer_choice==1)
            {
                cout<<"The dealer chose to shoot you..."<<endl;
                Sleep(3000);
                if(shots[i]==1)
                {
                    cout<<"The round was loaded"<<endl;
                    our_hp--;
                    Sleep(3000);
                    cout<<"Your hp: "<<our_hp<<endl;
                    cout<<"Dealer's hp: "<<dealer_hp<<endl;
                    flag=0;
                }
                else
                {
                    cout<<"The round was empty"<<endl;
                    Sleep(3000);
                    cout<<"Your hp: "<<our_hp<<endl;
                    cout<<"Dealer's hp: "<<dealer_hp<<endl;
                    flag=0;
                }
            }
            else
            {
                cout<<"The dealer chose to shoot himself..."<<endl;
                if(shots[i]==1)
                {
                    cout<<"The round was loaded"<<endl;
                    dealer_hp--;
                    Sleep(3000);
                    cout<<"Your hp: "<<our_hp<<endl;
                    cout<<"Dealer's hp: "<<dealer_hp<<endl;
                    flag=0;
                }
                else
                {
                    cout<<"The round was empty"<<endl;
                    Sleep(3000);
                    cout<<"Your hp: "<<our_hp<<endl;
                    cout<<"Dealer's hp: "<<dealer_hp<<endl;
                    flag=1;
                }
            }
        }
    }
}


