//
// Created by stycks on 04/05/2021.
//

#ifndef EX4_A_FIELDDOCTOR_HPP
#define EX4_A_FIELDDOCTOR_HPP

#include "Player.hpp"

namespace pandemic {
/*This class represents a specific type of a player. FieldDoctor special ability: use "treat" not just in the current city, but also in it's neighbors (without throwing city's card).*/
    class FieldDoctor : public Player{
        string className;
    public:
        /*Constructor.*/
        FieldDoctor(Board& board, City city): pandemic::Player(board, city), className("FieldDoctor"){}
        /*Lowers current city's or one of its neighbors disease level by one.
         * Note: in case cure was already found, this action will lower current city's disease level to 0.
         * Note: this action is illegal in case current city's disease level is 0. */
        FieldDoctor &treat(City city) override;
        /*Returns this player role.*/
        string role() override{return className;}
    };
}

#endif //EX4_A_FIELDDOCTOR_HPP
