#include <iostream>
#include <fstream>
#include <string>
#include "queue.h"
#include "stack.h"
using namespace std;

int main() {

  	ifstream input("myFile.txt", ios::in);

	//Obtain word count of document
	int wordCount = 0;
	string word;
	while(!input.eof()){
		getline(input, word, ' ');
		wordCount++;
	}
	
	//Add words to queue will determining the longest word
	input.clear();
	input.seekg(0, ios::beg);
	int longestWord = 0;
	Queue<string> myQueue(wordCount+1);

	while(!input.eof()){
		getline(input, word, ' ');
		if(longestWord <= word.length()){
			longestWord = word.length();
		}
		myQueue.enqueue(word);
	}
	input.close();
  bool period;
	char pun;
	//Inverts words and displays them to the screen
	Stack<char> myStack(longestWord);
	while(!myQueue.isEmpty()){
		string currWord = myQueue.dequeue();
		for (int n = 0; n < currWord.length(); n++){
			if(currWord[n] == '.' or currWord[n] == '!' or currWord[n] == '?' or currWord[n] == ','){
				period = true;
				pun = currWord[n];
			}
			myStack.push(&currWord[n]);
		}
		if(period){myStack.pop();}
		while(!myStack.isEmpty()){
			char c = *myStack.pop();
			cout << c;
		}
		if(period){
			cout << pun;
			period = false;
		}
		cout << " ";
	}
}