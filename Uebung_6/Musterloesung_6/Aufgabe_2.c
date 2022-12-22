int answerPhone (int isMorning, int isMom, int isSleeping) {
    int ret = !isSleeping && (!isMorning || isMom);

    return ret;
}
