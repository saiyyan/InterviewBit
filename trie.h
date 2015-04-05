#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <Queue> 
#include <math.h>
using namespace std;

/*
Autocomplete & Trie class 
Author: Devruth Khanna
*/


struct TrieNode{
	bool is_end; //is the last letter of a word
	char cur_char;
	vector<TrieNode*> children;
	TrieNode(char cur) : cur_char(cur), children(27), is_end(false){}
};


class Trie{

private:
	int count; 
	TrieNode* root;
public:
	Trie(){
		root = new TrieNode('\0'); 
	}

	void insert(const string& word){
	
		TrieNode* n = root;
		for (int i = 0; i < word.size(); ++i){
			char cur = tolower(word[i]);
			int posn = cur - 'a';
		
			if (!n->children[posn]){
				TrieNode* child = new TrieNode(cur);
				n->children[posn] = child;
				n = child;
			}
			else{
				n = n->children[posn];
			}
		}
		n->is_end = true;
	}
	
	/*Traverse the Trie starting from node n*/
	void Traverse(TrieNode* n, string& word, vector<string> & all_words){
		if (n->is_end) {
			all_words.push_back(word);
		}

		for (int i = 0; i < n->children.size(); ++i){
			TrieNode* child = n->children[i];
			if (child){
				char ch = child->cur_char;
				word.push_back(ch);
				Traverse(child, word, all_words);
				word.pop_back();
			}
		}
	}

	/*Prints all words inside the Trie*/
	void PrintTrie(){ 
		TrieNode* n = root;
		string word = "";
		vector<string> res;
		Traverse(n, word, res);
		for (int i = 0; i < res.size(); ++i) cout << res[i] << endl;

	}
	
	/*Given a prefix, print all words in the trie that have the prefix*/
	vector<string> Autocomplete(string prefix){
		TrieNode* n = root;
		vector<string> res;

		for (int i = 0; i < prefix.size(); ++i){
			char cur_char = tolower(prefix[i]);
			int posn = cur_char - 'a';
		        n = n->children[posn];
			if (!n) return res;
		}
		string str;

		Traverse(n, str, res);
		for (int i = 0; i < res.size(); ++i){
			cout << prefix+res[i] << endl;
		}

		return res;
	}

};

/*Given a list of strings, find the largest common prefix */
string LongestCommonPrefix(const vector<string> strs){
	string res = "";
	int i = 0;
	string first = strs[0];
	int j = 1;
	int k = i;

	for (int k = i; k < first.size(); ++k){
		for (int j = 1; j < strs.size(); ++j){
			if (first[i] != strs[j][k]) {
				return res;
			}
		}
		res += first[i++];
	}
	return res;
}
