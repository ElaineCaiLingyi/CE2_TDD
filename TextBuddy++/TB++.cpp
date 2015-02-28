// Cai Lingyi
// A0115990B

/*assumptions: 
1) deletion happens after display. ie. the user knows what he is deleting
2) cases of the command matters. --> lower case
3) cases of user input --> lower case

important note:
The file is saved to the disk after each user operation (in the case of crashes) 
and when the user exit the program. (double confirm)

*/
#include "TB++.h"

const string TextBuddy:: MESSAGE_COMMAND = "command: ";
const string TextBuddy:: MESSAGE_INVALID_ENTRY = "ERROR: Invalid entry";
const string TextBuddy:: MESSAGE_ERROR_DELETE = "ERROR: Cannot delete as it does not exist";
const string TextBuddy:: MESSAGE_ALL_SORTED = "All lines are sorted alphabetically";

string TextBuddy:: MESSAGE_LINE_ADDED(string input){

	ostringstream oss;
	oss<< "added to " <<_filename<< ": \""<<input<<"\""<<endl;
	string s = oss.str();
	return s;
}

string TextBuddy:: MESSAGE_LINE_DELETED (string deletedline){

	ostringstream oss;
	oss<< "deleted from "<<_filename<<": \""<<deletedline<<"\""<<endl;
	string s = oss.str();
	return s;
}

string TextBuddy:: MESSAGE_IS_EMPTY (){

	ostringstream oss;
	oss<<_filename<<" is empty"<<endl;
	string s=oss.str();
	return s;
}

string TextBuddy:: MESSAGE_ALL_CLEARED (){

	ostringstream oss;
	oss<<"all content deleted from " <<_filename<<endl;
	string s=oss.str();
	return s;
}

/*=========================================================================================================================================*/

TextBuddy:: TextBuddy(string filename){

	_filename=filename;
	_numberoflines=0;
}

TextBuddy:: ~TextBuddy(){
}

void TextBuddy::addLine(){
	
	string input;
	getline(cin,input);
	string addedline=input.substr(1); //substr 1 gets rid of the blank space after the command
	text.push_back(addedline); 
	_numberoflines++;
	cout<<MESSAGE_LINE_ADDED(addedline);
	writeFile();    
	//updating the file after every action: add, delete and clear.
	//in case the program ends unexpectedly. ie, not through 'exit'
}

void TextBuddy:: deleteLine(){
	
	int n;
	cin>>n;
	if(_numberoflines==0 || _numberoflines>text.size() || n>text.size()){
		cout<<MESSAGE_ERROR_DELETE<<endl; 
        return;
	}
	cout<<MESSAGE_LINE_DELETED(text[n-1]); 
	//must display message before erasing, else the line wont be there anymore
	text.erase(text.begin()+n-1);
	_numberoflines--;
	writeFile();
}

void TextBuddy:: displayAll(){

	if (text.empty()){
		cout<<MESSAGE_IS_EMPTY();
	}
	for (int i=0;i<text.size();i++){
		cout<<i+1<<". "<<text[i]<<endl;
	}
}

void TextBuddy:: clearAll(){

	text.clear();
	_numberoflines=0;
	cout<<MESSAGE_ALL_CLEARED();
	writeFile();
}

//assumption: all the lines the user entered are in lower cases.
void TextBuddy:: sortFile(){

	std::sort(text.begin(),text.end());  
	cout<<MESSAGE_ALL_SORTED<<endl; 

}

string TextBuddy:: searchFile(string word){
	
	int count=0; size_t found;
	ostringstream oss;

	for (int i=0;i<text.size();i++){
		found=0;
		found=text[i].find(word);
		if(found!=string::npos) {
			count++;
			oss<<text[i]<<endl;
		}
	}

	if (count==0){
		return "The word cannot be found\n";
	}
	else { 
		return oss.str();
	}
}


void TextBuddy:: identifyCommandType(string command){

	_switchcase=0; //default; in the case of invalid entry

	if (command=="add"){
		_switchcase=1;
	}
	else if (command=="delete"){
		_switchcase=2;
	}
	else if (command=="display"){
		_switchcase=3;
	}
	else if (command=="clear"){
		_switchcase=4;
	}
	else if (command=="exit"){
		_switchcase=5;
	}
	else if (command=="sort"){
		_switchcase=6;
	}
	else if (command=="search"){
		_switchcase=7;
	}
}

void TextBuddy:: executeCommand(string command){

	identifyCommandType(command);
	switch (_switchcase) {
		case 1: {
			addLine();
		}
			break;
		case 2: {
			deleteLine();
		}
			break;
	    case 3: displayAll();
			break;
		case 4: clearAll();
			break;
		case 5: {
			 writeFile();
			 exit(1);
		}
			break;
		case 6: {
			sortFile(); 
		}
			break;
		case 7: {
			string word;
			cin>>word;
			cout<<searchFile(word); 
		}
			break;
		default: cout<<MESSAGE_INVALID_ENTRY<<endl;
  }

}

// for updating the file.
void TextBuddy:: writeFile(){   

	ofstream file;
	file.open(_filename);
	for(int i=0;i<text.size();i++){
        file<<text[i]<<endl;
	}
	file.close();
} 

int main(int argc,char* argv[]){       

    if (argc<2){
       cout<<"Usage: "<<argv[0]<<" FILENAME.TXT"<<endl;
       return 1;
    }
    cout<<"Welcome to TextBuddy. "<<argv[1]<<" is ready for use"<<endl;
	
	TextBuddy tb(argv[1]); string command;

	//endless loop until 'exit'
	while(true){
		cout<<tb.MESSAGE_COMMAND; 
		cin>>command;
		tb.executeCommand(command);
	}
    return 0;
}