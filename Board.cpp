#include "Board.hpp"
using namespace std;
using namespace pandemic;

bool Board::is_clean(){
	return true;
}
bool Board::is_discover_cure(City c){
	return true;
}

void Board::remove_cures(){}

ostream& pandemic::operator<<(ostream& os, const Board& board){
	return os;
}
int& Board::operator[](City c) {
    return sick_level[c];
}

bool Board::is_connected(City c_1,City c_2){
	return true;
}

bool Board::is_research_city(City c){
	return true;
}



			
		
