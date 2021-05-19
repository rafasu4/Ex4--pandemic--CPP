//
// Created by stycks on 04/05/2021.
//

#ifndef EX4_A_VIROLOGIST_HPP
#define EX4_A_VIROLOGIST_HPP
#include "Player.hpp"

namespace pandemic {
/*This class represents a specific type of a player. Virologist special ability: use "treat" in any city in the world, even if it's not its current city.
 * Cost that city's card.  */
    class Virologist : public Player {
        string className;
    public:
        /*Constructor.*/
        Virologist(Board& board, City city): pandemic::Player(board, city),className("Virologist"){}
        /*Lowers city's disease level by one. If it's not player's current city, cost that city card.
         * Note: in case cure was already found, this action will lower current city's disease level to 0.
         * Note: this action is illegal in case the city's disease level is 0. */
        Virologist &treat(City city) override;
        /*Returns this player role.*/
        string role() override{return className;}
    };
}
#endif //EX4_A_VIROLOGIST_HPP
