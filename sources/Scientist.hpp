//
// Created by stycks on 04/05/2021.
//

#ifndef EX4_A_SCIENTIST_HPP
#define EX4_A_SCIENTIST_HPP

#include "Player.hpp"

namespace pandemic {

    class Scientist :public Player {
        //the number of cards Scientist should throw for discover_cure
        int ability;
        string className;
    public:
        /*Constructor. n is the number of cards Scientist should throw for discover_cure.*/
        Scientist(Board& board, City city, int n=4): pandemic::Player(board, city), ability(n), className("Scientist"){}
        /*Discovers a cure to a given color type(doesn't have to be the same as city's). Player must have a research lab in current city.
         * Cost n city card of the same color (n is given at constructor).
         * Note: in case cure was already found, nothing will happen.*/
        void discover_cure(Color color) override;
        /*Returns this player role.*/
        string role() override {return className;}
    
    private:
        void remove_cards() override;
    };
}

#endif //EX4_A_SCIENTIST_HPP
