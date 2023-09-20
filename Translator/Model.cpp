//implementation file
#include "Model.h"

Model :: Model(){} // constructor
Model :: ~Model(){} //destructor

//takes in a single character, matches it to the case and returns a string
//constants change while vowels stay the same
//repeated for both capitalized and lower case letters
string Model :: translateSingleCharacter(char letter) {
  switch (letter){
    case 'B':
      return "Bub";
    case 'b':
      return "bub";
    case 'C':
      return "Cash";
    case 'c':
      return "cash";
    case 'D':
      return "Dud";
    case 'd':
      return "dud";
    case 'F':
      return "Fuf";
    case 'f':
      return "fuf";
    case 'G':
      return "Gug";
    case 'g':
      return "gug";
    case 'H':
      return "Hash";
    case 'h':
      return "hash";
    case 'J':
      return "Jay";
    case 'j':
      return "jay";
    case 'K':
      return "Kuck";
    case 'k':
      return "kuck";
    case 'L':
      return "Lul";
    case 'l':
      return "lul";
    case 'M':
      return "Mum";
    case 'm':
      return "mum";
    case 'N':
      return "Nun";
    case 'n':
      return "nun";
    case 'P':
      return "Pub";
    case 'p':
      return "pub";
    case 'Q':
      return "Quack";
    case 'q':
      return "quack";
    case 'R':
      return "Rug";
    case 'r':
      return "rug";
    case 'S':
      return "Sus";
    case 's':
      return "sus";
    case 'T':
      return "Tut";
    case 't':
      return "tut";
    case 'V':
      return "Vuv";
    case 'v':
      return "vuv";
    case 'W':
      return "Wack";
    case 'w':
      return "wack";
    case 'X':
      return "Ex";
    case 'x':
      return "ex";
    case 'Y':
      return "Yub";
    case 'y':
      return "yub";
    case 'Z':
      return "Zub";
    case 'z':
      return "zub";
    default:
      return string (1, letter);
    }
  }

  //takes in a single character, matches it to the case and returns a string
  //used when there are two same letters next to each other
  //takes capitalization into account
  string Model:: translateDoubleCharacter(char letter) {
    switch (letter){
      case 'B':
        return "Squabub";
      case 'b':
        return "squabub";
      case 'C':
        return "Squacash";
      case 'c':
        return "squacash";
      case 'D':
        return "Squadud";
      case 'd':
        return "squadud";
      case 'F':
        return "Squafuf";
      case 'f':
        return "squafuf";
      case 'G':
        return "Squagug";
      case 'g':
        return "squagug";
      case 'H':
        return "Squahash";
      case 'h':
        return "squahash";
      case 'J':
        return "Squajay";
      case 'j':
        return "squajay";
      case 'K':
        return "Squakuck";
      case 'k':
        return "squakuck";
      case 'L':
        return "Squalul";
      case 'l':
        return "squalul";
      case 'M':
        return "Squamum";
      case 'm':
        return "squamum";
      case 'N':
        return "Squanun";
      case 'n':
        return "squanun";
      case 'P':
        return "Squapub";
      case 'p':
        return "squapub";
      case 'Q':
        return "Squaquack";
      case 'q':
        return "squaquack";
      case 'R':
        return "Squarug";
      case 'r':
        return "squarug";
      case 'S':
        return "Squasus";
      case 's':
        return "squasus";
      case 'T':
        return "Squatut";
      case 't':
        return "squatut";
      case 'V':
        return "Squavuv";
      case 'v':
        return "squavuv";
      case 'W':
        return "Squawack";
      case 'w':
        return "squawack";
      case 'X':
        return "Squaex";
      case 'x':
        return "squaex";
      case 'Y':
        return "Squayub";
      case 'y':
        return "squayub";
      case 'Z':
        return "Squazub";
      case 'z':
        return "squazub";
      //adding vowels for double character as they need to change
      case 'A':
        return "Sqauta";
      case 'a':
        return "squata";
      case 'E':
        return "Sqaute";
      case 'e':
        return "squate";
      case 'I':
        return "Sqauti";
      case 'i':
        return "squati";
      case 'O':
        return "Sqauto";
      case 'o':
        return "squato";
      case 'U':
        return "Sqautu";
      case 'u':
        return "squatu";
      default:
        return string (1, letter);
      }
    }

  //takes in a word in tutnese and returns english translation
  //looks through the word for each tutnese alphabet
  //if found, then replaces tutnese alphabet with english
  string Model :: translateTutnese(string tut_word) {
    //http://www.cplusplus.com/reference/string/string/find/
    //checking for vowels
    std :: size_t found = tut_word.find("Sqauta");
    if(found!=std::string::npos) {
      tut_word.replace(found,6,"Aa");
    }
    found = tut_word.find("squata");
    if(found!=std::string::npos) {
      tut_word.replace(found,6,"aa");
    }
    found = tut_word.find("Sqaute");
    if(found!=std::string::npos) {
      tut_word.replace(found,6,"Ee");
    }
    found = tut_word.find("squate");
    if(found!=std::string::npos) {
      tut_word.replace(found,6,"ee");
    }
    found = tut_word.find("Sqauti");
    if(found!=std::string::npos) {
      tut_word.replace(found,6,"Ii");
    }
    found = tut_word.find("squati");
    if(found!=std::string::npos) {
      tut_word.replace(found,6,"ii");
    }
    found = tut_word.find("Sqauto");
    if(found!=std::string::npos) {
      tut_word.replace(found,6,"Oo");
    }
    found = tut_word.find("squato");
    if(found!=std::string::npos) {
      tut_word.replace(found,6,"oo");
    }
    found = tut_word.find("Sqautu");
    if(found!=std::string::npos) {
      tut_word.replace(found,6,"Uu");
    }
    found = tut_word.find("squatu");
    if(found!=std::string::npos) {
      tut_word.replace(found,6,"uu");
    }
    //checking for double letters
    found = tut_word.find("Squabub");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"Bb");
    }
    found = tut_word.find("squabub");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"bb");
    }
    found = tut_word.find("Squacash");
    if(found!=std::string::npos) {
      tut_word.replace(found,8,"Cc");
    }
    found = tut_word.find("squacash");
    if(found!=std::string::npos) {
      tut_word.replace(found,8,"cc");
    }
    found = tut_word.find("Squadud");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"Dd");
    }
    found = tut_word.find("squadud");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"dd");
    }
    found = tut_word.find("Squafuf");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"Ff");
    }
    found = tut_word.find("squafuf");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"ff");
    }
    found = tut_word.find("Squagug");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"Gg");
    }
    found = tut_word.find("squagug");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"gg");
    }
    found = tut_word.find("Squahash");
    if(found!=std::string::npos) {
      tut_word.replace(found,8,"Hh");
    }
    found = tut_word.find("squahash");
    if(found!=std::string::npos) {
      tut_word.replace(found,8,"hh");
    }
    found = tut_word.find("Squajay");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"Jj");
    }
    found = tut_word.find("sqaujay");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"jj");
    }
    found = tut_word.find("Sqaukuck");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"Kk");
    }
    found = tut_word.find("squakuck");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"kk");
    }
    found = tut_word.find("Squalul");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"Ll");
    }
    found = tut_word.find("squalul");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"ll");
    }
    found = tut_word.find("Squamum");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"Mm");
    }
    found = tut_word.find("squamum");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"mm");
    }
    found = tut_word.find("Squanun");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"Nn");
    }
    found = tut_word.find("squanun");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"nn");
    }
    found = tut_word.find("Sqaupub");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"Pp");
    }
    found = tut_word.find("squapub");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"pp");
    }
    found = tut_word.find("Sqauquack");
    if(found!=std::string::npos) {
      tut_word.replace(found,9,"Qq");
    }
    found = tut_word.find("squaquack");
    if(found!=std::string::npos) {
      tut_word.replace(found,9,"qq");
    }
    found = tut_word.find("Sqaurug");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"Rr");
    }
    found = tut_word.find("squarug");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"rr");
    }
    found = tut_word.find("Sqausus");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"Ss");
    }
    found = tut_word.find("squasus");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"ss");
    }
    found = tut_word.find("Sqautut");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"Tt");
    }
    found = tut_word.find("squatut");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"tt");
    }
    found = tut_word.find("Sqauvuv");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"Vv");
    }
    found = tut_word.find("squavuv");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"vv");
    }
    found = tut_word.find("Sqauwack");
    if(found!=std::string::npos) {
      tut_word.replace(found,8,"Ww");
    }
    found = tut_word.find("squawack");
    if(found!=std::string::npos) {
      tut_word.replace(found,8,"ww");
    }
    found = tut_word.find("Sqauex");
    if(found!=std::string::npos) {
      tut_word.replace(found,6,"Xx");
    }
    found = tut_word.find("squaex");
    if(found!=std::string::npos) {
      tut_word.replace(found,6,"xx");
    }
    found = tut_word.find("Sqauyub");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"Yy");
    }
    found = tut_word.find("squayub");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"yy");
    }
    found = tut_word.find("Sqauzub");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"Zz");
    }
    found = tut_word.find("squazub");
    if(found!=std::string::npos) {
      tut_word.replace(found,7,"zz");
    }
    //checking for single letters
    found = tut_word.find("Bub");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"B");
    }
    found = tut_word.find("bub");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"b");
    }
    found = tut_word.find("Cash");
    if(found!=std::string::npos) {
      tut_word.replace(found,4,"C");
    }
    found = tut_word.find("cash");
    if(found!=std::string::npos) {
      tut_word.replace(found,4,"c");
    }
    found = tut_word.find("Dud");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"D");
    }
    found = tut_word.find("dud");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"d");
    }
    found = tut_word.find("Fuf");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"F");
    }
    found = tut_word.find("fuf");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"f");
    }
    found = tut_word.find("Gug");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"G");
    }
    found = tut_word.find("gug");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"g");
    }
    found = tut_word.find("Hash");
    if(found!=std::string::npos) {
      tut_word.replace(found,4,"H");
    }
    found = tut_word.find("hash");
    if(found!=std::string::npos) {
      tut_word.replace(found,4,"h");
    }
    found = tut_word.find("Jay");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"J");
    }
    found = tut_word.find("jay");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"j");
    }
    found = tut_word.find("Kuck");
    if(found!=std::string::npos) {
      tut_word.replace(found,4,"K");
    }
    found = tut_word.find("kuck");
    if(found!=std::string::npos) {
      tut_word.replace(found,4,"k");
    }
    found = tut_word.find("Lul");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"L");
    }
    found = tut_word.find("lul");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"l");
    }
    found = tut_word.find("Mum");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"M");
    }
    found = tut_word.find("mum");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"m");
    }
    found = tut_word.find("Nun");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"N");
    }
    found = tut_word.find("nun");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"n");
    }
    found = tut_word.find("Pub");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"P");
    }
    found = tut_word.find("pub");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"p");
    }
    found = tut_word.find("Quack");
    if(found!=std::string::npos) {
      tut_word.replace(found,5,"Q");
    }
    found = tut_word.find("quack");
    if(found!=std::string::npos) {
      tut_word.replace(found,5,"q");
    }
    found = tut_word.find("Rug");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"R");
    }
    found = tut_word.find("rug");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"r");
    }
    found = tut_word.find("Sus");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"S");
    }
    found = tut_word.find("sus");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"s");
    }
    found = tut_word.find("Tut");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"T");
    }
    found = tut_word.find("tut");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"t");
    }
    found = tut_word.find("Vuv");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"V");
    }
    found = tut_word.find("vuv");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"v");
    }
    found = tut_word.find("Wack");
    if(found!=std::string::npos) {
      tut_word.replace(found,4,"W");
    }
    found = tut_word.find("wack");
    if(found!=std::string::npos) {
      tut_word.replace(found,4,"w");
    }
    found = tut_word.find("Ex");
    if(found!=std::string::npos) {
      tut_word.replace(found,2,"X");
    }
    found = tut_word.find("ex");
    if(found!=std::string::npos) {
      tut_word.replace(found,2,"x");
    }
    found = tut_word.find("Yub");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"Y");
    }
    found = tut_word.find("yub");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"y");
    }
    found = tut_word.find("yub");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"y");
    }
    found = tut_word.find("Zub");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"Z");
    }
    found = tut_word.find("zub");
    if(found!=std::string::npos) {
      tut_word.replace(found,3,"z");
    }
    return tut_word;
  }
