#include "keyboard.h"

KeyboardDriver::KeyboardDriver(InterruptManager* manager) 
: InterruptHandler(0x21, manager), dataport(0x60), commandport(0x64) {
    while (commandport.Read() & 0x1) {
        dataport.Read();
    }
    commandport.Write(0xAE); // activate interrupts
    commandport.Write(0x20); // get current state
    uint8_t status = (dataport.Read() | 1) & ~0x10;
    commandport.Write(0x60); // set state
    dataport.Write(status);
    dataport.Write(0xF4);
}

KeyboardDriver::~KeyboardDriver() {

}

void printf(char*);

uint32_t KeyboardDriver::HandleInterrupt(uint32_t esp) {
    uint8_t key = dataport.Read();

    static bool shift = false;

    if (key == 0x36 || key == 0x2A) { shift = true; }
    if (key == 0xAA || key == 0xB6) { shift = false; }

    if (key < 0x80) {
        switch (key) {
            case 0xFA: break;
            case 0x36: case 0x2A: break;
            case 0x45: case 0xC5: break;
            case 0x02: printf("1"); break;
            case 0x03: printf("2"); break;
            case 0x04: printf("3"); break;
            case 0x05: printf("4"); break;
            case 0x06: printf("5"); break;
            case 0x07: printf("6"); break;
            case 0x08: printf("7"); break;
            case 0x09: shift ? printf("*") : printf("8"); break;
            case 0x0A: printf("9"); break;
            case 0x0B: printf("0"); break;
            case 0x10: shift ? printf("Q") : printf("q"); break;
            case 0x11: shift ? printf("W") : printf("w"); break;
            case 0x12: shift ? printf("E") : printf("e"); break;
            case 0x13: shift ? printf("R") : printf("r"); break;
            case 0x14: shift ? printf("T") : printf("t"); break;
            case 0x15: shift ? printf("Y") : printf("y"); break;
            case 0x16: shift ? printf("U") : printf("u"); break;
            case 0x17: shift ? printf("I") : printf("i"); break;
            case 0x18: shift ? printf("O") : printf("o"); break;
            case 0x19: shift ? printf("P") : printf("p"); break;
            case 0x1E: shift ? printf("A") : printf("a"); break;
            case 0x1F: shift ? printf("S") : printf("s"); break;
            case 0x20: shift ? printf("D") : printf("d"); break;
            case 0x21: shift ? printf("F") : printf("f"); break;
            case 0x22: shift ? printf("G") : printf("g"); break;
            case 0x23: shift ? printf("H") : printf("h"); break;
            case 0x24: shift ? printf("J") : printf("j"); break;
            case 0x25: shift ? printf("K") : printf("k"); break;
            case 0x26: shift ? printf("L") : printf("l"); break;
            case 0x2C: shift ? printf("Z") : printf("z"); break;
            case 0x2D: shift ? printf("X") : printf("x"); break;
            case 0x2E: shift ? printf("C") : printf("c"); break;
            case 0x2F: shift ? printf("V") : printf("v"); break;
            case 0x30: shift ? printf("B") : printf("b"); break;
            case 0x31: shift ? printf("N") : printf("n"); break;
            case 0x32: shift ? printf("M") : printf("m"); break;
            case 0x0E: printf("\b"); break;
            case 0x1C: printf("\n"); break;
            default:
                char* foo = "*KEYBOARD 0x00* ";
                char* hex = "0123456789ABCDEF";
                foo[12] = hex[(key >> 4) & 0x0F];
                foo[13] = hex[key & 0x0F];
                printf(foo);
        }
    }
    return esp;
}