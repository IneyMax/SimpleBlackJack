#include "black_jack.h"
#include <iostream>


void black_jack::print_current_point()
{
    std::cout << "Dialer has " << point_dialer << " points. " << "Player has " << point_player << " points\n";
}


void black_jack::round_winner(int winner)
{
    switch (winner)
    {
    case 1: std::cout << "Player Win!";
        break;
    case 2: std::cout << "Dialer Win!";
        break;
    case 3: std::cout << "Dead heat!";
        break;
    default: ;
    }
}


void black_jack::play_blackjack()
{
    main_deck.shuffle_deck();
    
    point_player += main_deck.deal_card().get_card_value(point_player);
    point_player += main_deck.deal_card().get_card_value(point_player);
    point_dialer += main_deck.deal_card().get_card_value(point_dialer);
    
    print_current_point();

    if (turn_player())
    {
        return round_winner(2);
    }
    else if (turn_dialer())
    {
        return round_winner(1);
    }
    else
    {
        if (point_player == point_dialer)
        {
            return round_winner(3);
        }
        else if (point_player > point_dialer)
        {
            return round_winner(1);
        }
        else if (point_player < point_dialer)
        {
            return round_winner(2);
        }
    }
;
    
}


bool black_jack::turn_player()
{
    bool l_hit;
    do
    {
        if (point_player < 22)
        {
            std::cout << "Take card? ";
            std::cin >> l_hit;
            if (l_hit)
            {
                point_player += main_deck.deal_card().get_card_value(point_player);
                if (point_player == 21)
                {
                    std::cout << "BLACKJACK!!! 21 POINTS! \n";
                }
                else
                    std::cout << "Player has " << point_player << " points \n";
            }
            else
                return false;
        }
        else
            return true;
    }
    while (l_hit);
    return false;
}


bool black_jack::turn_dialer()
{
    while (point_dialer < 17)
    {
        point_dialer += main_deck.deal_card().get_card_value(point_dialer);
        if (point_dialer == 21)
        {
            std::cout << "BLACKJACK!!! 21 POINTS! \n";
        }
        else
            std::cout << "Dialer has " << point_dialer << " points \n";
    }
    
    if (point_dialer > 21 )
    {
        return true;
    }
    return false;
}


















































/*
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


int take_card(std::array<card,52> &deck)
{
    static int i {};
    std::cout <<"Take card: "<< get_card_value(deck[i]) << "\n";
    card *choose_card {&deck[i]}; // Указатель на "верхнюю карту колоды"
    ++i;
    return get_card_value(*choose_card);
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
*/

