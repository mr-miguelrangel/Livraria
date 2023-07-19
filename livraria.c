#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int disp_Matematica = 10, disp_Probabilidade = 10, disp_Fisica = 10, disp_Quimica = 10, disp_Computacao = 10;
  int vendido_Matematica = 0, vendido_Probabilidade = 0, vendido_Fisica = 0, vendido_Quimica = 0, vendido_Computacao = 0;
  int codigo, opcao, quantidade, vendido_Total;
  float valor_Total = 0;

  FILE *file = fopen("descricao.txt", "r");
  char texto[100];

  do{
    printf("-----------------------Livraria LP---------------------\n\n");
    printf("1 - Mostrar total de unidades e valor de cada categoria\n"); 
    printf("2 - Mostrar descricao da categoria\n");
    printf("3 - Comprar livros\n"); 
    printf("4 - Total vendido e montante em caixa\n");
    printf("5 - Encerrar\n\n");
  
    printf("Selecione uma da opcoes: ");
    scanf("%d", &opcao);
    system("clear");

    switch(opcao){
      case 1:
        printf("\n                       Disponivel     Vendido   Codigo        Valor\n");
        printf("Matematica                     %.2d        %.2d        1        R$ 150,00\n", disp_Matematica, vendido_Matematica);
        printf("Probabilidade e estatistica    %.2d        %.2d        2        R$ 100,00\n", disp_Probabilidade, vendido_Probabilidade);
        printf("Fisica                         %.2d        %.2d        3        R$ 160,00\n", disp_Fisica, vendido_Fisica);
        printf("Quimica                        %.2d        %.2d        4        R$ 160,00\n", disp_Quimica, vendido_Quimica);
        printf("Computacao                     %.2d        %.2d        5        R$ 200,00\n\n", disp_Computacao, vendido_Computacao);
        break;

      case 2:
        while(fgets(texto, 100, file))
        {
          printf("%s", texto);           
        }
        fclose(file);
        break;

      case 3:
        do{
        printf("\n1 - Matematica;\n2 - Probabilidade e estatistica;\n3 - Fisica;\n4 - Quimica;\n5 - Computacao.\n6 - Finalizar compra\n\n");
        printf("Digite o codigo da categoria de livro que voce deseja comprar: ");
        scanf("%d", &codigo);

        if(codigo != 6){
          printf("\nQuantos livros voce deseja comprar: ");
          scanf("%d", &quantidade);
        }
          
        switch(codigo){   
  
          case 1:
            if(quantidade <= disp_Matematica){
              disp_Matematica -= quantidade;
              vendido_Matematica += quantidade;
              valor_Total += quantidade * 150.0;
            }
            else{
              printf("\nVenda nao efetivada! Nos temos apenas %d livros dessa categoria em estoque.\n\n", disp_Matematica);
            }
          break;
          
          case 2:
            if(quantidade <= disp_Probabilidade){
              disp_Probabilidade -= quantidade;
              vendido_Probabilidade += quantidade;
              valor_Total += quantidade * 100.0;
            }
            else{
              printf("\nVenda nao efetivada! Nos temos apenas %d livros dessa categoria em estoque.\n\n", disp_Probabilidade);
            }
          break;
          
          case 3:
            if(quantidade <= disp_Fisica){
              disp_Fisica -= quantidade;
              vendido_Fisica += quantidade;
              valor_Total += quantidade * 160.0;
            }
            else{
              printf("\nVenda nao efetivada! Nos temos apenas %d livros dessa categoria em estoque.\n\n", disp_Fisica);
            }
          break;
          
          case 4:
            if(quantidade <= disp_Quimica){
              disp_Quimica -= quantidade;
              vendido_Quimica += quantidade;
              valor_Total += quantidade * 160.0;
            }
            else{
              printf("\nVenda nao efetivada! Nos temos apenas %d livros dessa categoria em estoque.\n\n", disp_Quimica);
            }            
          break;
          
          case 5:
            if(quantidade <= disp_Computacao){
              disp_Computacao -= quantidade;
              vendido_Computacao += quantidade;
              valor_Total += quantidade * 200.0;
            }
            else{
              printf("\nVenda nao efetivada! Nos temos apenas %d livros dessa categoria em estoque.\n\n", disp_Computacao);
            }
          break;
          
          case 6:
            printf("\nVenda efetivada!\nValor total: R$ %.2f \n\n", valor_Total);  
          break;
          
          default:
            printf("\nCodigo invalido!\n\n");
          break;

        }          
        } while(codigo != 6);
      break;

      case 4:
        vendido_Total = vendido_Matematica + vendido_Probabilidade + vendido_Fisica + vendido_Quimica + vendido_Computacao;
      
        printf("\n%d ja foram vendidos!\nMontante em caixa R$ %.2f\n\n", vendido_Total, valor_Total);
        
      break;

      case 5:
        printf("Obrigado e volte sempre!\n");
      break;

      default:
        printf("Opcao invalida!\n\n");
      break;
    }
  } while(opcao != 5);
  
  return 0;
}