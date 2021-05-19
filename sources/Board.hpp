#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#include "City.hpp"
#include <unordered_map>
#include <vector>
#include "CityContainer.hpp"


namespace pandemic{
    class Board {
    private:
        std::unordered_map<City,CityContainer> world;
    
    public:
        bool blueCure;
        bool yellowCure;
        bool blackCure;
        bool redCure;

    public:
        /*Constructor.*/
        Board();
        /*Returns the city name in string format.*/
        std::string getCityName (City city);
        /*Returns given city's color. */
        Color getColor (City city);
        /*Returns given city's disease level.*/
        int getDiseaseLevel (City city);
        /*Returns given city's size.*/
        size_t getCitySize (City city);
        /*Returns whether given city has a research lab.*/
        bool hasResearchLab(City city);
        /*Return whether two cities are neighbors.*/
        bool isConnected(City c1, City c2);
        /*Insert an integer to determines city disease level.*/
        int& operator[] (City city); 
        /*Returns disease level if given city.*/
        int operator[] (City city) const;
        friend std::ostream &operator<<(std::ostream &os, const Board &board);
        /*Returns if there is a disease somwhere in the map.*/
        bool is_clean();
        /*Remove all the cures from the map - used for QA.*/
        void remove_cures();
    
    private:
        void lowerDiseaseLevel(City city);
        void nullifyDiseaseLevel(City city);
        void build(City city);

    friend class Medic;
    friend class Virologist;
    friend class Player;
    friend class FieldDoctor;
    friend class OperationsExpert;
    };
}

#endif //UNTITLED_BOARD_H
