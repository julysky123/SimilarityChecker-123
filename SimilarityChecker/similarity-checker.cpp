#include <string>
#include <algorithm>
#include <set>
using std::string;


class SimilarityChecker {
public:
	double checkLengthSimilarity(const string& string1, const string& string2) {
		int length1 = static_cast<int>(string1.size());
		int length2 = static_cast<int>(string2.size());
		return calculateLengthSimilarity(length1, length2);
	}

	double checkAlphabetSimilarity(const string& string1, const string& string2) {
		std::set<char> totalAlphabetInTwoStrings;
		std::set<char> sameAlphabetInTwoStrings;

		for (char target = 'A'; target <= 'Z'; target++) {
			if (string1.find(target) == string::npos) continue;
			if (string2.find(target) == string::npos) continue;
			sameAlphabetInTwoStrings.insert(target);
		}

		for (char target = 'A'; target <= 'Z'; target++) {
			if (string1.find(target) != string::npos) totalAlphabetInTwoStrings.insert(target);
			if (string2.find(target) != string::npos) totalAlphabetInTwoStrings.insert(target);
		}
		int sameCnt = static_cast<int>(sameAlphabetInTwoStrings.size());
		int totalCnt = static_cast<int>(totalAlphabetInTwoStrings.size());
		return static_cast<double>(sameCnt) / totalCnt * 40;
		
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