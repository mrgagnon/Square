/* Maylee Gagnon
 * CS 2223 proj2 p4 Square
 * 11.8.2019
 */

#include <iostream>
#include <vector>
using namespace std;



int main() {
	cout << "Hello" << endl;

	int arr[16] = {1,14,14,4,11,7,6,9,8,10,10,5,13,2,3,15}; // initializing square
	int sum = 33;
	int tally4 = 0;
	int tally33 = 0;


	int n = 16;
	vector<string> arrGroups;
		arrGroups.push_back("0");
		arrGroups.push_back("1");

		int i;
		int j;
		for (i = 2; i < (1<<n); i = i<<1) {
			for (j = i-1; j >= 0; j--) { // reverse
				arrGroups.push_back(arrGroups[j]);
			}
			for (j = 0; j < i; j++) { // 0 to first half
				arrGroups[j] = "0" + arrGroups[j];
			}
			for (j = i; j < 2*i; j++) { // 1 to second half
				arrGroups[j] = "1" + arrGroups[j];
			}
		}


	for (i = 0; i < arrGroups.size(); i++) { // go through each combination
		int groupSum = 0;
		int numInGroup = 0;
		string curGroup= arrGroups[i];
		for (j = 0; j < n; j++) { // go through the current combination
			if (curGroup.at(j) == '1'){ // map to actual values in square
				groupSum += arr[j]; // update sum of the combination
				numInGroup++;
			}
		}

		if (groupSum == 33 && numInGroup == 4) {
			tally4++;
		}
	}

	cout << "tally4; " << tally4 << endl;

	// TODO !!! binary lists > actual numbers

	// TODO total of the numbers in each set

	/*Part A&B TODO
	 * if (total == sum){
	 * 	if (amountOfNumbers == 4){
	 * 		 tally4++;
	 * 	}
	 * 	tally33++;
	 * }
	 */

	/* Part C TODO
	 * some way to track all the sums & corresponding tally [0,total of all] A large 2d array?
	 * if sum present then corresponding tally++; // efficient way to search/where to add?
	 * if new sum then add to list & tally=1;
	 */

	/* Part D TODO
	 * Loop through tally list & Look for the most tallies
	 * Get sum & tally count
	 */

	return 0;
}
