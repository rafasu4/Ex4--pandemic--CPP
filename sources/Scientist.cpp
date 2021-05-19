#include "Scientist.hpp"


using namespace std;
namespace pandemic {
    void Scientist::discover_cure(Color color) {
        if (board.hasResearchLab(currentCity)) {
            bool res= false;
            switch (color) {
                case Blue:
                    if (board.blueCure) {
                        return; 
                    }
                    board.blueCure = res = removeCards(lower_blue, higher_blue, ability);
                    break;
                case Yellow:
                    if (board.yellowCure) {
                        return; 
                    }
                    board.yellowCure = res = removeCards(lower_yellow, higher_yellow, ability);
                    break;
                case Black:
                    if (board.blackCure) {
                        return; 
                    }
                    board.blackCure = res = removeCards(lower_black, higher_black, ability);
                    break;
                case Red:
                    if (board.redCure) {
                        return;
                    }
                    board.redCure = res = removeCards(lower_red, higher_red, ability);
                    break;
            }
            if (!res) {
                string message = "You don't have " + to_string(ability)+" cards!";
                throw std::invalid_argument(message);
            }
        } else {
            string message = "Current city " + board.getCityName(currentCity) + " doesn't have a research station!";
            throw std::invalid_argument(message);
        }
    }
    void Scientist::remove_cards(){
        int temp = ability;
        Player::remove_cards();
        ability=temp;
    }
}

