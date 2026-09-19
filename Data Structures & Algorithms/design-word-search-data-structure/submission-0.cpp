class Node{
private:
    vector<Node*> next;
    bool word;
public:
    Node(): next(26), word(false){
        for(auto &x: next){
            x = nullptr;
        }
    }

    Node* getNext(int idx){
        return next[idx];
    }

    bool isWord(){
        return word;
    }

    void setWord(){
        word = true;
    }

    void setNext(int idx){
        next[idx] = new Node;
    }

};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(auto &x: word){
            if(!curr->getNext(x - 'a')){
                curr->setNext(x - 'a');
            }
            curr = curr->getNext(x - 'a');
        }
        curr->setWord();
    }

    bool search(Node* curr, string& word, int i){
        if(curr == nullptr) return false;
        if(i == word.size()){
            return curr->isWord();
        }
        char x{word[i]};
        if(x == '.'){
            for(int j{0}; j < 26; j++){
                bool res = search(curr->getNext(j), word, i+1);
                if(res == true) return true;
            }
            return false;
        } else {
            return search(curr->getNext(x - 'a'), word, i + 1);
        }
    }
    
    bool search(string word) {
        return search(root, word, 0);
    }
};
