//"/Users/jinhanhan/Documents/jinh/scrabble/words.txt"
#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;
const int MAXRESULTS   = 20;    // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in


//loadDictionary(istream &dictfile, vector<string>& dict);
int loadDictionary(istream &dictfile, string dict[])
{
    string line;
    
    if(getline(dictfile, line))
    {
        *dict = line;
        return (1 + loadDictionary(dictfile, dict + 1)); //increase index using recursive
    }
    else
        return 0;
}
//Places each string in dictfile into the array dict. Returns the number of words read into dict.
//This number should not be larger than MAXDICTWORDS since that is the size of the array.

bool CopyChkr(string target, string results[], int start, int max)
{
    //cout << "results " << results[0] << " " <<results[1]<<results[2]<<endl;
    if(start >= max)
        return false;
    
    if(target == *results)
    {
        return true;}
    else
        return CopyChkr(target, results + 1, start + 1, max);
}

// the function helps assigning target into *AssignedResult ( it is &results[count])
int copier(string target, const string dict[], int size, string results[], string AssignedResult[], int& count)
{
    if(size == 0)
        return 0;
    
    cout << " ddd " << size << endl;
    cout << " ddda " << target << endl;
    if(target == *dict)
    {
        if(CopyChkr(target, results, 0, count)) //It is checker whereas result takes value or not.
            return 0;
        else
        {
            *AssignedResult = target;
            cout << "address  " << (1 + copier(target, dict + 1, size - 1, results, AssignedResult + 1, count)) << endl;
            cout << endl;
            return (1 + copier(target, dict + 1, size - 1, results, AssignedResult + 1, count));
        }
    }
    else
        return copier(target, dict + 1, size - 1, results, AssignedResult, count);
}

void otherWord_Loop(int i, int max, string otherWord, string rest, const string dict[], const int& size, string results[], int& count);


void printPermutation(string otherWord, string theWord, const string dict[], const int& size, string results[], int& count)
{
    if (theWord.length() == 0)
    {
        cout <<"The possible word : "<< otherWord << endl;
        
        // The results[count] is specific data in the result sequence
        // it takes otherWord which is a possible word consist of letters from input word
        count += copier(otherWord, dict, size, results, &results[count], count);
    }
    else
    {
        //cout << " check other word " << otherWord << " "  << theWord.length() << endl;
        otherWord_Loop(0, (int)theWord.length(), otherWord, theWord, dict, size, results, count);
        //Using substr, it automatically delete a letter[index] in "theWord".
    }
}

void otherWord_Loop(int i, int max, string otherWord, string theWord, const string dict[], const int& size, string results[], int& count)
{
   
    if(i >= max)
        return;
    
    for(i=0;i<max;i++)
    {
        //cout<<"check " << otherWord << " "<< theWord[i] << " chk "<<theWord.substr(0, i) << " " <<theWord.substr(i+1) << "  " << theWord.substr(0, i) + theWord.substr(i+1) << endl;
        //cout<<"ddd s "<<theWord[i] << endl;
        printPermutation(otherWord + theWord[i], theWord.substr(0, i) + theWord.substr(i+1), dict, size, results, count);
        //cout<<"ddd s2 "<<theWord[i] << endl;
        //As increasing i,they add later order letters to the otherWord.
        //substr(i) peeks letter of index.
        //
    }
}


//permute(string word, vector<string>& dict, vector<string>& results);
int permute(string word, const string dict[], int size, string results[])
{
    int count = 0;
    //otherWord is assigned that ""
     printPermutation("", word, dict, size, results, count);
    
    return count;
}
// Places all the permutations of word, which are found in dict into results.
// Returns the number of matched words found.
// This number should not be larger than MAXRESULTS since that is the size of the array.
// The size is the number of words inside the dict array.

void recurPrint(const string results[], int size)
{
    
    if(size == 0)
    {
        return;
    }
    else
    {
        cout << results->length() << "what is" << size << endl;
        for(int i =0; i< size;i++)
        {
            cout << "Matching word " << results[i] << endl;
        }
        cout << "The number of matched words : "<<size  << endl;
    }
}
// Prints size number of strings from results.
// The results can be printed in any order, which are found in dict into results

int main()
{
    
    string p[5];
    vector<string> pp;
    pp.push_back("dd");
    pp.push_back("aa");
    p[0]="a";
    p[1]="a";
    p[2]="a";
    p[3]="a";
    p[4]="a";
    cout << p << endl;
    cout << p+1 << endl;
    cout << &pp[0] << endl;
    cout << &pp[1] << endl;
    cout <<"dd d "<< *p << endl;
    string results[MAXRESULTS];
    string dict[MAXDICTWORDS];
    ifstream dictfile;         // file containing the list of words
    int nwords;                // number of words read from dictionary
    string word;
    
    dictfile.open("/Users/jinhanhan/Documents/jinh/scrabble/words.txt");
    if (!dictfile) {
        cout << "File not found!" << endl;
        return (1);
    }
    
    nwords = loadDictionary(dictfile, dict);
    
    //string exampleDict[] = {"kool", "moe", "dee"};
    //int numResults = recursivePermute("look", exampleDict, 3, results);
    //assert(numResults == 1 && results[0] == "kool");
    cout <<"sdsdsdf  "<< p+1 <<endl;
    cout << "Please enter a string for an anagram: ";
    cin >> word;
    
    int numMatches = permute(word, dict, nwords, results);
    
    if (!numMatches)
        cout << "No matches found" << endl;
    else
        recurPrint(results, numMatches);
    
    dictfile.close();
    
}


