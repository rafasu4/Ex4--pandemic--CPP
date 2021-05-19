#include "Medic.hpp"

using namespace std;
namespace pandemic {

    

    Medic &Medic::drive(City other) {
        Player::drive(other);
        ability(other);
        return *this;
    }

    Medic &Medic::fly_direct(City dest_city) {
        Player::fly_direct(dest_city);
        ability(dest_city);
        return *this;
    }

    Medic &Medic::fly_charter(City dest_city) {
        Player::fly_charter(dest_city);
        ability(dest_city);
        return *this;
    }

    Medic &Medic::fly_shuttle(City dest_city) {
        Player::fly_shuttle(dest_city);
        ability(dest_city);
        return *this;
}

Medic &Medic::treat(City city) {
    if (city != currentCity) {
        string message = board.getCityName(city) + " must be current city!\n";
        throw std::invalid_argument(message);
    }
    if (board.getDiseaseLevel(city) == 0) {
        string message = "City is already cured!\n";
        throw std::invalid_argument(message);
    }
    board.nullifyDiseaseLevel(city);
    return *this;
}

void Medic::ability(City city){
        Color color = board.getColor(city);
        switch (color)
        {
        case Blue:
            //if a cure was found for this color - nullify disease level (medic)
            if(board.blueCure){
                board.nullifyDiseaseLevel(city);
            }
            break;
        
        case Yellow:
            //if a cure was found for this color - nullify disease level (medic)
            if(board.yellowCure){
                board.nullifyDiseaseLevel(city);
            }
            break;

            case Black:
            //if a cure was found for this color - nullify disease level (medic)
            if(board.blackCure){
                board.nullifyDiseaseLevel(city);
            }
            break;

            case Red:
            //if a cure was found for this color - nullify disease level (medic)
            if(board.redCure){
                board.nullifyDiseaseLevel(city);
            }
            break;
        }
    
    }
}