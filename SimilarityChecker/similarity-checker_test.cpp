#include "gmock/gmock.h"
#include "similarity-checker.cpp"

TEST(SimilarityChecker, SameLengthStringTest) {
	SimilarityChecker sc;
	double expected = 60.;
	double actual = sc.checkLength("abc", "efg");
	EXPECT_EQ(expected, actual);
}

TEST(SimilarityChecker, MoreThanTwiceStringTest) {
	SimilarityChecker sc;
	double expected = 0.;
	double actual = sc.checkLength("abcefgh", "efg");
	EXPECT_EQ(expected, actual);
	actual = sc.checkLength("efg", "abcefgh");
	EXPECT_EQ(expected, actual);
}

TEST(SimilarityChecker, LengthStringTest) {
	SimilarityChecker sc;
	double expected = 30.;
	double actual = sc.checkLength("abcdef", "abcd");
	EXPECT_EQ(expected, actual);
}

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}