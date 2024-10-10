#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, std::string> queue;
    std::string cInpt;
    std::cout << "Lastname - add to queue" << std::endl;
    std::cout << "Next - escape from queue" << std::endl;
    std::cout << "Queue - showe the queue" << std::endl;
    std::cout << "Quit - close the programm" << std::endl;

    for (int i{ 0 }; cInpt != "Quit" || cInpt != "quit"; i++) {
        std::cin >> cInpt;
        if (cInpt == "Quit" || cInpt == "quit") break;
        if (cInpt == "Next" || cInpt == "next") { // удаление из очереди
            if (queue.empty()) {
                std::cout << "No patients to call" << std::endl;
            }
            else {
                std::cout << queue.begin()->second << " is escape the queue" << std::endl;
                queue.erase(queue.begin()->first);
            }
        }
        else if (cInpt == "Queue" || cInpt == "queue") { //вывод очереди на экран
            if (queue.empty()) {
                std::cout << "The queue is empty" << std::endl;
            } else {
                std::cout << "---start queue---" << std::endl;
                for (std::map<std::string, std::string>::iterator it = queue.begin(); it != queue.end(); it++) {
                    std::cout << it->second << std::endl;
                }
                std::cout << "---end queue---" << std::endl;
            }
        }
        else {                                      // добавление в очередь
            std::string cKey{ ""};
            for (int j{ 1 }; j < cInpt.size(); j++) {
                if (!queue.count(cInpt.substr(0, j))) {
                    cKey = cInpt.substr(0, j);
                    break;
                } 
            }
            if (cKey.empty()) cKey = cInpt + std::to_string(i);
            queue[cKey] = cInpt;
        }
    } 
    return 0;
}
