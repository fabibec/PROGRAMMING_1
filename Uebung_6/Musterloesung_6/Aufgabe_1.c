int main (void) {
    int i = 10;
    int n = i++%5;

    // Wert von n ist 0, da der Wert des Ausdrucks "i++" 10 ist (Post-Inkrement)

    // 1) Bei Präfix-Inkrementierung wäre der Wert des Ausdrucks "++i" 11, somit
    // n dann 1:
    // int i = 10;
    // int n = i++%5; // n ist 1

    // 2) Um Unklarheiten im Code zu vermeiden könnte man es vermeiden, den Wert
    // eines Ausdrucks mit Prä/Post-Inkrement-Operatoren zu verwenden, also z.B.:
    // int i = 10;
    // int n = i % 5;
    // i++;

    return 0;
}