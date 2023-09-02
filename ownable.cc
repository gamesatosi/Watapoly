#include "ownable.h"
#include "random.h"

void OwnableBuilding::setOwner(Player *p) {
    this->owner = p;
}


Player* OwnableBuilding::getOwner() {
    return this->owner;
}


string OwnableBuilding::getType() {
    return this->type;
}

int OwnableBuilding::getpurchase_cost() {
    return this->purchase_cost;
}

int Academic_building::getimprovement_cost() {
    return improvement_cost;
}

void Academic_building::notify(GameBoard& g, Player& p){
    if (this->getOwner() == nullptr) {
        cout << "this land is not owned!" << endl; 
        cout << "do you want to buy it? [yes/no]" << endl;
        string response;
        while (cin >> response) {
            if (response == "yes") {
                if (p.getMoney() >= this->getpurchase_cost()){
                    p.addProperty(this);
                    p.spend(this->getpurchase_cost());
                    this->setOwner(&p);
                    cout << "you pay $" << this->getpurchase_cost() << " to buy it!" << endl;
                } else {
                    cout << "you have no enough money!" << endl;
                }
                return;
            } else if (response == "no") {
                cout << "start to bid " << this->getName() << " !" << endl;
                while (true) {
                    int bid = 0;
                    string s = g.auction(g.getPlayer(), bid, g.numOfPlayers, &p);
                    Player* player = g.getPlayer(s);
                    if (player->getMoney() >= bid) {
                        cout << "you win this building!" << endl;
                        player->addProperty(this);
                        player->spend(bid);
                        this->setOwner(player);
                        break;
                    } else {
                        cout << "you have no enough money! the auction will start again!" << endl;
                        continue;
                    }
                }

                return;
            }


        }
    }
    if (improvement_level == -1) {
        cout << "the owner has mortage the property!" << endl;
    } else {
        if (!(p.smartSpend(this->getFee(), this->getOwner()))) {
            this->getOwner()->earn(this->getFee());
            cout << "you pay $" << this->getFee() << " for landing on it!" << endl;
        }
    }

}

int Academic_building::getimprovement_level() {
    return improvement_level;
}

bool Academic_building::improve() {
    if (!(this->getOwner()->monopoly(this->monopoly_block))) {
        std::cout << this->monopoly_block << " is not monopolied, so you cannot improve!" << std::endl;
        return false;
    }
    if (this->improvement_level == 5) {
        std::cout << this->getName() << " has been level 5, so you cannot improve!" << std::endl;
        return false;
    }

    if (this->getOwner()->getMoney() >= this->improvement_cost) {
        this->getOwner()->spend(this->improvement_cost);
        ++this->improvement_level;
        std::cout << this->getName() << " is level " << this->getimprovement_level() << " now!" << std::endl;
        return true;
    } else {
        std::cout << "improve " << this->getName() << " need " << this->getimprovement_cost() 
        << ", but you have only " << this->getOwner()->getMoney() << "!" << std::endl;
        return false;
    }
}

int Academic_building::getFee() {
    if (this->improvement_level == 0 && this->getOwner()->monopoly(this->monopoly_block)) return this->level_fee[this->improvement_level] * 2;
    return this->level_fee[this->improvement_level];
}

string Academic_building::getmonopoly_block() {
    return this->monopoly_block;
}

int Academic_building::getValue() {
    if (improvement_level > 0) {
        --improvement_level;
        return improvement_cost * 0.5;
    }
    cout << "you have no improvement for this building, so you cannot sell!"<< endl;
    return 0;
}


int Residence::getFee() {
    int n = this->getOwner()->getnum_residences();
    if (n == 1) return 25;
    if (n == 2) return 50;
    if (n == 3) return 100;
    if (n == 4) return 200;
    return 0;
}

void Residence::notify(GameBoard& g, Player& p){
    if (this->getOwner() == nullptr) {
        cout << "this land is not owned!" << endl; 
        cout << "do you want to buy it? [yes/no]" << endl;
        string response;
        while (cin >> response) {
            if (response == "yes") {
                if (p.getMoney() >= this->getpurchase_cost()){
                    p.addProperty(this);
                    p.spend(this->getpurchase_cost());
                    this->setOwner(&p);
                    cout << "you pay $" << this->getpurchase_cost() << " to buy it!" << endl;
                } else {
                    cout << "you have no enough money!" << endl;
                }
                return;
            } else if (response == "no") {
                cout << "start to bid " << this->getName() << " !" << endl;
                while (true) {
                    int bid = 0;
                    string s = g.auction(g.getPlayer(), bid, g.numOfPlayers, &p);
                    Player* player = g.getPlayer(s);
                    if (player->getMoney() >= bid) {
                        cout << "you win this building!" << endl;
                        player->addProperty(this);
                        player->spend(bid);
                        this->setOwner(player);
                        break;
                    } else {
                        cout << "you have no enough money! the auction will start again!" << endl;
                        continue;
                    }
                }
                return;
            }
        }
    }
    if (improvement_level == -1) {
        cout << "the owner has mortage the property!" << endl;
    } else {
        if (!(p.smartSpend(this->getFee(), this->getOwner()))) {
            this->getOwner()->earn(this->getFee());
            cout << "you pay $" << this->getFee() << " for landing on it!" << endl;
        }
    }
}

int Residence::getValue() {
    return this->getpurchase_cost();
}

int Gym::getFee() {
    int n = this->getOwner()->getnum_gym();
    Random r{6};
    int die1 = r.generate();
    int die2 = r.generate();
    int sum = die1 + die2;
    if (n == 1) return sum * 4;
    if (n == 2) return sum * 10;
    return 0;
}

void Gym::notify(GameBoard& g, Player& p){
    if (this->getOwner() == nullptr) {
        cout << "this land is not owned!" << endl; 
        cout << "do you want to buy it? [yes/no]" << endl;
        string response;
        while (cin >> response) {
            if (response == "yes") {
                if (p.getMoney() >= this->getpurchase_cost()){
                    p.addProperty(this);
                    p.spend(this->getpurchase_cost());
                    this->setOwner(&p);
                    cout << "you pay $" << this->getpurchase_cost() << " to buy it!" << endl;
                } else {
                    cout << "you have no enough money!" << endl;
                }
                return;
            } else if (response == "no") {
                cout << "start to bid " << this->getName() << " !" << endl;
                while (true) {
                    int bid = 0;
                    cout << g.numOfPlayers << endl;
                    string s = g.auction(g.getPlayer(), bid, g.numOfPlayers, &p);
                    Player* player = g.getPlayer(s);
                    if (player->getMoney() >= bid) {
                        cout << "you win this building!" << endl;
                        player->addProperty(this);
                        player->spend(bid);
                        this->setOwner(player);
                        break;
                    } else {
                        cout << "you have no enough money! the auction will start again!" << endl;
                        continue;
                    }
                }
                return;
            }
        }
    }
    if (improvement_level == -1) {
        cout << "the owner has mortage the property!" << endl;
    } else {
        int a = this->getFee();
        if (!(p.smartSpend(a, this->getOwner()))) {
            this->getOwner()->earn(a);
            cout << "you pay $" << a << " for landing on it!" << endl;
        }
    }
}

int Gym::getValue() {
    return this->getpurchase_cost();
}

void Residence::setimprovement_level(int improvement) {
    improvement_level = improvement;
}

void Academic_building::setimprovement_level(int improvement) {
    this->improvement_level = improvement;
}



void Gym::setimprovement_level(int improvement) {
    improvement_level = improvement;
}





