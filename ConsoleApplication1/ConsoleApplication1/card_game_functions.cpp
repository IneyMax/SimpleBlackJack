#include "main.h"
#include <random>

void print_card(const card &cur_card)
{
    switch (cur_card.suit)
    {
        case diamonds:
            std::cout<< "dia";
            break;
        case hearts:
            std::cout<< "hea";
            break;
        case clubs:
            std::cout<< "clu";
            break;
        case spades:
            std::cout<< "spa";
            break;
        case max_suit: break;
        default: ;
    }

    std::cout << " ";
    
    switch (cur_card.rank)
    {
    case two:std::cout<< "two";
        break;
    case tree:std::cout<< "tre";
        break;
    case four:std::cout<< "fou";
        break;
    case five:std::cout<< "fiv";
        break;
    case six:std::cout<< "six";
        break;
    case seven:std::cout<< "sev";
        break;
    case eight:std::cout<< "eig";
        break;
    case nine:std::cout<< "nin";
        break;
    case ten:std::cout<< "ten";
        break;
    case jack:std::cout<< "jac";
        break;
    case queen:std::cout<< "que";
        break;
    case king:std::cout<< "kin";
        break;
    case ace:std::cout<< "ace";
        break;
    case max_rank:
        break;
    default: ;
    }
}

void print_deck(const std::array<card,52> & deck)
{
    for (auto cur_card: deck)
    {
        print_card(cur_card);
        std::cout << "\n";
    }
    std::cout << "\n";
}

void swap_cards(card& first,card &second)
{
    auto temple_card = first;
    first = second;
    second = temple_card;
}

void shuffle_deck(std::array<card,52> &deck)
{
    int index {0};
    for (card cur_card: deck)
    {
        std::random_device rd;   // non-deterministic generator
        std::mt19937 gen(rd());  // to seed mersenne twister.
        std::uniform_int_distribution<> dist(0,51); // distribute results between 1 and 6 inclusive.
        
        swap_cards(deck[dist(gen)], deck[index]);
        index ++;
        
    }
}

void deck_initialisation(std::array<card,52> &deck)
{
    int card_index {0};
    for (int suit {0}; suit<max_suit; ++suit )
        for (int rank {0}; rank<max_rank; ++rank)
        {
            deck[card_index].rank = static_cast<cards_ranks>(rank);
            deck[card_index].suit = static_cast<cards_suits>(suit);
            card_index ++;
        }
}

int get_card_value(const card cur_card)
{
    switch (cur_card.rank) {
    case two:
        return 2;
    case tree:
        return 3;
    case four:
        return 4;
    case five:
        return 5;
    case six:
        return 6;
    case seven:
        return 7;
    case eight:
        return 8;
    case nine:
        return 9;
    case ten:
        return 10;
    case jack:
        return 10;
    case queen:
        return 10;
    case king:
        return 10;
    case ace:
        return 11;
    case max_rank:
        return 0;
    default:
        return 0;
    }
}



