#!/bin/bash
echo -en "\E[6n" > /dev/tty
read -s -d '['
read -s -d ';' ROW
read -s -d 'R' COLUMN

if [ $# != 1 ]; then
  echo "Excepted only one argument"
  exit -1
fi

if [[ $1 == "ROW" ]]; then
	exit $ROW
fi

if [[ $1 == "COLUMN" ]]; then
	exit $COLUMN
fi

echo "Excepted \$1 to be in {\"ROW\", \"COLUMN\"}"
exit -1

