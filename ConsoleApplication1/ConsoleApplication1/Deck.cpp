#include "Deck.h"
#include <random>


int Deck::get_random_number()
{
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> dist(0,51); // distribute results between 1 and 6 inclusive.
    return dist(gen);
}


void Deck::swap_cards(Card& first, Card &second)
{
    auto temple_card = first;
    first = second;
    second = temple_card;
}


void Deck::shuffle_deck()
{
    for (auto cur_card: deck_)
    {
        swap_cards(cur_card, deck_[get_random_number()]);
    }
    card_index = 0;
}


const void Deck::print_deck()
{
    for (auto card: deck_)
    {
        card.print_card();
    }
}


const Card Deck::deal_card()
{
    return deck_[card_index++];
}


