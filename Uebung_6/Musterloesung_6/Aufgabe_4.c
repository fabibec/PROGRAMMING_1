int noThirteenSum (int a, int b, int c) {
    int ret;

    if (a == 13) {
        ret = 0;
    } else if (b == 13) {
        ret = a;
    } else if (c == 13) {
        ret = a + b;
    } else {
        ret = a + b + c;
    }

    return ret;
}