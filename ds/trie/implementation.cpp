// implementation of trie data structure
#include <bits/stdc++.h>
using namespace std;

struct Trie{
    bool isLeaf;
    unordered_map<char, Trie*> map;
};

Trie *getNewTrieNode(){
    Trie *node = new Trie;
    node->isLeaf = false;

    return node;
}

void insert(Trie *&head, string str){
    if(head == nullptr){
        head = getNewTrieNode();
    }

    Trie *curr = head;
    int index = 0;
    while(index < str.length()){
        char ch = str[index];
        // create a new node if path doesnt exist
        if(curr->map.find(ch) == curr->map.end())
            curr->map[ch]= getNewTrieNode();

        curr = curr->map[ch];
        index++;
    }

    curr->isLeaf = true;
}

// iterative function to search a string in the Trie. It returns true is the string is found in the Trie, else it returns false
bool search(Trie *head, string str){
    // return false if Trie is empty
    if(head == nullptr) return false;

    Trie *curr = head;
    int index = 0;
    while(index < str.length()){
        char ch = str[index];
        curr = curr->map[ch];

        // if string is invalid (reached end of the path in trie)
        if(curr == nullptr) return false;

        index++;      // move to next charecter
    }

    // if current node is a leaf and we have reached the end of the string, return true
    return curr->isLeaf;
}

// returns true if given node has any children
bool haveChildren(Trie const *curr){
    for(auto it:curr->map)
        if(it.second != nullptr)
            return true;

    return false;
}

// Recursive function to delete a string in Trie
bool deletion(Trie *&curr, string str){
    if(curr == nullptr) return false;       // if trie is empty

    // if we have not reached the end of the string
    int index = 0;
    if(index < str.length()){
        // recur for the node corresponding to the next charecter in the string
        // if it return true and doesnt have any children, then deleted it
        if(curr != nullptr && curr->map.find(str[index]) != curr->map.end() &&
            deletion(curr->map[str[index]], str.substr(index+1)) && curr->isLeaf == false
        ){
            if(!haveChildren(curr)){        // deleting the non-leaf parent
                delete curr;
                curr = nullptr;
                return true;
            }
            else
                return false;
        }
    }

    // if we have reached the end of the string
    if(index == str.length() && curr->isLeaf){
        if(!haveChildren(curr)){
            delete curr;                // delete curr node
            curr = nullptr;
            return true;                //  delete non-leaf parent
        }

        // if the current node is a leaf node and have childrens
        else {
            curr->isLeaf = false;   // mark the current node as non-leaf node (dont delete it)
            return false;           // and don't delete it's parent node
        }
    }

    return false;
}

// Driver function
int main(){
    Trie* head = nullptr;

	insert(head, "hello");
	cout << search(head, "hello") << " ";		// print 1

	insert(head, "helloworld");
	cout << search(head, "helloworld") << " ";	// print 1

	cout << search(head, "helll") << " ";		// print 0 (Not present)

	insert(head, "hell");
	cout << search(head, "hell") << " ";		// print 1

	insert(head, "h");
	cout << search(head, "h") << endl; 		// print 1 + newline

	deletion(head, "hello");
	cout << search(head, "hello") << " ";		// print 0 (hello deleted)
	cout << search(head, "helloworld") << " ";	// print 1
	cout << search(head, "hell") << endl;		// print 1 + newline

	deletion(head, "h");
	cout << search(head, "h") << " ";			// print 0 (h deleted)
	cout << search(head, "hell") << " ";		// print 1
	cout << search(head, "helloworld") << endl; // print 1 + newline

	deletion(head, "helloworld");
	cout << search(head, "helloworld") << " ";	// print 0
	cout << search(head, "hell") << " ";		// print 1

	deletion(head, "hell");
	cout << search(head, "hell") << endl;		// print 0 + newline

	if (head == nullptr)
		cout << "Trie empty!!\n";				// Trie is empty now

	cout << search(head, "hell");				// print 0
}
