#include <iostream>
#include <fstream>
#include <cstring>
#include <boost/lexical_cast.hpp>
#include "hs.h"
#include "hs_pcre_mnrl.h"
#include <mnrl.hpp>

using namespace std;

char *strdup(const char *src_str) noexcept {
    char *new_str = new char[std::strlen(src_str) + 1];
    std::strcpy(new_str, src_str);
    return new_str;
}

void printUsage(){
 cout << "Usage: pcre2mnrl [OPTION] <regex file path> <mnrl file path>" << endl;
 cout << "	-f, --force 	Force compilation by discarding invalid modifiers." << endl;
 cout << "	-a, --abort	Abort compilation if there are invalid modifiers." << endl;
}

int main(int argc, char *argv[]) {
  
    // -f force to compile by discarding invalid modifiers
    // -a abort compilation if there are invalid modifiers.
    long flag_option; 
    int fflag = 0;
    int aflag = 0;
    char choice = 'n';
    while((flag_option = getopt(argc, argv, "af")) != -1){
      switch(flag_option){
	case 'f':
	  if(fflag){
	    printUsage();
	    return 1;
	  } else {
	    aflag ++;
	    fflag ++;
	  }
	  choice = 'f';
	  break;
	case 'a':
	  if(aflag){
	    printUsage();
	    return 1;
	  } else {
	    aflag ++;
	    fflag ++;
	  }
	  choice = 'a';
	  break;
	default:
	  printUsage();
	  return 1;
      }
    }
  
    if (argc != 4) {
	printUsage();
        return 1;
    }
    
    // read in the file
    ifstream infile(argv[2]);
    string line;
    
    vector<string> expressions;
    vector<const char*> cexpressions;
    vector<unsigned> ids;
    vector<unsigned> flags;

    unsigned i = 0;
    while(getline(infile, line)) {
        
        size_t start_loc = line.find_first_of("/");
        size_t end_loc = line.find_last_of("/");

        // check that we have 3 parts (i.e. 2 / characters)
        if(start_loc == string::npos || end_loc == string::npos){
            cerr << "Rule on line " << i+1 << " was not surrounded by slashes!" << endl;
            exit(5);
        }
        
        string expr = line.substr(start_loc + 1, end_loc - 1);
        //cout << "EXPR: " << expr << endl;
        string mods = line.substr(end_loc + 1, line.size());
        //cout << "MODS: " << mods << endl;

        // convert the modifiers
        int e_flags = 0;
        bool failed = false;
        if(mods.size() > 0) {
            for(char &m : mods) {
                // PAY ATTENTION note that we are ORing things together
                // DON'T FORGET A BREAK
                switch(m) {
                case 'i':
                    e_flags |= HS_FLAG_CASELESS;
                    break;
                case 'm':
                    e_flags |= HS_FLAG_MULTILINE;
                    break;
                case 's':
                    e_flags |= HS_FLAG_DOTALL;
                    break;
                case 'H':
                    e_flags |= HS_FLAG_SINGLEMATCH;
                    break;
                default:
		    if(choice == 'f'){
		      continue;
		    } else if (choice == 'a') {
		      failed = true; 
		      cerr << "Unsupported modifier '" << m << "' on line " << i+1 << endl;
		    }
                }
            }
        }        
        
        // if we failed to parse, continue
        if(failed) {
            cerr << "Rule on line " << i+1 << " had unsupported modifiers, skipping" << endl;
        } else {

            expressions.push_back(expr);
            const char *cexpr = strdup(expr.c_str());
            cexpressions.push_back(cexpr);

            //
            ids.push_back(i);

            flags.push_back(e_flags);
        }
        
        i++;        
    }

    hs_compile_error_t *compile_err;
    MNRL::MNRLNetwork mnrl("pcre");

    if (hs_pcre_mnrl_multi(cexpressions.data(),
                     mnrl,
                     &flags[0],
                     &ids[0],
                     cexpressions.size(),
                     &compile_err) != HS_SUCCESS) {
        cerr << "ERROR: Unable to compile PCRE expression file " << argv[2] << " expression number " << compile_err->expression << " : " << compile_err->message << endl;
        cerr << " pcre: " << expressions[compile_err->expression] << endl;
        cerr << " flags: " << flags[compile_err->expression] << endl;
    }
    
    mnrl.exportToFile(argv[3]);
    
    return 0;
    
}
