/* Maylee Gagnon
 * CS 2223 proj2 p4 Square
 * 11.8.2019
 */

#include <iostream>
#include <vector>
using namespace std;



int main() {
	cout << "Hello" << endl;

	//total 132
	int arr[16] = {1,14,14,4,11,7,6,9,8,10,10,5,13,2,3,15}; // initializing square
	int tallies[133] = {0};
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

		if (groupSum == 33) {
			if (numInGroup == 4){
					tally4++;
			}
			tally33++;
		}
		tallies[groupSum]++; //increment tally count for corresponding sum
	} // end for loop going through each combination

	cout << "tally4: " << tally4 << endl;
	cout << "tally33: " << tally33 << endl;

	for (int i = 0; i <= 132; i++){
		cout << tallies[i] << " Number of combinations equal to " << i << endl;
	}
	return 0;
}
