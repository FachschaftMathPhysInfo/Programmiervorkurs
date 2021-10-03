#include <iostream>
#include <vector>

struct DVD {
    int id;
    std::string titel;
    bool ausgeliehen;
};

class DVDSammlung {
private:
    std::vector<DVD> _dvds;
    std::string _name;

public:
    DVDSammlung(std::string name): _name(name) {}

    int hinzufuegen(const std::string& name){
        int last_id = _dvds.size() + 1;
        _dvds.push_back(DVD{last_id, name, false});
        return _dvds.size();
    }

    void sammlungUmbenennen(std::string name) {
        _name = name;
    }

    void print(){
        std::cout << "Die Sammlung '" << _name 
                  << "' enthält folgende Filme:" << std::endl;
        if(_dvds.size() == 1)
            std::cout << _dvds[0].titel;
        else {
            for(int i = 0; i < _dvds.size(); i++) {
                if (i < _dvds.size()-1)
                    std::cout << _dvds[i].titel << ", ";
                else
                    std::cout << _dvds[i].titel;
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    DVDSammlung filme("Actionfilme");
    filme.hinzufuegen("Rocky");
    filme.hinzufuegen("Rocky2");
    filme.print();
    filme.sammlungUmbenennen("Superfilme");
    filme.print();
    return 0;
}
