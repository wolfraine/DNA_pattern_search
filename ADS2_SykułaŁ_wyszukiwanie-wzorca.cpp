#include <string.h>
#include <iostream>
#include <fstream>

#define alfabetLenght 256

void rabinKarp(std::string pattern, std::string text, int q) {
	int m = pattern.length();
	int n = text.length();
	int p = 0;
	int t = 0;
	int j = 0;
	int h = 1;

	for (int i = 0; i < m - 1; i++)
		h = (h * alfabetLenght) % q;
	for (int i = 0; i < m; i++) {
		p = (alfabetLenght * p + pattern[i]) % q;
		t = (alfabetLenght * t + text[i]) % q;
	}
	for (int i = 0; i <= n - m; i++) {
		if (p == t) {
			for (j = 0; j < m; j++) {
				if (text[i + j] != pattern[j])
					break;
			}
			if (j == m)
				std::cout << i << " ";

		}

		if (i < n - m) {
			t = (alfabetLenght * (t - text[i] * h) + text[i + m]) % q;

			if (t < 0)
				t = (t + q);
		}
	}
}

int main() {
	std::string text = "";
	std::string pattern = "";
	std::string fileName = "";
	std::fstream plik;
	int lp = 0;
	int q = 13;
	std::cin >> lp;
	for (int i = 0; i < lp; i++) {
		std::cin >> fileName;
		plik.open(fileName);
		if (plik.is_open()) {
			while (!plik.eof()) {
				plik >> text;
			}
			std::cin >> pattern;

			rabinKarp(pattern, text, q);
			plik.close();
		}
		else {
			std::cout << "Plik nie istnieje lub jest uszkodzony. \n";
		}
	}
	std::cout << "\n";
	system("PAUSE");
}