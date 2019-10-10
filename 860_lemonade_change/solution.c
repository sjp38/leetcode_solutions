bool lemonadeChange(int* bills, int billsSize){
    int nr_changes[3] = {0,};    /* number of 5, 10, 20 dollars */
    int bill, i;
    for (i = 0; i < billsSize; i++) {
        bill = bills[i];
        if (bill == 5) {
            nr_changes[0]++;
        } else if (bill == 10) {
            nr_changes[1]++;
            if (nr_changes[0] == 0)
                return false;
            nr_changes[0]--;
        } else if (bill == 20) {
            nr_changes[2]++;
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
