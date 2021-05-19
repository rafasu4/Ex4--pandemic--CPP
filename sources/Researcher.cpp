#include "Researcher.hpp"

using namespace std;
namespace pandemic {
    void Researcher::discover_cure(Color color) {
        bool flag = false;
        switch (color) {
            case Blue:
                //if a cure was found for the given color - no action needed
                if (board.blueCure) {
                    return; 
                }
                board.blueCure = flag = removeCards(lower_blue, higher_blue, DISCOVER_CARD_COST);
                break;

            case Yellow:
                //if a cure was found for the given color - no action needed
                if (board.yellowCure) {
                    return; 
                }
                board.yellowCure = flag = removeCards(lower_yellow, higher_yellow, DISCOVER_CARD_COST);
                break;

            case Black:
                //if a cure was found for the given color - no action needed
                if (board.blackCure) {
                    return; 
                }
                board.blackCure = flag = removeCards(lower_black, higher_black, DISCOVER_CARD_COST);
                break;

            case Red:
                //if a cure was found for the given color - no action needed
                if (board.redCure) {
                    return; 
                }
                board.redCure = flag = removeCards(lower_red, higher_red, DISCOVER_CARD_COST);
                break;
        }
        if (!flag) {
            string message = "You don't have 5 cards!";
            throw std::invalid_argument(message);
        }
    }
}