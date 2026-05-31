#include <iostream>
using namespace std;

class Tree {
    public:
        virtual void draw() = 0; 
        
        virtual ~Tree() {} 
};

class SlashTree : public Tree {
    public:
        void draw() override {
            cout << "Drawing 1:" << endl;
            cout << " /\\ " << endl;
            cout << "//\\\\" << endl;
        }
};

class StarTree : public Tree {
    public:
        void draw() override {
            cout << "Drawing 2:" << endl;
            cout << " /\\ " << endl;
            cout << "/**\\" << endl;
        }
};

class PlusTree : public Tree {
    public:
        void draw() override {
            cout << "Drawing 3:" << endl;
            cout << " /\\ " << endl;
            cout << "/++\\" << endl;
        }
};

int main() {
    Tree* forest[3];

    SlashTree tree1;
    StarTree tree2;
    PlusTree tree3;

    forest[0] = &tree1;
    forest[1] = &tree2;
    forest[2] = &tree3;

    for (int i = 0; i < 3; i++) {
        forest[i] -> draw();
    }

    return 0;
}