#include "Card.h"
#include <iostream>


int Card::get_card_value(int cur_ponts) const
{
    switch (Card::m_rank) {
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
        {
            std::cout << "Ace!\n";
            if (cur_ponts < 11)
            {
                return 11;
            }
            else return 1;
        }
    case max_rank:
        return 0;
    default:
        return 0;
    }
}


void Card::print_card() const
{
    switch (Card::m_suit)
    {
    case diamonds:
        std::cout<< "diamonds";
        break;
    case hearts:
        std::cout<< "hearts";
        break;
    case clubs:
        std::cout<< "clubs";
        break;
    case spades:
        std::cout<< "spades";
        break;
    case max_suit: break;
    default: ;
    }

    std::cout << " ";
    
    switch (Card::m_rank)
    {
    case two:std::cout<< "two";
        break;
    case tree:std::cout<< "tree";
        break;
    case four:std::cout<< "four";
        break;
    case five:std::cout<< "five";
        break;
    case six:std::cout<< "six";
        break;
    case seven:std::cout<< "seven";
        break;
    case eight:std::cout<< "eight";
        break;
    case nine:std::cout<< "nine";
        break;
    case ten:std::cout<< "ten";
        break;
    case jack:std::cout<< "jack";
        break;
    case queen:std::cout<< "queen";
        break;
    case king:std::cout<< "king";
        break;
    case ace:std::cout<< "ace";
        break;
    case max_rank:
        break;
    default: ;
    }
    std::cout << "\n";
}
