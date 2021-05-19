
#include "City.hpp"
#include <unordered_map>
#include <vector>


namespace pandemic{
    class CityContainer {
    public:
        Color c;
        std::vector<City> connections;
        std::string cityName;
        bool research_station;
        size_t citySize;
        int level; //public so the operator [] could change it
        CityContainer() { //default constructor
            cityName="";
            level=0;
            c=Blue;
            research_station= false;
            connections= std::vector<City>();
        }
        CityContainer(Color color,std::string name,size_t num, City connections1=nullCity, City connections2=nullCity, City connections3=nullCity,
               City connections4=nullCity, City connections5=nullCity, City connections6=nullCity): c(color), cityName(name), level(0), research_station(
                false), citySize(num){
            this->connections.push_back(connections1);
            if (connections2!=nullCity) this->connections.push_back(connections2);
            if (connections3!=nullCity) this->connections.push_back(connections3);
            if (connections4!=nullCity) this->connections.push_back(connections4);
            if (connections5!=nullCity) this->connections.push_back(connections5);
            if (connections6!=nullCity) this->connections.push_back(connections6);
        }

    };
}