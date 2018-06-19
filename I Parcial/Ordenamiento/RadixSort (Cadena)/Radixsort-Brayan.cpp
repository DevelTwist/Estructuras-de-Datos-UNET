  /********************************/
        /****** RADIXSORT BRAYAN  *******/
        /********************************/
          int salida[Size];
          int divisor = 1;
          int posicionNueva=0;
          int numMayor = numeroMax(VP, Size);

          // Bucle hasta que se haga 0 el numero mas grande del arreglo
          while (numMayor / divisor > 0){

            ImprimirVector(VP, Size);
            cout<<endl;
            for (i = 0; i < Size; i++){
                cout<<V[i]<<"\t";
            }

            int contador[10] = { 0 };

            for (i = 0; i < Size; i++)
              contador[(VP[i] / divisor) % 10]++;

            for (i = 1; i < 10; i++)
              contador[i] += contador[i - 1];

            for (i = Size - 1; i >= 0; i--){
              posicionNueva = --contador[(VP[i] / divisor) % 10];
              salida[posicionNueva] = VP[i];
              strcpy(Vaux[posicionNueva], V[i]);
            }
            cout<<endl;
            for (i = 0; i < Size; i++){
                VP[i] = salida[i];
                strcpy(V[i], Vaux[i]);
            }

            divisor *= 10;

            system("pause");
          }

          ImprimirVector(VP, Size);
          cout<<endl;
          for (i = 0; i < Size; i++){
             cout<<V[i]<<"\t";
          }
        /********************************/
        /****** RADIXSORT BRAYAN  *******/
        /********************************/
