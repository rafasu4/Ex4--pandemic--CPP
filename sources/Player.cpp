
#include "Player.hpp"
#include <iostream>

using namespace std;
namespace pandemic {

    bool Player::removeCards(size_t indexStart, size_t indexEnd, int n) {
        int counter = 0;
        //going over the given indexes
        for (size_t i = indexStart; i < indexEnd; i++) {
            if (cityCards.at(i)) {
                counter++;
            }
            if (counter == n) {
                break;
            }
        }
        //if there isn't enugh cards
        if (counter < n) {
            return false;
        }
        //removing cards
        for (size_t i = indexStart; i < indexEnd; i++) {
            if (cityCards.at(i)) {
                cityCards.at(i) = false;
                counter--;
            }
            if (counter == 0) {
                break;
            }
        }
        return true;
    }

    Player &Player::drive(City city) {
        //if directly connected - drive with no cost
        if (board.isConnected(currentCity, city)) {
            currentCity = city;
            return *this;
        }
        string message = board.getCityName(currentCity) + " and " + board.getCityName(city) + " aren't neighbors!";
        throw std::invalid_argument(message);
    }

    void Player::fly(City city, City card) {
        //if cityination is same as source
        if (currentCity == city) {
            string message = "Can't fly from the city to itself!";
            throw std::invalid_argument(message);
        }
        //if has the right card - use it and discard
        if (cityCards.at(board.getCitySize(card))) { 
            currentCity = city;
            cityCards.at(board.getCitySize(card)) = false;//discard
        } else {
            string message = role() + " doesn't have a " + board.getCityName(card) + " card!";
            throw std::invalid_argument(message);
        }
    }

    Player &Player::fly_direct(City city) {
        fly(city, city);
        return *this;
    }

    Player &Player::fly_charter(City city) {
        fly(city, currentCity);
        return *this;
    }

    Player &Player::fly_shuttle(City city) {
        if (currentCity == city) {
            string message = "Can't fly from the city to itself";
            throw std::invalid_argument(message);
        }
        //if one of the cities doesn't have a research lab
        if (!board.hasResearchLab(currentCity) || !board.hasResearchLab(city)) {
            string message = "Illegal action! There isn't a research lab in one of the cities!";
            throw std::invalid_argument(message);
        }
        currentCity = city;
        return *this;
    }

    void Player::build() {
        //if has the current city card
        if (cityCards.at(board.getCitySize(currentCity))) {
            //if there isn't a reserach lab build, otherwise - do nothing
            if (!board.hasResearchLab(currentCity)) {
                board.build(currentCity);
                cityCards.at(board.getCitySize(currentCity)) = false;//discard
            }
        } else {
            string message = "Illegal action! doesn't have a " + board.getCityName(currentCity) + " card!";
            throw std::invalid_argument(message);
        }
    }


    Player &Player::take_card(City city) {
        cityCards.at(board.getCitySize(city)) = true;
        return *this;
    }

    void Player::discover_cure(Color color) {
        //if have a reserch lab
        if (board.hasResearchLab(currentCity)) {
            bool flag = false;
            switch (color) {
                case Blue:
                    //if a cure was found for this color - no need for action
                    if (board.blueCure) {
                        return; 
                    }
                    board.blueCure = flag = removeCards(lower_blue, higher_blue, DISCOVER_CARD_COST);
                    break;
                case Yellow:
                    //if a cure was found for this color - no need for action
                    if (board.yellowCure) {
                        return; 
                    }
                    board.yellowCure = flag = removeCards(lower_yellow, higher_yellow, DISCOVER_CARD_COST);
                    break;
                case Black:
                    //if a cure was found for this color - no need for action
                    if (board.blackCure) {
                        return;
                    }
                    board.blackCure = flag = removeCards(lower_black, higher_black, DISCOVER_CARD_COST);
                    break;
                case Red:
                    //if a cure was found for this color - no need for action
                    if (board.redCure) {
                        return; 
                    }
                    board.redCure = flag = removeCards(lower_red, higher_red, DISCOVER_CARD_COST);
                    break;
            }
            if (!flag) {
                string message = "Illegal action! Doesn't have 5 cards!";
                throw std::invalid_argument(message);
            }
        } else {
            string message = "Current city " + board.getCityName(currentCity) + " doesn't have a research station!";
            throw std::invalid_argument(message);
        }
    }

    Player &Player::treat(City city) {
        //if not in the given city
        if (city != currentCity) {
            string message = "Must be in the city for this action!";
            throw std::invalid_argument(message);
        }
        Color color = board.getColor(city);
        //if there is no disease
        if (board.getDiseaseLevel(city) == 0) {
            string message = "Current city is already heald!";
            throw std::invalid_argument(message);
        }
        switch (color) {
            case Blue:
                //if cure was found - lower disease level to zero
                if (!board.blueCure) {
                    board.lowerDiseaseLevel(city);
                } else {
                    board.nullifyDiseaseLevel(city);
                }
                break;

            case Yellow:
                //if cure was found - lower disease level to zero
                if (!board.yellowCure) {
                    board.lowerDiseaseLevel(city);
                } else {
                    board.nullifyDiseaseLevel(city);
                }
                break;

            case Black:
                //if cure was found - lower disease level to zero
                if (!board.blackCure) {
                    board.lowerDiseaseLevel(city);
                } else {
                    board.nullifyDiseaseLevel(city);
                }
                break;

            case Red:
                //if cure was found - lower disease level to zero
                if (!board.redCure) {
                    board.lowerDiseaseLevel(city);
                } else {
                    board.nullifyDiseaseLevel(city);
                }
                break;
        }
        return *this;
    }
    
 void Player::remove_cards() {
        for (size_t i = lower_blue; i < higher_red + 1; i++) {
            cityCards.at(i) = false;
        }
    }
}