#pragma once

#include <functional>
#include <iostream>
#include <map>



class Game {

public:
    
    
public:
    bool isRunning;
    std::string commandA;
    std::string commandB;


public:
    Game();
    void Awake();
    void Start();
    void Update();

    void Interact(const std::string& Item);
    std::function<void(const std::string)> InteractLinkFunction;
};