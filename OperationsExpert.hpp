#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <set>

namespace pandemic{
	class OperationsExpert: public Player{
		public:
			OperationsExpert(Board& board,City c):Player(board,c,"OperationsExpert"){}
			Player& build();
				
	};	
	
}


