int fixTeenAge (int n) {
    if (n >= 13 && n <= 19 && n != 15 && n != 16)
        return 0;

    return n;
}

int sumNoTeens (int a, int b, int c) {
    int ret = 0;

    ret += fixTeenAge(a);
    ret += fixTeenAge(b);
    ret += fixTeenAge(c);

    return ret;
}