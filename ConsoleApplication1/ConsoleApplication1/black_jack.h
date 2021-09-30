#pragma once
#include "Deck.h"

class black_jack
{
public:
    Deck main_deck;
    void play_blackjack();

private:
    int point_player {0};
    int point_dialer {0};
    bool turn_player();
    bool turn_dialer();
    void round_winner(int winner);
    void print_current_point();
    
};
