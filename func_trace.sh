#!/bin/bash
EXECUTABLE="$1"
TRACELOG="$2"
while read TRACEFLAG FADDR CADDR; do
FNAME="$(addr2line -f -e ${EXECUTABLE} ${FADDR}|head -1)"
if test "${TRACEFLAG}" = "entry"
then
CNAME="$(addr2line -f -e ${EXECUTABLE} ${CADDR}|head -1)"
CLINE="$(addr2line -s -e ${EXECUTABLE} ${CADDR})"
echo "Enter ${FNAME} called from ${CNAME} (${CLINE})"
fi
if test "${TRACEFLAG}" = "exit"
then
echo "Exit  ${FNAME}"
fi
done < "${TRACELOG}"