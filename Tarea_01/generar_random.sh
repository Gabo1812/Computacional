#!/bin/bash
#Gabriel Alvarez C00368
# Asigno la cantidad de numeros aleatorios N a utilizar y la cantidad de archivos i que quiero utilizar
N=$1  #Primer argumento de la func.
i=$2  #Segundo argumento de la func.
# Ahora vamos a generar 5 archivos ( desde i=0 hasta algún valor i) usando un  ciclo for
for j in $(seq 0 $i) # Genera un rango de 0 hasta i
do 	
	# Ejecuta random.sh y filtra solo líneas con números y extrae los primeros N valores 
	selected_numbers=$(./random.sh | grep -E "^[0-9]+$"| head -n "$N")

	# Generar el nombre del archivo 
	output_file="rand_${j}_${N}.dat"

	# Guardar los números en el archivo
	echo "$selected_numbers" > "$output_file"

	# Confirmar la creación del archivo
	echo "Archivo generado: $output_file"
done
