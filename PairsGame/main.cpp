#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

class Card {
    public :
        int value;
};

class Player {
    public:
        string name;
        int total_score;
        vector<Card> hand_card; // Kartu yang dipegang
        vector<Card> folded_card; // Kartu yang sudah di fold/dinilai

        explicit Player(const string &_name) {
            name = _name;
            total_score = 0;
        }
        void draw_card(const Card card) {
            hand_card.push_back(card);
        }

        vector<Card> return_card_to_deck() {
            vector<Card> returned_cards = hand_card; // Copy cards before clearing
            hand_card.clear();
            return returned_cards;
        }

        Card take_card_from_hand(int card_index) {
            Card card = hand_card[card_index];
            hand_card.erase(hand_card.begin() + card_index);
            return card;
        }

        void put_card_to_folded_card(Card card) {
            folded_card.push_back(card);
            total_score += card.value;
        }

        bool hand_card_has_duplicate() {
            for (int i = 0; i < hand_card.size(); i++) {
                for (int j = i + 1; j < hand_card.size(); j++) {
                    if (hand_card[i].value == hand_card[j].value) {
                        put_card_to_folded_card(take_card_from_hand(i));
                        return true;
                    }
                }
            }
            return false;
        }

        int get_smallest_card_from_hand() {
            int lowest_card_index = 0;
            for (int i = 0; i < hand_card.size(); i++) {
                if (hand_card[i].value < hand_card[lowest_card_index].value) {
                    lowest_card_index = i;
                }
            }
            return lowest_card_index;
        }
};


class Game {
public:
    vector<Card> deck;
    vector<Player> players;
    int target_score;
    int round;
    int starting_player_index;

    Game() {
        cout << "Starting Game";
        initialize_deck();
        create_player();
        player_initial_draw();
        starting_player_index = get_smallest_card_on_round();
        check_duplicate_across_player();
        target_score = 60/players.size()+1;
        round = 1;
    }

    void initialize_deck() {
        for (int i = 1; i <= 10; i++) {
            for (int j = 0; j < i; j++) {
                Card card = Card();
                card.value = i;
                deck.push_back(card);
            }
        }
    }

    void handle_next_round() {
        for (auto& player : players) {
            vector<Card> returned_cards = player.return_card_to_deck();
            deck.insert(deck.end(), returned_cards.begin(), returned_cards.end());
        }
        shuffle_deck();
        player_initial_draw();
        starting_player_index = get_smallest_card_on_round();
        check_duplicate_across_player();
        round++;
    }

    int get_smallest_card_on_round() {
        int player_index = 0;
        for (int i = 1; i < players.size(); i++) {
            if (players[i].get_smallest_card_from_hand() < players[player_index].get_smallest_card_from_hand()) {
                player_index = i;
            }
        }
        return player_index;
    }

    void check_duplicate_across_player() {
        vector player_with_duplicate_index = {starting_player_index};
        for (int i = 0; i < players.size(); i++) {
            if (i == starting_player_index) {
                continue;
            }
            if (players[i].hand_card[0].value == players[starting_player_index].hand_card[0].value) {
                player_with_duplicate_index.push_back(i);
            }
        }
        if (player_with_duplicate_index.size() == 1) {
            return;
        }

        for (const int player_index : player_with_duplicate_index) {
            player_draw_card(player_index);
        }
        int smallest_card_player_hold = player_with_duplicate_index[0];
        for (int i = 1; i < player_with_duplicate_index.size(); i++) {
            if (players[player_with_duplicate_index[i]].hand_card.back().value < players[smallest_card_player_hold].hand_card.back().value) {
                smallest_card_player_hold = player_with_duplicate_index[i];
            }
        }
        starting_player_index = smallest_card_player_hold;
    }
    void handle_fold_player(const int player_who_fold_index) {
        const Card smallest_card_from_player = players[get_smallest_card_on_round()].take_card_from_hand(players[get_smallest_card_on_round()].get_smallest_card_from_hand());
        players[player_who_fold_index].put_card_to_folded_card(smallest_card_from_player);
    }

    void player_initial_draw() {
        for (int i = 0; i < players.size(); i++) {
            player_draw_card(i);
        }
    }

    void player_draw_card(const int player_index) {
        const Card card = deck.back();
        deck.pop_back();
        players[player_index].draw_card(card);
    }


    void create_player() {
        int n;
        cout << "How many player (2-8) : ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Enter player name : ";
            string player_name;
            cin >> player_name;
            auto player = Player(player_name);
            players.push_back(player);
        }
    }

    void shuffle_deck() {
        // Get a random seed from the current time
        const unsigned seed = chrono::system_clock::now().time_since_epoch().count();

        // Create a random number generator
        default_random_engine rng(seed);

        // Shuffle the deck
        ranges::shuffle(deck, rng);
    }

    void check_deck() {
        for (const Card& card : deck) {
            cout << card.value << " ";
        }
        cout << endl;
    }
};

int main() {
    Game pairs_game;
    pairs_game.shuffle_deck();
    pairs_game.check_deck();
    return 0;
}
