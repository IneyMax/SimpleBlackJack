#pragma once
#include <array>
#include "Card.h"

class Deck
{
private:
    int card_index;
    std::array<Card, 52> deck_;
    static int get_random_number();
    static void swap_cards(Card& first, Card &second);

public:
    explicit Deck(): card_index {0}
    {
        int card = 0;
        for (int suit = 0; suit < Card::max_suit; ++suit)
            for (int rank = 0; rank < Card::max_rank; ++rank)
            {
                deck_[card] = Card(static_cast<Card::cards_ranks>(rank), static_cast<Card::cards_suits>(suit));
                ++card;
            }
    }
    
    void shuffle_deck();
    
    const void print_deck();

    const Card deal_card();
    
};
