#include "gmock/gmock.h"
#include "similarity-checker.cpp"
using namespace testing;

class SimilarityCheckerFixture : public Test {
public:
	SimilarityChecker sc;
	void lengthSimilarityTest(double expected, const string& str1, const string& str2) {
		double actual = sc.checkLengthSimilarity(str1, str2);
		EXPECT_EQ(expected, actual);
	}
};

TEST_F(SimilarityCheckerFixture, SameLengthStringTest) {
	lengthSimilarityTest(60., "abc", "efg");
}

TEST_F(SimilarityCheckerFixture, MoreThanTwiceStringTest) {
	lengthSimilarityTest(0., "abcefgh", "efg");
	lengthSimilarityTest(0., "efg", "abcefgh");
}

TEST_F(SimilarityCheckerFixture, LengthStringTest) {
	lengthSimilarityTest(30., "abcdef", "abcd");
	lengthSimilarityTest(30., "abcd", "abcdef");
}

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}