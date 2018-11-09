# !/bin/bash

# Allowed Commands
# ================
# - mkdir
# - touch
# - cd
# - chmod
# - mv
# - cp
# - rm
# - rmdir

if [ $# -eq 0 ]; then
	echo "Usage: $0 <dir>"
	exit 1
fi

if [ ! -d $1 ]; then
	echo "Parent Directory \"$1\" does not exist!"
	exit 1
fi

echo "--- Creating Directories ---"
mkdir -p $1/Dir1
mkdir -p $1/Dir2
mkdir -p $1/Dir1/Dir3
mkdir -p $1/Dir1/Dir3/Dir4

echo "--- Creating Files ---"
touch $1/Dir1/File1
touch $1/Dir2/File2
touch $1/Dir1/Dir3/Dir4/File3
touch $1/Dir1/Dir3/Dir4/File4

echo "--- Setting Permissions ---"
chmod 770 $1/Dir1/
chmod 775 $1/Dir2/
chmod 750 $1/Dir1/Dir3/Dir4/
chmod 400 $1/Dir1/File1
chmod 640 $1/Dir2/File2
chmod 200 $1/Dir1/Dir3/Dir4/File3
chmod 666 $1/Dir1/Dir3/Dir4/File4
chmod 000 $1/Dir1/Dir3/
