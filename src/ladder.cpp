#include "ladder.h"

void error(string word1, string word2, string msg){
    std::cerr << word1 << ": " << word2 << ": " << msg;
}



bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int s1size = str1.length();
    int s2size = str2.length();
    int str_diff = s1size-s2size;
    if (abs(str_diff) > d) return false;
    int distance = 0;

    for(int i1 = 0, i2 = 0; i1 < s1size && i2 < s2size; ++i1, ++i2){
        if(distance > d) return false;
        if(str1[i1] != str2[i2]) {
           ++distance;
            if (s1size > s2size) {
                --i2;
            }
            else if (s1size < s2size) {
                --i1;

            }
        }
    }

    return distance <= d;
}


bool is_adjacent(const string& word1, const string& word2){
    //wsize1 = word1.size();
    //wsize2 = word2.size();
    int sizediff = word1.size() - word2.size();

    if (abs(sizediff) <= 1)
        return edit_distance_within(word1, word2, 1);
    else return false;
}



vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    if(begin_word == end_word) return {};



    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});

    set<string> visited;


    visited.insert(begin_word);


    while(!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        for(string w: word_list){
            if( is_adjacent(last_word, w) && !visited.contains(w)){
                visited.insert(w);

                vector<string> new_ladder = ladder;
                new_ladder.push_back(w);
                if(w == end_word)
                    return new_ladder;
                ladder_queue.push(new_ladder);
            }
        }
    }
    return {};
}


void load_words(set<string> & word_list, const string& file_name){
    fstream inFile;
    inFile.open(file_name);
    //for(auto s: inFile)
        

    for (string word; inFile >> word;){
        tolower(word[0]);
        word_list.insert(word);
    }
}

void print_word_ladder(const vector<string>& ladder){
    if (ladder.size() == 0)
        std::cout << ("No word ladder found.\n");
    else{
        std::cout << ("Word ladder found: ");
    for(auto s: ladder)
        std::cout << s << " " ;
        std::cout << "\n";
    }
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void verify_word_ladder() {

    set<string> word_list;

    load_words(word_list, "src/words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);

    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);

    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);

    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);

    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);

    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);

}