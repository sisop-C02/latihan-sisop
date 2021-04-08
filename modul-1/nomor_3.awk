# nomor 3 gawk

/Iris-setosa/   {
    ++n;
    if ($1 > 5.4) {
        print "Luas petal pada baris ", n, " adalah ", ($3 * $4);
    }
}
