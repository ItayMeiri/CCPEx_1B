/**
 * AUTHOR: I M
 * 
 * Date: 03/09/21
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good snowman code") { // 

	//HNLRXYTB
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(12222222)) == nospaces("_===_\n\\(o.o)/\n(] [)\n(\" \")"));
	CHECK(nospaces(snowman(12341234)) == nospaces("_===_\n(O.-)/\n<(> <)\n(   )"));
	CHECK(nospaces(snowman(22222222)) == nospaces(" ___ .....\n\\(o.o)/\n(] [)\n(\" \")"));
	CHECK(nospaces(snowman(23333333)) == nospaces(" ___ .....\n(O_O)\n/(> <)\\\n(___)"));
	CHECK(nospaces(snowman(23412341)) == nospaces(" ___ .....\n\\(-_.)\n(   )\\\n( : )"));
	CHECK(nospaces(snowman(24123123)) == nospaces(" ___ .....\n(.o)\n/(] [)>\n(___)"));
	CHECK(nospaces(snowman(24444442)) == nospaces(" ___ .....\n(--)\n(   )\n(\" \")"));
	CHECK(nospaces(snowman(33333333)) == nospaces("   _\n  /_\\\n(O_O)\n/(> <)\\\n(___)"));
	CHECK(nospaces(snowman(34444441)) == nospaces("   _\n  /_\\\n(--)\n(   )\n( : )"));
	CHECK(nospaces(snowman(34444442)) == nospaces("   _\n  /_\\\n(--)\n(   )\n(\" \")"));
	CHECK(nospaces(snowman(34444443)) == nospaces("   _\n  /_\\\n(--)\n(   )\n(___)"));
	CHECK(nospaces(snowman(43214321)) == nospaces("  ___ \n (_*_)\n(o_.)\n(] [)\\\n( : )"));
	CHECK(nospaces(snowman(44444444)) == nospaces("  ___ \n (_*_)\n(--)\n(   )\n(   )"));

}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(555));
	CHECK_THROWS(snowman(-43214321));
	CHECK_THROWS(snowman(0));
	CHECK_THROWS(snowman(-1));
	CHECK_THROWS(snowman(10));
	CHECK_THROWS(snowman(11114418));
	CHECK_THROWS(snowman(11114711));
	CHECK_THROWS(snowman(81114411));
	CHECK_THROWS(snowman(00000000));



	



    /* Add more checks here */
}


/* Add more test cases here */
