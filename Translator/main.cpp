//main method
#include "FileProcessor.h"

//invoked by three command line arugments
//they represent input file name, desired output file name and translation command
//checks if commands asks to translate from english or tutnese
//uses file processor class to translate
int main(int argc, char**argv) {
  for (int i=1; i<=3; i++) {
    if(argv[i] == NULL) {
      cout << "Cannot run the code" << endl;
    }
  }
  FileProcessor a;
  std::string command = argv[3];
  if(command.compare("E2T") == 0) {
    a.processEnglishFile(argv[1],argv[2]);
    cout<<"File has been translated"<<endl;
  }
  else if(command.compare("T2E") == 0) {
    a.processTutneseFile(argv[1],argv[2]);
    cout<<"File has been translated"<<endl;
  }
  else{
    cout<<"Invalid Entry"<<endl;
  }
}
