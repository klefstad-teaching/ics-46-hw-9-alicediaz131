#include "ladder.h"

int main(){
    //std::cout << is_adjacent("cat", "hat");

    std::cout << edit_distance_within("cat", "cheat", 1);

    set<string> words;
    load_words(words, "src/words.txt");

    vector<string> ladder = generate_word_ladder("cat", "cheat", words);

    for(auto s: ladder)
        std::cout << std::endl << s;

    
    //verify_word_ladder();
    return 0;
}