#pragma once
#include <algorithm>
#include <string>

#include "StringManipulationLibrary.h"

struct Action {
    std::string description;
    std::function<void(std::string value)> mainAction;
    std::function<void()> endFunc;
};

using ActionMap = std::map<std::string, Action>;

void OptionSelection(const ActionMap& actions, std::string commandA, std::string commandB) {
    std::string answer;
    bool waitingForAnswer = true;

    // COMMAND ITEM

    do {
        system("cls");
        std::cout << "What should i do?\n";
        std::getline(std::cin, answer);

        std::transform(answer.begin(), answer.end(), answer.begin(), ::toupper);

        answer = Trim(answer);

        SplitString(answer, commandA, commandB);

        if (actions.find(commandA) != actions.end()) {
            actions.at(commandA).mainAction(commandB);
            waitingForAnswer = false;
        }
        else {
            std::cout << "Invalid Command...\n";
            system("pause");
        }

    } while (waitingForAnswer);
}

ActionMap SettingCommands(const std::function<void(const std::string)>& InteractFunc) {

    ActionMap actions;
    actions["INTERACT"] = Action{
            "Interact with an object in the room",
            [&](const std::string objectToInteract) { InteractFunc(objectToInteract); },
            [&]() { std::cout << "End Func...\n"; }
    };

    return actions;
}