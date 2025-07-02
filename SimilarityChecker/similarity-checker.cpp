#include <string>
using std::string;


class SimilarityChecker {
public:
	int checkLength(const string& string1, const string& string2) {
		int length1 = static_cast<int>(string1.size());
		int length2 = static_cast<int>(string2.size());
		int bigLength = length1 > length2 ? length1 : length2;
		int smallLength = length1 > length2 ? length2 : length1;
		if (bigLength >= smallLength * 2) return 0;
		return 60;
	}
};