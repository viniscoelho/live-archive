#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	bool hasund, hasupp, prev;
	char p;
	string str;
	while ( getline(cin, str) ){
		hasund = hasupp = prev = false;
		for ( int i = 0; i < str.size(); ++i ){
			if ( i > 0 && str[i] == str[i-1] && str[i] == '_' )
				hasund = hasupp = true;
			hasund |= (str[i] == '_');
			hasupp |= isupper(str[i]);
		}
		if ( str[str.size()-1] == '_' || isupper(str[0]) || str[0] == '_' || (hasund && hasupp) ){
			cout << "Error!\n";
			continue;
		}
		if ( hasund ){
			for ( int i = 0; i < str.size(); ++i ){
				if ( str[i] == '_' ){
					prev = true;
					continue;
				}
				if ( prev && isalpha(str[i]) ) cout << (char)toupper(str[i]);
				else cout << str[i];
				prev = false;
			}
		}
		else if ( hasupp ){
			for ( int i = 0; i < str.size(); ++i ){
				if ( isupper(str[i]) ) cout << '_' << (char)tolower(str[i]);
				else cout << str[i];
			}
		}
		else cout << str;
		cout << "\n";
	}
	return 0;
}
