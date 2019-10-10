bool judgeCircle(char * moves){
    int x = 0, y = 0;
    while (*moves) {
        if (*moves == 'U')
            y += 1;
        else if (*moves == 'D')
            y -= 1;
        else if (*moves == 'L')
            x -= 1;
        else
            x += 1;
        moves++;
    }
    if (x || y)
        return false;
    return true;
}
