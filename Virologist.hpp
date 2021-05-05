#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <set>

namespace pandemic{
	class Virologist: public Player{
	
		public:
			Virologist(Board& board,City c):Player(board,c,"Virologist"){}
			Player& treat(City c);
	};	
	
}


