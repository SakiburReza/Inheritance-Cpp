#include<iostream>
using namespace std;


class Unit{
    int health;
    int damage;
    int cost;
    int range;
    int position;
public:

    static int round,coin_remaining;

    Unit(){health=300;damage=40;cost=0;range=200;position=200;}
    Unit(int a,int b,int c,int d,int e){health=a;damage=b;cost=c;range=d;position=e;}
    string shoot_type;
    bool died= false;

    virtual int showGameState(int m,int s,int t){};
};
int Unit::coin_remaining=1600;
int Unit::round=1;
class Bowman: public Unit{
    int Return_coin;
public:
    Bowman(int a=40):Unit(60,10,100,110,100){Return_coin=a;shoot_type="Basic Arrow";}
    int showGameState(int m,int s,int t);

};

class AdvancedBowman: public Unit{
    int Return_coin;
public:
    AdvancedBowman(int a=60):Unit(85,15,200,130,80){Return_coin=a;shoot_type="Canon";}
    int showGameState(int m,int s,int t);

};

class Archer:public Unit{
    int Step_size;
    char movement[20];
public:
    Archer(int a=25):Unit(100,25,150,50,125){Step_size=a;shoot_type="Advanced Arrow";}
    int showGameState(int m,int s,int t);

};
class AdvancedArcher:public Unit{
    int Step_size;
    char movement[20];
public:
    AdvancedArcher(int a=30):Unit(120,25,600,50,110){Step_size=a; shoot_type="Improved Arrow";}
    int showGameState(int m,int s,int t);

};



int Bowman::showGameState(int m,int s,int t)  ///m=enemytower's health s=enemy tower's position, t=enemy tower's range
{

    while(!died){
        if(m<=0) {return m;}
        if(health<=0)
        {
            cout<<"Round : "<<round<<endl;
            cout<<"Bowman's health "<<health<<" Units died!"<<endl;
            cout<<"Bowman gave 40 coins while dying"<<endl;
            return m;
        }
        else
        {
            cout<<"Round : "<<round<<endl;
            if(s-position<=range){m-=10;
            cout<<"Bowman's Health :"<<health<<". StationaryPositioned at 0. Bowman is shooting Basic arrow."<<endl;}
            else cout<<"Enemy Tower is out of Bowman's range"<<endl;
            if(s-position<=t){
            cout<<"EnemyTower's Health: "<<m<<". Enemy Tower is shooting five arrow."<<endl; health-=40;}
            else cout<<"Bowman is out of Enemy Tower's range"<<endl;
            round++;
        }
    }
}


int AdvancedBowman::showGameState(int m,int s,int t)
{

    while(!died){
        if(m<=0) { return m;}
        if(health<=0)
        {
            cout<<"Round : "<<round<<endl;
            cout<<"AdvancedBowman's health "<<health<<" Units died!"<<endl;
            cout<<"Advanced Bowman gave 60 coins while dying"<<endl;
            return m;
        }
        else
        {

            cout<<"Round : "<<round<<endl;
            if(s-position<=range){ m-=15;
            cout<<"Advanced Bowman's Health :"<<health<<". StationaryPositioned at 0. Bowman is shooting Canon."<<endl;}
            else cout<<"Enemy Tower is out of Advanced Bowman's range"<<endl;
            if(s-position<=t){
            cout<<"EnemyTower's Health: "<<m<<". Enemy Tower is shooting five arrow."<<endl;health-=40;}
            else cout<<"Advanced Bowman is out of Enemy Tower's range"<<endl;
            round++;
        }
    }
}


int Archer::showGameState(int m,int s,int t)
{
     int first=1;
    while(!died){
        if(m<=0) {cout<<"EnemyTower's Health: "<<m<<endl; return m;}
         if(s-position<=range) {first=0;}
        if(first){
            cout<<"Round : "<<round<<endl;
            cout<<"Archer's Health :"<<health<<". Running. Positioned at "<<position<<endl;
            if(s-position<=t){
            cout<<"EnemyTower's Health: "<<m<<". Enemy Tower is shooting five arrow."<<endl;health-=40;}
            else cout<<"Archer is out of Enemy Tower's range"<<endl;
            round++;position+=Step_size;
        }
        else if(health<=0)
        {
            cout<<"Round : "<<round<<endl;
            cout<<"Archer's health "<<health<<" Units died!"<<endl;
            return m;
        }
        else{
            cout<<"Round : "<<round<<endl;
            cout<<"Archer's Health :"<<health<<". Running. Positioned at "<<position<<". Archer is shooting Advanced arrow"<<endl;
            if(health>0) m-=25;
            if(s-position<=t){
            cout<<"EnemyTower's Health: "<<m<<". Enemy Tower is shooting five arrow."<<endl;health-=40;}
            else cout<<"Archer is out of Enemy Tower's range"<<endl;
            round++;position+=Step_size;
        }
    }
}



int AdvancedArcher::showGameState(int m,int s,int t)
{
     int first=1;
    while(!died){
        if(m<=0) {cout<<"EnemyTower's Health: "<<m<<endl; return m;}
        if(s-position<=range) {first=0;}
        if(first){
            cout<<"Round : "<<round<<endl;
            cout<<"Advanced Archer's Health :"<<health<<". Riding horse. Positioned at "<<position<<endl;
            if(s-position<=t){
            cout<<"EnemyTower's Health: "<<m<<". Enemy Tower is shooting five arrow."<<endl;health-=40;}
           else cout<<"Advanced Archer is out of Enemy Tower's range"<<endl;
           round++;position+=Step_size;
        }
         else if(health<=0)
        {
            cout<<"Round : "<<round<<endl;
            cout<<"Advanced Archer's health "<<health<<" Units died!"<<endl;
            return m;
        }
        else{
            cout<<"Round :"<<round<<endl;
            cout<<"Advanced Archer's Health :"<<health<<". Running. Positioned at "<<position<<". Advanced Archer is shooting Advanced Improved arrow"<<endl;
            if(health>0)m-=50;
            if(s-position<=t){
            cout<<"EnemyTower's Health: "<<m<<". Enemy Tower is shooting five arrow."<<endl;health-=40;}
            else cout<<"Archer is out of Enemy Tower's range"<<endl;
            round++;position+=Step_size;
        }
    }
}

int main()
{
    Unit *w,*a;
    int choice;
    a=new Unit;
    int n=a->health,s,t,over=0;
    s=a->position;
    t=a->range;
    while(1)
    {
            cout<<"Coin Remaining:"<<w->coin_remaining<<endl;

            cout<<"Choose your option:"<<endl;
            cout<<"1. Archer (Cost 150)"<<endl;
            cout<<"2. Advanced Archer (Cost 600)"<<endl;
            cout<<"3. Bowman (Cost 100)"<<endl;
            cout<<"4. Advanced Bowman (Cost 200)"<<endl;

            cin>>choice;
        switch(choice)
        {
            case 1: w =  new Archer;
                   if(w->coin_remaining<150) {cout<<"Insufficient coin to buy"<<endl;break;}
                   n= w->showGameState(n,s,t);w->coin_remaining-=w->cost;
                    break;
            case 2: w = new AdvancedArcher;
                    if(w->coin_remaining<600) {cout<<"Insufficient coin to buy"<<endl;break;}
                   n= w->showGameState(n,s,t);w->coin_remaining-=w->cost;
                    break;
            case 3: w =  new Bowman;
                    if(w->coin_remaining<100) {cout<<"Insufficient coin to buy"<<endl;break;}
                   n= w->showGameState(n,s,t);w->coin_remaining-=w->cost-40;
                    break;
            default : w = new AdvancedBowman;
                    if(w->coin_remaining<200) {cout<<"Insufficient coin to buy"<<endl;break;}
                    n=w->showGameState(n,s,t);w->coin_remaining-=w->cost-60;
                    break;
        }
        if(w->coin_remaining<100) over=1;
        if(over) {cout<<"Machine won the game.";break;}
        if(n<=0) {cout<<"You won the game.";break;}


    }


        ///You have to complete all the functionalities of the user using the base class pointer w.
        ///That means you have to call the derived class functions using only this.
    }
