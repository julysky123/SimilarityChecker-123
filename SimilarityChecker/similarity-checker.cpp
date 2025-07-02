#include <string>
using std::string;


class SimilarityChecker {
public:
	int checkLength(const string& a, const string& b) {
		if (a.size() >= b.size() * 2) return 0;
		if (b.size() >= a.size() * 2) return 0;
		return 60;
	}
};