//
// Created by stycks on 04/05/2021.
//

#ifndef EX4_A_GENESPLICER_HPP
#define EX4_A_GENESPLICER_HPP
#include "Player.hpp"

namespace pandemic {
/*This class represents a specific type of a player. GeneSplicer special ability: use "discover_cure" with any cards colors combination - not just the current city's disease color.*/
    class GeneSplicer : public Player{
        string className;
    public:
        /*Constructor.*/
        GeneSplicer(Board& board, City city): pandemic::Player(board, city),className("GeneSplicer"){}
        /*Discovers a cure to a given color type(doesn't have to be the same as city's). Player must have a research lab in current city.
         GeneSplicer can use any cards colors combination - not just the current city's disease color.
         * Note: in case cure was already found, nothing will happen.*/
        void discover_cure(Color color) override;
         /*Returns this player role.*/
        string role() override{return className;}
    };
}
#endif //EX4_A_GENESPLICER_HPP
