#!/bin/bash 

for x in "date" "value" "type_" "Internet" "EdF" "paidby" "Irene" "Andrey" "ts"; do echo ${x}; sed -i -E 's/'${x}'/"'${x}'"/g' ./src/bills.json; done
sed -i -E 's/(/\[/g' ./src/bills.json
sed -i -E 's/)/\]/g' ./src/bills.json