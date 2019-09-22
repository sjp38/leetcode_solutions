/*
if (year is not divisible by 4) then (it is a common year)
else if (year is not divisible by 100) then (it is a leap year)
else if (year is not divisible by 400) then (it is a common year)
else (it is a leap year)
*/
int days_in_months_common_year[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days_in_months_leap_year[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static inline bool is_leap_year(int year)
{
    if (year % 4)
        return false;
    if (year % 100)
        return true;
    if (year % 400)
        return false;
    return true;
}

int dayOfYear(char * date){
    int year, month, day;
    int *days_map;
    int i;
    int ret;
    
    date[4] = '\0';
    date[7] = '\0';
    year = atoi(date);
    month = atoi(&date[5]);
    day = atoi(&date[8]);
    days_map = is_leap_year(year) ? days_in_months_leap_year : days_in_months_common_year;
    for (i = 0, ret = 0; i < month - 1; i++)
        ret += days_map[i];
    return ret + day;
}
