#include "GeneSplicer.hpp"
using namespace std;
namespace pandemic {
    void GeneSplicer::discover_cure(Color color) {
        if (color==Blue && board.blueCure) {
            return;
        }
        if (color==Yellow && board.yellowCure) {
            return;
        }
        if (color==Black && board.blackCure) {
            return;
        }
        if (color==Red && board.redCure) {
            return;
        }
        if (!board.hasResearchLab(currentCity)){
            string message = "Current city " + board.getCityName(currentCity) + " doesn't have a research station!";
            throw std::invalid_argument(message);
        }
        int counter=0;
        for (size_t i=lower_blue; i<higher_red+1&&counter!=DISCOVER_CARD_COST; i++){
            if (cityCards.at(i)) {
                counter++;
            }
        }
        if (counter<DISCOVER_CARD_COST) {
            string message = "You don't have 5 cards!";
            throw std::invalid_argument(message);
        }
        for (size_t i=lower_blue; i<higher_red+1&&counter!=0; i++){
            if (cityCards.at(i)) {
                cityCards.at(i)= false;
                counter--;
            }
        }
        if (color==Blue) {
            board.blueCure= true;
            return;
        }
        if (color==Yellow) {
            board.yellowCure= true;
            return;
        }if (color==Black) {
            board.blackCure= true;
            return;
        }if (color==Red) {
            board.redCure= true;
            return;
        }
    }
}