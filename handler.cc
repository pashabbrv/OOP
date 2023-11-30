#include "handler.h"

Operations Handler::get_operation() {
    char key = input_.reader();
    Operations operation;
    if (operations_.count(key) == 0)
        operation = Operations::Unknown;
    else
        operation = operations_[key];
    return operation;
}

Handler::Handler(Input& input, const std::string& new_file) : input_(input) {
    std::ifstream file(new_file);
    if (!file.is_open()) {
        std::cout << "Failed to open file" << std::endl;
        exit(0);
    }

    char key;
    std::string operation;
    std::unordered_map<char, Operations> operations_map; 
    std::unordered_map<std::string, bool> operations_assigned; 

    operations_assigned["up"] = false;
    operations_assigned["down"] = false;
    operations_assigned["left"] = false;
    operations_assigned["right"] = false;
    operations_assigned["quit"] = false;
    operations_assigned["yes"] = false;
    operations_assigned["no"] = false;
    operations_assigned["first_level"] = false;
    operations_assigned["second_level"] = false;

    while (file >> key >> operation) {
        key = tolower(key);
        if (operations_map.count(key) > 0) {
            std::cout << "Error: Collision. Key " << key << " is assigned to multiple operations." << std::endl;
            exit(0);
        }
        if (operations_assigned[operation]) {
            std::cout << "Error: Collision. Action " << operation << " is assigned to multiple keys." << std::endl;
            exit(0);
        }
        operations_map[key] = convert_operation(operation);
        operations_assigned[operation] = true;
    }

    for (const auto& pair : operations_assigned) {
        if (!pair.second) {
            std::cout << "Error: Action " << pair.first << " is not assigned to any key" << std::endl;
            exit(0);
        }
    }
    operations_ = operations_map;
    file.close();
}

Operations Handler::convert_operation(const std::string& operation) {
    if (operation == "up")
        return Operations::GoUp;
    else if (operation == "down")
        return Operations::GoDown;
    else if (operation == "left")
        return Operations::GoLeft;
    else if (operation == "right")
        return Operations::GoRight;
    else if (operation == "quit")
        return Operations::Quit;
    else if (operation == "yes")
        return Operations::Yes;
    else if (operation == "no")
        return Operations::No;
    else if (operation == "first_level")
        return Operations::Level1;
    else if (operation == "second_level")
        return Operations::Level2;
    else
        return Operations::Unknown;
}