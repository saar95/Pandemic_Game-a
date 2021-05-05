

#include <stdexcept>
#include <set>
#include "Medic.hpp"
#include "Player.hpp"
#include "Scientist.hpp"
#include "Researcher.hpp"
#include "Dispatcher.hpp"
#include "OperationsExpert.hpp"
#include "GeneSplicer.hpp"
#include "FieldDoctor.hpp"
#include "Virologist.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "doctest.h"
#include <iostream>

using namespace std;
using namespace pandemic;

TEST_CASE("cheking operator []"){
	Board board;
	CHECK_NOTHROW(board[City::Algiers]=5);
	CHECK(board[City::Algiers]==5);
	CHECK_NOTHROW(board[City::Santiago]=9);
	CHECK(board[City::Santiago]==9);
	CHECK_NOTHROW(board[City::Algiers]-=3);
	CHECK(board[City::Algiers]==2);
	CHECK_NOTHROW(board[City::Santiago]+=10);
	CHECK(board[City::Santiago]==19);
	CHECK_NOTHROW(board[City::Santiago]=0);
	CHECK(board[City::Santiago]==0);


}
TEST_CASE("drive function"){
	Board board;
	GeneSplicer genesplicer{board,City::Taipei};
	FieldDoctor fielddoctor{board,City::Baghdad};
	OperationsExpert operationsexpert{board,City::Paris};
	Virologist virologist{board,City::SaoPaulo};
	Scientist scientist{board,City::SanFrancisco,2};
	Dispatcher dispatcher{board,City::Sydney};

	CHECK_NOTHROW(genesplicer.drive(City::Osaka));
	CHECK_NOTHROW(fielddoctor.drive(City::Tehran));
	CHECK_NOTHROW(operationsexpert.drive(City::London));
	CHECK_NOTHROW(virologist.drive(City::Lagos));
	CHECK_NOTHROW(scientist.drive(City::Chicago));
	CHECK_NOTHROW(dispatcher.drive(City::Manila));
	CHECK_THROWS(genesplicer.drive(City::Algiers));
	CHECK_THROWS(fielddoctor.drive(City::NewYork));
	CHECK_THROWS(operationsexpert.drive(City::Taipei));
	CHECK_THROWS(virologist.drive(City::Madrid));
	CHECK_THROWS(scientist.drive(City::Paris));
	CHECK_THROWS(dispatcher.drive(City::Tokyo));
	CHECK_THROWS(genesplicer.drive(City::Atlanta));
	CHECK_THROWS(fielddoctor.drive(City::LosAngeles));
	CHECK_THROWS(operationsexpert.drive(City::Tokyo));
	CHECK_THROWS(virologist.drive(City::Miami));
	CHECK_THROWS(scientist.drive(City::Milan));
	CHECK_THROWS(dispatcher.drive(City::Moscow));
	
}
TEST_CASE("fly/build function"){
	Board board;
	OperationsExpert operationsexpert_p{board,City::Paris};
	Dispatcher dispatcher_p{board,City::Paris};
	OperationsExpert operationsexpert_s{board,City::Sydney};
	Dispatcher dispatcher_s{board,City::Sydney};
	OperationsExpert operationsexpert_l{board,City::London};
	Dispatcher dispatcher_l{board,City::London};
	FieldDoctor fielddoctor{board,City::Baghdad};
	CHECK_NOTHROW(operationsexpert_l.build());
	CHECK_NOTHROW(operationsexpert_p.build());
	CHECK_NOTHROW(operationsexpert_s.build());
	CHECK_THROWS(fielddoctor.build());
	CHECK_NOTHROW(dispatcher_l.fly_direct(City::Sydney));
	CHECK_NOTHROW(dispatcher_p.fly_direct(City::London));
	CHECK_NOTHROW(dispatcher_s.fly_direct(City::Paris));
	CHECK_NOTHROW(dispatcher_s.fly_direct(City::Sydney));
	CHECK_NOTHROW(dispatcher_s.fly_direct(City::London));
	CHECK_THROWS(dispatcher_l.fly_direct(City::Algiers));
	CHECK_THROWS(dispatcher_p.fly_direct(City::Atlanta));
	CHECK_THROWS(dispatcher_s.fly_direct(City::LosAngeles));
	
}
TEST_CASE("discover_cure function"){
	Board board;
	GeneSplicer genesplicer{board,City::Taipei};
	Researcher researcher{board,City::LosAngeles};
	Medic medic{board,City::Miami};
	Scientist scientist{board,City::Mumbai,3};
	CHECK_NOTHROW(researcher.discover_cure(Color::Red));
	CHECK_NOTHROW(researcher.discover_cure(Color::Yellow));
	CHECK_NOTHROW(medic.discover_cure(Color::Red));
	CHECK_NOTHROW(medic.discover_cure(Color::Blue));
	CHECK_NOTHROW(scientist.discover_cure(Color::Black));
	CHECK_THROWS(genesplicer.discover_cure(Color::Black));
	CHECK_THROWS(genesplicer.discover_cure(Color::Red));



}

TEST_CASE("treat function"){
	Board board;
	CHECK_NOTHROW(board[City::Paris]=2);
	CHECK_NOTHROW(board[City::Algiers]=3);
	CHECK_NOTHROW(board[City::London]=4);
	FieldDoctor fielddoctor_1{board,City::Paris};
	FieldDoctor fielddoctor_2{board,City::Algiers};
	FieldDoctor fielddoctor_3{board,City::London};
	CHECK_NOTHROW(fielddoctor_1.treat(City::Paris));
	CHECK_NOTHROW(fielddoctor_2.treat(City::Algiers));
	CHECK_NOTHROW(fielddoctor_3.treat(City::London));
	CHECK_THROWS(fielddoctor_1.treat(City::LosAngeles));
	CHECK_THROWS(fielddoctor_1.treat(City::Madrid));
	CHECK_THROWS(fielddoctor_1.treat(City::Miami));
	CHECK(board[City::Paris]==2);
	CHECK(board[City::Algiers]==3);
	CHECK(board[City::London]==4);
}


	

