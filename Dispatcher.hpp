#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <set>

namespace pandemic{
	class Dispatcher: public Player{
	
		public:
			Dispatcher(Board& board,City c):Player(board,c,"Dispatcher"){}
			Player& fly_direct(City c);
	};	
	
}


