#include "tuit.h"

static void strip_cr(string& s) {
    if (!s.empty() && s.back() == '\r')
        s.pop_back();
}

static vector<string> split(const string& s, char delim) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delim))
        tokens.push_back(token);
    return tokens;
}

static Element* parse_element(const string& line) {
    auto t = split(line, '|');
    if (t.empty()) return nullptr;

    if (t[0] == "Emoji" && t.size() >= 4)
        return new Emoji(stoi(t[1]), t[2], stoi(t[3]));

    if (t[0] == "Media" && t.size() >= 3)
        return new Media(stoi(t[1]), t[2]);

    if (t[0] == "Poll" && t.size() >= 7) {
        auto opts = split(t[3], ',');
        return new Poll(stoi(t[1]), t[2], opts,
                        stoi(t[4]), stoi(t[5]), stoi(t[6]));
    }
    return nullptr;
}

void Emoji::show(ostream& os) const {
    os << symbol << "\n";
}

void Emoji::save(ostream& os) const {
    os << "Emoji|" << id << "|" << symbol << "|" << count << "\n";
}

ostream& operator<<(ostream& os, const Emoji& e) {
    e.save(os);
    return os;
}

istream& operator>>(istream& is, Emoji& e) {
    string line;
    if (getline(is, line)) {
        strip_cr(line);
        auto t = split(line, '|');
        if (t.size() >= 4 && t[0] == "Emoji") {
            e.id     = stoi(t[1]);
            e.symbol = t[2];
            e.count  = stoi(t[3]);
        }
    }
    return is;
}

void Media::show(ostream& os) const {
    os << filename << "\n";
}

void Media::save(ostream& os) const {
    os << "Media|" << id << "|" << filename << "\n";
}

ostream& operator<<(ostream& os, const Media& m) {
    m.save(os);
    return os;
}

istream& operator>>(istream& is, Media& m) {
    string line;
    if (getline(is, line)) {
        strip_cr(line);
        auto t = split(line, '|');
        if (t.size() >= 3 && t[0] == "Media") {
            m.id       = stoi(t[1]);
            m.filename = t[2];
        }
    }
    return is;
}

void Poll::show(ostream& os) const {
    // Solo el título (sin prefijo "title : ")
    os << title << "\n";
    for (const auto& opt : options)
        os << "- " << opt << "\n";
}

void Poll::save(ostream& os) const {
    os << "Poll|" << id << "|" << title << "|";
    for (size_t i = 0; i < options.size(); ++i) {
        if (i > 0) os << ",";
        os << options[i];
    }
    os << "|" << v1 << "|" << v2 << "|" << v3 << "\n";
}

ostream& operator<<(ostream& os, const Poll& p) {
    p.save(os);
    return os;
}

istream& operator>>(istream& is, Poll& p) {
    string line;
    if (getline(is, line)) {
        strip_cr(line);
        auto t = split(line, '|');
        if (t.size() >= 7 && t[0] == "Poll") {
            p.id      = stoi(t[1]);
            p.title   = t[2];
            p.options = split(t[3], ',');
            p.v1      = stoi(t[4]);
            p.v2      = stoi(t[5]);
            p.v3      = stoi(t[6]);
        }
    }
    return is;
}

void Tuit::clear() {
    for (auto* e : elements) delete e;
    elements.clear();
    replies.clear();
}

void Tuit::copy_from(const Tuit& other) {
    user_name = other.user_name;
    text      = other.text;
    replies   = other.replies;
    elements.clear();
    for (auto* e : other.elements) {
        if (auto* em = dynamic_cast<Emoji*>(e))
            elements.push_back(new Emoji(*em));
        else if (auto* me = dynamic_cast<Media*>(e))
            elements.push_back(new Media(*me));
        else if (auto* po = dynamic_cast<Poll*>(e))
            elements.push_back(new Poll(*po));
    }
}

Tuit::Tuit(const string& user_name, const string& text)
    : user_name(user_name), text(text) {}

Tuit::Tuit(const Tuit& other) {
    copy_from(other);
}

Tuit& Tuit::operator=(const Tuit& other) {
    if (this != &other) {
        clear();
        copy_from(other);
    }
    return *this;
}

Tuit::~Tuit() {
    clear();
}

Tuit& Tuit::add_element(Element* elem) {
    elements.push_back(elem);
    return *this;
}

Tuit& Tuit::add_reply(const Tuit& reply) {
    replies.push_back(reply);
    return *this;
}

Tuit& Tuit::load_from(const string& filename) {
    ifstream in(filename);
    in >> *this;
    return *this;
}

Tuit& Tuit::save_to(const string& filename) {
    ofstream out(filename);
    out << *this;
    return *this;
}

Tuit& Tuit::show(ostream& os) {
    os << "====================\n";
    os << "@" << user_name << "\n";
    os << text << "\n";
    os << "--------------------\n";
    for (auto* e : elements)
        e->show(os);
    for (auto& r : replies)
        r.show(os);
    return *this;
}

ostream& operator<<(ostream& os, const Tuit& t) {
    os << "Tuit|" << t.user_name << "|" << t.text << "\n";
    for (auto* e : t.elements)
        e->save(os);
    for (const auto& r : t.replies)
        os << r;
    os.flush();
    return os;
}

istream& operator>>(istream& is, Tuit& t) {
    string line;
    
    while (getline(is, line)) {
        strip_cr(line);
        if (!line.empty()) break;
    }

    if (!is && line.empty()) return is;

    auto tokens = split(line, '|');
    if (tokens.size() < 3 || tokens[0] != "Tuit")
        return is;

    t.clear();
    t.user_name = tokens[1];
    t.text      = tokens[2];

    Tuit* current = &t;

    while (getline(is, line)) {
        strip_cr(line);
        if (line.empty()) continue;

        auto toks = split(line, '|');
        if (toks.empty()) continue;

        if (toks[0] == "Tuit" && toks.size() >= 3) {
            t.replies.emplace_back(toks[1], toks[2]);
            current = &t.replies.back();
        } else {
            Element* elem = parse_element(line);
            if (elem) current->elements.push_back(elem);
        }
    }
 
    return is;
}