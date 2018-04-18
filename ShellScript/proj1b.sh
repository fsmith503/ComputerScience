#echo "my_script"
#echo "starting to run script"
mkdir $1
cd $1
mkdir Dir1
chmod 770 Dir1
mkdir Dir2
chmod 775 Dir2
cd Dir2
touch File2
chmod 640 File2
#ls -l
cd ..
cd Dir1
touch File1
chmod 400 File1
#ls -l
mkdir Dir3
cd Dir3
mkdir Dir4
cd Dir4
touch File4
chmod 666 File4
touch File3
chmod 200 File3
cd ..
cd ..
chmod 000 Dir3
#echo "done running script"

