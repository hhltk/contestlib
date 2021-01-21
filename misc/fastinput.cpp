#include <cctype>
#include <cstdio>
#include <string>
#include <type_traits>

class FastInput {
public:
	template<class T>
	std::enable_if_t<std::is_integral_v<T>> operator>>(T& t) {
		char c;
		for (c = next_char(); c != '-' && !isdigit(c); c = next_char());
		bool neg = c == '-';
		if (neg) c = next_char();
		for (t = 0; isdigit(c); c = next_char()) {
			t = t * 10 + c - '0';
		}
		if (neg) t = -t;
	}
	template<class T>
	std::enable_if_t<std::is_floating_point_v<T>> operator>>(T& t) {
		std::string s;
		this->operator>>(s);
		t = static_cast<T>(std::stold(s));
	}
	void operator>>(std::string& s) {
		s.clear();
		char c;
		while (isspace(c = next_char()));
		do {
			s.push_back(c);
		} while (!isspace(c = next_char()));
	}
	void operator>>(char& c) {
		while (isspace(c = next_char()));
	}
private:
	char buf[1 << 20];
	size_t it = 0, n = 0;
	char next_char() {
		if (it >= n) {
			buf[0] = 0;
			it = 0;
			n = std::fread(buf, 1, sizeof(buf), stdin);
		}
		return buf[it++];
	}
};
