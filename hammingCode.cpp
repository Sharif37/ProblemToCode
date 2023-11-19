#include<bits/stdc++.h>
using namespace std ;
int lengthOfRedundentBits(string data)
{
	int l = size(data);
	for (int i = 0 ;; i++)
	{
		if (pow(2, i) >= (l + i + 1))
			return  i ;
	}
	return 0 ;

}

void solve()
{

	string data ;
	cin >> data ;
	int length = lengthOfRedundentBits(data);
	int hammingCOdeLength = data.length() + length ;

	vector<int>index[length] ;
	for (int i = 0 ; i < length ; i++)
	{
		for (int j = 1 ; j <= hammingCOdeLength ; j++ )
		{
			if (1 << i & j)
				index[i].push_back(j);
		}

	}

	char hammingCode[hammingCOdeLength + 1]  ;
	int k = 0 ;
	for (int i = hammingCOdeLength ; i >= 1 ; i--)
	{
		if ( (i & (i - 1)) == 0) {
			continue ;
		}
		char c = data[k++] ;
		hammingCode[i] = c ;

	}



	//odd parity
	for (int i = 0 ; i < length; i++)
	{
		int indx = 1 << i ;
		int isOdd = 0 ;
		for (auto u : index[i])
		{
			if (hammingCode[u] == '1')
				isOdd++ ;
		}
		if (isOdd % 2)
			hammingCode[indx] = '0' ;
		else
			hammingCode[indx] = '1' ;

	}
	cout << "length of hamming code: " << hammingCOdeLength << endl ;
	cout << "Hamming Code: " ;
	for (int i = hammingCOdeLength; i >= 1; i--)
		cout << hammingCode[i];

	cout << endl ;


}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin) ;
	freopen("o.txt", "w", stdout) ;
#endif

	int t ;
	t = 1 ;
	while (t--)
	{
		solve() ;
	}





}