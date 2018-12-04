/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, X_to_O)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, O_to_X)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	ASSERT_EQ(obj.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, place_row_too_small_column_too_small)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.placePiece(-1, -2), Invalid);
}

TEST(TicTacToeBoardTest, place_row_too_small_column_too_big)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.placePiece(-1, 3), Invalid);
}

TEST(TicTacToeBoardTest, place_row_too_small_valid_column)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.placePiece(-1, 1), Invalid);
}

TEST(TicTacToeBoardTest, place_row_too_big_column_too_small)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.placePiece(3, -1), Invalid);
}

TEST(TicTacToeBoardTest, place_row_too_big_column_too_big)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.placePiece(3, 3), Invalid);
}

TEST(TicTacToeBoardTest, place_row_too_big_valid_column)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.placePiece(3, 1), Invalid);
}

TEST(TicTacToeBoardTest, place_valid_row_column_too_small)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.placePiece(1, -1), Invalid);
}

TEST(TicTacToeBoardTest, place_valid_row_column_too_big)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.placePiece(1, 3), Invalid);
}

TEST(TicTacToeBoardTest, place_valid_X)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.placePiece(1, 1), X);
}

TEST(TicTacToeBoardTest, place_valid_O)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	ASSERT_EQ(obj.placePiece(1, 1), O);
}

TEST(TicTacToeBoardTest, place_on_used_space)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.placePiece(1, 1);
	ASSERT_EQ(obj.placePiece(1, 1), X);
}

TEST(TicTacToeBoardTest, finished_X_top_row_place)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<3; i++){
		obj.placePiece(0, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.placePiece(1,1), Invalid);
}

TEST(TicTacToeBoardTest, finished_O_top_row_place)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(0, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.placePiece(1,1), Invalid);
}

TEST(TicTacToeBoardTest, finished_X_middle_row_place)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<3; i++){
		obj.placePiece(1, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.placePiece(0,1), Invalid);
}

TEST(TicTacToeBoardTest, finished_O_middle_row_place)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(1, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.placePiece(0,1), Invalid);
}

TEST(TicTacToeBoardTest, finished_X_bottom_row_place)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<3; i++){
		obj.placePiece(2, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.placePiece(1,1), Invalid);
}

TEST(TicTacToeBoardTest, finished_O_bottom_row_place)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(2, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.placePiece(1,1), Invalid);
}

TEST(TicTacToeBoardTest, finished_X_left_column_place)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<3; i++){
		obj.placePiece(i, 0);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.placePiece(1,1), Invalid);
}

TEST(TicTacToeBoardTest, finished_O_left_column_place)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(i, 0);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.placePiece(1,1), Invalid);
}

TEST(TicTacToeBoardTest, finished_X_middle_column_place)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<3; i++){
		obj.placePiece(i, 1);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.placePiece(1,0), Invalid);
}

TEST(TicTacToeBoardTest, finished_O_middle_column_place)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(i, 1);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.placePiece(1,0), Invalid);
}

TEST(TicTacToeBoardTest, finished_X_right_column_place)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<3; i++){
		obj.placePiece(i, 2);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.placePiece(1,1), Invalid);
}

TEST(TicTacToeBoardTest, finished_O_right_column_place)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(i, 2);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.placePiece(1,1), Invalid);
}

TEST(TicTacToeBoardTest, finished_X_top_left_bottom_right_diagonal_place)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<3; i++){
		obj.placePiece(i, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.placePiece(1,2), Invalid);
}

TEST(TicTacToeBoardTest, finished_O_top_left_bottom_right_diagonal_place)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(i, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.placePiece(1,2), Invalid);
}

TEST(TicTacToeBoardTest, finished_X_bottom_left_top_right_diagonal_place)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<3; i++){
		obj.placePiece(2-i, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.placePiece(1,2), Invalid);
}

TEST(TicTacToeBoardTest, finished_O_bottom_left_top_right_diagonal_place)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(2-i, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.placePiece(1,2), Invalid);
}

TEST(TicTacToeBoardTest, get_row_too_small_column_too_small)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.getPiece(-1, -2), Invalid);
}

TEST(TicTacToeBoardTest, get_row_too_small_column_too_big)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.getPiece(-1, 3), Invalid);
}

TEST(TicTacToeBoardTest, get_row_too_small_valid_column)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.getPiece(-1, 1), Invalid);
}

TEST(TicTacToeBoardTest, get_row_too_big_column_too_small)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.getPiece(3, -1), Invalid);
}

TEST(TicTacToeBoardTest, get_row_too_big_column_too_big)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.getPiece(3, 3), Invalid);
}

TEST(TicTacToeBoardTest, get_row_too_big_valid_column)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.getPiece(3, 1), Invalid);
}

TEST(TicTacToeBoardTest, get_valid_row_column_too_small)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.getPiece(1, -1), Invalid);
}

TEST(TicTacToeBoardTest, get_valid_row_column_too_big)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.getPiece(1, 3), Invalid);
}

TEST(TicTacToeBoardTest, get_empty_space)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.getPiece(1, 1), Blank);
}


TEST(TicTacToeBoardTest, get_valid_X)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.placePiece(1, 1);
	ASSERT_EQ(obj.getPiece(1, 1), X);
}

TEST(TicTacToeBoardTest, get_valid_O)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	obj.placePiece(1, 1);
	ASSERT_EQ(obj.getPiece(1, 1), O);
}

TEST(TicTacToeBoardTest, game_not_over_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	ASSERT_EQ(obj.getWinner(), Invalid);
}

TEST(TicTacToeBoardTest, game_over_no_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
			obj.placePiece(i, j);
		}
	}
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(2, i);
	}
	ASSERT_EQ(obj.getWinner(), Blank);
}

TEST(TicTacToeBoardTest, X_top_row_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<3; i++){
		obj.placePiece(0, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.getWinner(), X);
}

TEST(TicTacToeBoardTest, O_top_row_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(0, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.getWinner(), O);
}

TEST(TicTacToeBoardTest, X_middle_row_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<3; i++){
		obj.placePiece(1, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.getWinner(), X);
}

TEST(TicTacToeBoardTest, O_middle_row_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(1, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.getWinner(), O);
}

TEST(TicTacToeBoardTest, X_bottom_row_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<3; i++){
		obj.placePiece(2, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.getWinner(), X);
}

TEST(TicTacToeBoardTest, O_bottom_row_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(2, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.getWinner(), O);
}

TEST(TicTacToeBoardTest, X_left_column_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<3; i++){
		obj.placePiece(i, 0);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.getWinner(), X);
}

TEST(TicTacToeBoardTest, O_left_column_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(i, 0);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.getWinner(), O);
}

TEST(TicTacToeBoardTest, X_middle_column_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<3; i++){
		obj.placePiece(i, 1);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.getWinner(), X);
}

TEST(TicTacToeBoardTest, O_middle_column_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(i, 1);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.getWinner(), O);
}

TEST(TicTacToeBoardTest, X_right_column_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<3; i++){
		obj.placePiece(i, 2);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.getWinner(), X);
}

TEST(TicTacToeBoardTest, O_right_column_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(i, 2);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.getWinner(), O);
}

TEST(TicTacToeBoardTest, X_top_left_bottom_right_diagonal_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<3; i++){
		obj.placePiece(i, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.getWinner(), X);
}

TEST(TicTacToeBoardTest, O_top_left_bottom_right_diagonal_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(i, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.getWinner(), O);
}

TEST(TicTacToeBoardTest, X_bottom_left_top_right_diagonal_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	for(int i=0; i<3; i++){
		obj.placePiece(2-i, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.getWinner(), X);
}

TEST(TicTacToeBoardTest, O_bottom_left_top_right_diagonal_winner)
{
	TicTacToeBoard obj = TicTacToeBoard();
	obj.toggleTurn();
	for(int i=0; i<3; i++){
		obj.placePiece(2-i, i);
		obj.toggleTurn();
	}
	ASSERT_EQ(obj.getWinner(), O);
}
