#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <set>

namespace pandemic{
	class GeneSplicer: public Player{
	
		public:
			GeneSplicer(Board& board,City c):Player(board,c,"GeneSplicer"){}
			Player& discover_cure(Color color);
	};	
	
}


