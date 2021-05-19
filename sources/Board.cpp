#include "Board.hpp"
#include <iostream>
using namespace std;
namespace pandemic{

    pandemic::Board::Board():blueCure(false), yellowCure(false), blackCure(false), redCure(false){
        //blue cities
        world[Atlanta] =CityContainer (Blue,"Atlanta",size_t(Atlanta), Chicago,Miami,Washington);
        world[Chicago]=CityContainer(Blue,"Chicago",size_t(Chicago), SanFrancisco,LosAngeles,MexicoCity,Atlanta,Montreal);
        world[Essen]=CityContainer(Blue,"Essen" ,size_t(Essen),London,Paris,Milan,StPetersburg);
        world[London]=CityContainer(Blue,"London",size_t(London), NewYork,Madrid,Essen,Paris);
        world[Madrid]=CityContainer(Blue,"Madrid",size_t(Madrid),London,NewYork,Paris,SaoPaulo,Algiers);
        world[Milan]=CityContainer(Blue,"Milan",size_t(Milan), Essen,Paris,Istanbul);
        world[Montreal]=CityContainer(Blue,"Montreal",size_t(Montreal),Chicago,Washington,NewYork);
        world[NewYork]=CityContainer(Blue,"NewYork",size_t(NewYork), Montreal,Washington,London,Madrid);
        world[Paris]=CityContainer(Blue,"Paris",size_t(Paris),Algiers,Essen,Madrid,Milan,London);
        world[SanFrancisco]=CityContainer(Blue,"SanFrancisco",size_t(SanFrancisco),LosAngeles,Chicago,Tokyo,Manila);
        world[StPetersburg]=CityContainer(Blue,"StPetersburg",size_t(StPetersburg),Essen,Istanbul,Moscow);
        world[Washington]=CityContainer(Blue,"Washington",size_t(Washington),Atlanta,NewYork,Montreal,Miami);
        //yellow cities
        world[Bogota]=CityContainer(Yellow,"Bogota",size_t(Bogota),MexicoCity,Lima,Miami,SaoPaulo,BuenosAires);
        world[BuenosAires]=CityContainer(Yellow,"BuenosAires",size_t(BuenosAires),Bogota,SaoPaulo);
        world[Johannesburg]=CityContainer(Yellow,"Johannesburg",size_t(Johannesburg),Kinshasa,Khartoum);
        world[Khartoum]=CityContainer(Yellow,"Khartoum",size_t(Khartoum),Lagos,Kinshasa,Johannesburg,Cairo);
        world[Kinshasa]=CityContainer(Yellow,"Kinshasa",size_t(Kinshasa),Lagos,Khartoum,Johannesburg);
        world[Lagos]=CityContainer(Yellow,"Lagos",size_t(Lagos),SaoPaulo,Khartoum,Kinshasa);
        world[Lima]=CityContainer(Yellow,"Lima",size_t(Lima),MexicoCity,Bogota,Santiago);
        world[LosAngeles]=CityContainer(Yellow,"LosAngeles",size_t(LosAngeles),SanFrancisco,Chicago,MexicoCity,Sydney);
        world[MexicoCity]=CityContainer(Yellow,"MexicoCity",size_t(MexicoCity),LosAngeles,Chicago,Miami,Lima,Bogota);
        world[Miami]=CityContainer(Yellow,"Miami",size_t(Miami),Atlanta,MexicoCity,Washington,Bogota);
        world[Santiago]=CityContainer(Yellow,"Santiago",size_t(Santiago),Lima);
        world[SaoPaulo]=CityContainer(Yellow,"SaoPaulo",size_t(SaoPaulo),Bogota,BuenosAires,Lagos,Madrid);
        //black cities
        world[Algiers]=CityContainer(Black,"Algiers",size_t(Algiers),Madrid,Paris,Istanbul,Cairo);
        world[Baghdad]=CityContainer(Black,"Baghdad",size_t(Baghdad),Tehran,Istanbul,Cairo,Riyadh,Karachi);
        world[Cairo]=CityContainer(Black,"Cairo",size_t(Cairo),Algiers,Istanbul,Baghdad,Khartoum,Riyadh);
        world[Chennai]=CityContainer(Black,"Chennai",size_t(Chennai),Mumbai,Delhi,Kolkata,Bangkok,Jakarta);
        world[Delhi]=CityContainer(Black,"Delhi",size_t(Delhi),Tehran,Karachi,Mumbai,Chennai,Kolkata);
        world[Istanbul]=CityContainer(Black,"Istanbul",size_t(Istanbul),Milan,Algiers,StPetersburg,Cairo,Baghdad,Moscow);
        world[Karachi]=CityContainer(Black,"Karachi",size_t(Karachi),Tehran,Baghdad,Riyadh,Mumbai,Delhi);
        world[Kolkata]=CityContainer(Black,"Kolkata",size_t(Kolkata),Delhi,Chennai,Bangkok,HongKong);
        world[Moscow]=CityContainer(Black,"Moscow",size_t(Moscow),StPetersburg,Istanbul,Tehran);
        world[Mumbai]=CityContainer(Black,"Mumbai",size_t(Mumbai),Karachi,Delhi,Chennai);
        world[Riyadh]=CityContainer(Black,"Riyadh",size_t(Riyadh),Baghdad,Cairo,Karachi);
        world[Tehran]=CityContainer(Black,"Tehran",size_t(Tehran),Baghdad,Moscow,Karachi,Delhi);
        //red cities
        world[Bangkok]=CityContainer(Red,"Bangkok",size_t(Bangkok),Kolkata,Chennai,Jakarta,HoChiMinhCity,HongKong);
        world[Beijing]=CityContainer(Red,"Beijing",size_t(Beijing),Shanghai,Seoul);
        world[HoChiMinhCity]=CityContainer(Red,"HoChiMinhCity",size_t(HoChiMinhCity),Jakarta,Bangkok,HongKong,Manila);
        world[HongKong]=CityContainer(Red,"HongKong",size_t(HongKong),Bangkok,Kolkata,HoChiMinhCity,Shanghai,Manila,Taipei);
        world[Jakarta]=CityContainer(Red,"Jakarta",size_t(Jakarta),Chennai,Bangkok,HoChiMinhCity,Sydney);
        world[Manila]=CityContainer(Red,"Manila",size_t(Manila),Taipei,SanFrancisco,HoChiMinhCity,Sydney,HongKong);
        world[Osaka]=CityContainer(Red,"Osaka",size_t(Osaka),Taipei,Tokyo);
        world[Seoul]=CityContainer(Red,"Seoul",size_t(Seoul),Beijing,Shanghai,Tokyo);
        world[Shanghai]=CityContainer(Red,"Shanghai",size_t(Shanghai),Beijing,HongKong,Taipei,Seoul,Tokyo);
        world[Sydney]=CityContainer(Red,"Sydney",size_t(Sydney),Jakarta,Manila,LosAngeles);
        world[Taipei]=CityContainer(Red,"Taipei",size_t(Taipei),Shanghai,HongKong,Osaka,Manila);
        world[Tokyo]=CityContainer(Red,"Tokyo",size_t(Tokyo),Seoul,Shanghai,Osaka,SanFrancisco);
    }

    string Board::getCityName (City city){
        return world.at(city).cityName;
    }

    size_t Board::getCitySize(City city) {
        return world.at(city).citySize;
    }

    Color Board::getColor (City city){
        return world.at(city).c;
    }

    int Board::getDiseaseLevel (City city){
        return world.at(city).level;
    }

    void Board::lowerDiseaseLevel(City city) {
        world.at(city).level--;
    }

    void Board::nullifyDiseaseLevel(City city) {
        world.at(city).level=0;
    }

    bool Board::hasResearchLab(City city){
        return world.at(city).research_station;
    }

    void Board::build(City city){
        world.at(city).research_station=true;
    }

    int& Board::operator[] (City city){ //write
        return world.at(city).level;
    }
    int Board::operator[] (City city) const { //read
        return world.at(city).level;
    }

    std::ostream &operator<<(std::ostream &os, const Board &board){
        string ans;
        for (int i=0; i<board.world.size(); i++){
            CityContainer get = board.world.at(static_cast<City>(i));
            ans+= "City:" + get.cityName+ ", Amount of diseases: " + to_string(get.level) + '\n';
        }
        if (board.blueCure){
            ans+="blue cure has been discovered!\n";
        }
        if (board.yellowCure){
            ans+="yellow cure has been discovered!\n";
        }
        if (board.blackCure){
            ans+="black cure has been discovered!\n";
        }
        if (board.redCure){
            ans+="red cure has been discovered!\n";
        }

        return os << ans;
    }

    bool Board::is_clean(){
        for (int i=0; i<world.size(); i++){
            if (world[ static_cast<City>(i)].level!=0){
                return false;
            }
        }
        return true;
    }

    bool Board::isConnected(City c1, City c2){
        for (auto nei: world.at(c1).connections){
            //if in neighbors list - return true
            if (nei == c2) {
                return true;
            }
        }
        return false;
    }

    void Board::remove_cures(){
        blueCure = false;
        redCure = false; 
        blackCure = false;
        yellowCure = false;
    }
}