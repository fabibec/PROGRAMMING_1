int checkAdmission (int you, int date) {
    int ret;

    if (you <= 2 || date <= 2) {
        ret = 0;
    } else if ( (you >= 8) || (date >= 8) ) {
        ret = 2;
    } else {
        ret = 1;
    }

    return ret;
}