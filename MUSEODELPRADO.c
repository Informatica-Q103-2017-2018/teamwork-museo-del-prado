
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20 //limita el numero de obras que se pueden almacenar a 20

typedef struct 
{
	int codigo; //debe tener una longitud de ocho digitos solo numeros 
	char nombreobra[30];
	char autor[30];
	char tipo; //escultura o pintura 
	int creacion;
	int adquisicion;
} datosobra;

typedef struct //estructura para la contraseña 
{
	char usuario[25];
	char clave[20];
} contrasena;

void menu ();
int existeUsuario(contrasena usuarioValido[], char nombre[], char clave[]);

int main()
{
	//Primeras llamadas 
	int i, j, k;
	int opcion;
	int num = N; //numero de obras a registrar
	datosobra *obra; //puntero para introducir los datos de las obras, esto ira en un archivo 
	datosobra ordenar;	 // estructura para ordenar
	datosobra obrades;   // Estructura para decargas las obras del fichero *************
	int buscar;
	char retirar[30];
	char buscarnombre[20], buscarautor[20]; 
	FILE *pf;
	
	obra = (datosobra *) malloc(num * sizeof(datosobra));
	
	//Contraseña para entrar
	contrasena autorizado [2], acceso;
	int contador = 0;
	int valido =1;
	//nombres y claves para entrar en el programa 
	strcpy (autorizado[0].usuario, "Claudia"); 	strcpy (autorizado[0].clave, "53382");
	strcpy (autorizado[1].usuario, "Elvira"); 	strcpy (autorizado[1].clave, "53576");
	
	do
	{
		if (contador == 3) return 666; //solo se tienen tres oportunidades en el caso de fallar al meter la clave y el usuario
		printf ("\n\nIndique su nombre de usuario y su contrasena:  ");
		scanf ("%s %s", acceso.usuario, acceso.clave);
		while (getchar() != '\n');

		valido = existeUsuario(autorizado, acceso.usuario, acceso.clave);//funcion que verifica la clave y usuario

		contador++;
	}	while (valido != 0);
	
	do
	{	
	i=0;
	menu();//llamamos a la opcion menu 
	//empezamos el switch para el menu
	scanf("%d", &opcion);
	fflush(stdin);
	
		switch(opcion)
		{
			case 1: //registrar obra se puede hacer mas de una a la vez 
				system ("cls");
				printf("\nHa seleccionado la opcion Registrar Obras\n"); //comprobar si el fichero se abre 
					if ((pf = fopen("registrodeobras.txt","r"))== NULL)
						{
							printf("Error: no se puede abrir el fichero \n");
							return(1);
						}
					i=0;
			 		while(fscanf(pf,"%d %s %s %c %d %d", &obrades.codigo, obrades.nombreobra, obrades.autor, &obrades.tipo,
													&obrades.creacion, &obrades.adquisicion)!=EOF)
					{//lee los datos del fichero y luego los pasa a un vetor de estructura 
		 				i = obrades.codigo - 1;
						obra[i].codigo = obrades.codigo;
						for(j=0; obrades.nombreobra[j]!='\0';j++)//se utiliza en el casi de que el nombre de la obra tenga mas 
						{										//de una palabra 
							if(obrades.nombreobra[j] == '_')
							  obra[i].nombreobra[j] = ' ';
							  else
							  obra[i].nombreobra[j] = obrades.nombreobra[j];
						}
						obra[i].nombreobra[j]= '\0';
						for(j=0; obrades.autor[j]!='\0';j++)//en este caso por si es el autor el que tiene mas de una palabra en su nombre 
						{
							if(obrades.autor[j] == '_')
							  obra[i].autor[j] = ' ';
							  else
							  obra[i].autor[j] = obrades.autor[j];
						} 
						obra[i].autor[j]= '\0';
						obra[i].tipo = obrades.tipo, 
						obra[i].creacion  = obrades.creacion, 
						obra[i].adquisicion  = obrades.adquisicion;	
					}
				fclose(pf);
				
				for(i=0; i < 20; i++ )//en este bucle recoge los datos del usuario introducidos por usuario en un vector de estuctura
				{
					if(obra[i].codigo != i+1)					  
					{
						obra[i].codigo = i+1;
						printf("Nombre de la obra: \n");
						scanf(" %[^\n]", obra[i].nombreobra);
						for(j=0; obra[i].nombreobra[j]!='\0';j++)
						{
							if(obra[i].nombreobra[j] == ' ')
							  obra[i].nombreobra[j] = '_';
							  else
							  obra[i].nombreobra[j] = obra[i].nombreobra[j];
						}
						obra[i].nombreobra[j]= '\0';						
						printf("Autor de la obra: \n");	
						scanf(" %[^\n]", obra[i].autor);
						for(j=0; obra[i].autor[j]!='\0';j++)
						{
							if(obra[i].autor[j] == ' ')
							  obra[i].autor[j] = '_';
							  else
							  obra[i].autor[j] = obra[i].autor[j];
						}
							obra[i].autor[j]= '\0';
						printf("e -> Escultura \np -> Pintura \n"); //Tiene que introducirse solo una de las opciones  
						scanf(" %c", &obra[i].tipo);
						fflush(stdin);
						printf("Fecha de creacion: \n");
						scanf(" %d", &obra[i].creacion); 
						fflush(stdin);
						printf("Fecha de adquisicion: \n");
						scanf(" %d", &obra[i].adquisicion);	
					    fflush(stdin);
					    break;
					}
				}					
				
				pf = fopen("registrodeobras.txt","w");	 //se escribiran en el fichero las obras que ha registrado el usuario
				for(i =0; i < num; ++i)						//al abrir el fichero con w se sobreescribiran 
				if (obra[i].codigo > 0 && obra[i].codigo <= num)
				for(j=0; obra[i].nombreobra[j]!='\0';j++)
						{
							if(obra[i].nombreobra[j] == ' ')
							  obra[i].nombreobra[j] = '_';
							  else
							  obra[i].nombreobra[j] = obra[i].nombreobra[j];
						}
						obra[i].nombreobra[j]= '\0';						
						printf("Autor de la obra: \n");	
						gets(obra[i].autor);
						for(j=0; obra[i].autor[j]!='\0';j++)
						{
							if(obra[i].autor[j] == ' ')
							  obra[i].autor[j] = '_';
							  else
							  obra[i].autor[j] = obra[i].autor[j];
						}
							obra[i].autor[j]= '\0';
				fprintf(pf, "%d %s %s %c %d %d\n", obra[i].codigo, obra[i].nombreobra,obra[i].autor, obra[i].tipo, 
														obra[i].creacion, obra[i].adquisicion);
				fclose(pf);
				break;
			
			case 2: //Buscar las obras tanto por autor como por nombre
				system ("cls");
				printf("Ha seleccionado la opcion buscar obra\n\n");
				printf("Indique si desea buscar por nombre (1) o por autor (2): \n");
				scanf("%d", &buscar);
				fflush(stdin);
				pf= fopen("registrodeobras.txt", "r");
				switch(buscar)
				{
					case 1: //Buscador por nombre 
					printf("Introduzca el nombre de la obra: \n");
					scanf(" %[^\n]", buscarnombre);
					while(fscanf(pf, "%d %s %s %c %d %d", &obra[i].codigo, obra[i].nombreobra, obra[i].autor, &obra[i].tipo, 
												&obra[i].creacion, &obra[i].adquisicion)!=EOF)
					{						
						for(j=0; obra[i].nombreobra[j]!='\0';j++)
						{
							if(obra[i].nombreobra[j] == '_')
							  obra[i].nombreobra[j] = ' ';
							  else
							  obra[i].nombreobra[j] = obra[i].nombreobra[j];
						}
						obra[i].nombreobra[j] = '\0';
						for(j=0; obra[i].autor[j]!='\0';j++)
						{
							if(obra[i].autor[j] == '_')
							  obra[i].autor[j] = ' ';
							  else
							  obra[i].autor[j] = obra[i].autor[j];
						}
							obra[i].autor[j]= '\0';
							
						if(!strcmp(buscarnombre, obra[i].nombreobra))//imprime por pantalla si encuentra una coincidencia entre los nombres
						{										//todos los datos de la obra 
							printf("El codigo es: %d\n", obra[i].codigo);
							printf("El nombre  es %s\n",obra[i].nombreobra);
							printf("El autor es %s\n",obra[i].autor);
							printf("El tipo es  %c\n", obra[i].tipo);
							printf("La fecha de creacion es %d\n", obra[i].creacion);
							printf("la fecha de adquisicion es %d\n\n\n",obra[i].adquisicion);	
						break;
						}
						i++;
					}
					fclose(pf);
					break;
					case 2: //Buscador por autor
					printf("\nIntroduzca el autor de la obra: \n");
					gets(buscarautor);
					i = 0;
					while(fscanf(pf, "%d %s %s %c %d %d", &obra[i].codigo, obra[i].nombreobra, obra[i].autor, &obra[i].tipo, 
															&obra[i].creacion, &obra[i].adquisicion)!=EOF)
					{
							for(j=0; obra[i].nombreobra[j]!='\0';j++)
						{
							if(obra[i].nombreobra[j] == '_')
							  obra[i].nombreobra[j] = ' ';
							  else
							  obra[i].nombreobra[j] = obra[i].nombreobra[j];
						}
						obra[i].nombreobra[j] = '\0';
						for(j=0; obra[i].autor[j]!='\0';j++)
						{
							if(obra[i].autor[j] == '_')
							  obra[i].autor[j] = ' ';
							  else
							  obra[i].autor[j] = obra[i].autor[j];
						}
							obra[i].autor[j]= '\0';								
						if(!strcmp(buscarautor,obra[i].autor))//vuelve a comparar pero en este caso en busca del autor
						{
							printf("El codigo es: %d\n", obra[i].codigo);
							printf("El nombre es: %s\n",obra[i].nombreobra);
							printf("El autor es: %s\n",obra[i].autor);
							printf("El tipo es:  %c\n", obra[i].tipo);
							printf("La fecha de creacion es: %d\n", obra[i].creacion);
							printf("la fecha de adquisicion es: %d\n\n\n",obra[i].adquisicion);	
						break;
						}
						i++;
					}
					fclose(pf);
					break;	
				}
				break;   
							
			case 3: //Eliminar obra por nombre de la obra
			system ("cls");
			printf("\nHa elegido la opcion Retirar Obra\n");
			printf("\nIndique el nombre de la obra que desea retirar: \n");
			scanf(" %[^\n]", retirar);
			
			pf=fopen ("registrodeobras.txt","r"); //lee el fichero solamente pero sin haber borrado los datos todavia  
			
			i = 0;
			while(fscanf(pf, "%d %s %s %c %d %d", &obra[i].codigo, obra[i].nombreobra, obra[i].autor, &obra[i].tipo, 
												&obra[i].creacion, &obra[i].adquisicion)!=EOF)
			{
						for(j=0; obra[i].nombreobra[j]!='\0';j++)
						{
							if(obra[i].nombreobra[j] == '_')
							  obra[i].nombreobra[j] = ' ';
							  else
							  obra[i].nombreobra[j] = obra[i].nombreobra[j];
						}
						obra[i].nombreobra[j]= '\0';						
														
				if(!strcmp(retirar, obra[i].nombreobra))
				{
					obra[i].codigo = -1; //para que cuando lo reescribas no guarde los codigos negativos, es como borrarlo 
					printf("Se ha retirado correctamente la obra.\n");
				}
				i++;
			}
			
			fclose(pf);
			pf = fopen ("registrodeobras.txt", "w");
			
			for(i =0; i < num; ++i)
				if (obra[i].codigo > 0 && obra[i].codigo <= num) //con esto solo se grabaran otra vez las obras que tengan codigos 
				{//positivos por eso antes se ha modificado el codigo a -1 que el usuario ha solicitado borrar 
						for(j=0; obra[i].nombreobra[j]!='\0';j++)
						{
							if(obra[i].nombreobra[j] == ' ')
							  obra[i].nombreobra[j] = '_';
							  else
							  obra[i].nombreobra[j] = obra[i].nombreobra[j];
						}
						obra[i].nombreobra[j] = '\0';
						for(j=0; obra[i].autor[j]!='\0';j++)
						{
							if(obra[i].autor[j] == ' ')
							  obra[i].autor[j] = '_';
							  else
							  obra[i].autor[j] = obra[i].autor[j];
						}
							obra[i].autor[j]= '\0';
			
				fprintf(pf, "%d %s %s %c %d %d\n", obra[i].codigo, obra[i].nombreobra,obra[i].autor, obra[i].tipo, 
														obra[i].creacion, obra[i].adquisicion);
													}
			fclose(pf);
			break;
			
			case 4: //listado de obras 
			//mostrar de dos formas:
			//1. orden cronologico por orden de antiguedad
			//2.orden cronologico por orden de adquisicion 
			system ("cls");		
			printf("Ha elegido la opcion Listado de obras\n Indique por que orden: \n");
			int opcionlistado;
			int mayor;
			printf("1. Orden cronologico por antiguedad\n");
			printf("2. Orden cronologico por adquisicion\n");
			scanf("%d", &opcionlistado);
			
			pf = fopen("registrodeobras.txt", "r");//vuelve a abrir el archivo solo en modo lectura
			
			if(opcionlistado==1)
			{
				k=0;
				i=0;
				while(fscanf(pf, "%d %s %s %c %d %d", &obra[i].codigo, obra[i].nombreobra, obra[i].autor, &obra[i].tipo, 
														&obra[i].creacion, &obra[i].adquisicion)!=EOF)
													{
															for(j=0; obra[i].nombreobra[j]!='\0';j++)
															{
																if(obra[i].nombreobra[j] == '_')
							 									obra[i].nombreobra[j] = ' ';
							  									else
							  									obra[i].nombreobra[j] = obra[i].nombreobra[j];
															}
															obra[i].nombreobra[j] = '\0';
															for(j=0; obra[i].autor[j]!='\0';j++)
															{
																if(obra[i].autor[j] == '_')
							  									obra[i].autor[j] = ' ';
							  									else
							  									obra[i].autor[j] = obra[i].autor[j];
															}
															obra[i].autor[j]= '\0';
														k++;
														i++;
													}
														
				{
								
				//metodo burbuja para ordenar los años
					for(j=0; j<k-1; j++) //Con este se repetirá la comparacion hasta que finalice 
					{
						for (i=0; i<k-1;i++)	
						{
							if (obra[i].creacion > obra[i+1].creacion)
							{
								ordenar = obra[i];
								obra[i] = obra[i+1];
								obra[i+1] = ordenar;
							}
						}
					}
								
				}
				for(i=0; i<k; i++)//imprime despues todas la obras ordenadas por años
					printf("\n%d \t%s \t%s \t%c \t%d \t%d\n", obra[i].codigo, obra[i].nombreobra, obra[i].autor, obra[i].tipo, 
												obra[i].creacion, obra[i].adquisicion);
			}
			
			if(opcionlistado==2)
			{
				k=0;
				i= 0;
				while (fscanf(pf, "%d %s %s %c %d %d", &obra[i].codigo, obra[i].nombreobra, obra[i].autor, &obra[i].tipo, 
														& obra[i].creacion, &obra[i].adquisicion)!=EOF)
														{
															for(j=0; obra[i].nombreobra[j]!='\0';j++)
															{
																if(obra[i].nombreobra[j] == '-')
							 									obra[i].nombreobra[j] = ' ';
							  									else
							  									obra[i].nombreobra[j] = obra[i].nombreobra[j];
															}
															obra[i].nombreobra[j] = '\0';
															for(j=0; obra[i].autor[j]!='\0';j++)
															{
																if(obra[i].autor[j] == '_')
							  									obra[i].autor[j] = ' ';
							  									else
							  									obra[i].autor[j] = obra[i].autor[j];
															}
															obra[i].autor[j]= '\0';
															k++;
															i++;
														}
				{						
					//metodo burbuja para ordenar los años
					for(j=0; j<k-1; j++) //Con este se repetirá la comparacion hasta que finalice 
					{
						for (i=0; i<k-1;i++)	
						{
							if (obra[i].adquisicion > obra[i+1].adquisicion)
							{
								ordenar = obra[i];
								obra[i] = obra[i+1];
								obra[i+1] = ordenar;
							}
						}
					}
				
				}
				for(i=0; i<k; i++)//imprime despues todas las obras ordenadas por años 
					printf("%d \t%s \t%s \t%c \t%d \t%d\n", obra[i].codigo, obra[i].nombreobra, obra[i].autor, obra[i].tipo, 
												obra[i].creacion, obra[i].adquisicion);
			}
			fclose(pf);
			break;
				
			case 5://almacén 
			system ("cls");
			printf ("La opcion elegida es ver la cantidad de esculturas y pinturas en el almacen.\n");
			int totalpinturas = 0;
			int totalesculturas = 0;

			pf = fopen("registrodeobras.txt", "r");//abre el fichero en modo lectura 
			
			while (fscanf(pf, "%d %s %s %c %d %d", &obra[i].codigo, obra[i].nombreobra, obra[i].autor, &obra[i].tipo, 
														&obra[i].creacion, &obra[i].adquisicion)!=EOF)
			{
			if (obra[i].tipo == 'p')//compara si la letra es una p se suma 1 a pinturas 
				totalpinturas++;
			
					if(obra[i].tipo == 'e')//en cambio si es una e se suma a esculturas 
						totalesculturas++;
				i++;
			}	//despues imprime todo por pantalla tambien el total de obras en el almacén 
			printf("El total de pinturas es %d \n", totalpinturas);
			printf("El total de esculturas es %d \n", totalesculturas);
			printf("El total de obras es %d \n", totalpinturas+totalesculturas);
			fclose(pf);
			break;
			case 6:
				return 0; //Buscar numero para salir del programa 	
				
			default: 
				system("cls");
				printf("Opcion incorrecta\n");	
				break;
		}
	
	} while(1); 

	system("pause");
	return 0;	
}

int existeUsuario(contrasena usuarioValido[], char nombre[], char clave[])
{
	int valido =0, i;
	for (i = 0; i < 2; i++)
		{
			valido = strcmp (usuarioValido[i].usuario, nombre) || strcmp (usuarioValido[i].clave, clave); 
			if (valido == 0) break;
		}
	return valido;
}

void menu ()
{
	system ("cls");
	printf("Bienvenido al MENU DE OPCIONES del Museo del Prado.\n ");
	printf ("Por favor seleccione una de las siguientes opciones: \n");
	printf("1. Registrar obra\n");
	printf("2. Buscar obra\n");
	printf("3. Retirar obra\n");
	printf("4. Listado de obras\n");
	printf("5. Almacen\n");
	printf("6. Salir\n");
	//default printf("Opcion incorrecta");
	fflush(stdin);
}


