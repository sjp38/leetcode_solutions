bool judgeCircle(char * moves){
    int x = 0, y = 0;
    for (; *moves != '\0'; moves++) {
        if (*moves == 'U')
            y += 1;
        else if (*moves == 'D')
            y -= 1;
        else if (*moves == 'L')
            x -= 1;
        else
            x += 1;
    }
    if (x == 0 && y == 0)
        return true;
    return false;
}
