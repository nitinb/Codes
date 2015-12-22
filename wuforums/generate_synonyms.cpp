#include <iostream>
#include <map>

using namespace std;

std::map<std::string, std::string> dict;

void generate_synonyms(std::string input, std::string prefix){
    if(input.length() == 0){
        return;
    }

    for(int i = 1; i < input.length(); i++){
        std::string rem_string = input.substr(i, input.length()-i);
        std::string search_string = input.substr(0, i);
        if(dict.find(search_string) != dict.end() && dict[search_string] != search_string){
            std::cout << prefix << dict[search_string] << rem_string << std::endl;
            generate_synonyms(rem_string, prefix + dict[search_string]);
        }
        generate_synonyms(rem_string, prefix + search_string);
    }
}

int main(){
   std::string input = "AABCS";

   dict["F"] = "H";
   dict["A"] = "FGH";
   dict["AB"] = "CS";

   generate_synonyms(input, "");
}
