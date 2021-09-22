#include "main.h"


int take_card(std::array<card,52> &deck)
{
    static int i {};
    std::cout <<"Take card: "<< get_card_value(deck[i]) << "\n";
    card *choose_card {&deck[i]}; // Указатель на "верхнюю карту колоды"
    ++i;
    return get_card_value(*choose_card);
}

bool turn_player(std::array<card,52> &deck, int* p_player)
{
    bool hit;
    do
    {
        if (*p_player < 22)
            {
            std::cout << "Take card?";
            std::cin >> hit;
            if (hit)
            {
                *p_player += take_card(deck);
                std::cout << "Player has " << *p_player << " points \n";
            }
            else
                return false;
        }
        else
            return true;
    }
    while (hit);
}

bool turn_dialer(std::array<card,52> &deck, int* p_dialer)
{
    bool hit {true};
    do
    {
        if (*p_dialer < 22)
        {
            if (*p_dialer < 17)
            {
                *p_dialer += take_card(deck);
                std::cout << "Dialer has " << *p_dialer << " points \n";
            }
            else
                return false;
        }
        else
            return true;
    }
    while (hit);
}

bool play_blackjack(std::array<card,52> &deck)
{
    int point_player {}; // Сумма очков игрока
    int point_dialer {}; // Сумма очков дилера

    std::cout << "Dialer take card: ";
    point_dialer += take_card(deck);
    std::cout << "Player take card: ";
    point_player += take_card(deck);
    std::cout << "Player take card: ";
    point_player += take_card(deck);

    if(turn_player(deck, &point_player))
    {
        return false;
    }
    
    if(turn_dialer(deck, &point_dialer))
    {
        return true;
    }
    
    if (point_player > point_dialer)
    {
        return true;
    }
    return false;
}



