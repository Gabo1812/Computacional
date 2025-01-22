#!/bin/bash

# Definir el archivo de salida
output_file="rand_combined.dat"

# Concatenar los archivos en columnas y guardarlo en un nuevo archivo
paste rand_*.dat > "$output_file"

# Confirmar que la concatenación se ha realizado
echo "Archivos concatenados en columnas en el archivo: $output_file"

