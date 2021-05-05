#pragma once
#include "Color.hpp"
#include "City.hpp"
#include <map>
#include <iostream>
#include <set>

namespace pandemic{
	class Board{

		private:
			std::map<City,int> sick_level;
			std::map<City,int> res_station;

		public:
			Board(){}
            int& operator[](City c);
			bool is_discover_cure(City c);
			friend std::ostream& operator<<(std::ostream& os, const Board& board);
			bool is_connected(City c_1,City c_2);
			bool is_clean();
			void remove_cures();
			bool is_research_city(City c);
	};

}