#include <iostream>
#include <vector>
#include <random>

using namespace std;
class Card {
    public : 
        int value;
        int playerId;
        bool isOnHand;
        Card(int _value, int _playerId) {
            this->value = _value;
            this->playerId = _playerId;
            this->isOnHand = false;
        }
};
class Players {
    public : 
        int id;
        int score;
        string name;

        Players(int _id, string _name) {
            this->id = _id;
            this->name = _name;
            this->score = 0;
        }

        void addScore(int _score) {
            this->score += _score;
        }
};
class PairsGame {
    private :
        int targetScore;
    public :
        bool roundIsOver = false;
        int playerCount;

        vector<Card> cards;
        vector<Players> players;

        PairsGame(int _playerCount) {
            cout << "Game is starting" << endl;
            this->playerCount = _playerCount;
            this->targetScore = 60/this->playerCount+1;
        }

        void generateCard(){
            for(int i=1; i<=10; i++) {
                for (int j=1; j<=i; j++) {
                    Card card(i, -1);
                    this->cards.push_back(card);
                }
            }
        }
        void generatePlayer() {
            for(int i=0; i<this->playerCount; i++) {
                Players player(i, "Player "+to_string(i));
                this->players.push_back(player);
            }
        }
        void playerTakeCard(int playerId) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(0, this->cards.size());

            int attempts = 0;
            while (attempts < cards.size()) {
                int randomIndex = dis(gen);
                if (this->cards[randomIndex].isOnHand == false && this->cards[randomIndex].playerId == -1) {
                    this->cards[randomIndex].isOnHand = true;
                    this->cards[randomIndex].playerId = playerId;
                    return;
                }
            }
        }
        void handlePlayerTurn(int playerId) {
            cout << "Player " << playerId%players.size() << " is playing" << endl;
            cout << "Do you want to take a card? (y/n)" << endl;
            char answer;
            cin >> answer;
            if (answer == 'y') {
                this->playerTakeCard(playerId);
                cout << "Player " << playerId << " has taken a card" << endl;
            } else {
                cout << "Player " << playerId << " is fold" << endl;
                int smallestCard = getSmallestCardTable();
                players[playerId].addScore(smallestCard);
                cards.erase(cards.begin() + smallestCard);
                this->roundIsOver = true;
            }
        }
        int getSmallestCardTable(){
            int smallestCard = 100;
            for(int i=0; i<this->cards.size(); i++) {
                if (
                    this->cards[i].value < this->cards[smallestCard].value &&
                    this->cards[i].isOnHand == true && 
                    this->cards[i].playerId != -1
                    ) {
                        smallestCard = i;
                }
            }
            return smallestCard;
        }
        int getSmallestCardFromPlayer() {
            int playerWithSmallestCard = 100;
            for(int i=0; i<this->cards.size(); i++) {
                if (
                    this->cards[i].value < playerWithSmallestCard && 
                    this->cards[i].isOnHand == true && 
                    this->cards[i].playerId != -1
                    ) {
                    playerWithSmallestCard = this->cards[i].playerId;
                }
            }
            return playerWithSmallestCard;
        }

        void getCurrentCardState(){
            for(int i=0; i<this->cards.size(); i++) {
                if (this->cards[i].isOnHand == true) {
                    cout << "Card " << i << " : " << this->cards[i].value << " | " << this->cards[i].playerId << " | " << this->cards[i].isOnHand << endl;
                }
            }
        }

};

int main() {
    int n;
    PairsGame game(4);
    game.generateCard();
    game.generatePlayer();
    game.playerTakeCard(0);
    game.playerTakeCard(1);
    game.playerTakeCard(2);
    game.playerTakeCard(3);
    for (int i=0; i<100; i++) {
        game.getCurrentCardState();
        game.handlePlayerTurn(i%n);
    }
    return 0;
}