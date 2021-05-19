//
// Created by stycks on 04/05/2021.
//

#ifndef EX4_A_RESEARCHER_HPP
#define EX4_A_RESEARCHER_HPP
#include "Player.hpp"

namespace pandemic {
/*This class represents a specific type of a player. Researcher special ability: use "discover_cure" even if current city doesn't have research lab.  */
    class Researcher : public Player {
        string className;
    public:
        /*Constructor.*/
        Researcher(Board& board, City city): pandemic::Player(board, city), className("Researcher"){}
         /*Discovers a cure to a given color type(doesn't have to be the same as city's).
         * Cost 5 city card of the same color.
         * Note: in case cure was already found, nothing will happen.*/
        void discover_cure(Color color) override;
        /*Returns this player role.*/
        string role() override{return className;}
    };
}

#endif //EX4_A_RESEARCHER_HPP
