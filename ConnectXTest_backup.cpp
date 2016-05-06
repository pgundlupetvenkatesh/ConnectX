/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"
 
class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(ConnectXTest, atPlacePieceBLACK)
{
	ConnectX cx;
	cx.placePiece(2);
	ASSERT_EQ(2, cx.at(2, 5));
	//cx.showBoard();
}

TEST(ConnectXTest, atPlacePieceEMPTY)
{
	ConnectX cx;
	cx.placePiece(2);
	//ASSERT_FALSE(cx.at(2, 4));
	ASSERT_EQ(0, cx.at(2, 4));
	//cx.showBoard();
}

TEST(ConnectXTest, atPlacePieceWHITE1)
{
	ConnectX cx;
	cx.placePiece(10);
	cx.placePiece(3);
	ASSERT_EQ(1, cx.at(3, 5));
	//ASSERT_EQ(1, cx.at(3, 4));
	//ASSERT_FALSE(cx.at(3, 3));
	//cx.showBoard();
}

TEST(ConnectXTest, atPlacePieceWHITE2)
{
	ConnectX cx;
	cx.placePiece(3);
	cx.placePiece(3);
	//ASSERT_EQ(1, cx.at(3, 5));
	ASSERT_EQ(1, cx.at(3, 4));
	//ASSERT_FALSE(cx.at(3, 3));
	//cx.showBoard();
}

TEST(ConnectXTest, atPlacePieceOutBounds)
{
	ConnectX cx;
	cx.placePiece(8);
	//cx.showBoard();
	ASSERT_EQ(0,cx.at(4, 3));
	ASSERT_EQ(-1,cx.at(8, 5));	//BUG
}

TEST(ConnectXTest, atWidthOutBounds)
{
	ConnectX cx;
	cx.placePiece(6);
	//cx.showBoard();
	ASSERT_EQ(-1,cx.at(9, 5));	//BUG
	//cx.showBoard();
}

TEST(ConnectXTest, atWidthOutBoundsNegative)
{
	ConnectX cx;
	cx.placePiece(4);
	ASSERT_EQ(-1,cx.at(-1, 5));	//BUG
	//cx.showBoard();
}

TEST(ConnectXTest, atHeightOutBounds)
{
	ConnectX cx;
	cx.placePiece(6);
	//cx.showBoard();
	ASSERT_EQ(-1,cx.at(6, 7));
	/*ASSERT_EQ(2,cx.at(6, 5));
	cx.placePiece(6);
	ASSERT_EQ(1,cx.at(6, 4));
	ASSERT_EQ(0,cx.at(6, 3));*/
	//cx.showBoard();
}

TEST(ConnectXTest, atHeightOutBoundsNegative)
{
	ConnectX cx;
	cx.placePiece(5);
	ASSERT_EQ(-1,cx.at(5, -2));
	//cx.showBoard();
}

TEST(ConnectXTest, atOutBoundsBothInvalidNegative)
{
	ConnectX cx;
	cx.placePiece(1);
	ASSERT_EQ(-1,cx.at(-2, -1));
	//cx.showBoard();
}

TEST(ConnectXTest, atPlacePieceBothInvalidPositive)
{
	ConnectX cx;
	cx.placePiece(4);
	ASSERT_EQ(-1,cx.at(8, 7));
	//cx.showBoard();
}

/*TEST(ConnectXTest, atPlacePieceBlack)
{
	ConnectX cx;
	cx.placePiece(1);
	ASSERT_EQ(2,cx.at(1, 5));
	//cx.showBoard();
}

TEST(ConnectXTest, atPlacePieceWhite)
{
	ConnectX cx;
	cx.placePiece(2);
	cx.placePiece(2);
	ASSERT_EQ(1,cx.at(2, 4));
	//cx.showBoard();
}*/

TEST(ConnectXTest, showBoardWidthHeightWinOutbound)
{
	ConnectX cx(8, 8, 5);
	cx.placePiece(7);
	ASSERT_EQ(2,cx.at(7, 7));
	cx.placePiece(0);
	ASSERT_EQ(1,cx.at(0, 7));
	//cx.showBoard();
}

/*TEST(ConnectXTest, showBoardWidthHeightOutbound)
{
	ConnectX cx(8, 8, 2);
	cx.placePiece(0);
	ASSERT_EQ(2,cx.at(0, 7));
	cx.placePiece(1);
	ASSERT_EQ(1,cx.at(1, 7));
	cx.placePiece(1);
	ASSERT_EQ(2,cx.at(1, 6));
	cx.placePiece(10);
	ASSERT_EQ(-1,cx.at(10, 7));
	cx.showBoard();
}*/

TEST(ConnectXTest, showBoardWidthNegative)
{
	ConnectX cx(-1, 3, 2);
	//cx.placePiece(-1);		//BUG
	//ASSERT_EQ(0,cx.at(1, 5));
	//cx.placePiece(1);
	//ASSERT_EQ(2,cx.at(1, 5));
	//cx.showBoard();
}

TEST(ConnectXTest, showBoardHeightZero)
{
	ConnectX cx(1, 0, 2);
	cx.placePiece(6);
	ASSERT_EQ(2,cx.at(6, 5));
	//cx.showBoard();
}

TEST(ConnectXTest, showBoardWinZero)
{
	ConnectX cx(1, 1, 0);
	cx.placePiece(6);
	ASSERT_EQ(2,cx.at(6, 5));	
	//cx.showBoard();
}

TEST(ConnectXTest, showBoardAllOutbound)
{
	ConnectX cx(-1, -1, 0);
	cx.placePiece(6);
	ASSERT_EQ(2,cx.at(6, 5));
	//cx.showBoard();
}

TEST(ConnectXTest, showBoardBlackWhite)
{
	ConnectX cx(2,2,1);
	cx.placePiece(1);
	ASSERT_EQ(2, cx.at(1, 1));
	cx.placePiece(1);
	ASSERT_EQ(1, cx.at(1, 0));
	cx.placePiece(0);
	ASSERT_EQ(2, cx.at(0, 1));
	cx.placePiece(1);
	ASSERT_EQ(2, cx.at(1, 1));
	cx.placePiece(0);
	ASSERT_EQ(2, cx.at(0, 0));
	//cx.showBoard();
}

TEST(ConnectXTest, placePieceBadEntry)
{
	ConnectX cx(2, 2, 1);
	cx.placePiece(1);
	ASSERT_EQ(2, cx.at(1, 1));
	cx.placePiece(1);
	ASSERT_EQ(1, cx.at(1, 0));
	cx.placePiece(1);
	ASSERT_EQ(2, cx.at(1, 1));
	cx.placePiece(3);
	ASSERT_EQ(-1, cx.at(1, 2));
	ASSERT_EQ(0, cx.at(0, 0));
	cx.showBoard();
}

/*TEST(ConnectXTest, inBoundsInvalid)
{
	ConnectX cx(3, 1, 2);
	//cx.showBoard();
	cx.placePiece(2);
	ASSERT_EQ(2, cx.at(2, 0));
	cx.placePiece(4);
	ASSERT_EQ(-1, cx.at(4, 0));
	ASSERT_EQ(0, cx.at(1, 0));

}*/
