#!/bin/bash

# Ruta al ejecutable
EXECUTABLE="./solong"

# Carpeta que contiene los archivos
FOLDER="./map/error/"

# Iterar sobre todos los archivos en la carpeta
for file in "$FOLDER"/*
do
    if [ -f "$file" ]; then
        echo "-----------------------------------------------------"
        echo "Procesando $file"
        $EXECUTABLE "$file"
    fi
done

# sed -i 's/\r//g' archivo.txt