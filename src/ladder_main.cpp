#include "ladder.h"

int main(){
    //std::cout << is_adjacent("cat", "hat");

    std::cout << edit_distance_within("seep", "sleep", 1);
    
    set<string> words;
    
    load_words(words, "src/words.txt");
    vector<string> ladder = generate_word_ladder("chat", "cat", words);
    print_word_ladder(ladder);
    ladder = generate_word_ladder("marty", "curls", words);
    print_word_ladder(ladder);
    //for(auto s: ladder)
   //     std::cout << std::endl << s;
    //print_word_ladder(ladder);
    
    //verify_word_ladder();
    return 0;
}