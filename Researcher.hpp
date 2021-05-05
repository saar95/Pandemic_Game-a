#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <set>

namespace pandemic{
	class Researcher: public Player{
	
		public:
			Researcher(Board& board,City c):Player(board,c,"Researcher"){}
			Player& discover_cure(Color color);
	};	
	
}


