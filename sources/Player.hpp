#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include "City.hpp"
#include "Board.hpp"
/*With the help of Neta Ruth*/

using namespace std;
namespace pandemic {
    class Player {
    protected:
        /*Search in map.*/
        const size_t lower_blue = 0;
        /*Search in map.*/
        const size_t higher_blue = 12;
        /*Search in map.*/
        const size_t lower_yellow = 12;
        /*Search in map.*/
        const size_t higher_yellow = 24;
        /*Search in map.*/
        const size_t lower_black = 24;
        /*Search in map.*/
        const size_t higher_black = 36;
        /*Search in map.*/
        const size_t lower_red = 36;
        /*Search in map.*/
        const size_t higher_red = 48;
        /*Cost for using dicover_cure.*/
        const int DISCOVER_CARD_COST = 5;
        /*The current board player is playing on.*/
        Board &board;
        /*Current location.*/
        City currentCity;
        /*Cards in players hand.*/
        std::array<bool,49> cityCards;
        


    public:
    /*Constructor.*/
        Player(Board &board, City currentCity) : board(board), currentCity(currentCity) {
            for (size_t i = 0; i < 49; i++) cityCards.at(i) = false;
        }
     /*Move from current city to one of it's neighbors.*/
        virtual Player & drive(City city);
        /*Move from current city to city that player has a card of it. Cost that city's card*/
        virtual Player &fly_direct(City city);
        /*Move from current city to any city. Cost current city's card*/
        virtual Player &fly_charter(City city);
        /*Move to any other city that has a research lab, if current city has one.*/
        virtual Player &fly_shuttle(City city);
        /*Builds a research lab in current city. Cost current city's card.*/
        virtual void build();
        /*Discovers a cure to a given color type(doesn't have to be the same as city's). Player must have a research lab in current city.
         * Cost 5 city card of the same color.
         * Note: in case cure was already found, nothing will happen.*/
        virtual void discover_cure(Color color);
        /*Lowers current city's disease level by one.
         * Note: in case cure was already found, this action will lower current city's disease level to 0.
         * Note: this action is illegal in case current city's disease level is 0. */
        virtual Player &treat(City city);
        /*Takes a given city's card to the player hand.
         * Note: each city has only one card.
         * Note: if player has this city's card, nothing will happen.*/
        Player &take_card(City city);
        virtual void remove_cards();

        virtual std::string role() = 0;

    protected:
        /*Moves to destination with the given card as a cost. */
        void fly(City city, City card);
        /*Removes all cards from player's hand.*/
        bool removeCards(size_t indexStart, size_t indexEnd, int n);
    };
}

#endif //UNTITLED_PLAYER_H
