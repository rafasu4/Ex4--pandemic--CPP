#include "OperationsExpert.hpp"

using namespace std;
namespace pandemic {
    void OperationsExpert::build() {
        if ((!board.hasResearchLab(currentCity))) {
            board.build(currentCity);
        }
    }
}