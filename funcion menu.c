char menu (char opcion)
{
	printf("Bienvenido al MENU DE OPCIONES del Museo del Prado.\n ");
	printf ("Por favor seleccione una de las siguientes opciones: \n");
	printf("1. Registrar obra\n");
	printf("2. Buscar obra\n");
	printf("3. Eliminar obra\n");
	printf("4. Listado de obras\n");
	printf("5. Almacén\n");
	printf("6. Salir\n");
	//default printf("Opcion incorrecta");
	scanf ("%c", &opcion);
	while (getchar() != '\n');
	return opcion;	
}

//usar el switch case para las opciones 
//Usar el while para que se repita el menu cada vez que acabes una actividad hasta que el usuario pida salir

int main()
{
	//Primeras llamadas 
	int i;
	int num; //numero de obras a registrar
	datosobra *obra; //puntero para introducir los datos de las obras, esto ira en un archivo 
					//Futura modificación 
	
	menu(opcion);//llamamos a la opcion menu 
	//empezamos el switch para el menu

	do
	{	
		switch(opcion)
		{
			case 1: //registrar obra se puede hacer mas de una a la vez 
				printf("Ha seleccionado la opcion Registrar Obras\n")
				printf("Introduzca el numero de obras que desea registrar: ");
				scanf("%d", &num);
				
				obra = (datosobra *) malloc(num * sizeof(datosobra));
				
				for(i=0; i<num; i++)
				{
					fflush(stdin);
					printf("Nombre de la %d obra: \n", i+1);
					gets(obra[i].nombreobra);
					printf("Autor de la %d obra: \n", i+1);	
					gets(obra[i].autor);
					printf("e -> Escultura \n p -> Pintura \n"); //Tiene que introducirse solo una de las opciones  
					gets(obra[i].tipo);
					printf("Fecha de creacion: \n");
					scanf("%d %d %d", &, &, &); 
					printf("Fecha de aquisición: \n");
					scanf("%d %d %d", &, &, &);
					//El programa debe registrar el codigo
					/*obra[i].codigo = i+1; No sirve */
					
				}
				
				if(num==1)	printf("Su obra ha sido registrada correctamente\n");
				else		printf("Sus obras han sido registradas correctamente\n");
				
			//Hay que meter todos estos datos en el archivo registrodeobras.txt
			
			case 2: //Buscar las obras tanto por codigo como por nombre
				int buscar;
				char buscarnombre[20], buscarcodigo[20]; 
				printf("Ha seleccionado la opcion buscar obra\n");
				printf("Indique si desea buscar por nombre (1) o por codigo (2): \n");
				scanf("%d", &buscar);
				
				if(buscar == 1) //Buscador por nombre
				{
					printf("Introduzca el nombre de la obra: \n");
					gets(buscarnombre);
					buscarobra (buscarnombre, buscarcodigo);
				}
				
				if(buscar == 2) //Buscador por codigo
				{
					printf("Introduzca el codigo de la obra: \n");
					gets(buscarcodigo);
					buscarobra (buscarnombre, buscarcodigo);
					
				}
				
				else 
				{
					printf("Opcion incorrecta");
					return 1; //Buscar el numero para volver al menu
				}
				
			case 3:
			case 4:
			case 5:
				
			case 6:
				return; //Buscar numero para salir del programa 
				
			default printf("Opcion incorrecta\n");	
		}
	} while(1);

	system("pause");
	return 0;
	
}
