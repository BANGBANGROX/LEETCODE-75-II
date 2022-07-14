#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int longestPalindrome(vector<string>& words) {
		unordered_map<string, int> dictionary;
		int totalLen = 0;
		int maxLengthPalindrome = 0;

		for (string word : words) {
			++dictionary[word];
		}

		for (string word : words) {
			if (dictionary.find(word) == dictionary.end()) continue;
			if (word[0] == word[1]) {
				if (dictionary[word] % 2 == 0) {
					totalLen += 2 * dictionary[word];
				}
				else {
					if (maxLengthPalindrome < 2 * dictionary[word]) {
						if (maxLengthPalindrome > 0) totalLen += 2 * (maxLengthPalindrome / 2 - 1);
						maxLengthPalindrome = 2 * dictionary[word];
					}
					else {
						totalLen += (2 * (dictionary[word] - 1));
					}
				}
			}
			else {
				string reverseWord("");
				reverseWord += word[1];
				reverseWord += word[0];
				if (dictionary.find(reverseWord) == dictionary.end()) continue;
				totalLen += min(dictionary[word], dictionary[reverseWord]);
				dictionary.erase(reverseWord);
			}
			dictionary.erase(word);
		}

		totalLen += maxLengthPalindrome;

		return totalLen;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<string> words(n);
		for (string& word : words) cin >> word;

		Solution solution;
		cout << solution.longestPalindrome(words) << endl;
	}

	return 0;
}