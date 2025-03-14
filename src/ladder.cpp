#include "ladder.h"

void error(string word1, string word2, string msg){
    std::cerr << word1 << ": " << word2 << ": " << msg;
}




bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int s1size = str1.length();
    int s2size = str2.length();
    vector<vector<int>> matrix(s1size+1, vector<int>(s2size+1));
    for (int i = 0; i <= s1size; i++)
        matrix[i][0] = i;
    for (int i = 0; i <= s2size; i++) 
        matrix[0][i] = i; 
    for (int i = 1; i <= s1size; i++)
        for (int j = 1; j <= s2size; j++) 
            if (str1[i-1] == str2[j-1])
                matrix[i][j] = matrix[i-1][j-1];
            else
                matrix[i][j] = 1 + min({matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]});

    return matrix[s1size][s2size] <= d;
}


bool is_adjacent(const string& word1, const string& word2){
    //wsize1 = word1.size();
    //wsize2 = word2.size();
    int sizediff = word1.size() - word2.size();

    if (-1 <= sizediff && 1 >= sizediff)
        return edit_distance_within(word1, word2, 1);
    else return false;
}
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<string> ladder_queue;
    ladder_queue.push(begin_word);
    vector<string> result;
    //result.push_back(begin_word);

    set<string> visited;
    visited.insert(begin_word);


    while(!ladder_queue.empty()){
        int len = ladder_queue.size();
        result.push_back(ladder_queue.front());
        for (int i = 0; i < len; ++i) {
            string word = ladder_queue.front();
            ladder_queue.pop();
            for(string w: word_list)
                if(!visited.contains(w))
                    if(is_adjacent(word, w)){
                        visited.insert(w);
                        //vector<string> new_ladder = ladder;
                        
                        if(w == end_word){
                        result.push_back(w);
                            return result;
                        }
                        ladder_queue.push(w);
    }

}
    }
    return result;
}

/*
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    //queue<string> ladder_queue;
    queue<vector<string>> ladder_queue;
    
    ladder_queue.push(vector<string>{begin_word});
    //vector<string> result;

    //int wordlen = begin_word.size();
    //int level = 1;
    //unordered_set<string> set(word_list.begin(), word_list.end());
    set<string> visited;

    visited.insert(begin_word);

    while(!ladder_queue.empty()){
        std::cout << "\nladder count:" << ladder_queue.size() << std::endl;
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        for(string w: word_list)
            if(!visited.contains(w))
                if(is_adjacent(last_word, w)){
                    if(!visited.contains(w)){
                        visited.insert(w);
                        //std::cout <<"\nvisited now has: " << w << " adjacanent to " << last_word << std::endl;
                        vector<string> new_ladder = ladder;
                        new_ladder.push_back(w);
                        if(w == end_word)
                            return new_ladder;
                        ladder_queue.push(new_ladder);
                    }
                    
                }
            //else std::cout << "\nfound contained word.\n";

    }
    vector<string> result;
    return result;
}
*/
void load_words(set<string> & word_list, const string& file_name){
    fstream inFile;
    inFile.open(file_name);
    //for(auto s: inFile)
        

    for (string word; inFile >> word;)
        word_list.insert(word);
}

void print_word_ladder(const vector<string>& ladder){
    if (ladder.size() == 0)
        std::cout << ("No word ladder found.\n");
    else{
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