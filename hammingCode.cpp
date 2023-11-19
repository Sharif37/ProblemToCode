#include <bits/stdc++.h>
using namespace std;

int lengthOfRedundantBits(string data) {
	int l = size(data);
	for (int i = 0;; i++) {
		if (pow(2, i) >= (l + i + 1))
			return i;
	}
	return 0;
}

void solve() {
	string data;
	cin >> data;
	int length = lengthOfRedundantBits(data);
	int hammingCodeLength = data.length() + length;

	vector<int> index[length];
	for (int i = 0; i < length; i++) {
		for (int j = 1; j <= hammingCodeLength; j++) {
			if (1 << i & j)
				index[i].push_back(j);
		}
	}

	char hammingCode[hammingCodeLength + 1];
	int k = 0;
	for (int i = hammingCodeLength; i >= 1; i--) {
		if ((i & (i - 1)) == 0) {
			continue;
		}
		char c = data[k++];
		hammingCode[i] = c;
	}

	// Odd parity
	for (int i = 0; i < length; i++) {
		int indx = 1 << i;
		int isOdd = 0;
		for (auto u : index[i]) {
			if (hammingCode[u] == '1')
				isOdd++;
		}
		if (isOdd % 2)
			hammingCode[indx] = '0';
		else
			hammingCode[indx] = '1';
	}

	cout << "Length of Hamming code: " << hammingCodeLength << endl;
	cout << "Hamming Code: ";
	for (int i = hammingCodeLength; i >= 1; i--)
		cout << hammingCode[i];
	cout << endl;

	//Detect and correct errors
	string receiveData = "10011100101110A";
	reverse(receiveData.begin(), receiveData.end());
	int syndrome = 0 ;
	for (int i = 0; i < length; i++) {
		int isOdd = 0;
		for (auto u : index[i]) {
			if (receiveData[u] == '1')
				isOdd++;
		}
		if (isOdd % 2 == 0)
			syndrome += 1 << i;
	}

	if (syndrome != 0) {
		cout << "Error detected at position " << syndrome << endl;
		receiveData[syndrome] = (receiveData[syndrome] == '0') ? '1' : '0';
		cout << "Corrected Hamming Code: ";
		for (int i = hammingCodeLength; i >= 1; i--)
			cout << receiveData[i];
		cout << endl;
	} else {
		cout << "No errors detected." << endl;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif

	int t;
	t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
