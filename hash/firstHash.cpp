#include <iostream>

using namespace std;

// Let's map variable data size to fixed data size.

// This code will make a hash function using a remainder of a division (hash_aux).

int hash_aux(int k, int m){
	int p = k%m;

	if(p >= 0){
		return p;
	} else {
		return p+m;
	}
}

int main(){
	int key, size;
	
	cin >> key >> size;
	
	while(key != 0 && size != 0){
		cout << hash_aux(key, size) << endl;
		cin >> key >> size;
	}
	
	return 0;
}