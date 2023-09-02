#include<iostream>
#include<string>
#include<vector>
#include"square.h"
#include"gameboard.h"
#include"unownable.h"
#include"random.h"
using namespace std;

string Unownable::getType() {return "";}

Player* Unownable::getOwner() {return nullptr;}
void Unownable::setOwner(Player *p) {return;}
void Unownable::setimprovement_level(int improvement) {return;}
int Unownable::getimprovement_cost() {return 0;}
    int Unownable::getpurchase_cost() {return 0;}
    string Unownable::getmonopoly_block() {return "";}
    bool Unownable::improve() {return true;}
    int Unownable::getValue() {return 0;}
    int Unownable::getimprovement_level() {return 0;}


void CoopFee::notify(GameBoard& g, Player& p){
    if (p.eligibleBankruptcy(150)) {
	if (p.declareBankruptcy(150, nullptr)) {
	    return;
	}
    }
    p.spend(150);
}

void GooseNesting::notify(GameBoard& g, Player& p){
    cout<<"attacked by geese, nothing happens"<<endl;
}

void OSAP::notify(GameBoard& g, Player& p){
    p.earn(200);
}

void Tuition::notify(GameBoard& g, Player& p){
    cout<<"enter one of the following: $300 OR 10%"<<endl;
    string cmd;
    while (cin>>cmd){
	if (cmd == "$300") {
	    if (p.bankruptcy(300, nullptr)) {
		p.setBankruptcy();
	 	return;
	    }
	    p.spend(300);
	    break;
	} else if (cmd == "10%") {
	    if (p.bankruptcy(p.totalMoney() * 0.1, nullptr)) {
		p.setBankruptcy();
		return;
	    }
	    p.spend(p.totalMoney() * 0.1);
	    break;
	} else {  
	     cout<<"error:enter one of the following: $300 OR 10%"<<endl;
	}
    }
}

void Slc::notify(GameBoard& g, Player& p){
    Player** players = g.getPlayer(); //attention
    Square** squares = g.getSquare(); //attention
    int total = 0;
    for (int i = 0; i < g.numOfPlayers; ++i) {
	total += players[i]->getTimscups();
    }
    if (total <= 4) {
	Random dice{100};
	if (dice.generate() == 1) {
	    cout<<"you received a tims cup!"<<endl; 
	    p.receiveTimscups();
	}
    }
    Random ran{24};
    int result = ran.generate();
    if (result <= 3) {
	p.move(-3);
	cout<<"move back 3 to square #"<<p.getPosition()<<' '<<squares[p.getPosition()]->getName()<<endl;
	squares[p.getPosition()]->notify(g, p);
    } else if (result <= 7){
	p.move(-2);
	cout<<"move back 2 to square #"<<p.getPosition()<<' '<<squares[p.getPosition()]->getName()<<endl;
	squares[p.getPosition()]->notify(g, p);
    } else if (result <= 11){
	p.move(-1);
	cout<<"move back 1 to square #"<<p.getPosition()<<' '<<squares[p.getPosition()]->getName()<<endl;
	squares[p.getPosition()]->notify(g, p);
    } else if (result <= 14){
	p.move(1);
	cout<<"move forward 1 to square #"<<p.getPosition()<<' '<<squares[p.getPosition()]->getName()<<endl;
	squares[p.getPosition()]->notify(g, p);
    } else if (result <= 18){
	p.move(2);
	cout<<"move forward 2 to square #"<<p.getPosition()<<' '<<squares[p.getPosition()]->getName()<<endl;
	squares[p.getPosition()]->notify(g, p);
    } else if (result <= 22){
	p.move(3);
	cout<<"move forward 3 to square #"<<p.getPosition()<<' '<<squares[p.getPosition()]->getName()<<endl;
	cout<<p.getPosition();
	squares[p.getPosition()]->notify(g, p);
    } else if (result <= 23){
	cout<<"move to square #10 DC Tims Line"<<endl;
	p.setPosition(10);
	squares[10]->notify(g, p);
    } else if (result <= 24){
	cout<<"move to square #0 Collect OSAP"<<endl;
	p.setPosition(0);
	squares[0]->notify(g, p);
    }
}

void NeedlesHall::notify(GameBoard& g, Player& p){
    Random ran{18};
    int result = ran.generate();
    if (result <= 1) {
	cout<<"you are charged $200"<<endl;
	if (p.bankruptcy(200, nullptr)) {
	    p.setBankruptcy();
	    return;
	}
	p.spend(200);
    } else if (result <= 3){
	cout<<"you are charged $100"<<endl;
	if (p.bankruptcy(100, nullptr)) {
	    p.setBankruptcy();
	    return;
	}
	p.spend(100);
    } else if (result <= 6){
	cout<<"you are charged $50"<<endl;
	if (p.bankruptcy(50, nullptr)) {
	    p.setBankruptcy();
	    return;
	}
	p.spend(50);
    } else if (result <= 12){
	cout<<"you earn $25"<<endl;
	p.earn(25);
    } else if (result <= 15){
	cout<<"you earn $50"<<endl;
	p.earn(50);
    } else if (result <= 17){
	cout<<"you earn $100"<<endl;
	p.earn(100);
    } else if (result <= 18){
	cout<<"you earn $200"<<endl;
	p.earn(200);
    }
}

void GoToTims::notify(GameBoard& g, Player& p){
    //cout<<"move to square #10 DC Tims Line"<<endl;
    Square** squares = g.getSquare(); //attention
    p.setPosition(10);
    squares[40]->notify(g, p);
}

void LandDCTimsLine::notify(GameBoard& g, Player& p){
    Player** players = g.getPlayer(); //attention
    int total = 0;
    for (int i = 0; i < g.numOfPlayers; ++i) {
	total += players[i]->getTimscups();
    }
    if (total <= 4) {
	Random dice{100};
	if (dice.generate() == 1) {
	    cout<<"you received a tims cup!"<<endl; 
	    p.receiveTimscups();
	}
    }  
    p.setPosition(10);
}

void SentToDCTimsLine::notify(GameBoard& g, Player& p){
	Square** squares = g.getSquare(); //attention
    p.sentTimsLine();
    cout<<"welcome to DC Tims Line, this it your "<<p.getDCturns()<<" turns here, you now have "<<p.getTimscups()<<" Tims Cups."<<endl;
    string cmd;
    bool roll = true;
    if (p.getDCturns() != 3){
	cout<<"Do you want to stay here for another turn or roll dices or pay $50 or use Tims Cups to leave?"<<endl;
	cout<<"Please enter one of the following: stay, roll, pay, cups"<<endl;
	while (cin>>cmd){
	    if (cmd == "stay"){
		cout<<"you chose to stay"<<endl;
		p.stayTimsLine();
		return;
	    } else if (cmd == "roll" && roll){
		cout<<"you chose to roll dices"<<endl;
		Random dice{6};
    		int result1 = dice.generate();
    		int result2 = dice.generate();
		p.setLastRoll(result1 + result2);
		cout<<"your dices are "<<result1<<' '<<result2<<endl;
		if (result1 == result2) {
		    cout<<"you leave DC tims line"<<endl;
		    p.move(result1 + result2);
		    p.leaveTimsLine();
		    squares[p.getPosition()]->notify(g, p);
		    return;
		} else {
		    cout<<"your dices are not double, do you want to stay here for another turn or pay $50 or use Tims Cups to leave?"<<endl;
		    cout<<"Please enter one of the following: stay, pay, cups"<<endl;
		    roll = false;
		    continue;
		}
	    } else if (cmd == "roll" && !roll){
		cout<<"you have rolled dices but they are not double, you cannot roll again until next turn"<<endl;
		cout<<"Do you want to stay here for another turn or pay $50 or use Tims Cups to leave?"<<endl;
		cout<<"Please enter one of the following: stay, pay, cups"<<endl;
		continue;
	    } else if (cmd == "pay" && roll){
		cout<<"you choose to pay $50"<<endl;
		if (p.bankruptcy(50, nullptr)) {
	    	    p.setBankruptcy();
	    	    return;
		}
		p.spend(50);
		cout<<"you leave DC tims line"<<endl;
		p.leaveTimsLine();
		Random dice{6};
    		int result1 = dice.generate();
    		int result2 = dice.generate();
			p.setLastRoll(result1 + result2);
		p.move(p.getLastRoll());
		cout<<"move forward "<<p.getLastRoll()<<" to square "<<p.getPosition()<<endl;
		squares[p.getPosition()]->notify(g, p);
		return;
	    } else if (cmd == "cups" && p.getTimscups() != 0){
		cout<<"you choose to use Tims cups"<<endl;
		p.useTimscups();
		cout<<"you leave DC tims line"<<endl;
		p.leaveTimsLine();
		p.move(p.getLastRoll());
		squares[p.getPosition()]->notify(g, p);
		return;
	    } else if (cmd == "cups" && p.getTimscups() == 0 ){
		cout<<"you don't have Tims cups, please choose another way"<<endl;
		cout<<"Please enter one of the following: stay, roll, pay"<<endl;
		continue;
	    } else {
		cout<<"invalid command, please enter again"<<endl;
	    }
	}
     } else {
		cout<<"This is your third turn here, you must leave now. Do you want to roll dices or pay $50 or use Tims Cups to leave?"<<endl;
		cout<<"Please enter one of the following: roll, pay, cups"<<endl;
	while (cin>>cmd){
	    if (cmd == "roll" && roll){
		cout<<"you choose to roll dices"<<endl;
		Random dice{6};
    		int result1 = dice.generate();
    		int result2 = dice.generate();
		p.setLastRoll(result1 + result2);
		cout<<"your dices are "<<result1<<' '<<result2<<endl;
		if (result1 == result2) {
		    cout<<"you leave DC tims line"<<endl;
		    p.move(result1 + result2);
		    p.leaveTimsLine();
		    squares[p.getPosition()]->notify(g, p);
		    return;
		} else {
		    cout<<"your dices are not double, do you want to pay $50 or use Tims Cups to leave?"<<endl;
		    cout<<"Please enter one of the following: pay, cups"<<endl;
		    roll = false;
		    continue;
		}
	    } else if (cmd == "roll" && !roll){
			cout<<"you have rolled dices but they are not double, you cannot roll again until next turn"<<endl;
			cout<<"Do you want to pay $50 or use Tims Cups to leave?"<<endl;
			cout<<"Please enter one of the following: pay, cups"<<endl;
			continue;
	    } else if (cmd == "pay"){
			cout<<"you choose to pay $50"<<endl;
			if (p.bankruptcy(50, nullptr)) {
	    		    p.setBankruptcy();
	    	    	return;
			}
			p.leaveTimsLine();
			p.spend(50);
			Random dice{6};
    		int result1 = dice.generate();
    		int result2 = dice.generate();
		    p.setLastRoll(result1 + result2);
			p.move(p.getLastRoll());
			squares[p.getPosition()]->notify(g, p);
			return;
	    } else if (cmd == "cups" && p.getTimscups() != 0){
			cout<<"you choose to use Tims cups"<<endl;
			p.useTimscups();
			cout<<"you leave DC tims line"<<endl;
			p.leaveTimsLine();
			p.move(p.getLastRoll());
			squares[p.getPosition()]->notify(g, p);
			return;
	    } else if (cmd == "cups" && p.getTimscups() == 0 ){
		cout<<"you don't have Tims cups, please choose another way"<<endl;
		cout<<"Please enter one of the following: roll, pay"<<endl;
		continue;
	    } else {
		cout<<"invalid command, please enter again"<<endl;
	    }
	}
    }
}

