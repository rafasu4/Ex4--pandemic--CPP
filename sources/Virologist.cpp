#include "Virologist.hpp"


using namespace std;
namespace pandemic {
    Virologist &Virologist::treat(City city) {
        if (cityCards.at(city) || currentCity == city) {
            Color c = board.getColor(city);
            if (board.getDiseaseLevel(city) == 0) {
                string message =
                        "Current city's level of disease is 0!";
                throw std::invalid_argument(message);
            }
            switch (c) {
                case Blue:
                    if (!board.blueCure) {
                        board.lowerDiseaseLevel(city);
                    } else {
                        board.nullifyDiseaseLevel(city);
                    }
                    break;
                case Yellow:
                    if (!board.yellowCure) {
                        board.lowerDiseaseLevel(city);
                    } else {
                        board.nullifyDiseaseLevel(city);
                    }
                    break;
                case Black:
                    if (!board.blackCure) {
                        board.lowerDiseaseLevel(city);
                    } else {
                        board.nullifyDiseaseLevel(city);
                    }
                    break;
                case Red:
                    if (!board.redCure) {
                        board.lowerDiseaseLevel(city);
                    } else {
                        board.nullifyDiseaseLevel(city);
                    }
                    break;
            }
        } else {
            string message =
                    "You don't have " + board.getCityName(city) + " card!";
            throw std::invalid_argument(message);
        }
        return *this;
    }
}
