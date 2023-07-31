
extern int num;  // undefined external symbol
extern char *str; // undefined external symbol

void change()
{               // defined symbol in text section
    int x = 37; // local variable linker knows nothing about it
    num = x;
    str = "X";
}