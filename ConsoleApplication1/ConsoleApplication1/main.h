#pragma once
#include <array>
#include <iostream>

enum cards_suits
{
 diamonds,
 hearts,
 clubs,
 spades,
 max_suit,
};

enum cards_ranks
{
 two,
 tree,
 four,
 five,
 six,
 seven,
 eight,
 nine,
 ten,
 jack,
 queen,
 king,
 ace,
 max_rank,
};

struct card
{
 cards_suits suit;
 cards_ranks rank;
};

void print_card(const card &cur_card);

void print_deck(const std::array<card,52> &deck);

void swap_cards(card& first,card &second);

void shuffle_deck(std::array<card,52> &deck);

int get_card_value(const card);

void deck_initialisation(std::array<card,52> &deck);

bool play_blackjack(std::array<card,52> &deck);



