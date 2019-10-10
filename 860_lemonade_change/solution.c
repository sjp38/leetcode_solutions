bool lemonadeChange(int* bills, int billsSize){
    int nr_changes[2] = {0,};    /* number of 5, 10 dollars */
    int i;
    for (i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            nr_changes[0]++;
        } else if (bills[i] == 10) {
            nr_changes[1]++;
            if (nr_changes[0] == 0)
                return false;
            nr_changes[0]--;
        } else { /* 20 dollars */
            if (nr_changes[0] > 0 && nr_changes[1] > 0) {
                nr_changes[0]--;
                nr_changes[1]--;
            } else if (nr_changes[0] >= 3) {
                nr_changes[0] -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}
