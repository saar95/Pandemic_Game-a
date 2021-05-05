#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <set>

namespace pandemic{
	class Scientist: public Player{
		int num;
	
		public:
			Scientist(Board& board,City c,int num):Player(board,c,"Scientist"),num(num){}
			Player& discover_cure(Color color);
	};	
	
}


