//
// Created by stycks on 04/05/2021.
//

#ifndef EX4_A_OPERATIONSEXPERT_HPP
#define EX4_A_OPERATIONSEXPERT_HPP

#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

/*This class represents a specific type of a player. OperationsExpert special ability: use "Build" without card cost.*/
    class OperationsExpert : public Player {
        string className;
    public:
        /*Constructor.*/
        OperationsExpert(Board& board, City city): pandemic::Player(board, city), className("OperationsExpert"){}
       /*Builds a research lab in current city without the Cost of current city's card.*/
        void build() override;
        /*Returns this player role.*/
        string role() override{return className;}
    };

}

#endif //EX4_A_OPERATIONSEXPERT_HPP
