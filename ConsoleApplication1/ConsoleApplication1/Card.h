#pragma once

class Card
{
public:

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

    struct s_card
    {
        cards_suits suit;
        cards_ranks rank;
    };

    Card(::Card::cards_ranks m_rank = max_rank, ::Card::cards_suits m_suit = max_suit)
        : m_rank(m_rank),
          m_suit(m_suit)
    {
    }

    void print_card() const;

    int get_card_value(int cur_points) const;

private:
    cards_ranks m_rank;
    cards_suits m_suit;
    
};
