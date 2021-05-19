#include "Dispatcher.hpp"

using namespace std;
namespace pandemic {
    Dispatcher &Dispatcher::fly_direct(City city) {
        //if the destination same as current city - an error
           if(currentCity == city){
             string message = "Can't fly from city to itself!";
             throw message;
         }
        if (board.hasResearchLab(currentCity)){
            currentCity = city;
        }
        else{
            Player::fly(city, city);
        }
        return *this;
    }
}