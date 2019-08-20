#!/bin/bash

echo -n "Result: "
if [[ $? ]]
then
	echo -e "[${GREEN}OK${NC}]"
else
	echo -e "[${RED}ERROR${NC}]"
fi
echo -e -n '\n'