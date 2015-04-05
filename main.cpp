#include "trie.h"


int main(int argc, char** argv){

	Trie *trie = new Trie();
	trie->insert("abc");	trie->insert("abe");
	trie->insert("abd");
	trie->insert("ABC");
	trie->insert("apple");

	trie->Autocomplete("ab");
	cout << endl;
	trie->PrintTrie();
	cout << endl;
	
	vector<string> strs = { "abc", "abe", "able", "ac" };
	cout << LongestCommonPrefix(strs) << endl;

	return 0;
	
}
