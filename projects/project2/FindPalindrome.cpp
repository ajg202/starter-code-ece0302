#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i]);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	// TODO need to implement this recursive function!
    string test = "";

    for (int i = 0; i < currentStringVector.size(); i++){
        test = test + currentStringVector[i];
    }

    bool isDuplicate = false;
    for (int i = 0; i < palindromes.size(); i++){
        if (palindromes[i] == currentStringVector){
            isDuplicate = true;
            break;
        }
    }

	convertToLowerCase(test);

	bool invalid = false;
	for (int i=0;i<test.size();i++){
		if (!isalpha(test[i])){
			invalid = true;
			break;
		}
	}

    if (isPalindrome(test) && !isDuplicate && !invalid){
        palindromes.push_back(currentStringVector);
		numPalindromes++;
    }

    for (size_t i = 0; i < candidateStringVector.size(); i++){
        string chosenString = candidateStringVector[i];
        currentStringVector.push_back(chosenString);

        candidateStringVector.erase(candidateStringVector.begin() + i);
        	recursiveFindPalindromes(candidateStringVector, currentStringVector);
        currentStringVector.pop_back();
    }

    return;
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	// TODO need to implement this...
	numPalindromes = 0;
	candidateStringVector.clear();
	currentStringVector.clear();
	palindromes.clear();
}

FindPalindrome::~FindPalindrome()
{
	// TODO need to implement this...
}

int FindPalindrome::number() const
{
	// TODO need to implement this...
	return numPalindromes;
}

void FindPalindrome::clear()
{
	// TODO need to implement this...
	numPalindromes=0;
	candidateStringVector.clear();
	currentStringVector.clear();
	palindromes.clear();
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	// TODO need to implement this...

	if (stringVector.empty()){
		return false;
	}

	string arr1="";
	for(int i=0;i<stringVector.size();i++){
		arr1=arr1+stringVector[i];
	}

	for (int i=0;i<arr1.size();i++){
		if (!isalpha(arr1[i])){
			return false;
		}
	}

	int odds=0,count=0;
	for (int j = 0; j < arr1.size(); j++) {
		char currentChar = tolower(arr1[j]);
		int charCount = 0;
		for (int k = 0; k < arr1.size(); k++) {
			if (tolower(arr1[k]) == currentChar) {
				charCount++;
			}
		}
		if (charCount % 2 == 1) {
			count++;
		}
	}
	return count <= 1;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...

	if (stringVector1.empty() || stringVector2.empty()){
		return false;
	}

	string arr1="",arr2="";
	for (int i=0;i<stringVector1.size();i++){
		arr1=arr1+stringVector1[i];
	}

	for (int i=0;i<stringVector1.size();i++){
		arr2=arr2+stringVector2[i];
	}

	for (int i=0;i<arr1.size();i++){
		if (!isalpha(arr1[i])){
			return false;
		}
	}

	for (int i=0;i<arr2.size();i++){
		if (!isalpha(arr2[i])){
			return false;
		}
	}

	if (arr1.size()==arr2.size()){
		for (int k=0,l=arr1.size()-1;k<arr1.size();k++,l--){
			if (arr1[k]!=arr2[l]){
				return false;
			}
		}
	}
	else if (arr1.size()==arr2.size()-1){
		for (int k=0,l=arr1.size();k<arr1.size();k++,l--){
			if (arr1[k]!=arr2[l]){
				return false;
			}
		}
	}
	else if (arr1.size()-1==arr2.size()){
		for (int k=0,l=arr1.size()-2;k<arr1.size()-1;k++,l--){
			if (arr1[k]!=arr2[l]){
				return false;
			}
		}
	}
	else{
		return false;
	}

	return true;
}

bool FindPalindrome::add(const string & value)
{
	// TODO need to implement this...
	if (value.empty()){
		return false;
	}
	
	for (int i=0;i<value.size();i++){
		if (!isalpha(value[i])){
			return false;
		}
	}

	string lowerTest1,lowerTest2;
	for (int i=0;i<value.size();i++){
		lowerTest2.push_back(tolower(value[i]));
	}
	for (int i=0;i<candidateStringVector.size();i++){
		lowerTest1=candidateStringVector[i];
		convertToLowerCase(lowerTest1);

		if (lowerTest2 == lowerTest1) {
			return false;
		}
	}

	candidateStringVector.push_back(value);
	recursiveFindPalindromes(candidateStringVector,currentStringVector);
	return true;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	// TODO need to implement this...
	if (stringVector.empty()){
		return false;
	}

	string testChar;
	for (int i=0;i<stringVector.size();i++){
		testChar = stringVector[i];
		for (int j=0;j<testChar.size();j++){
			if (!isalpha(testChar[j])){
				return false;
			}
		}
	}

	string lowerTest1,lowerTest2,lowerTest3,lowerTest4;
	for (int i=0;i<candidateStringVector.size();i++) {
		lowerTest1=candidateStringVector[i];
		for (int j=0;j<stringVector.size();j++){
			lowerTest2=stringVector[j];
			for (int k=0;k<lowerTest1.size();k++){
				lowerTest1[k]=tolower(lowerTest1[k]);
			}
			for (int k=0;k<lowerTest2.size();k++){
				lowerTest2[k]=tolower(lowerTest2[k]);
			}
			if (lowerTest1 == lowerTest2) {
				return false;
			}
		}
	}

	for (int i=0,j=1;i<stringVector.size();i++,j++){
		if (j==stringVector.size()){
			lowerTest3=stringVector[i];
			lowerTest4=stringVector[0];
		}
		else{
			lowerTest3=stringVector[i];
			lowerTest4=stringVector[j];
		}
		convertToLowerCase(lowerTest3);
		convertToLowerCase(lowerTest4);

		if (lowerTest3==lowerTest4){
			return false;
		}

	}

	for (int i=0;i<stringVector.size();i++){
		candidateStringVector.push_back(stringVector[i]);
	}
	recursiveFindPalindromes(candidateStringVector,currentStringVector);
	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	return palindromes;
}

