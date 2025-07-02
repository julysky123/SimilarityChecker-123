#include <string>
using std::string;


class SimilarityChecker {
public:
	double checkLength(const string& string1, const string& string2) {
		int length1 = static_cast<int>(string1.size());
		int length2 = static_cast<int>(string2.size());
		if (length1 == length2) return 60;
		int bigLength = length1 > length2 ? length1 : length2;
		int smallLength = length1 > length2 ? length2 : length1;
		int gap = bigLength - smallLength;

		if (bigLength >= smallLength * 2) return 0;
		
		double score = (1 - (gap * 1.0) / smallLength) * 60;
		return score;
	}
};