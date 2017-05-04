#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include "tree.hpp"
#include "header.hpp"


#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE Suites
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(Integer)

bTree<int> A(3);
bIterator<int> I(A);
int a;
bTree<int> B(3);
int b;


BOOST_AUTO_TEST_CASE(AddingElementIntoEmptyTree)
{
	A.insert(0,0);
	I.begin();
	BOOST_CHECK( **I == 0);
}


BOOST_AUTO_TEST_CASE(DeletingElementFromTreeThenTreeIsEmpty)
{
	A.remove(0);
	BOOST_CHECK( A.empty() == true);
}


BOOST_AUTO_TEST_CASE(AddingElementsFrom_1_to_9_CheckingTheLastElement)
{
	for(a = 0; a <10; a++)
	A.insert(a,a);
	I.begin();
	BOOST_CHECK(**(++I) == 0);
	BOOST_CHECK(**(++I) == 3);
	BOOST_CHECK(**(++I) == 6);
	BOOST_CHECK(*(*I + (I.currDe()-1)) == 9);
}

BOOST_AUTO_TEST_CASE(GettingElementFromBeginningOfTree)
{
	a = **I.begin();
	BOOST_CHECK(a == 2);

}

BOOST_AUTO_TEST_CASE(GettingElementFromBackOfTree)
{
	a = **I.back();
	BOOST_CHECK(a == 6);

}

BOOST_AUTO_TEST_CASE(GettingElementFromTreeByIndex)
{
	a = *I(1,0);
	BOOST_CHECK(a == 0);

}


BOOST_AUTO_TEST_CASE(ComparingTwoTrees)
{
	for(a = 0; a <10; a++)
	B.insert(a,a);
	BOOST_CHECK(A == B);
	
}


BOOST_AUTO_TEST_CASE(ComparingSizeOfTwoTres)
{
int NodeA,NodeB;
int CellsA,CellsB;
A.getSize(NodeA,CellsA);
B.getSize(NodeB,CellsB);

	BOOST_CHECK_EQUAL(NodeA,NodeB);
	BOOST_CHECK_EQUAL(CellsA,CellsB);

}


BOOST_AUTO_TEST_CASE(AddingTwoTrees)
{
int NodeA, CellsA;

	A = A+B;
	A.getSize(NodeA,CellsA);
	BOOST_CHECK(NodeA == 5);
	BOOST_CHECK(CellsA == 20);
	BOOST_CHECK(**I.begin() == 2);
	BOOST_CHECK_EQUAL(*I(1,0) , 0);
	BOOST_CHECK_EQUAL(*I(2,0) , 2);
	BOOST_CHECK_EQUAL(*I(3,0) , 5);
	BOOST_CHECK(*I(4,(I[4]).currDe()-1) == 9);

}


BOOST_AUTO_TEST_CASE(ComparingSizeOfTwoTresShouldntBeLondgerTheSame)
{
int NodeA,NodeB;
int CellsA,CellsB;
A.getSize(NodeA,CellsA);
B.getSize(NodeB,CellsB);

	BOOST_CHECK(NodeA != NodeB);
	BOOST_CHECK(CellsA != CellsB);

}


BOOST_AUTO_TEST_CASE(ComparingTwoDiffTrees)
{
	BOOST_CHECK( A != B);
}


BOOST_AUTO_TEST_CASE(CopyOfTreeCheck)
{
	A = B;
	BOOST_CHECK( A == B);
int NodeA,NodeB;
int CellsA,CellsB;
A.getSize(NodeA,CellsA);
B.getSize(NodeB,CellsB);

	BOOST_CHECK(NodeA == NodeB);
	BOOST_CHECK(CellsA == CellsB);

}


BOOST_AUTO_TEST_CASE(SubtracktTwoTheSameTreesRootShouldBeNULL)
{
	A - B;
	BOOST_CHECK(A.root == NULL);

int NodeA, CellsA;

	A.getSize(NodeA,CellsA);
	BOOST_CHECK_EQUAL(NodeA,0);
	BOOST_CHECK_EQUAL(CellsA,0);
	BOOST_CHECK(A.empty() == true);
	
}


BOOST_AUTO_TEST_CASE(CheckSizeOfTree)
{
int NodeB, CellsB;
B.getSize(NodeB,CellsB);
	BOOST_CHECK(NodeB == 4);
	BOOST_CHECK(CellsB == 10);	
}


BOOST_AUTO_TEST_CASE(IteratorChecking)
{
	bIterator<int> i(B);
	i.begin();
	BOOST_CHECK_EQUAL(**i,2);
	i++;
	BOOST_CHECK_EQUAL(**i,0);
	i++;
	BOOST_CHECK_EQUAL(**i,3);
	i++;
	BOOST_CHECK_EQUAL(**i,6);
}

BOOST_AUTO_TEST_SUITE_END()


////////////////////////////////////STRING////////////////////////////////////
BOOST_AUTO_TEST_SUITE(String)

bTree<std::string> A(3);
bIterator<std::string> I(A);
int a;
std::string s1 = "a";
bTree<std::string> B(3);
std::string s2 = "a";
int b;


BOOST_AUTO_TEST_CASE(AddingElementIntoEmptyTree)
{
	A.insert("a","a");
	I.begin();
	BOOST_CHECK( **I == "a");
}


BOOST_AUTO_TEST_CASE(DeletingElementFromTreeThenTreeIsEmpty)
{
	A.remove("a");
	BOOST_CHECK( A.empty() == true);
}


BOOST_AUTO_TEST_CASE(AddingElementsFrom_1_to_9_CheckingTheLastElement)
{
	for(a = 0; a <10; a++)
	{
		A.insert(s1,s1);
		s1 = s1 + "a";
	}
	I.begin();
	BOOST_CHECK(**(++I) == "a");
	BOOST_CHECK(**(++I) == "aaaa");
	BOOST_CHECK(**(++I) == "aaaaaaa");
	BOOST_CHECK(*(*I + (I.currDe()-1)) == "aaaaaaaaaa");
}

BOOST_AUTO_TEST_CASE(GettingElementFromBeginningOfTree)
{
	s1 = **I.begin();
	BOOST_CHECK(s1 == "aaa");

}

BOOST_AUTO_TEST_CASE(GettingElementFromBackOfTree)
{
	s1 = **I.back();
	BOOST_CHECK(s1 == "aaaaaaa");

}

BOOST_AUTO_TEST_CASE(GettingElementFromTreeByIndex)
{
	s1 = *I(1,0);
	BOOST_CHECK(s1 == "a");

}


BOOST_AUTO_TEST_CASE(ComparingTwoTrees)
{
	for(a = 0; a <10; a++)
	{
		B.insert(s1,s1);
		s1 = s1 + "a";
	}
	
	BOOST_CHECK(A == B);
	
}


BOOST_AUTO_TEST_CASE(ComparingSizeOfTwoTres)
{
int NodeA,NodeB;
int CellsA,CellsB;
A.getSize(NodeA,CellsA);
B.getSize(NodeB,CellsB);

	BOOST_CHECK_EQUAL(NodeA,NodeB);
	BOOST_CHECK_EQUAL(CellsA,CellsB);

}


BOOST_AUTO_TEST_CASE(AddingTwoTrees)
{
int NodeA, CellsA;

	A = A+B;
	A.getSize(NodeA,CellsA);
	BOOST_CHECK(NodeA == 5);
	BOOST_CHECK(CellsA == 20);
	BOOST_CHECK(**I.begin() == "aaa");
	BOOST_CHECK_EQUAL(*I(1,0) , "a");
	BOOST_CHECK_EQUAL(*I(2,0) , "aaa");
	BOOST_CHECK_EQUAL(*I(3,0) , "aaaaaa");
	BOOST_CHECK(*I(4,(I[4]).currDe()-1) == "aaaaaaaaaa");

}


BOOST_AUTO_TEST_CASE(ComparingSizeOfTwoTresShouldntBeLondgerTheSame)
{
int NodeA,NodeB;
int CellsA,CellsB;
A.getSize(NodeA,CellsA);
B.getSize(NodeB,CellsB);

	BOOST_CHECK(NodeA != NodeB);
	BOOST_CHECK(CellsA != CellsB);

}


BOOST_AUTO_TEST_CASE(ComparingTwoDiffTrees)
{
	BOOST_CHECK( A != B);
}


BOOST_AUTO_TEST_CASE(CopyOfTreeCheck)
{
	A = B;
	BOOST_CHECK( A == B);
int NodeA,NodeB;
int CellsA,CellsB;
A.getSize(NodeA,CellsA);
B.getSize(NodeB,CellsB);

	BOOST_CHECK(NodeA == NodeB);
	BOOST_CHECK(CellsA == CellsB);

}


BOOST_AUTO_TEST_CASE(SubtracktTwoTheSameTreesRootShouldBeNULL)
{
	A - B;
	BOOST_CHECK(A.root == NULL);

int NodeA, CellsA;

	A.getSize(NodeA,CellsA);
	BOOST_CHECK_EQUAL(NodeA,0);
	BOOST_CHECK_EQUAL(CellsA,0);
	BOOST_CHECK(A.empty() == true);
	
}


BOOST_AUTO_TEST_CASE(CheckSizeOfTree)
{
int NodeB, CellsB;
B.getSize(NodeB,CellsB);
	BOOST_CHECK(NodeB == 4);
	BOOST_CHECK(CellsB == 10);	
}


BOOST_AUTO_TEST_CASE(IteratorChecking)
{
	bIterator<std::string> i(B);
	i.begin();
	BOOST_CHECK_EQUAL(**i,"aaa");
	i++;
	BOOST_CHECK_EQUAL(**i,"a");
	i++;
	BOOST_CHECK_EQUAL(**i,"aaaa");
	i++;
	BOOST_CHECK_EQUAL(**i,"aaaaaaa");
}

BOOST_AUTO_TEST_SUITE_END()



////////////////////////////////////intSet////////////////////////////////////
BOOST_AUTO_TEST_SUITE(inttSet)

bTree<intSet> A(3);
bIterator<intSet> I(A);
int a;
intSet s1;
bTree<intSet> B(3);
intSet s2;
int b;


BOOST_AUTO_TEST_CASE(AddingElementIntoEmptyTree)
{
	s1.addNodeAtTheEnd(0);
	A.insert(s1,s1);
	s2 = **I.begin();
	BOOST_CHECK( s2.getValue(1) == 0);
}


BOOST_AUTO_TEST_CASE(DeletingElementFromTreeThenTreeIsEmpty)
{
	A.remove(s1);
	BOOST_CHECK( A.empty() == true);
	s1.clear();
}


BOOST_AUTO_TEST_CASE(AddingElementsFrom_1_to_9_CheckingTheLastElement)
{
	for(a = 0; a <10; a++)
	{
		s1.addNodeAtTheEnd(a);
		A.insert(s1,s1);
		s1.clear();	
		
	}
	I.begin();
	s2 = **(++I);
	BOOST_CHECK(s2.getValue(1) == 0);
	s2 = **(++I);
	BOOST_CHECK_EQUAL(s2.getValue(1) , 3);
	s2 = **(++I);
	BOOST_CHECK_EQUAL(s2.getValue(1) , 7);

}

BOOST_AUTO_TEST_CASE(GettingElementFromBeginningOfTree)
{
	intSet	s1 = **I.begin();
	BOOST_CHECK(s1.getValue(1) == 2);

}

BOOST_AUTO_TEST_CASE(GettingElementFromBackOfTree)
{
	intSet s1 = **I.back();
	BOOST_CHECK(s1.getValue(1) == 7);

}

BOOST_AUTO_TEST_CASE(GettingElementFromTreeByIndex)
{
	intSet s2 = *I(1,0);
	BOOST_CHECK(s2.getValue(1) == 0);

}


BOOST_AUTO_TEST_CASE(ComparingTwoTrees)
{
	s2.clear();
	for(a = 0; a <10; a++)
	{
		s2.addNodeAtTheEnd(a);
		B.insert(s2,s2);
		s2.clear();
	}
	
	BOOST_CHECK(A == B);
	
}


BOOST_AUTO_TEST_CASE(ComparingSizeOfTwoTres)
{
int NodeA,NodeB;
int CellsA,CellsB;
A.getSize(NodeA,CellsA);
B.getSize(NodeB,CellsB);

	BOOST_CHECK_EQUAL(NodeA,NodeB);
	BOOST_CHECK_EQUAL(CellsA,CellsB);

}


BOOST_AUTO_TEST_CASE(AddingTwoTrees)
{
int NodeA, CellsA;

	A = A+B;
	A.getSize(NodeA,CellsA);
	BOOST_CHECK(NodeA == 6);
	BOOST_CHECK(CellsA == 20);
	intSet s = **I.begin();
	BOOST_CHECK_EQUAL(s.getValue(1) , 2);
	s = *I(1,0);
	BOOST_CHECK_EQUAL(s.getValue(1) , 0);
	s = *I(2,0);
	BOOST_CHECK_EQUAL(s.getValue(1) , 3);
	s = *I(3,0);
	BOOST_CHECK_EQUAL(s.getValue(1) , 7);
	s = *I(4,0);
	BOOST_CHECK_EQUAL(s.getValue(1) , 1);
	s = *I(5,0);
	BOOST_CHECK_EQUAL(s.getValue(1) , 4);

}


BOOST_AUTO_TEST_CASE(ComparingSizeOfTwoTresShouldntBeLondgerTheSame)
{
int NodeA,NodeB;
int CellsA,CellsB;
A.getSize(NodeA,CellsA);
B.getSize(NodeB,CellsB);

	BOOST_CHECK(NodeA != NodeB);
	BOOST_CHECK(CellsA != CellsB);

}


BOOST_AUTO_TEST_CASE(ComparingTwoDiffTrees)
{
	BOOST_CHECK( A != B);
}


BOOST_AUTO_TEST_CASE(CopyOfTreeCheck)
{
	A = B;
	BOOST_CHECK( A == B);
int NodeA,NodeB;
int CellsA,CellsB;
A.getSize(NodeA,CellsA);
B.getSize(NodeB,CellsB);

	BOOST_CHECK(NodeA == NodeB);
	BOOST_CHECK(CellsA == CellsB);

}


BOOST_AUTO_TEST_CASE(SubtracktTwoTheSameTreesRootShouldBeNULL)
{
	A-B;
	BOOST_CHECK(A.root == NULL);

int NodeA, CellsA;

	A.getSize(NodeA,CellsA);
	BOOST_CHECK_EQUAL(NodeA,0);
	BOOST_CHECK_EQUAL(CellsA,0);
	BOOST_CHECK(A.empty() == true);
	
}


BOOST_AUTO_TEST_CASE(CheckSizeOfTree)
{
int NodeB, CellsB;
B.getSize(NodeB,CellsB);
	BOOST_CHECK(NodeB == 4);
	BOOST_CHECK(CellsB == 10);	
}


BOOST_AUTO_TEST_CASE(IteratorChecking)
{
	bIterator<intSet> i(B);
	intSet s = **i.begin();
	BOOST_CHECK_EQUAL(s.getValue(1),2);
	s = **(++i);
	BOOST_CHECK_EQUAL(s.getValue(1),0);
	s = **(++i);
	BOOST_CHECK_EQUAL(s.getValue(1),3);
	s = **(++i);
	BOOST_CHECK_EQUAL(s.getValue(1),7);
}

BOOST_AUTO_TEST_SUITE_END()





















