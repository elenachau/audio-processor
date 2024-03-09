//
// Created by trentr on 4/7/22.
//

#include "Console.h"
#include "Controller.h"

int main()
{
    Console console;
    Controller controller;
    controller.setUI(&console);
    controller.run();

    return 0;
}