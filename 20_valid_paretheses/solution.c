char *opened;
int nr_opened;
int cap_opened;

void init_opened(int cap)
{
    cap_opened = cap;
    nr_opened = 0;
    opened = (char *)malloc(sizeof(char) * cap_opened);
}

void push_opened(char c)
{
    if (nr_opened == cap_opened) {
        cap_opened *= 2;
        opened = (char *)realloc(opened, sizeof(char) * cap_opened);
    }
    opened[nr_opened++] = c;
}

char pop_opened(void)
{
    if (!nr_opened)
        return -1;
    return opened[--nr_opened];
}

bool chk_valid(char c)
{
    char expected;
    char open;
    switch (c) {
        case ')':
            expected = '(';
            break;
        case '}':
            expected = '{';
            break;
        case ']':
            expected = '[';
            break;
        default:
            break;
    }
    open = pop_opened();
    if (open != expected)
        return false;
    return true;
}

bool isValid(char * s){
    if (opened)
        free(opened);
    init_opened(10);
    while (*s) {
        switch (*s) {
            case '(':
            case '{':
            case '[':
                push_opened(*s);
                break;
            case ')':
            case '}':
            case ']':
                if (!chk_valid(*s))
                    return false;
                break;
            default:
                break;
        }
        s++;
    }
    if (nr_opened)
        return false;
    return true;
}
