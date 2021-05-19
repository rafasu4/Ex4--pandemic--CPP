#include "FieldDoctor.hpp"
using namespace std;
namespace pandemic {
    FieldDoctor &FieldDoctor::treat(City city) {
        //if the given city is current city - same action as player
        if(currentCity == city){
            Player::treat(city);
        }
        if (city != currentCity && !board.isConnected(currentCity,city)) {
            string message = "Illegal action! " + board.getCityName(city) + " isn't current city or one of its neighbors!\n";
            throw std::invalid_argument(message);
        }
        Color color = board.getColor(city);
        if (board.getDiseaseLevel(city) == 0) {
            string message = "City is already cured!\n";
            throw std::invalid_argument(message);
        }
        switch (color) {
            case Blue:
                //if a cure was found - nullify disease level
                if (board.blueCure) {
                    board.nullifyDiseaseLevel(city);
                } else {
                    board.lowerDiseaseLevel(city);
                }
                break;

            case Yellow:
                //if a cure was found - nullify disease level
                if (board.yellowCure) {
                    board.nullifyDiseaseLevel(city);
                } else {
                    board.lowerDiseaseLevel(city);
                }
                break;

            case Black:
                //if a cure was found - nullify disease level
                if (board.blackCure) {
                    board.nullifyDiseaseLevel(city);
                } else {
                    board.lowerDiseaseLevel(city);
                }
                break;

            case Red:
                //if a cure was found - nullify disease level
                if (board.redCure) {
                    board.nullifyDiseaseLevel(city);
                } else {
                    board.lowerDiseaseLevel(city);
                }
                break;
        }
        return *this;
    }
}