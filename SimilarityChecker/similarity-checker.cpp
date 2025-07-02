#include <string>
#include <algorithm>
using std::string;


class SimilarityChecker {
public:
	double checkLengthSimilarity(const string& string1, const string& string2) {
		int length1 = static_cast<int>(string1.size());
		int length2 = static_cast<int>(string2.size());
		return calculateLengthSimilarity(length1, length2);
	}

private:
	const double MAX_LENGTH_SCORE = 60.;
	const double MIN_LENGTH_SCORE = 0.;
	double calculateLengthSimilarity(int length1, int length2) {
		int big = std::max(length1, length2);
		int small = std::min(length1, length2);
		if (isDoubleLength(big, small)) return MIN_LENGTH_SCORE;
		int gap = big - small;
		return (1 - static_cast<double>(gap) / small) * MAX_LENGTH_SCORE;
	}
	bool isDoubleLength(int big, int small)
	{
		return big >= small * 2;
	}
};