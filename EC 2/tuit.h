#ifndef PROGRA3_EC2_tuit_H
#define PROGRA3_EC2_tuit_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Element {
public:
    int id;
    explicit Element(int id = 0) : id(id) {}
    virtual ~Element() = default;
    virtual void show(ostream& os) const = 0;
    virtual void save(ostream& os) const = 0;
};

class Emoji : public Element {
public:
    string symbol;
    int count;

    Emoji() : Element(0), count(0) {}
    Emoji(int id, const string& symbol, int count)
        : Element(id), symbol(symbol), count(count) {}

    void show(ostream& os) const override;
    void save(ostream& os) const override;

    friend ostream& operator<<(ostream& os, const Emoji& e);
    friend istream& operator>>(istream& is, Emoji& e);
};

class Media : public Element {
public:
    string filename;

    Media() : Element(0) {}
    Media(int id, const string& filename)
        : Element(id), filename(filename) {}

    void show(ostream& os) const override;
    void save(ostream& os) const override;

    friend ostream& operator<<(ostream& os, const Media& m);
    friend istream& operator>>(istream& is, Media& m);
};

class Poll : public Element {
public:
    string title;
    vector<string> options;
    int v1, v2, v3;

    Poll() : Element(0), v1(0), v2(0), v3(0) {}
    Poll(int id, const string& title, const vector<string>& options,  // const ref
         int v1, int v2, int v3)
        : Element(id), title(title), options(options),
          v1(v1), v2(v2), v3(v3) {}

    void show(ostream& os) const override;
    void save(ostream& os) const override;

    friend ostream& operator<<(ostream& os, const Poll& p);
    friend istream& operator>>(istream& is, Poll& p);
};

class Tuit {
public:
    string user_name;
    string text;
    vector<Element*> elements;
    vector<Tuit> replies;

    Tuit() = default;
    Tuit(const string& user_name, const string& text);

    // Regla de tres
    Tuit(const Tuit& other);
    Tuit& operator=(const Tuit& other);
    ~Tuit();

    Tuit& add_element(Element* elem);
    Tuit& add_reply(const Tuit& reply);
    Tuit& load_from(const string& filename);
    Tuit& save_to(const string& filename);
    Tuit& show(ostream& os);

    friend ostream& operator<<(ostream& os, const Tuit& t);
    friend istream& operator>>(istream& is, Tuit& t);

private:
    void clear();
    void copy_from(const Tuit& other);
};
#endif //PROGRA3_EC2_tuit_H