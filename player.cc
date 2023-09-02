#include<iostream>
#include<string>
#include<vector>
#include<map>
#include <utility> 
#include"player.h"
#include"gameboard.h"
#include"random.h"
#include"square.h"
#include"unownable.h"
#include"ownable.h"
#include"player.h"
using namespace std;

Player::Player(string n, char c, int timscups, int money, int pos, int DCturns): money{money}, position{pos}, character{c}, name{n}, timscups{timscups}, DCturns{DCturns}  {}

bool Player::monopoly(string block){
    if (block == "Arts1" && num_Art1 == 2) return true;
    if (block == "Arts2" && num_Art2 == 3) return true;
    if (block == "Eng" && num_Eng == 3) return true;
    if (block == "Health" && num_Health == 3) return true;
    if (block == "Env" && num_Env == 3) return true;
    if (block == "Sci1" && num_Sci1 == 3) return true;
    if (block == "Sci2" && num_Sci2 == 3) return true;
    if (block == "Math" && num_Math == 2) return true;
    return false;
}

int Player::getnum_academic_building(){
    return this->num_academic_building;
}

int Player::getnum_residences(){
    return this->num_residences;
}

int Player::getnum_gym (){
    return this->num_gym ;
}

int Player::getnum_Art1 (){
    return this->num_Art1 ;
}

int Player::getnum_Art2 (){
    return this->num_Art2 ;
}

int Player::getnum_Eng (){
    return this->num_Eng ;
}

int Player::getnum_Health (){
    return this->num_Health ;
}

int Player::getnum_Env (){
    return this->num_Env ;
}

int Player::getnum_Sci1 (){
    return this->num_Sci1 ;
}

int Player::getnum_Sci2 (){
    return this->num_Sci2 ;
}

int Player::getnum_Math (){
    return this->num_Math ;
}

int Player::getMoney(){
    return this->money;
}

bool Player::bankruptcy(){
    return (money < 0);
}

void Player::setBankruptcy(){
    money = -1;
}


void Player::setLastRoll(int r){
    this->lastRoll = r;
}

int Player::getLastRoll(){
    return this->lastRoll;
}

int Player::getPosition(){
    return this->position;
}

map<Square*, int> Player::getProperty(){
    return this->property;
}

vector<Square*> Player::getMortgage(){
    return this->mortgages;
}

char Player::getCharacter(){
    return this->character;
}

string Player::getName(){
    return this->name;
}

int Player::getTimscups(){
    return this->timscups;
}

int Player::getDCturns(){
    return this->DCturns;
}

void Player::leaveTimsLine(){
    this->DCturns = -1;
}

void Player::sentTimsLine(){
    if (DCturns == -1) DCturns = 0;
}

void Player::spend(int fee){
    money = money - fee;
}

bool Player::smartSpend(int fee, Player* p){
    if (money >= fee) { // can buy it
		this->spend(fee);
		return false;
    } else {
		
		if (!(this->declareBankruptcy(fee, p))){
			this->spend(fee);
			return false;
		} 
		return true;
    }
}

void Player::earn(int fee){
    money = money + fee;
}

void Player::stayTimsLine(){
    this->DCturns += 1;
}

void Player::useTimscups(){
    this->timscups -= 1;
}

void Player::receiveTimscups(){
    this->timscups += 1;
}

int Player::totalMoney(){// returns all assets including savings, printed prices of all buildings owned and costs of improvemnts
    int total = 0;
    for (auto p:property){
	total += p.first->getpurchase_cost();
	if (p.second != 0){
	    total += p.first->getimprovement_cost();
	}
    }
    for (auto p:mortgages){
	total += p->getpurchase_cost();
    }
    total += money;
    return total;
}

void Player::addProperty(Square* s){
    property[s] = 0;
    if (s->getType() == "academic"){ //attention
		++num_academic_building;
			if (s->getmonopoly_block() == "Arts1") num_Art1++; 
        	if (s->getmonopoly_block() == "Arts2") num_Art2++; 
        	if (s->getmonopoly_block() == "Eng") num_Eng ++; 
        	if (s->getmonopoly_block() == "Health") num_Health++; 
        	if (s->getmonopoly_block() == "Env") num_Env++; 
        	if (s->getmonopoly_block() == "Sci1") num_Sci1++; 
        	if (s->getmonopoly_block() == "Sci2") num_Sci2++; 
        	if (s->getmonopoly_block() == "Math") num_Math++; 
    } else if (s->getType() == "residence") {
		++num_residences;
	} else if (s->getType() == "gym") {
		++num_gym;
	}
}

void Player::deleteProperty(Square* s){
    for (auto p:property){
	if (s == p.first) {
	    property.erase(p.first);
	    break;
	}
    }
    if (s->getType() == "academic"){ //attention
		--num_academic_building;
			if (s->getmonopoly_block() == "Arts1") num_Art1--; 
        	if (s->getmonopoly_block() == "Arts2") num_Art2--; 
        	if (s->getmonopoly_block() == "Eng") num_Eng--; 
        	if (s->getmonopoly_block() == "Health") num_Health--; 
        	if (s->getmonopoly_block() == "Env") num_Env--; 
        	if (s->getmonopoly_block() == "Sci1") num_Sci1--; 
        	if (s->getmonopoly_block() == "Sci2") num_Sci2--; 
        	if (s->getmonopoly_block() == "Math") num_Math--; 
    } else if (s->getType() == "residence") {
		--num_residences;
	} else if (s->getType() == "gym") {
		--num_gym;
	}

}

void Player::setPosition(int pos){
    position = pos;
}

void Player::move(int p){
    position += p;
	if (position >= 40) {
		position -= 40;
	} else if (position < 0) {
		position += 40;
	}
}

void Player::display(){
    cout<<"cash: "<<money<<endl;
    cout<<"unmortgaged buildings: "<<endl;
    for (auto p:property){
	cout<<p.first->getName(); //attention
	cout <<"  improvements: "<<p.second <<endl;
    }
    cout<<"mortgaged buildings: " << endl;
    for (auto p:mortgages){
	cout<<p->getName()<<endl; //attention
    }
}

void Player::mortgage(Square* s){
    this->deleteProperty(s);
    mortgages.push_back(s);
}

void Player::unmortgage(Square* s){
    for (auto p:mortgages){
	if (s == p) {
	    property.erase(p);
	    break;
	}
    }
    property[s] = 0;
}

void Player::buyImprovement(Square* s){
    for (auto p:property){
	if (s == p.first) {
	    ++property[p.first];
	    break;
	}
    }
}

void Player::sellImprovement(Square* s){
    for (auto p:property){
	if (s == p.first) {
	    --property[p.first];
	    break;
	}
    }
}

bool Player::eligibleBankruptcy(int fee){
    return (fee > money);
}

bool Player::declareBankruptcy(int fee, Player* p){
    string cmd, name;
    int sell;
    bool flag = false;
    pair<Square*, int> pa;
    if (p == nullptr) {
	cout<<name<<": you are now owing more money than you currently have. Do you choose to declare bankruptcy or raise money?"<<endl;
	cout<<"Please enter: bankrupt OR raise"<<endl;
	while (cin>>cmd){
	    if (cmd == "bankrupt") {
		this->setBankruptcy();
		this->money = -2;
		cout << "Are you sure? Please enter it again![bankrupt]" << endl;
		return true;
	    }
	    if (cmd == "raise") {
		cout<<"You choose to raise money. Please enter the building name you want to mortgage or bankrupt to end the game"<<endl;
		while (cin>>name){
		    if (name == "bankrupt") {
			this->setBankruptcy();
			this->money = -2;
			cout << "Are you sure? Please enter it again![Bankruptcy]" << endl;
			return true;
	    	    }
		    for (auto o:property){
			if (name == o.first->getName()) {
			    flag = true;
			    pa = o;
			    break;
			}
		    }
		    if (!flag) {
			cout<<"invalid input. Please enter one of the following or bankrupt to end the game"<<endl;
			for (auto p:property){
			    cout<<p.first->getName()<<' ';
			}
			cout<<endl;
			continue;
		    }
		    if (pa.second == 0) {
			cout<<"you are mortgaging building "<<pa.first->getName()<<endl;
			this->mortgage(pa.first);
			pa.first->setimprovement_level(-1); //4.10
			money += pa.first->getpurchase_cost() * 0.5;
			if (money >= fee) {
			    cout<<"you raised enough money"<<endl;
			    return false;
		        } else {
			    cout<<"you still owe money. Please enter the building name you want to mortgage or bankruptcy to end the game"<<endl;
			    continue;
		        }
		    }
		    cout<<pa.first->getName()<<" has "<<pa.second<<" improvements. How much of them do you want to sell? Please enter a NUMBER."<<endl;
		    cin>>sell;
		    while (sell > pa.second || sell < 0) {
			cout<<"error. Please enter a valid amount."<<endl;
			cin>>sell;
		    }
		    for (int i = 0; i < sell; ++i){
			this->sellImprovement(pa.first);
			money += pa.first->getimprovement_cost() * 0.5; //attention
		    }
		    pa.first->setimprovement_level(0); //4.10
		    if (money >= fee) {
			cout<<"you raised enough money"<<endl;
			return false;
		    } else {
			cout<<"you still owe money. Please enter the building name you want to mortgage or bankruptcy to end the game or bankruptcy to end the game"<<endl;
			continue;
		    }
		}
	    } else {
		cout<<"invalid input. Please enter again."<<endl;
		continue;
	    }
	}
    } else{
	cout<<name<<": you are now owing more money than you currently have. Do you choose to declare bankruptcy or raise money?"<<endl;
	cout<<"Please enter: bankrupt OR raise"<<endl;
	while (cin>>cmd){
	    if (cmd == "bankrupt") {
		p->earn(this->money);
    		for (auto o : property){
		    p->addProperty(o.first);
		    o.first->setOwner(p); //4.10
		    for (int i = 0; i < o.second; ++i){
	    		p->buyImprovement(o.first);
		    }
		}
    		for (auto o : mortgages){
		    o->setOwner(p); //4.10
		    if (p->smartSpend(o->getpurchase_cost() * 0.1, nullptr)) return true; //attention
		    cout<<"you are receiving a mortgaged building, do you want to unmortgage it now? Plase enter: yes or no"<<endl;
		    while (cin>>cmd){
	    		if (cmd == "yes"){
	        	    if (p->smartSpend(o->getpurchase_cost() * 0.5, nullptr)) return true; //attention
	        	    p->addProperty(o);
		    	    o->setimprovement_level(0); //4.10
			    break;
	    		} else if (cmd == "no"){
			    p->addProperty(o);
			    p->mortgage(o);
			    break;
	    		} else {
			    cout<<"Plase enter: yes or no"<<endl;
	   		}
		    }
    		}
		this->setBankruptcy();
		return true;
	    }
	    if (cmd == "raise") {
		cout<<"You choose to raise money. Please enter the building name you want to mortgage or bankrupt to end the game"<<endl;
		while (cin>>name){
		    if (name == "bankrupt") {
			p->earn(this->money);
    			for (auto o : property){
		    	    p->addProperty(o.first);
		    	    o.first->setOwner(p); //4.10
		    	    for (int i = 0; i < o.second; ++i){
	    			p->buyImprovement(o.first);
		    	    }
			}
    			for (auto o : mortgages){
		    	    o->setOwner(p); //4.10
		    	    if (p->smartSpend(o->getpurchase_cost() * 0.1, nullptr)) return true; //attention
		    	    cout<<"you are receiving a mortgaged building, do you want to unmortgage it now? Plase enter: yes or no"<<endl;
		    	    while (cin>>cmd){
	    			if (cmd == "yes"){
	        	    	    if (p->smartSpend(o->getpurchase_cost() * 0.5, nullptr)) return true; //attention
	        	    	    p->addProperty(o);
		    	     	    o->setimprovement_level(0); //4.10
			    	    break;
	    			} else if (cmd == "no"){
			    	    p->addProperty(o);
			    	    p->mortgage(o);
			    	    break;
	    			} else {
			    	    cout<<"Plase enter: yes or no"<<endl;
	   			}
		    	    }
    			}
			this->setBankruptcy();
			return true;
	    	    }
		    for (auto o:property){
			if (name == o.first->getName()) {
			    flag = true;
			    pa = o;
			    break;
			}
		    }
		    if (!flag) {
			cout<<"invalid input. Please enter one of the following or bankrupt to end the game"<<endl;
			for (auto p:property){
			    cout<<p.first->getName()<<' ';
			}
			cout<<endl;
			continue;
		    }
		    if (pa.second == 0) {
			cout<<"you are mortgaging building "<<pa.first->getName()<<endl;
			this->mortgage(pa.first);
		    	pa.first->setimprovement_level(-1); //4.10
			money += pa.first->getpurchase_cost() * 0.5; //attention
			if (money >= fee) {
			    cout<<"you raised enough money"<<endl;
			    return false;
		        } else {
			    cout<<"you still owe money. Please enter the building name you want to mortgage or bankruptcy to end game"<<endl;
			    continue;
		        }
		    }
		    cout<<pa.first->getName()<<" has "<<pa.second<<" improvements. How much of them do you want to sell? Please enter a NUMBER."<<endl;
		    cin>>sell;
		    while (sell > pa.second || sell < 0) {
			cout<<"error. Please enter a valid amount."<<endl;
			cin>>sell;
		    }
		    for (int i = 0; i < sell; ++i){
			this->sellImprovement(pa.first);
			money += pa.first->getimprovement_cost() * 0.5; //attention
		    }
		    pa.first->setimprovement_level(0); //4.10
		    if (money >= fee) {
			cout<<"you raised enough money"<<endl;
			return false;
		    } else {
			cout<<"you still owe money. Please enter the building name you want to mortgage or bankruptcy to end the game"<<endl;
			continue;
		    }
		}
	    } else {
		cout<<"invalid input. Please enter again."<<endl;
		continue;
	    }
	}
    }
    return false;
}

bool Player::bankruptcy(int fee, Player* p){
    if (!this->eligibleBankruptcy(fee)) return false;
    return this->declareBankruptcy(fee, p);
}
