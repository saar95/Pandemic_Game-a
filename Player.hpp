#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <stdexcept>
#include <set>
#include <string>

namespace pandemic{
	class Player{
		protected:
			Board board;
			std::set<City> city_cards;		
			City c_location;
			std::string m_role;

		public:
			Player(Board& board,City c,std::string role):board(board),c_location(c),m_role(role){}
			std::string role(){
				return this->m_role;
			}
			Player& take_card(City c);
			Player& drive(City c);
			virtual Player& fly_direct(City c);
			Player& fly_charter(City c);
			Player& fly_shuttle(City c);
			virtual Player& build();
			virtual Player& treat(City c);
			virtual Player& discover_cure(Color color);
			
	};	
	
}


