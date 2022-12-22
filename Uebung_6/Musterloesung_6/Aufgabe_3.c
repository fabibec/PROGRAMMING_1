int squirrelParty (int numCigars, int isWeekend) {
    int ret = (numCigars >= 40) && ( (numCigars <= 60) || isWeekend );

    return ret;
}