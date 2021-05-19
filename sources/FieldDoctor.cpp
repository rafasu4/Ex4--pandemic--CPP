#include "FieldDoctor.hpp"
using namespace std;
namespace pandemic {
    FieldDoctor &FieldDoctor::treat(City city) {
        if (city != currentCity && !board.isConnected(currentCity, city)) {
            string message ="Illegal action! " + board.getCityName((city)) + " isn't current city or one of its neighbors!\n";
            throw std::invalid_argument(message);
        }
        Color color = board.getColor(city);
        if (board.getDiseaseLevel(city) == 0) {
            string message =
                    "Current city's level of disease is 0!";
            throw std::invalid_argument(message);
        }
        switch (color) {
            case Blue:
                //if has cure for this disease color - nullify to zero
                if (board.blackCure) {
                    board.nullifyDiseaseLevel(city);
                } else {
                    board.lowerDiseaseLevel(city);
                }
                break;

            case Yellow:
                //if has cure for this disease color - nullify to zero
                if (board.yellowCure) {
                    board.nullifyDiseaseLevel(city);
                } else {
                    board.lowerDiseaseLevel(city);
                }
                break;

            case Black:
                //if has cure for this disease color - nullify to zero
                if (board.blackCure) {
                    board.nullifyDiseaseLevel(city);
                } else {
                    board.lowerDiseaseLevel(city);
                }
                break;

            case Red:
                //if has cure for this disease color - nullify to zero
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