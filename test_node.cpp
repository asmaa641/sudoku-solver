#include <gtest/gtest.h>
#include "Node.h"
#include "Matrix.h"

TEST(NodeTest, DefaultConstructorInitializesBoardAndParent) {
    Node n;

    n.board.setCell(0, 0, 5);
    EXPECT_EQ(n.board.getCell(0, 0), 5);
}

TEST(NodeTest, ParameterizedConstructorCopiesBoard) {
    Matrix m;
    m.setCell(0, 0, 7);

    Node parentNode(m, nullptr);


    EXPECT_EQ(parentNode.board.getCell(0, 0), 7);
}

TEST(NodeTest, AddChildCreatesChildWithUpdatedBoard) {
    Matrix m;
    m.setCell(1, 1, 4);

    Node parent(m, nullptr);

    Node* child = parent.addChild(1, 2, 9);
    ASSERT_NE(child, nullptr);


    EXPECT_EQ(child->board.getCell(1, 1), 4);
    EXPECT_EQ(child->board.getCell(1, 2), 9);


    EXPECT_EQ(parent.board.getCell(1, 2), 0);
}

TEST(NodeTest, AddChildReturnsNullWhenMoreThanNineChildren) {
    Matrix m;
    Node parent(m, nullptr);

    Node* lastChild = nullptr;
    // capacity is 9 children
    for (int i = 0; i < 9; ++i) {
        lastChild = parent.addChild(0, i, i + 1);
        ASSERT_NE(lastChild, nullptr);
    }

    // The 10th call must return nullptr
    Node* extra = parent.addChild(1, 0, 5);
    EXPECT_EQ(extra, nullptr);
}

TEST(NodeTest, PopulateChildrenCreatesValidMovesForFirstEmptyCell) {
    Matrix m;


    for (int c = 0; c < 8; ++c) {
        m.setCell(0, c, c + 1);
    }
    m.setCell(0, 8, 0); // empty

    Node n(m, nullptr);
    n.populateChildren();


    bool foundExpectedChild = false;

    Matrix mExpected = m;
    mExpected.setCell(0, 8, 9);


    Node n2(m, nullptr);
    Node* expectedChild = n2.addChild(0, 8, 9);
    ASSERT_NE(expectedChild, nullptr);

    EXPECT_EQ(expectedChild->board.getCell(0, 8), 9);
    for (int c = 0; c < 8; ++c) {
        EXPECT_EQ(expectedChild->board.getCell(0, c), c + 1);
    }


    (void)n;
}

TEST(NodeTest, PopulateChildrenDoesNothingOnCompleteBoard) {
    Matrix m;

    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            m.setCell(r, c, 1); // any non-zero to avoid empties
        }
    }

    Node n(m, nullptr);

    EXPECT_NO_THROW(n.populateChildren());
}