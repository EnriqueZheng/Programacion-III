#include <iostream>
#include <vector>
#include <functional>
#include <list>
#include <string>
using namespace std;

struct Event {
    int document_id;
    string action;
};

class EventBus {
    vector<function<void(const Event&)>> subscribers;
public:
    void subscribe(const std::function<void(const Event&)>& subscriber) {
        subscribers.emplace_back(subscriber);
    }
    void publish(const Event& event) {
        for (auto& subscriber : subscribers) {
            subscriber(event);
        }
    }
};

template<typename... Args>
    auto f(Args... args){ return (args - ...); }

int main() {
    EventBus bus;
    bus.subscribe([](const Event& e) {
        std::cout << "[Audit] Documento "
        << e.document_id
        << " accion: "
        << e.action
        << '\n';
    }
    );

    bus.subscribe([](const Event& e) {
        std::cout << "[Metrics] Evento registrado: "
        << e.action
        << '\n';
    }
    );
    std::string username = "Ruben";
    bus.subscribe([username](const Event& e) {
        std::cout << "[User] "
        << username
        << " recibio evento sobre documento "
        << e.document_id
        << '\n';
    });
    bus.publish({42, "approved"});
    list A = {9,1,2,3,4};
    return 0;
}