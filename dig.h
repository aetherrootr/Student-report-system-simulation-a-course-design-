/**
 * @FileNname dig.h
 * @Function This head file can change any int into string
 */
#ifndef dig_h
#define dig_h

#include <bits/stdc++.h>

using namespace std;

string dig(int x){//main function
    string s;
    while(x>0){//Enumerate each bit
   		s+=x%10+'0';
		x/=10;
	}
   	reverse(s.begin(),s.end());
   	if(s.length()==0) return "0";
	return s;
}

#endif