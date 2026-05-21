#ifndef PROGRA_III_NODE_H
#define PROGRA_III_NODE_H
#include <map>
#include <string>

using namespace std;
using Context = map<string, int>;


struct Node {
    virtual Node* eval(Context ctx) = 0;
    virtual Node* clone() = 0;
    virtual ~Node() = default;
};

class Multiple: public Node {
    public:
    Multiple(Node* lhs, Node* rhs);
    Node* eval(Context ctx);
    Node* clone() override;
    private:
    Node* lhs;
    Node* rhs;
};
class Addition: public Node {
    public:
    Addition(Node* lhs, Node* rhs);
    Node* eval(Context ctx) override;
    Node* clone() override;
    private:
    Node* lhs;
    Node* rhs;
};

class Number: public Node {
  public:
    explicit Number(int val);
    Node* eval(Context ctx) override;
    Node* clone() override;
private:
    int val;
};

class Variable: public Node {
    public:
    Variable(string text);
    Node* eval(Context ctx) override;
    Node* clone() override;
    private:
    string text;

};


#endif //PROGRA_III_NODE_H