#include "gmock/gmock.h"
#include "similarity-checker.cpp"

TEST(SimilarityChecker, SameLengthStringTest) {
	SimilarityChecker sc;
	int expected = 60;
	int actual = sc.checkLength("abc", "efg");
	EXPECT_EQ(expected, actual);
}

TEST(SimilarityChecker, MoreThanTwiceStringTest) {
	SimilarityChecker sc;
	int expected = 0;
	int actual = sc.checkLength("abcefgh", "efg");
	EXPECT_EQ(expected, actual);
	actual = sc.checkLength("efg", "abcefgh");
	EXPECT_EQ(expected, actual);
}

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}