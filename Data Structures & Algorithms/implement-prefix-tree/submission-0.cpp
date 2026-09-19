class Node{
private:    
    vector<Node*> next;
    bool word;
public:
    Node(): next(26), word(false) {
        for(auto &x: next){
            x = nullptr;
        }
    }

    vector<Node*>& getNext(){
        return next;
    }

    void setNext(int idx){
        next[idx] = new Node();
    }

    bool isWord(){
        return word;
    }

    void setWord(){
        word = true;
    }
};

class PrefixTree {
private:
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(auto &x: word){
            if(!temp->getNext()[x - 'a']){
                temp->setNext(x - 'a');
            }
            temp = temp->getNext()[x - 'a'];
        }
        temp->setWord();
    }
    
    bool search(string word) {
        Node* temp = root;
        for(auto &x: word){
            if(!temp->getNext()[x - 'a']){
                return false;
            }
            temp = temp->getNext()[x - 'a'];
        }
        return temp->isWord();
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(auto &x: prefix){
            if(!temp->getNext()[x - 'a']){
                return false;
            }
            temp = temp->getNext()[x - 'a'];
        }
        return true;
    }
};
