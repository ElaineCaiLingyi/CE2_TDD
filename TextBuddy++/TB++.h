#ifndef TB_H
#define TB_H

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

class TextBuddy {

//private attributes for use in the class itself
public:
	    string _filename;
		vector<string> text;
		int _switchcase;
		int _numberoflines;


public:
		//constructor
		//input: name of text file
		TextBuddy(string);	
		~TextBuddy();

		//setters, or getters
		void addLine();
		void deleteLine();
		void writeFile();
		void identifyCommandType(string);
		void executeCommand(string);
		void displayAll();
		void clearAll();
		void sortFile();

		//removal of magic strings through all these:
		static const string MESSAGE_COMMAND;
		static const string MESSAGE_INVALID_ENTRY;
		static const string MESSAGE_ERROR_DELETE;
		static const string MESSAGE_ALL_SORTED;

		string MESSAGE_LINE_ADDED(string);
		string MESSAGE_LINE_DELETED (string);
		string MESSAGE_IS_EMPTY ();
		string MESSAGE_ALL_CLEARED();

};

#endif