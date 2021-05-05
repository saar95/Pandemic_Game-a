#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <set>

namespace pandemic{
	class FieldDoctor: public Player{
	
		public:
			FieldDoctor(Board& board,City c):Player(board,c,"FieldDoctor"){}
			Player& treat(City c);
	};	
	
}


