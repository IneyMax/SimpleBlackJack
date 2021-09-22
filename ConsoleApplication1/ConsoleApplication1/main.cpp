#include "main.h"

int main()
{
    
    std::array<card, 52> deck;
    deck_initialisation(deck);
    shuffle_deck(deck);
    
    bool win = play_blackjack(deck);
    
    if (win)
    {
        std::cout << "WIN!!!!!!!!!";
    }
    else
    {
        std::cout << "LOOOOOOSER";
    }
}
