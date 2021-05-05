#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <set>

namespace pandemic{
	class Medic: public Player{
	
		public:
			Medic(Board& board,City c):Player(board,c,"Medic"){}
			Player& treat(City c);
	};	
	
}


