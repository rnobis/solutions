#!/bin/bash

cd "$(cd "$(dirname "$0")" ; pwd)/.."

EXEC="$1"
CMD="$2"
INF="$3"
OUTF="$4"
EXPECTEDF="$5"
VALGF="$6"

TMPF=$(mktemp /tmp/$USER.$EXEC.XXXXX)
trap cleanup EXIT
cleanup()
{
    rm -f $TMPF
}

echo
echo "./$EXEC $CMD $INF > $OUTF"
./$EXEC $CMD $INF > $OUTF
echo "cat $OUTF"
echo
cat $OUTF | sed 's/^/   /'
echo
echo -n "Checking expected output: $EXPECTEDF - "

# -- Check program output -- #

OUT_OKAY=0

diff -w $OUTF $EXPECTEDF > $TMPF && OUT_OKAY=1 

(( $OUT_OKAY == 1 )) && echo "okay"
(( $OUT_OKAY != 1 )) \
    && echo "FAIL. Expected: " \
    && echo \
    && cat $EXPECTEDF | sed 's/^/   /' \
    && echo

echo -n "Performing memory-check with valgrind: - "

# -- Check valgrind output -- #

VALG_OKAY=0

valgrind --tool=memcheck --leak-check=full --verbose \
    --log-file=$VALGF ./$EXEC $INF > $OUTF

cat "$VALGF" | grep -q "ERROR SUMMARY: 0 errors from 0 contexts" && VALG_OKAY=1

(( $VALG_OKAY == 1 )) && echo "okay"
(( $VALG_OKAY != 1 )) \
    && echo "FAIL!" \
    && echo "Examine the file '$VALGF' to diagnose the problem."

echo
(( $OUT_OKAY == 1 )) && (( $VALG_OKAY == 1 )) && exit 0
exit 1

